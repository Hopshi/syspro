#include <stdio.h>
#include <stdlib.h>
struct student {
int id;
char name[20];
};

int main()
{
	struct student *ptr;
	int n, i;
	printf("How many student what are you want insert? ");
	scanf("%d", &n);
	if (n <= 0) {
		fprintf(stderr, "Error: you wrong insert how many student.\n");
		fprintf(stderr, "exit process.\n");
		exit(1);
	}
	
	ptr = (struct student *) malloc(n * sizeof(struct student));
	if (ptr == NULL) {
		perror("malloc");
		exit(2);
	}
	
	printf("Insert %d student's number and name.\n", n);
	for (i = 0; i < n; i++)
		scanf("%d %s", &ptr[i].id, ptr[i].name);
	
	printf("\n*student's data(reverse) *\n");
	for (i = n-1; i >= 0; i--)
		printf("%d %s\n", ptr[i].id, ptr[i].name);
	
	printf("\n");
	exit(0);
}

