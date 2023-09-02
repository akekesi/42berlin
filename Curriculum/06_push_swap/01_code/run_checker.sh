#!/bin/bash

# INFO:
# to set ARG in bash terminal: export ARG="2 1 0"
# https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php

# The if statement [ -z "$ARG" ] checks if $ARG is empty or has no value:
#   -z flag tests if the following string is empty or has no value.

# The if statement [ $? -eq 0 ] checks the exit status:
#   $? represents the exit status of the previous command (make in this case).
#   -eq is an operator used for numerical comparison, and it checks if the exit status is equal to 0.

# > /dev/null 2>&1 redirects both standard output (stdout) and standard error (stderr) to /dev/null, which essentially discards all the output.

# check ARG is set
if [ -z $ARG ]; then
  echo "ARG is not set"
  exit 1
fi

# clear
clear
echo "clear"

# make, make bonus without print to terminal
echo "make"
make > /dev/null 2>&1
echo "make bonus"
make bonus > /dev/null 2>&1

# check success of make
if [ $? -eq 0 ]; then
  # run executable
  echo "./push_swap $ARG"
  ./push_swap $ARG | ./checker $ARG
  ./push_swap $ARG | ./checker_linux $ARG
  echo "moves: $(./push_swap $ARG | wc -l)"
else
  echo "Error (make failed)"
fi

# make fclean without print to terminal
echo "make fclean"
make fclean > /dev/null 2>&1
