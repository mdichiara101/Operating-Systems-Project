#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{       
        int i, status,MAX;
        pid_t pid[MAX],wpid;
        printf("Children Then Parent: Enter the your desired amount of children: ");
        scanf("%d",&MAX);


        for(i=0; i<MAX; i++) //loops based on the input size
        {
                if((pid[i]=fork())==0)//determines if its a child
                {
                        
                        printf("Hello from Child %d\n",getpid());
                        exit(i);//exits current process
                }
                else if(pid[i]<0)//determines if error
                {
                        printf("error");
                        exit(0);
                }
        }

        while((wpid=wait(&status))>0);//makes parent wait based on status
        printf("Hello from Parent %d\n",getppid());
  
	return 0;

}
