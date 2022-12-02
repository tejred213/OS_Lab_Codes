#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char buffer[2048];

void copy(int old, int new)
{
	int count;
	count = read(old,buffer,sizeof(buffer));
	write(new,buffer,count);
}

void main(int argc, char *argv[])
{
	int fdold, fdnew;
	if(argc !=3)
	{
		printf("need 2 agrc");
		exit(1);
	}
	fdold=open(argv[1],O_RDONLY);
	if(fdold==-1)
	{
		printf("can't open file %s\n",argv[1]);
		exit(1);
	}
	fdnew = creat(argv[2],0666);
	if(fdnew==-1)
	{
		printf("can't load %s\n",argv[2]);
		exit(1);
	}
	copy(fdold,fdnew);
	close(fdold);
	close(fdnew);
	exit(0);
}

