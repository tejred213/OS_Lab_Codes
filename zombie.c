#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	if((pid=fork())< 0)
		printf("\n\tfork error\n");
		else
			if(pid==0)
			{
				printf("child id is %d\n\n",getpid());
			}
			else
			{
				sleep(10);
				system("ps -axj | more");
			}
exit(0);
}					
