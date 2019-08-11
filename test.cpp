#include<stdio.h> 
#include<wait.h> 
#include<iostream>
#include<stdlib.h>
#include<signal.h> 
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
pid_t pid; 
int counter = 0; 
void handler1(int sig) 
{ 
    //counter++; 
    cout<<"The number is found.Killing Process "<<endl; 
    /* Flushes the printed string to stdout */
   // fflush(stdout); 
    kill(pid, SIGUSR1); 
} 

  
int main() 
{ 
    pid_t p; 
    int status; 
    signal(SIGUSR1, handler1); 
    /*if ((pid = fork()) == 0) 
    { 
        signal(SIGUSR1, handler2); 
        //kill(getppid(), SIGUSR1); 
        while(1) ; 
    } 
    if ((p = wait(&status)) > 0) 
    { 
        counter += 4; 
        printf("counter = %d\n", counter); 
    }
} */
}