#!/bin/bash

# If you enabled the commented line below, this script will list the total number of lines of C code by checking all subdirectories (Entire Project).
# CODE_LINES=$(git ls-files | grep '.c' | xargs wc -l | grep total | awk '{print $1}')

# This will check only in the current directory.
CODE_LINES=$(git ls-files | grep '.c'| sed -r 's/libft\/.*//g' | tr -s '' | xargs wc -l | grep total | awk '{print $1}')
echo "================================================================="
echo "You write $CODE_LINES lines of C code on this project. Good work!"
echo "================================================================="
