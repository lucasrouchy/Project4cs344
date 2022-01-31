#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int pip[2];

	pipe(pip);

	if (fork() == 0) {
		dup2(pip[0], 0);
		close(pip[1]);
		execlp("wc", "wc", "-l",NULL);
		exit(1);
	}

	dup2(pip[1], 1);
	close(pip[0]);

	execlp("ls", "ls", "-1", "-a", argv[1] ,NULL);
}
