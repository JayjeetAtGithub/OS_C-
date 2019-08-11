#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

int main()
{
	pid_t x;
	FILE *f;
	f=fopen("LOG_2.txt","w+");
	if(f)
	{
		fprintf(f,"PARENT ID\tPROCESS ID\tCHILD ID\n");
		fclose(f);
	}
	int i;
	f=fopen("LOG_mchild.txt","a+");
	for (int i = 0; i < 10; ++i)
	{
		x=fork();
		if (x==0)
		{

			printf("My Process id=%d ,Parent Process id=%d,Child id=%d\n",getpid(),getppid(),x);
			if(f)
			{	
			fprintf(f,"%u\t\t%u\t\t%d\n",getppid(),getpid(),x);
			fclose(f);
			}
			if((getpid()%2)==0)
				{
					printf("Hello\n");
				}
				else
				{
					printf("World\n");
				}
				break;
		}
		

	}
	printf("Bye\n");
}