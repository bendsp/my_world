##
## EPITECH PROJECT, 2021
## common
## File description:
## Makefile
##

SRCPATH	=	src/

SRC	=	$(SRCPATH)main.c	\
		$(SRCPATH)csfmlprocess.c	\
		$(SRCPATH)setup_struct.c	\
		$(SRCPATH)projection.c	\
		$(SRCPATH)manage_input.c	\
		$(SRCPATH)mouse_input.c	\
		$(SRCPATH)colors.c	\
		$(SRCPATH)switch_map.c	\
		$(SRCPATH)handlebutton.c	\
		$(SRCPATH)redim.c	\
		$(SRCPATH)editor.c	\
		$(SRCPATH)mousedrag.c	\
		$(SRCPATH)get_digits.c	\
		$(SRCPATH)save.c	\
		$(SRCPATH)load.c	\
		$(SRCPATH)saveloadtrig.c	\

NAME	=	my_world

CPPFLAGS	=	-I includes/

LDFLAGS	=	-L lib/ -lmy -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

LIBPATH	=	lib/my/

LIBNAME	=	libmy.a

CFLAGS	=	-Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(LIBNAME)
	gcc $(SRC) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

$(LIBNAME):
	make -C $(LIBPATH)

clean:
	make -C $(LIBPATH) clean
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)
	rm -f ./lib/$(LIBNAME)

re:	fclean	all
