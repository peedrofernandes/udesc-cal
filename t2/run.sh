#!/bin/bash

gcc main/algos.c main/index.c -o main/index.exe && ./main/index.exe

./venv/bin/python ./main/index.py
