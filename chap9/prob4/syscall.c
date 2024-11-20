#include <sys/wait.h>
#include <stdio.h>
int main()
{
	int status;
	if ((status = system("date")) < 0)
		perror("system() error");
		printf("endcode %d\n", WEXITSTATUS(status));
	if ((status = system("hello")) < 0)
		perror("system() error");
		printf("endcode %d\n", WEXITSTATUS(status));
	if ((status = system("who; exit 44")) < 0)
		perror("system() error");
		printf("endcode %d\n", WEXITSTATUS(status));
}
