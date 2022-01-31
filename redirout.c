#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
	if(argc < 3) {
		printf("Error:3 inputs not entered \n");
		exit(1);
	}
int opf = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

int pip[2];

pipe(pip);

if(fork() == 0) {
  dup2(pip[1],1)
  close(pip[0]);

  char *const *args = argv + 2;
  execvp(argv[2], args);
  exit(1);
}
