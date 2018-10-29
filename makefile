all: main.o
	@gcc -o random.out main.o

main.o: main.c
	@gcc -c main.c

run:
	@./random.out

clean:
	@rm *.o*
	@rm *.txt
