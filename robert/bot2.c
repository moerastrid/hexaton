// bot 2

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	 main(void)
{
	int num;

	while(1)
	{
		scanf("%*s %d", &num);
		num += 3;
		printf("%d\n", num);
		fflush(stdout);
	}
	return(0);
}



