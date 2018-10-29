#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int get_random()
{
	//open the random file, and declare the int to store it
	int file = open("/dev/random", O_RDONLY);
	int rand;
	//read exactly an integers worth of data and place it in rand
	read(file, &rand, sizeof(int));
	//return any errors if they exist
	if (errno)
	{
		printf("ERROR %d: %s\n", errno, strerror(errno));
	}
	
	//close and return the value of rand
	close(file);
	return rand;
}

int main()
{
	//printf("get_random #: %d\n", get_random()); test

	//generate the array of random integers
	int random_ints[10];
	for (int i = 0; i < 10; i++)
	{
		random_ints[i] = get_random();
	}
	for (int i = 0; i < 10; i++)
	{
		printf("random int #%d: %d\n", i, random_ints[i]);
	}

	//write to the file WITHOUT USING A LOOP, AS SPECIFIED
	//simply writes the array
	printf("WRITING TO THE FILE....\n");
	int file = open("random.txt", O_WRONLY | O_CREAT, 0666);
	write(file, random_ints, sizeof(int) * 10);
	close(file);

	//read from the file WITHOUT USING A LOOP, AS SPECIFIED
	//simply reads the strange data stored in our file
	printf("READING FROM THE FILE....\n");
	file = open("random.txt", O_RDONLY);
	int test_random_ints[10];
	read(file, test_random_ints, sizeof(int) * 10);
	close(file);

	//prints out to test if it truly is the same
	for(int i = 0; i < 10; i++)
	{
		printf("random int #%d: %d\n", i, test_random_ints[i]);
	}
	return 0;
}
