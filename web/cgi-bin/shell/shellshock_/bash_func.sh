#!/bin/bash



#第一种函数定义方式： name () 循环控制结构复合命令
echo "f1 () loop_control_command"
f1 () for i in 1 2 3
do
        echo "f1函数输出: $i"
done

echo "调用f1"
f1

echo "=================================="
echo


#第二种函数定义方式： name () 条件结构复合命令
echo "f2 () condition_command"
f2 () if test -f /etc/redhat-release
then
        echo "your OS is redhat variant"
else
        echo "I don't know your OS"
fi
echo "调用f2"
f2

echo "=================================="
echo

#第三种函数定义方式： name () 子shell分组命令
echo "f3 () ( sub_shell_cmd_list )"
f3 () (
        echo "f3函数中，当前目录是:"
        pwd
        cd /usr/local
        echo "f3函数中，cd后的目录是"
        pwd
)

cd /tmp
echo "调用f3之前,当前目录是:"
pwd
echo "调用f3"
f3
echo "调用f3之后，当前目录是:"
pwd

echo "=================================="
echo

#第四种函数定义方式： name () 当前shell组合命令
echo "f4 () { cmd_list; }"
f4 () {
        echo "f4函数中，当前目录是:"
        pwd
        cd /usr/local
        echo "f4函数中，cd后的目录是"
        pwd
}

cd /tmp
echo "调用f4之前,当前目录是:"
pwd
echo "调用f4"
f4
echo "调用f4之后，当前目录是:"
pwd

#第5种函数定义方式
echo "f5 () (( cmd_list; ))"
f5 () ((a++,a++,++a))

a=9
f5   # 递增a的值
echo "a=$a"



#第6种函数定义方式
echo "f6 () case  esac"

f6 () 
case "$1" in

1)  echo "Sending SIGHUP signal"
    ;;
2)  echo  "Sending SIGINT signal"
    ;;

*) echo "Signal number $1 is not processed"
   ;;
esac

f6 1


#第7种函数定义方式 仍然是if形式
echo "f7 () [[]]"

f7 () 
if [[ $1==1 ]]
	then 
	echo "== 1"
fi


f7 1











#3.2.4 Compound Commands
#• Looping Constructs:	  	Shell commands for iterative action.
#• Conditional Constructs:	  	Shell commands for conditional execution.
#• Command Grouping:	  	Ways to group commands.
#
#Compound commands are the shell programming constructs. Each construct begins with a reserved word or control operator and is terminated by a corresponding reserved word or operator. Any redirections (see Redirections) associated with a compound command apply to all commands within that compound command unless explicitly overridden.
#
#In most cases a list of commands in a compound command’s description may be separated from the rest of the command by one or more newlines, and may be followed by a newline in place of a semicolon.
#
#Bash provides looping constructs, conditional commands, and mechanisms to group commands and execute them as a unit. 
#


# https://www.gnu.org/software/bash/manual/html_node/Shell-Functions.html


#3.3 Shell Functions
#
#Shell functions are a way to group commands for later execution using a single name for the group. They are executed just like a "regular" command. When the name of a shell function is used as a simple command name, the list of commands associated with that function name is executed. Shell functions are executed in the current shell context; no new process is created to interpret them.
#
#Functions are declared using this syntax:
#
#name () compound-command [ redirections ]
#
#or
#
#function name [()] compound-command [ redirections ]
#
#This defines a shell function named name. The reserved word function is optional. If the function reserved word is supplied, the parentheses are optional. The body of the function is the compound command compound-command (see Compound Commands). That command is usually a list enclosed between { and }, but may be any compound command listed above. compound-command is executed whenever name is specified as the name of a command. When the shell is in POSIX mode (see Bash POSIX Mode), name may not be the same as one of the special builtins (see Special Builtins). Any redirections (see Redirections) associated with the shell function are performed when the function is executed.
#
#A function definition may be deleted using the -f option to the unset builtin (see Bourne Shell Builtins).
#
#The exit status of a function definition is zero unless a syntax error occurs or a readonly function with the same name already exists. When executed, the exit status of a function is the exit status of the last command executed in the body.
#
#Note that for historical reasons, in the most common usage the curly braces that surround the body of the function must be separated from the body by blanks or newlines. This is because the braces are reserved words and are only recognized as such when they are separated from the command list by whitespace or another shell metacharacter. Also, when using the braces, the list must be terminated by a semicolon, a ‘&’, or a newline.
#
#When a function is executed, the arguments to the function become the positional parameters during its execution (see Positional Parameters). The special parameter ‘#’ that expands to the number of positional parameters is updated to reflect the change. Special parameter 0 is unchanged. The first element of the FUNCNAME variable is set to the name of the function while the function is executing.
#
#All other aspects of the shell execution environment are identical between a function and its caller with these exceptions: the DEBUG and RETURN traps are not inherited unless the function has been given the trace attribute using the declare builtin or the -o functrace option has been enabled with the set builtin, (in which case all functions inherit the DEBUG and RETURN traps), and the ERR trap is not inherited unless the -o errtrace shell option has been enabled. See Bourne Shell Builtins, for the description of the trap builtin.
#
#The FUNCNEST variable, if set to a numeric value greater than 0, defines a maximum function nesting level. Function invocations that exceed the limit cause the entire command to abort.
#
#If the builtin command return is executed in a function, the function completes and execution resumes with the next command after the function call. Any command associated with the RETURN trap is executed before execution resumes. When a function completes, the values of the positional parameters and the special parameter ‘#’ are restored to the values they had prior to the function’s execution. If a numeric argument is given to return, that is the function’s return status; otherwise the function’s return status is the exit status of the last command executed before the return.
#
#Variables local to the function may be declared with the local builtin. These variables are visible only to the function and the commands it invokes.
#
#Function names and definitions may be listed with the -f option to the declare (typeset) builtin command (see Bash Builtins). The -F option to declare or typeset will list the function names only (and optionally the source file and line number, if the extdebug shell option is enabled). Functions may be exported so that subshells automatically have them defined with the -f option to the export builtin (see Bourne Shell Builtins). Note that shell functions and variables with the same name may result in multiple identically-named entries in the environment passed to the shell’s children. Care should be taken in cases where this may cause a problem.
#
#Functions may be recursive. The FUNCNEST variable may be used to limit the depth of the function call stack and restrict the number of function invocations. By default, no limit is placed on the number of recursive calls. 
