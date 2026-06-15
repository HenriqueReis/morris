CC = gcc
CFLAGS = -Wall -Wextra -g

morris:	morris.o ninemens.o
	$(CC) $(CFLAGS) morris.o ninemens.o -o morris

morris.o: src/morris.c includes/ninemens.h
	$(CC) $(CFLAGS) -c src/morris.c -I includes

ninemens.o: src/ninemens.c includes/ninemens.h
	$(CC) $(CFLAGS) -c src/ninemens.c -I includes

clean:
	rm -rf *.o

fclean: clean
	rm -f morris

re: fclean morris
