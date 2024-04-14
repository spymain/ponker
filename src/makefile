NAME=ponker
CC=gcc
CF=-g -Wall
OF=$(CF) -c

BINS=$(NAME) shuffle rand_hand best_hand

build: clean $(NAME)

all: $(BINS)

# ====================
#     MAIN PROGRAM
# ====================

$(NAME): main.c cards.o textinterface.o swap.o sort.o five_card.o nibble.o
	$(CC) $(CF) $^ -o $@

# ==================
#     UNIT TESTS
# ==================

TD=unit_tests
UF=-I$(shell pwd)

shuffle: $(TD)/shuffle.c cards.o textinterface.o swap.o sort.o five_card.o nibble.o
	$(CC) $(CF)$(UF)  $^ -o $@

rand_hand: $(TD)/rand_hand.c cards.o sort.o textinterface.o five_card.o swap.o nibble.o
	$(CC) $(CF)$(UF)  $^ -o $@

best_hand: $(TD)/best_hand.c cards.o sort.o textinterface.o five_card.o swap.o nibble.o
	$(CC) $(CF) $(UF) $^ -o $@

# ===============
#     OBJECTS
# ===============

cards.o: cards.c cards.h
	$(CC) $(OF) $<

textinterface.o: textinterface.c textinterface.h
	$(CC) $(OF) $<

swap.o: swap.c swap.h
	$(CC) $(OF) $<

sort.o: sort.c sort.h
	$(CC) $(OF) $<

five_card.o: five_card.c five_card.h
	$(CC) $(OF) $<

nibble.o: nibble.c nibble.h
	$(CC) $(OF) $<

clean:
	clear
	$(RM) $(BINS) *.o
