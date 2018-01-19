#!/bin/sh
set -e
set -x
set -a

thisscript="$0"
while [ -L "$thisscript" ]; do
        thisscript="`readlink "$thisscript"`"
done

dirname=`dirname "$thisscript"`
if [ $dirname = "." ]; then
        dirname="$PWD"
fi

appname="`basename "$thisscript" | sed 's,\.sh$,,'`"

LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$dirname"
export LD_LIBRARY_PATH
ldd "$dirname/$appname"
LD_DEBUG=all "$dirname/$appname" "$@"

