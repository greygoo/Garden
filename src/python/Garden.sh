#!/bin/sh

PWD=$(pwd)
LOGFILE="/tmp/Garden.log"

${PWD}/Garden.py /dev/ttyUSB0 2>&1 >> ${LOGFILE}
