##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Day 10 - Task 01 - Makefile
##

SRC = 	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_strlen.c \
	format_specifiers_part1.c \
	format_specifiers_part2.c \
	format_specifiers_part3.c \
	format_specifiers_part4.c \
	handle_e_functions.c \
	my_putnbr_base.c \
	my_printf.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

ROOT = ../../

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp -f $(NAME) $(ROOT)

clean:
	rm -f $(shell find -name '*~')
	rm -f $(shell find -name '#*#')
	rm -f $(shell find ../.. -name '*~')
	rm -f $(shell find ../.. -name '#*#')
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../../libmy.a

re: fclean all
