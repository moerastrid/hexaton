// bot 2

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	 main(void)
{
	int num;
	int filenum = open("test.txt", O_WRONLY | O_CREAT);

	write(filenum, "test", 4);
	while(1)
	{
		scanf("%*s %d", &num);
		write(filenum, "test", 4);
		num += 3;
		printf("%d\n", num);
		fflush(stdout);
	}
	return(0);
}



