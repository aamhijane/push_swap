#!/bin/bash

CODE_LINES=$(git ls-files | grep '.c'| sed -r 's/libft\/.*//g' | tr -s '' | xargs wc -l | grep total | awk '{print $1}')
echo "================================================================="
echo "You write $CODE_LINES lines of C code on this project. Good work!"
echo "================================================================="
