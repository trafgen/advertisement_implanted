#!/bin/bash

BIN_NAME="mproxy_arm"

PLATFORMS_NAME="$1"
ROOT_DIR="$2"
TOOL_CHAIN="$3"
TOOL_ARCH="$4"
MODEL_TARGET="$5"

VERSION=`cat src/version.h | grep -w VERSION | awk -F " " '{print $3}' | awk -F '"' '{print $2}'`

[ -z "$VERSION" ] && echo "not define version!" > ./complie.log && exit

echo "make clean BIN_NAME=$BIN_NAME"
make clean BIN_NAME=$BIN_NAME
echo "make ROOT_DIR=$ROOT_DIR TOOL_CHAIN=$TOOL_CHAIN TOOL_ARCH=$TOOL_ARCH MODEL_TARGET=$MODEL_TARGET BIN_NAME=$BIN_NAME 2>./complie.log"
make ROOT_DIR=$ROOT_DIR TOOL_CHAIN=$TOOL_CHAIN TOOL_ARCH=$TOOL_ARCH MODEL_TARGET=$MODEL_TARGET BIN_NAME=$BIN_NAME 2>./complie.log

complie_log=`cat ./complie.log`
[ -n "$complie_log" ] && {
	err=`cat ./complie.log | grep -w "error:" | wc -l`
	warn=`cat ./complie.log | grep -w "warning:" | wc -l`

	if [ "$err" == "0" ] && [ "$warn" == "1" ]
	then
		complie_log_tmp=$complie_log
		complie_log=`echo "$complie_log" | grep "warning: gethostbyname"`
		if [ -n "$complie_log" ]
		then
			echo > ./complie.log
		else
			echo "[ERROR] $complie_log_tmp"
			exit
		fi
	elif [ "$err" != "0" ] || [ "$warn" != "0" ]
	then
		echo "[ERROR] $complie_log"
		exit
	fi
}

echo "rm -rf ../package/app/$BIN_NAME"
rm -rf ../package/app/$BIN_NAME
echo "cp -rf hex/$BIN_NAME ../package/app/"
cp -rf hex/$BIN_NAME ../package/app/
sync

exit
