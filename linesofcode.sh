#!/usr/bin/env bash

LINES=$(find . -type f -name "*.c" -not -path "*./libft*" | xargs wc -l | grep total | awk '{ print $1 }')
echo "You write $LINES lines of C code."
