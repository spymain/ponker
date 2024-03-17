NAME=ponker
CC=gcc
CF=-g -Wall
OF=$(CF) -c

all: clean $(NAME)

$(NAME): main.c
	$(CC) $(CF) $^ -o $@

clean:
	clear
	$(RM) $(NAME) *.o
