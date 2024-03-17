NAME=ponker
CC=gcc
CF=-g -Wall
OF=$(CF) -c

all: clean $(NAME)

$(NAME): main.c cards.o
	$(CC) $(CF) $^ -o $@

cards.o: cards.c cards.h
	$(CC) $(OF) $<

clean:
	clear
	$(RM) $(NAME) *.o
