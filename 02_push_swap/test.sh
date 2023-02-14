#!/bin/bash
ARGS="$(seq 10 | sort -R | xargs)"
./push_swap $ARGS > cmd
./checker $ARGS < cmd