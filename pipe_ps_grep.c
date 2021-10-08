#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc,char* argv[]){
    int pipefd[2];
    int ret=pipe(pipefd);
    if(ret<0){
        perror("pipe error:");
        return -1; 
    }   

    if(fork()==0){
    //child1   ps -ef
       ret=dup2(pipefd[1],1);
       if(ret<0){
            perror("dup2 error:");
            return -1; 
       }   
       execlp("ps","ps","-ef",NULL);
       exit(-1);
    }   
    if(fork()==0){
    //child2   grep
        close(pipefd[1]);
        ret=dup2(pipefd[0],0);
        if(ret<0){
            perror("dup2 error:");
            return -1; 
        }   
        execlp("grep","grep","pipe",NULL);                                                                                                                                                     
        exit(-1);
    }   
    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}
