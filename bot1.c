// bot 1

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	 main(void)
{
	char input_string[1000];
	char *output_string = "brrs";

	while(1)
	{
		// write(1, "a", 1);
		scanf("%s", input_string);
		//num += 1;
		printf("%s\n", output_string);
		fflush(stdout);
	}
	return(0);
}



