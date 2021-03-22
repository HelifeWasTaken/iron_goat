CC =	gcc
CFLAGS =	-I./include -I./erty/lib/include -L./erty/lib -lerty
SRC 	=	main.c
OBJ =	$(SRC:.c=.o)
NAME =	test

all: $(OBJ)
	make -j -C ./erty/lib --silent
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	make fclean -j -C ./erty/lib --silent
	rm -rf $(OBJ)

fclean: clean

re:
	make re -j -C ./erty/lib/ --silent
	make fclean -j -C ./erty/lib --silent
	make all -j -C ./erty/lib --silent
