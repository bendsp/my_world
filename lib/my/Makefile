##
## EPITECH PROJECT, 2021
## d10
## File description:
## make some compilation
##

SRC	=	my_atoi.c	\
		my_baseconvert.c	\
		my_cutstr.c	\
		my_getstr.c	\
		my_is_prime.c	\
		my_power.c	\
		my_putchar.c	\
		my_putnbr.c	\
		my_putstr.c	\
		my_reallocstr.c	\
		my_revstr.c	\
		my_sqrt.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strncmp.c	\
		my_strcmp.c	\
		my_strncpy.c	\
		my_swap.c	\
		my_getline.c	\
		my_splitstr.c	\
		my_countchar.c	\
		my_addchar.c	\
		my_getcontent.c	\
		my_strcat.c	\
		my_strdup.c	\
		my_printf/cases.c	\
		my_printf/my_printf.c	\
		strlist/destroy_strlist.c	\
		strlist/lenstrlist.c	\
		strlist/strlistncpy.c	\

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c $(SRC) -I ../../includes/ -g
	ar rc $(NAME) *.o
	mv $(NAME) ..

clean:
	rm -f *.o

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all
