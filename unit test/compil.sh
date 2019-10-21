#!/bin/bash

if [ "$1" != "quick" ]; then
../setup.sh $1 $2
fi
gcc test.c $lib -lud_math -lud_array -lud_utils -lud_string -lud_string_array -lud_memory -o executable
./executable