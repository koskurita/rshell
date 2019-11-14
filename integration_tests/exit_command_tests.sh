#!/bin/sh

INPUTS=("exit" "Exit" "ls || exit" "GoingToFail || exit" "ls && ls -a && exit")


echo "Executing ./c-echo ${INPUTS[4]}"
./c-echo ${INPUTS[4]}
echo "Executing ./c-echo ${INPUTS[3]}"
./c-echo ${INPUTS[3]}
echo "Executing ./c-echo ${INPUTS[2]}"
./c-echo ${INPUTS[2]}
echo "Executing ./c-echo ${INPUTS[1]}"
./c-echo ${INPUTS[1]}
echo "Executing ./c-echo ${INPUTS[0]}"
./c-echo ${INPUTS[0]}

