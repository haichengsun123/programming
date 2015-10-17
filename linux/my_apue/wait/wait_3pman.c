WAIT(P)                                                                         POSIX Programmer's Manual                                                                         WAIT(P)



NAME
       wait, waitpid - wait for a child process to stop or terminate

SYNOPSIS
       #include <sys/wait.h>

       pid_t wait(int *stat_loc);
       pid_t waitpid(pid_t pid, int *stat_loc, int options);


DESCRIPTION
       The wait() and waitpid() functions shall obtain status information pertaining to one of the caller's child processes. Various options permit status information to be obtained for
       child processes that have terminated or stopped. If status information is available for two or more child processes, the order in which their status is reported is unspecified.

       The wait() function shall suspend execution of the calling thread until status information for one of the terminated child processes of the calling process is available, or until
       delivery  of a signal whose action is either to execute a signal-catching function or to terminate the process. If more than one thread is suspended in wait() or waitpid() await‐
       ing termination of the same process, exactly one thread shall return the process status at the time of the target process termination. If status information is available prior to
       the call to wait(), return shall be immediate.

       The  waitpid()  function  shall be equivalent to wait() if the pid argument is (pid_t)-1 and the options argument is 0. Otherwise, its behavior shall be modified by the values of
       the pid and options arguments.

       The pid argument specifies a set of child processes for which status is requested. The waitpid() function shall only return the status of a child process from this set:

        * If pid is equal to (pid_t)-1, status is requested for any child process. In this respect, waitpid() is then equivalent to wait().

        * If pid is greater than 0, it specifies the process ID of a single child process for which status is requested.

        * If pid is 0, status is requested for any child process whose process group ID is equal to that of the calling process.

        * If pid is less than (pid_t)-1, status is requested for any child process whose process group ID is equal to the absolute value of pid.

       The options argument is constructed from the bitwise-inclusive OR of zero or more of the following flags, defined in the <sys/wait.h> header:

       WCONTINUED
              The waitpid() function shall report the status of any continued child process specified by pid whose status has not been reported since it continued  from  a  job  control
              stop.

       WNOHANG
              The waitpid() function shall not suspend execution of the calling thread if status is not immediately available for one of the child processes specified by pid.

       WUNTRACED
              The  status of any child processes specified by pid that are stopped, and whose status has not yet been reported since they stopped, shall also be reported to the request‐
              ing process.


       If the calling process has SA_NOCLDWAIT set or has SIGCHLD set to SIG_IGN, and the process has no unwaited-for children that were transformed into zombie processes,  the  calling
       thread shall block until all of the children of the process containing the calling thread terminate, and wait() and waitpid() shall fail and set errno to [ECHILD].

       If wait() or waitpid() return because the status of a child process is available, these functions shall return a value equal to the process ID of the child process. In this case,
       if the value of the argument stat_loc is not a null pointer, information shall be stored in the location pointed to by stat_loc. The value stored at the location  pointed  to  by
       stat_loc shall be 0 if and only if the status returned is from a terminated child process that terminated by one of the following means:

        1. The process returned 0 from main().

        2. The process called _exit() or exit() with a status argument of 0.

        3. The process was terminated because the last thread in the process terminated.

       Regardless  of  its  value,  this  information may be interpreted using the following macros, which are defined in <sys/wait.h> and evaluate to integral expressions; the stat_val
       argument is the integer value pointed to by stat_loc.

       WIFEXITED(stat_val)

              Evaluates to a non-zero value if status was returned for a child process that terminated normally.

       WEXITSTATUS(stat_val)

              If the value of WIFEXITED(stat_val) is non-zero, this macro evaluates to the low-order 8 bits of the status argument that the child process passed to _exit() or exit(), or
              the value the child process returned from main().

       WIFSIGNALED(stat_val)

              Evaluates to a non-zero value if status was returned for a child process that terminated due to the receipt of a signal that was not caught (see <signal.h>).

       WTERMSIG(stat_val)

              If the value of WIFSIGNALED(stat_val) is non-zero, this macro evaluates to the number of the signal that caused the termination of the child process.

       WIFSTOPPED(stat_val)

              Evaluates to a non-zero value if status was returned for a child process that is currently stopped.

       WSTOPSIG(stat_val)

              If the value of WIFSTOPPED(stat_val) is non-zero, this macro evaluates to the number of the signal that caused the child process to stop.

       WIFCONTINUED(stat_val)

              Evaluates to a non-zero value if status was returned for a child process that has continued from a job control stop.


       It  is  unspecified whether the status value returned by calls to wait() or waitpid() for processes created by posix_spawn() or posix_spawnp() can indicate a WIFSTOPPED(stat_val)
       before subsequent calls to wait() or waitpid() indicate WIFEXITED(stat_val) as the result of an error detected before the new process image starts executing.

       It is unspecified whether the status value returned by calls to wait() or waitpid() for processes created by posix_spawn() or posix_spawnp() can indicate a  WIFSIGNALED(stat_val)
       if a signal is sent to the parent's process group after posix_spawn() or posix_spawnp() is called.

       If the information pointed to by stat_loc was stored by a call to waitpid() that specified the WUNTRACED flag  and did not specify the WCONTINUED flag,  exactly one of the macros
       WIFEXITED(*stat_loc), WIFSIGNALED(*stat_loc), and WIFSTOPPED(*stat_loc) shall evaluate to a non-zero value.

       If the information pointed to by stat_loc was stored by a call to waitpid() that specified the WUNTRACED    and WCONTINUED  flags, exactly one of the macros WIFEXITED(*stat_loc),
       WIFSIGNALED(*stat_loc), WIFSTOPPED(*stat_loc),  and WIFCONTINUED(*stat_loc)  shall evaluate to a non-zero value.

       If the information pointed to by stat_loc was stored by a call to waitpid() that did not specify the WUNTRACED  or WCONTINUED  flags, or by a call to the wait() function, exactly
       one of the macros WIFEXITED(*stat_loc) and WIFSIGNALED(*stat_loc) shall evaluate to a non-zero value.

       If the information pointed to by stat_loc was stored by a call to waitpid() that did not specify the WUNTRACED flag  and specified the WCONTINUED flag,   or  by  a  call  to  the
       wait() function, exactly one of the macros WIFEXITED(*stat_loc), WIFSIGNALED(*stat_loc),    and WIFCONTINUED(*stat_loc)  shall evaluate to a non-zero value.

       If  _POSIX_REALTIME_SIGNALS  is defined, and the implementation queues the SIGCHLD signal, then if wait() or waitpid() returns because the status of a child process is available,
       any pending SIGCHLD signal associated with the process ID of the child process shall be discarded. Any other pending SIGCHLD signals shall remain pending.

       Otherwise, if SIGCHLD is blocked, if wait() or waitpid() return because the status of a child process is available, any pending SIGCHLD signal shall be cleared unless the  status
       of another child process is available.

       For all other conditions, it is unspecified whether child status will be available when a SIGCHLD signal is delivered.

       There  may  be additional implementation-defined circumstances under which wait() or waitpid() report status.  This shall not occur unless the calling process or one of its child
       processes explicitly makes use of a non-standard extension. In these cases the interpretation of the reported status is implementation-defined.

       If a parent process terminates without waiting for all of its child processes to terminate, the remaining child processes shall be assigned a new parent process ID  corresponding
       to an implementation-defined system process.

RETURN VALUE
       If  wait()  or  waitpid()  returns because the status of a child process is available, these functions shall return a value equal to the process ID of the child process for which
       status is reported. If wait() or waitpid() returns due to the delivery of a signal to the calling process, -1 shall be returned and errno set to [EINTR]. If waitpid() was invoked
       with WNOHANG set in options, it has at least one child process specified by pid for which status is not available, and status is not available for any process specified by pid, 0
       is returned.  Otherwise, (pid_t)-1 shall be returned, and errno set to indicate the error.

ERRORS
       The wait() function shall fail if:

       ECHILD The calling process has no existing unwaited-for child processes.

       EINTR  The function was interrupted by a signal. The value of the location pointed to by stat_loc is undefined.


       The waitpid() function shall fail if:

       ECHILD The process specified by pid does not exist or is not a child of the calling process, or the process group specified by pid does not exist or  does  not  have  any  member
              process that is a child of the calling process.

       EINTR  The function was interrupted by a signal. The value of the location pointed to by stat_loc is undefined.

       EINVAL The options argument is not valid.


       The following sections are informative.

EXAMPLES
       None.

APPLICATION USAGE
       None.

RATIONALE
       A  call  to  the wait() or waitpid() function only returns status on an immediate child process of the calling process; that is, a child that was produced by a single fork() call
       (perhaps followed by an exec or other function calls) from the parent. If a child produces grandchildren by further use of fork(), none of those grandchildren nor  any  of  their
       descendants affect the behavior of a wait() from the original parent process.  Nothing in this volume of IEEE Std 1003.1-2001 prevents an implementation from providing extensions
       that permit a process to get status from a grandchild or any other process, but a process that does not use such extensions must be guaranteed to see status from only its  direct
       children.

       The waitpid() function is provided for three reasons:

        1. To support job control

        2. To permit a non-blocking version of the wait() function

        3. To permit a library routine, such as system() or pclose(), to wait for its children without interfering with other terminated children for which the process has not waited

       The  first  two  of these facilities are based on the wait3() function provided by 4.3 BSD. The function uses the options argument, which is equivalent to an argument to wait3().
       The WUNTRACED flag is used only in conjunction with job control on systems supporting job control. Its name comes from 4.3 BSD and refers to the fact that there are two types  of
       stopped  processes  in  that implementation: processes being traced via the ptrace() debugging facility and (untraced) processes stopped by job control signals. Since ptrace() is
       not part of this volume of IEEE Std 1003.1-2001, only the second type is relevant. The name WUNTRACED was retained because its usage is the same, even  though  the  name  is  not
       intuitively meaningful in this context.

       The  third  reason  for the waitpid() function is to permit independent sections of a process to spawn and wait for children without interfering with each other. For example, the
       following problem occurs in developing a portable shell, or command interpreter:


              stream = popen("/bin/true");
              (void) system("sleep 100");
              (void) pclose(stream);

       On all historical implementations, the final pclose() fails to reap the wait() status of the popen().

       The status values are retrieved by macros, rather than given as specific bit encodings as they are in most historical implementations (and thus expected  by  existing  programs).
       This  was  necessary  to  eliminate  a  limitation  on  the  number  of  signals  an  implementation  can  support that was inherent in the traditional encodings.  This volume of
       IEEE Std 1003.1-2001 does require that a status value of zero corresponds to a process calling _exit(0), as this is the most common encoding expected by existing  programs.  Some
       of the macro names were adopted from 4.3 BSD.

       These  macros  syntactically  operate on an arbitrary integer value.  The behavior is undefined unless that value is one stored by a successful call to wait() or waitpid() in the
       location pointed to by the stat_loc argument. An early proposal attempted to make this clearer by specifying each argument as *stat_loc rather than stat_val.  However,  that  did
       not  follow  the  conventions  of other specifications in this volume of IEEE Std 1003.1-2001 or traditional usage. It also could have implied that the argument to the macro must
       literally be *stat_loc; in fact, that value can be stored or passed as an argument to other functions before being interpreted by these macros.

       The extension that affects wait() and waitpid() and is common in historical implementations is the ptrace() function. It is called by a child process and  causes  that  child  to
       stop  and return a status that appears identical to the status indicated by WIFSTOPPED. The status of ptrace() children is traditionally returned regardless of the WUNTRACED flag
       (or by the wait() function). Most applications do not need to concern themselves with such extensions because they have control over what extensions they or their  children  use.
       However, applications, such as command interpreters, that invoke arbitrary processes may see this behavior when those arbitrary processes misuse such extensions.

       Implementations  that  support  core  file creation or other implementation-defined actions on termination of some processes traditionally provide a bit in the status returned by
       wait() to indicate that such actions have occurred.

       Allowing the wait() family of functions to discard a pending SIGCHLD signal that is associated with a successfully waited-for child process puts them into the sigwait() and  sig‐
       waitinfo() category with respect to SIGCHLD.

       This definition allows implementations to treat a pending SIGCHLD signal as accepted by the process in wait(), with the same meaning of "accepted" as when that word is applied to
       the sigwait() family of functions.

       Allowing the wait() family of functions to behave this way permits an implementation to be able to deal precisely with SIGCHLD signals.

       In particular, an implementation that does accept (discard) the SIGCHLD signal can make the following guarantees regardless of the queuing depth of signals in general  (the  list
       of waitable children can hold the SIGCHLD queue):

        1. If  a SIGCHLD signal handler is established via sigaction() without the SA_RESETHAND flag, SIGCHLD signals can be accurately counted; that is, exactly one SIGCHLD signal will
           be delivered to or accepted by the process for every child process that terminates.

        2. A single wait() issued from a SIGCHLD signal handler can be guaranteed to return immediately with status information for a child process.

        3. When SA_SIGINFO is requested, the SIGCHLD signal handler can be guaranteed to receive a non-NULL pointer to a siginfo_t structure that describes a child process for  which  a
           wait via waitpid() or waitid() will not block or fail.

        4. The system() function will not cause a process' SIGCHLD handler to be called as a result of the fork()/ exec executed within system() because system() will accept the SIGCHLD
           signal when it performs a waitpid() for its child process. This is a desirable behavior of system() so that it can be used in a library without causing side  effects  to  the
           application linked with the library.

       An  implementation  that  does not permit the wait() family of functions to accept (discard) a pending SIGCHLD signal associated with a successfully waited-for child, cannot make
       the guarantees described above for the following reasons:

       Guarantee #1

              Although it might be assumed that reliable queuing of all SIGCHLD signals generated by the system can make this guarantee, the counter-example is the  case  of  a  process
              that blocks SIGCHLD and performs an indefinite loop of fork()/ wait() operations. If the implementation supports queued signals, then eventually the system will run out of
              memory for the queue. The guarantee cannot be made because there must be some limit to the depth of queuing.

       Guarantees #2 and #3

              These cannot be guaranteed unless the wait() family of functions accepts the SIGCHLD signal. Otherwise, a fork()/ wait() executed while SIGCHLD is blocked (as in the  sys‐
              tem() function) will result in an invocation of the handler when SIGCHLD is unblocked, after the process has disappeared.

       Guarantee #4

              Although  possible  to make this guarantee, system() would have to set the SIGCHLD handler to SIG_DFL so that the SIGCHLD signal generated by its fork() would be discarded
              (the SIGCHLD default action is to be ignored), then restore it to its previous setting. This would have the undesirable side effect of discarding all SIGCHLD signals pend‐
              ing to the process.


FUTURE DIRECTIONS
       None.

SEE ALSO
       exec() , exit() , fork() , waitid() , the Base Definitions volume of IEEE Std 1003.1-2001, <signal.h>, <sys/wait.h>

COPYRIGHT
       Portions  of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1, 2003 Edition, Standard for Information Technology -- Portable Operating System Inter‐
       face (POSIX), The Open Group Base Specifications Issue 6, Copyright (C) 2001-2003 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group. In  the  event
       of  any  discrepancy  between  this version and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original
       Standard can be obtained online at http://www.opengroup.org/unix/online.html .



IEEE/The Open Group                                                                        2003                                                                                   WAIT(P)
