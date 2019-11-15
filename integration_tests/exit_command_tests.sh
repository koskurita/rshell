#!/bin/sh

INPUTS=("exit" "Exit" "ls && exit" "GoingToFail || exit" "ls && ls -a && exit")


echo "\nExecuting ./c-echo ${INPUTS[0]}"
./c-echo ${INPUTS[0]}
echo "Executing ./c-echo ${INPUTS[1]}"
./c-echo ${INPUTS[1]}
echo "\nExecuting ./c-echo ${INPUTS[2]}"
./c-echo ${INPUTS[2]}
echo "\nExecuting ./c-echo ${INPUTS[3]}"
./c-echo ${INPUTS[3]}
echo "\nExecuting ./c-echo ${INPUTS[4]}"
./c-echo ${INPUTS[4]}

