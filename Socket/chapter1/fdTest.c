#include <stdio.h>

int main()
{
	int fd1, fd2, fd3;

	//fd1 = socket(PF_INET, SCOK_STREAM, 0);
	//fd2 = open("test.dat", O_CREAT|O_WRONLY);
	//fd3 = socket(PF_INET, SOCK_DGRAM,0);

	printf("fd 1: %d\n", fd1);
	printf("fd 2: %d\n", fd2);
	printf("fd 3: %d\n", fd3);

	close(fd1);
	close(fd2);
	close(fd3);

	return 0;
}
