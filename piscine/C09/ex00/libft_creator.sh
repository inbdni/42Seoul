#!/bin/bash

gcc -Wall -Wextra -Werror -c *.c
ar scr libft.a *.o
rm *.o
