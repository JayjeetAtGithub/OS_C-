#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <random>
#include<stdlib.h>
#include<stdio.h>
#include <ctime>
#include <chrono>
using namespace std;
int main()
{
	//int start_t,end_t,elapsed_time;
	int n,m,l,c=0;
	pid_t x;
	vector<int>v;
	int index[100];
	//vector<int> sum;
	cout<<"Enter the number of childs:"<<endl;
	cin>>n;
	FILE *f;
	f=fopen("LOG_filessearch.txt","w");
	random_device rd; 
	std::chrono::time_point<std::chrono::system_clock> start_t, end_t;
	mt19937 eng(rd()); 
	uniform_int_distribution<> distr(1, 100);
	for(int i=0;i<100;i++)
	{

		if(f)
		{
			l=distr(eng);
			cout<<l<<endl;
			fprintf(f,"%d\n",l);
		}
	}
	fclose(f);
	int p;
	cout<<"Enter the number to be searched"<<endl;
	cin>>p;
	f=fopen("LOG_filessearch.txt","a");
	int k;
	if(f)
	{
		k=ftell(f);
		fclose(f);
	}

	//cout<<k<<endl;
	int last=k;
	//fclose(f);
	int ca=0,cb=0;
	int q;
	q=floor(k/n);
	//f=fopen("LOG_filessearch.txt","r");
	index[0]=q;
	int z;
	for(z=1;z<n;z++)
	{
		q=floor(k/n);
		index[z]=q+index[z-1];
	//	cout<<index[z]<<endl;;
	}
	//cout<<last<<endl;
	//index[z+1]=last;
	//cout<<index[z+1]<<endl;
	FILE* f1;
	FILE* f2;

	for(int j=0;j<n;j++)
	{
		x=fork();
		if(x==0)

		{	
			start_t = std::chrono::system_clock::now();

			ca=0;
			f1=fopen("LOG_filessearch.txt","r");
			if(f1)
			{



			//cout<<index[j]<<endl;
			//cout<<index[z+1]<<endl;
			//cout<<ftell(f1)<<endl;
			if(j==0)
			{

			

			while(ftell(f1)<index[j])
			{
				//cout<<ftell(f1)<<endl;
				fscanf(f1,"%d",&l);
				if(l==p)
					ca++;


			}
			}
			else
			{
				fseek(f1,index[j-1],SEEK_SET);
				//cout<<"a"<<endl;
				while(ftell(f1)<=index[j])
				{
					//cout<<ftell(f1)<<endl;
					fscanf(f1,"%d",&l);
					if(l==p)
						ca++;


				}

		}
			end_t = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds=end_t-start_t;
			cout<<"time "<<elapsed_seconds.count()<<endl;
			cout<<"the number of occurnce in child "<<j<<" is "<<ca<<endl;
			fclose(f1);
		}
		break;
		}

		

		
	}
		if(x!=0)
		{
			start_t = std::chrono::system_clock::now();
			//cout<<"A"<<endl;
			cb=0;
			f2=fopen("LOG_filessearch.txt","r");
			if(f2)
			{	
		//		cout<<"a"<<endl;

			fseek(f2,0,SEEK_SET);
			while(last--)
			{
				//cout<<ftell(f2)<<endl;
				fscanf(f2,"%d",&l);
				if(l==p)
				cb++;


			}
		//	cout<<"a"<<endl;
		
			end_t = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds=end_t-start_t;
			cout<<"time "<<elapsed_seconds.count()<<endl;
			cout<<"the number of occurnce in parent is "<<cb<<endl;
			fclose(f2);
		}

		}
	//return 0;


	}
			
			


	

	






