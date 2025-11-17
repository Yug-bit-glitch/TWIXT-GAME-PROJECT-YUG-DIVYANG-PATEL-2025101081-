CC = gcc
CFLAGS = -Wall -Wextra -std=c11

OBJ = board.o control.o

twixt: $(OBJ)
	$(CC) $(CFLAGS) -o twixt $(OBJ)

board.o: board.c twixt.h
	$(CC) $(CFLAGS) -c board.c

control.o: control.c twixt.h
	$(CC) $(CFLAGS) -c control.c

clean:
	rm -f *.o twixt
