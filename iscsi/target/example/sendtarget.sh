#!/bin/bash

device=$1
auth=$2
targetIQN=test:123456:${device}
lun=iscsi00

tcm_node --block iblock_0/test_${device} /dev/${device} 
lio_node --addlun test:123456:${device} 1 0 $lun iblock_0/test_${device} 
lio_node --listendpoints
lio_node --addnp test:123456:${device} 1 0.0.0.0:3260 
lio_node --enabletpg $targetIQN 1
# demo模式
lio_node --demomode $targetIQN 1
# 去掉验证
lio_node --disableauth $targetIQN 1
# 去掉写保护
lio_node --settpgattr=$targetIQN  1 demo_mode_write_protect 0
iscsiadm -m discovery -t sendtargets -p 192.168.146.233:3260
iscsiadm -m session -P3
#iscsiadm -m discovery -t sendtargets -p 192.168.146.26:3260
#sleep 10
#iscsiadm -m node -T $targetIQN -p  192.168.146.26:3260 --login

#sleep 60
#iscsiadm -m node -T $targetIQN -p  192.168.146.26:3260 --logout
#lio_node --deltpg  $targetIQN 1
#tcm_node --freedev iblock_0/$blockName
#lio_node --deliqn  $targetIQN





# 是否验证
#lio_node --enableauth test:123456:${device} 1 
#lio_node --addlunacl test:123456:${device} 1 iqn.1993-08.org.debian:01:fcc9228c36cc 0 0 
#lio_node --setchapauth test:123456:${device} 1 $targetIQN nbs netease 
#lio_node --settpgattr=test:123456:${device} 1 cache_dynamic_acls 0 
#lio_node --enabletpg test:123456:${device} 1 

