#!/bin/bash

# INFO:
# duration of fork's getting/letting caused 50 400 200 200 NOK ???
# delay caused by large number of processors --> first action is not in time stamp 0 but 1, 2... 30ms

# to set ARG in bash terminal:
# export ARG="  1 800 200 200    " ------> OK (death)
# export ARG="  5 800 200 200    " ------> OK
# export ARG="  5 800 200 200   7" ------> OK
# export ARG="  4 410 200 200    " ------> OK
# export ARG="  4 310 200 100    " ------> OK (death)
# export ARG=" 10 150  60  60  50" ------> OK
# export ARG="100 150  60  60  50" ------> OK
# export ARG=" 11 150  60  60  50" ------> OK (death) <-- odd number of philosophers
# export ARG="111 150  60  60  50" ------> OK (death) <-- odd number of philosophers
# export ARG="  2 150 130 130    " ------> OK (death)
# export ARG="  2 1500 1300 1300 " ------> OK (death)
# export ARG=" 50 121 60  60   20" ------> OK
# export ARG="100 123 60  60   20" ------> OK
# export ARG="150 125 60  60   20" ------> OK
# export ARG="200 125 60  60   20" ------> OK
# export ARG="111 185 60  60   20" ------> OK
# export ARG="151 185 60  60   20" ------> OK
# export ARG="199 185 60  60   20" ------> OK


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
rm -f philosophers.txt