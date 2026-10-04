CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: test_bits test_status

test_bits: bits.c test_bits.c bits.h 
	$(CC) $(CFLAGS) bits.c test_bits.c -o test_bits

test_status: bits.c status.c test_status.c bits.h status.h 
	$(CC) $(CFLAGS) bits.c status.c test_status.c -o test_status

clean: 
	rm -f test_bits test_status