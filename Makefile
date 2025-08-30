CFLAGS = -std=c11 -Wall -Wextra -O2
OBJS = lista_se.o musica.o playlist.o player.o main.o

all: tocador
tocador: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f *.o tocador
