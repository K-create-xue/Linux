#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<sys/wait.h> 
#include<unistd.h> 
#include<sys/stat.h> 
#include<fcntl.h> 
int main(int argc,char* argv[]){ 
        while(1){ 
                printf("[user@host path]$ "); 
                fflush(stdout); 
                char buf[1024]={0}; 
                fgets(buf,1023,stdin); 
                buf[strlen(buf)-1]='\0'; 
 
                int myargc=0; 
                char *ptr=buf,*myargv[32]={NULL}; 
                int flag=0;//0:没有，1:>,2:>> 
                char* redirect_file=NULL; 
                //[ls -a \0\0  test.txt\0] 
                while(*ptr!='\0'){ 
                    if(*ptr=='>'){ 
                        flag=1; 
                        *ptr='\0'; 
                        ++ptr; 
                     
                    if(*ptr=='>'){ 
                        flag=2; 
                        *ptr='\0'; 
                        ++ptr; 
                    } 
                    while(*ptr!='\0' && *ptr==' ') 
                        ++ptr; 
                    redirect_file=ptr; 
                    while(*ptr!='\0' && *ptr!=' ') 
                        ++ptr; 
                    *ptr='\0'; 
                    } 
                    ++ptr; 
                } 
                ptr=buf; 
                while(*ptr!='\0'){ 
                        if(*ptr!=' '){ 
                                myargv[myargc]=ptr; 
                                ++myargc; 
                                while(*ptr!=' ' && *ptr!='\0') 
                                        ++ptr; 
                                *ptr='\0'; 
                        } 
                        ++ptr; 
                } 
                myargv[myargc]=NULL; 
 
                //cd 
                if(strcmp("cd",myargv[0])==0){ 
                        chdir(myargv[1]); 
                        continue; 
                } 
                 
 
                //创建子进程 
                pid_t pid=fork(); 
                if(pid<0){ 
                        perror("fork error"); 
                        // 
                }else if(pid==0){ 
                if(flag==1){ 
                    int fd; 
                    umask(0); 
                    fd=open(redirect_file,O_RDWR|O_TRUNC|O_CREAT,0664); 
                    if(fd<0){ 
                        perror("open erroe:"); 
                        return -1; 
                    } 
                    dup2(fd,1); 
                }else if(flag==2){ 
                    int fd=open(redirect_file,O_RDWR|O_APPEND|O_CREAT,0664); 
                    if(fd<0){ 
                        perror("open erroe:"); 
                        return -1; 
                    } 
                    dup2(fd,1); 
                }    
                    execvp(myargv[0],myargv); 
                      //  perror("execvp errer"); 
                        exit(-1); 
                } 
 
                wait(NULL); 
        } 
        return 0; 
}
