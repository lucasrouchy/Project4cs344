#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
	if(argc < 3) {
		printf("Error:3 inputs not entered \n");
		exit(1);
	}
int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
