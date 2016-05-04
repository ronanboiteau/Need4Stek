#!/bin/bash
##
## File: [pipes.sh]
## Author: carbon_q.
## Contact: <carbonel.q@gmail.com> (github.com/yartFF)
## Created on 2016-04-21 12:28
## 
##
STUDENT_NAME="./ia"
BUFF_NAME="./n4s_buffer"
N4S_NAME="./n4s"

FIFONAME=".fifo"
trap "rm -f $FIFONAME" EXIT

if [ ! -p $FIFONAME ]; then
  mkfifo $FIFONAME
fi

if [ ! -x $STUDENT_NAME ] || [ ! -x $BUFF_NAME ] || [ ! -x $N4S_NAME ]; then
  echo "One of the following is missing or is missing execution user rights"
  echo $STUDENT_NAME $BUFF_NAME $N4S_NAME
  exit 1
fi

"./$STUDENT_NAME" < $FIFONAME |  "./$BUFF_NAME" | "./$N4S_NAME" |  "./$BUFF_NAME" > $FIFONAME 2> /dev/null
