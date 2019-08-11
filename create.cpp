#include<bits/stdc++.h>
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


return 0;
}

