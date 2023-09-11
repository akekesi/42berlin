#!/bin/bash

# INFO:
# duration of fork's getting/letting caused 50 400 200 200 NOK ???
# delay caused by large number of processors --> first action is not in time stamp 0 but 1, 2... 30ms

# to set ARG in bash terminal:
# export ARG="1 800 200 200" --------> not eat, die, delay < 10ms
# export ARG="5 800 200 200" --------> not die
# export ARG="5 800 200 200 7" ------> not die, 7 loop
# export ARG="4 410 200 200" --------> not die
# export ARG="4 310 200 100" --------> die, delay < 10ms
# export ARG="2 xxx xxx xxx ---------> delay for 2 philosophers
# export ARG="4 120 60 60" ----------> 
# export ARG="2 1000 500 500" -------> 
# export ARG="2 10000 5000 4999" ----> 
# export ARG="2 10000 5000 5000" ----> 
# export ARG="2 10000 5001 5000" ----> 
# export ARG="2 1000 501 500" -------> 
# export ARG="2 60 100 100" ---------> 
# export ARG="3 310 104 103" --------> 
# export ARG="3 3100 1040 1030" -----> 
# export ARG="3 310 103 103" --------> 
# export ARG="200 300 200 100 3" ----> 
# export ARG="0 300 310 100 5" ------> 
# export ARG="-1 300 310 100 5" -----> 
# export ARG="201 300 310 100 5" ----> 
# export ARG="111 59 310 100 5" -----> 
# export ARG="111 300 59 100 5" -----> 
# export ARG="111 300 310 59 5" -----> 
# export ARG="111 300 310 100" ------> 
# export ARG="111 300 310 100 -5" ---> 
# export ARG="111 300 310 100 -5" ---> 
# export ARG="111 222 333" ----------> 
# export ARG="111 222 333 444 555" --> 
# export ARG="111 300 310 100 0" ----> 
# export ARG="10 150 60 60" ---------> 
# export ARG="11 150 60 60" ---------> 
# export ARG="12 150 60 60" ---------> 
# export ARG="13/14 150 60 60" ------> 

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
