#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;
int main()
{
	int n,k,m,l,c=0;
	pid_t x;
	vector<int>v;
	vector<int> sum;
	cout<<"Enter the number of entries:"<<endl;
	cin>>n;
	FILE *f;
	f=fopen("LOG_filessearch.txt","w+");
	random_device rd; 
	mt19937 eng(rd()); 
	uniform_int_distribution<> distr(1, 100);
	for(int i=0;i<n;i++)
	{
		if(f)
		{
			l=distr(eng);
			fprintf(f,"%d\n",l);
		}
		v.push_back(l);
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	fclose(f);
	cout<<"Enter the number you want to search:"<<endl;
	cin>>m;
	std::chrono::time_point<std::chrono::system_clock> start, end; 
	start = std::chrono::system_clock::now();
	int j=count(v.begin(),v.end(),m);
	end = std::chrono::system_clock::now(); 
	std::chrono::duration<double> elapsed_seconds = end - start; 
	cout<<"elapsed time: " << elapsed_seconds.count() << "s\n";
	cout<<"Number of occurances: "<<j<<endl;
	cout<<"Enter the number of child processes you want to create for searching:"<<endl;
	cin>>k;
	int d=floor(n/k);
	int s=0,c1=0;
	int e=d;
	for(int i=0;i<k;i++)
	{
		x=fork();
		if(x==0)
		{
			if(i<k-1)
			{	
				start = std::chrono::system_clock::now();
				c=count(v.begin()+s,v.begin()+e,m);
				end = std::chrono::system_clock::now();
				
			}
			else if(i==(k-1))
			{
				start = std::chrono::system_clock::now();
				c=count(v.begin()+s,v.end(),m);
				end = std::chrono::system_clock::now(); 
			}
			std::chrono::duration<double> elapsed_second = end - start; 
			cout<<"elapsed time: " << elapsed_second.count() << "s\n";
			cout<<"Number of occurances: "<<c<<endl;
			break;
		}
		else
		{
			s+=d;
			e+=d;
			sleep(1);
		}
	}
	return 0;
}