#include<stdio.h>
#include<string.h>
#include<errno.h>
int main(int argc,char* argv[]){
    FILE* fp=fopen("./file.txt","w+");
    if(fp==NULL){
        perror("fopen error");
        return -1;
    }
    fseek(fp,-14,SEEK_SET);
    char* ptr="good weather in the day\n";
    int ret=fwrite(ptr,strlen(ptr),1,fp);
    if(ret==0){
        perror("fwrite error");
        return -1;
    }
    printf("ret: %d\n",ret);
    fseek(fp,0,SEEK_SET);
    char buf[1024];
   ret=fread(buf,1,1023,fp);
   if(ret==0){
    perror("fread error:");
    return -1;
   }

    printf("%s--ret: %d\n",buf,ret);
    fclose(fp);
    return 0;                                                                                                                  
}
