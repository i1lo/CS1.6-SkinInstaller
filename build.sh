#!/bin/bash

GCC=gcc
SRC=src/main.c
OUT=cs16.exe

echo "Compiling $SRC -> $OUT..."

$GCC -o $OUT $SRC -Wall -Wextra

if [ $? -eq 0 ]; then
    echo "Compilation successful! Executable: $OUT"
else
    echo "Compilation failed!"
fi
