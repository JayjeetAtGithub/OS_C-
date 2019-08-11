#include<bits/stdc++.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/time.h>
#include<unistd.h>
using namespace std;

int main()
{

FILE *F=fopen("file2.txt","wb+");
FILE *F1=fopen("log.txt","w");
int a=10;
if(F)
{
fwrite(&a,sizeof(int),sizeof(a),F);
fclose(F);
}
if(F1)
{
fprintf(F1,"PPID\t\tPID\t\tSECOND\t\tMili-Second\t\tINITIAL\t\tFINAL\n");
fclose(F1);

}
	
int a=1;
struct timeval tv;
for(int i=1;i<=500;i++)
{
FILE * f=fopen("file.txt","rb+");
FILE *f1=fopen("log.txt","a");

if(f)
{
fread(&a,sizeof(int),1,f);
fclose(f);
if (f1)
{

gettimeofday(&tv,NULL);
fprintf(f1,"%d\t\t%d\t\t%ld\t\t%ld\t\t%d\t\t%d\n",getppid(),getpid(),tv.tv_sec,tv.tv_usec,a-1,++a);
fclose(f1);

}

FILE *f=fopen("file.txt","wb+");
if(f)
{
fwrite(&a,sizeof(int),1,f);
fclose(f);
}
}
}
return 0;
}
