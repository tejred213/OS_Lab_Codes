#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/*pid_t : is a long integer type data type... prototype in types.h */
pid_t num_pid;

int main()
{
num_pid=fork(); /* return values of fork */
if(num_pid==0)
	{
		printf("This is child process id %d\n",getpid());
	}
	
if(num_pid>0)
	{
		printf("this is parent process id %d\n",getpid());
	}
exit (0);
}
		
