#!/bin/bash

if [ $# -lt 1 ]
then
    echo "Usage: `basename $0` xxx.proto"
    exit 1
fi

protoc -I=. --cpp_out=. $1

exit 0
