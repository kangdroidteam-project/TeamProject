CC=gcc-9
CFLAGS=-Wall -O3
TARGET=app.out
OBJS=main.o \
	score_menu.o \
	time_attack.o \
	mini_game.o \
	typing_game.o \
	init.o \
	find_way.o \
	show_vocab.o \
	save_load.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -rf ./*.out ./*.o