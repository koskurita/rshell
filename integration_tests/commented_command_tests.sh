#!/bin/sh



INPUTS=("ls #&& me try to fail this" "ls #&& ls -a" "echo hello #exit" "#exit && exit" "ls -a || ls || echo hello#ignored hopefully&&*")


echo "Executing ./c-echo ${INPUTS[0]}"
./c-echo ${INPUTS[0]}
echo "Executing ./c-echo ${INPUTS[1]}"
./c-echo ${INPUTS[1]}
echo "Executing ./c-echo ${INPUTS[2]}"
./c-echo ${INPUTS[2]}
echo "Executing ./c-echo ${INPUTS[3]}"
./c-echo ${INPUTS[3]}
echo "Executing ./c-echo ${INPUTS[4]}"
./c-echo ${INPUTS[4]}

