#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "store.h"

int main(int argc, char* argv[])
{
	int fd;
	struct store record;
	if (argc < 2) {
		fprintf(stderr, "How to use: %s FileName\n", argv[0]);
		exit(1);
	}
	if ((fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0640)) == -1) {
		perror(argv[1]);
		exit(2);
	}
	printf("%-9s %-8s %-5s %-4s\n", "name", "category", "expired date", "stock");
	while (scanf("%s %s %hd %hd", record.name, record.category, &record.expired_date, &record.stock)==4){
		lseek(fd, sizeof(record), SEEK_SET);
		write(fd, (char *) &record, sizeof(record) );
	}
	fclose(fd);
	return 0;
}
