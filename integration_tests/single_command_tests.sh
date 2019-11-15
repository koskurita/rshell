#!/bin/sh

INPUTS=("ls" "echo hello" "mkdir test" "rm -r test")

echo "Executing ./c-echo ${INPUTS[3]}"
./main.cpp ${INPUTS[3]}
echo "Executing ./c-echo ${INPUTS[2]}"
./main.cpp ${INPUTS[2]}
echo "Executing ./c-echo ${INPUTS[1]}"
./main.cpp ${INPUTS[1]}
echo "Executing ./c-echo ${INPUTS[0]}"
./main.cpp ${INPUTS[0]}
