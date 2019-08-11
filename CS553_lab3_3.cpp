#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <random>
#include<stdlib.h>
#include<stdio.h>
#include <ctime>
#include<signal.h>
#include <chrono>
using namespace std;

void write_file()
{
	FILE *f;
	int l;
	f=fopen("LOG_filessearch_2.txt","w");
	random_device rd; 
	//std::chrono::time_point<std::chrono::system_clock> start_t, end_t;
	mt19937 eng(rd()); 
	uniform_int_distribution<> distr(1, 100);
	for(int i=0;i<100;i++)
	{

		if(f)
		{
			l=distr(eng);
			//cout<<l<<endl;
			fprintf(f,"%d\n",l);
		}
	}
	fclose(f);
	//return 0;
}

void avg(int begin,int end)
{
	int sum,count,l;
	sum=0;
	double avg;
	count=0;

	
			FILE* f1;
			f1=fopen("LOG_filessearch_2.txt","r");
			if(f1)
			{
				

					fseek(f1,begin,SEEK_SET);
					if(ftell(f1)<=end)
					{
						fscanf(f1,"%d\n",&l);
						sum+=l;
						count++;
					}
				
				
				avg=sum/count;
				cout<<"My id is "<<getpid()<<" with parent "<<getppid()<<" my calculated average is "<<avg<<endl;
				//break;
				fclose(f1);
			}
			


		}





void divide(int end,int begin)
{
	pid_t t;

	int mid;
	//cout<<begin<<" "<<end<<endl;
	if(end-begin>25)
	{	
		//cout<<"c"<<endl;

		
		mid=(end+begin)/2;
		
		cout<<"My pid is "<<getpid()<<" with parent "<<getppid()<<" i forked"<<endl;
		t=fork();
		if(t==0)
		{
			//cout<<"a "<<endl;
			divide(mid,begin);

		}
		else
		{
			t=fork();
			if(t==0)
			{
				//cout<<"b"<<endl;
				divide(end,mid+1);	
			}
			else
			{
				sleep(3);
			}
			
			//avg(begin,mid,end);
		}
	//avg(begin,mid,end);
	}
	else
	{
		avg(begin,end);
	}

}

int main()
{
	int start,end;
	write_file();
	FILE* f1;

	f1=fopen("LOG_filessearch_2.txt","a");
	if(f1)
	{
	end=ftell(f1);
	fclose(f1);

	}
	start=0;
	//cout<<start<<" "<<end<<endl;

	divide(end,start);
	return 0;
}