##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

CC	=	gcc

SRC	=	$(wildcard *.c)

LIB	=	libmy.a

all:	$(LIB)

$(LIB):	$(SRC)
	gcc -c lib/my/*.c
	ar rc $(LIB) *.o
	rm *.o

clean:
	rm -f $(LIB)

fclean:
	rm -f $(LIB)

re:
	rm -f $(LIB)
	gcc -c lib/my/*.c
	ar rc $(LIB) *.o
	rm *.o
