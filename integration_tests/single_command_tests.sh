#!/bin/sh

INPUTS=("ls -a")

printf "Executing ./c-echo ${INPUTS[0]} \n"
./c-echo ${INPUTS[0]}
