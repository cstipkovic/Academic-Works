#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

main() {
	int pid;

	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "erro\n");
		exit(1);
	}

	if (0 == pid) {
		printf("FILHO: \t id is %d, pid (valor) is %d\n", getpid(), pid);
	} else {
		printf("PAI: \t id is %d, pid (filho) is %d\n", getpid(), pid);
		/* este comando é executado duas vezes... */
	}

	system("date");
}
