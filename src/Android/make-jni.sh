#!/bin/bash

ARGS=`getopt -o axby -l long-key: -- "$@"`
if [ $# == 0 ]; then echo "Usage: ./make-jni.sh --CPU=<ARM|x86> [--DEBUG]"; exit 1; fi

echo $*

eval set -- "${ARGS}"

echo $1, $2, $3, $4

while true; do
    case "$1" in
    -C|--CPU)
        CPU="$2"
        echo $CPU
        shift
    ;;
    --DEBUG)
        DEBUG=1
        echo DEBUG
    ;;
    --)
        echo BREAK
    break
    ;;
    esac
    shift
done
