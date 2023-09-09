#!/bin/bash

# INFO:
# to set ARG in bash terminal:
# export ARG="1 800 200 200" ------> not eat, die, delay < 10ms (worst case: 2ms)
# export ARG="5 800 200 200" ------> not die
# export ARG="5 800 200 200 7" ----> not die, 7 loop
# export ARG="4 410 200 200" ------> not die
# export ARG="4 310 200 100" ------> die, delay < 10ms (worst case: 3ms)
# export ARG="2 120 60 60" --------> not die
# export ARG="2 1000 500 500" -----> not die
# export ARG="2 10000 5000 4999" --> not die
# export ARG="2 10000 5000 5000" --> not die
# export ARG="2 10000 5001 5000" --> die, delay < 10ms (worst case: 0ms)
# export ARG="2 1000 501 500" -----> die, delay < 10ms (worst case: 0ms)
# export ARG="2 60 100 100" -------> die, delay < 10ms (worst case: 0ms)
# export ARG="3 310 104 103" ------> die, delay < 10ms (worst case: 3ms)
# export ARG="3 3100 1040 1030" ---> die, delay < 10ms (worst case: 2ms)
# export ARG="3 310 103 103" ------> not die

# The if statement [ -z "$ARG" ] checks if $ARG is empty or has no value:
#   -z flag tests if the following string is empty or has no value.

# The if statement [ $? -eq 0 ] checks the exit status:
#   $? represents the exit status of the previous command (make in this case).
#   -eq is an operator used for numerical comparison, and it checks if the exit status is equal to 0.

# > /dev/null 2>&1 redirects both standard output (stdout) and standard error (stderr) to /dev/null, which essentially discards all the output.

# Really cool visualizer/checker for this project with awesome github link :)
# https://nafuka11.github.io/philosophers-visualizer/


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
  echo "./philo $ARG"
  ./philo $ARG
  # ./philo $ARG 2>&1 | tee philosophers.txt
  # valgrind ./philo $ARG
  # valgrind --tool=helgrind ./philo $ARG # check data race but does not work !!! (stuck in first philospher !!
  echo "./philo $ARG"
else
  echo "Error (make failed)"
fi

# make fclean without print to terminal
echo "make fclean"
make fclean > /dev/null 2>&1
