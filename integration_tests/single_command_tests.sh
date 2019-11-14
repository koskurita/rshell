#!/bin/sh

INPUTS=("ls" "echo hello" "mkdir test" "rm -r test")

echo "Executing ./c-echo ${INPUTS[3]}"
./c-echo ${INPUTS[3]}
echo "Executing ./c-echo ${INPUTS[2]}"
./c-echo ${INPUTS[2]}
echo "Executing ./c-echo ${INPUTS[1]}"
./c-echo ${INPUTS[1]}
echo "Executing ./c-echo ${INPUTS[0]}"
./c-echo ${INPUTS[0]}
