NAME=ponker
CC=gcc
CF=-g -Wall
OF=$(CF) -c

all: clean $(NAME)

$(NAME): main.c cards.o textinterface.o swap_int8_t.o sort.o five_card.o nibble.o
	$(CC) $(CF) $^ -o $@

cards.o: cards.c cards.h
	$(CC) $(OF) $<

textinterface.o: textinterface.c textinterface.h
	$(CC) $(OF) $<

swap_int8_t.o: swap_int8_t.c swap_int8_t.h
	$(CC) $(OF) $<

sort.o: sort.c sort.h
	$(CC) $(OF) $<

five_card.o: five_card.c five_card.h
	$(CC) $(OF) $<

nibble.o: nibble.c nibble.h
	$(CC) $(OF) $<

clean:
	clear
	$(RM) $(NAME) *.o
