#!/bin/sh

INPUTS=("ls -a" "echo hello" "ls" "mkdir delitme" "rm -r delitme")

printf "Executing ./c-echo ${INPUTS[0]} \n"
./c-echo ${INPUTS[0]}
printf "Executing ./c-echo ${INPUTS[1]} \n"
./c-echo ${INPUTS[1]}
printf "Executing ./c-echo ${INPUTS[2]} \n"
./c-echo ${INPUTS[2]}
printf "Executing ./c-echo ${INPUTS[3]} \n"
./c-echo ${INPUTS[3]}
printf "Executing ./c-echo ${INPUTS[4]} \n"
./c-echo ${INPUTS[4]}


