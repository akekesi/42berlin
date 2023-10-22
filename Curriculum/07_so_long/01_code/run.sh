#!/bin/bash

# INFO:
# The if statement [ $? -eq 0 ] checks the exit status:
#   $? represents the exit status of the previous command (make in this case).
#   -eq is an operator used for numerical comparison, and it checks if the exit status is equal to 0.

# > /dev/null 2>&1 redirects both standard output (stdout) and standard error (stderr) to /dev/null, which essentially discards all the output.


# clear
clear
echo "clear"

# make, make bonus without print to terminal
echo "make"
make > /dev/null 2>&1

# check success of make
if [ $? -eq 0 ]; then
  # run executable
  echo "valgrind --leak-check=full --show-leak-kinds=all ./so_long assets/maps/map.ber"
  valgrind --leak-check=full --show-leak-kinds=all ./so_long assets/maps/map.ber
else
  echo "Error (make failed)"
fi

# make fclean without print to terminal
echo "make fclean"
make fclean > /dev/null 2>&1

# make fclean without print to terminal
echo "norminette error: " \
&& norminette | grep Error! | wc -l
