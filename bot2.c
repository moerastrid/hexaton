// bot 2

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	 main(void)
{
	char input_string[1000];
	char *output_string = "drrrs";
	char *output_string2 = "errrs";
	static int i = 0;
	
	while(1)
	{
		i++; // write(1, "a", 1);
		scanf("%s", input_string);
		//num += 1;
		if (i == 3)
			printf("%s\n", output_string2);
		else
			printf("%s\n", output_string);
		
		fflush(stdout);
	}
	return(0);
}
