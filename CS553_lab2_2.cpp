#include<stdio.h>
#include<iostream>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

int main()
{
	pid_t x;
	int ctr;
	ctr=0;
	int n;
	cout<<"Enter the required level "<<endl;
	cin>>n;
	FILE *f;
	f=fopen("LOG_1.txt","w+");
	if(f)
	{
		fprintf(f,"PARENT ID\tPROCESS ID\tCHILD ID\n");
		fclose(f);
	}

	x=fork();
	
	//int i=0;

	for(ctr=0;ctr<n;ctr++)
		{
			if(x==0)
			{
				
				
				//cout<<ctr<<endl;
				//if(ctr==(n-1))
					//printf("My Process id=%d ,Parent Process id=%d,Child id=-1\n",getpid(),getppid());
				//else
					printf("My Process id=%d ,Parent Process id=%d,Child id=%d\n",getpid(),getppid(),x);
				if((getpid()%2)==0)
				{
					printf("Hello\n");
					x=fork();
				}
				else
				{
					printf("World\n");
					x=fork();
				}
				
			
			}
			else
			{
				sleep(1);
			}
			
		}
		if(f)
	{
		fprintf(f,"%u\t\t%u\t\t%d\n",getppid(),getpid(),x);
		fclose(f);
	}
		cout<<"Bye"<<endl;



}
