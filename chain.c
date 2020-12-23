#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int i, MAX;
void Child(pid_t p,int i, int MAX, pid_t wpid, int status);
int main(int argc, char *argv[]){
        i=1;
        int status;
        
        pid_t wpid;
        printf("Child Parent Chain:Enter your desired amount of children ");
        scanf("%d",&MAX);
        if(MAX==2) //if input is 2
	{pid_t pid = fork(); //fork once
        Child(pid,i,MAX,wpid,status); //Calls child function   
        while((wpid=wait(&status))>0);//makes parent wait
       }
       else if(MAX==4) //if input is 4
      { pid_t pid = fork();//fork twice
        pid= fork();
        Child(pid,i,MAX,wpid,status);   
        while((wpid=wait(&status))>0);
       }
     else if(MAX==8) //if input is 8
      { pid_t pid = fork(); //fork 3 times
        pid= fork();
        pid=fork();
        Child(pid,i,MAX,wpid,status);   
        while((wpid=wait(&status))>0);
      }   
	return 0; 
}
        
void Child(pid_t pid,int i, int MAX, pid_t wpid, int status){
 
    if(i==MAX){ //executes the last pid first
        printf("Hello from Child %d\n", getpid());
        exit(i);
        return;
        
    }
    else if(i<MAX){ //recursively calls the function until last pid
        
        i++;
        while((wpid=wait(&status))>0);
        Child(pid, i, MAX, wpid, status);
        
    }
    else{
        return;
    }
     
}
