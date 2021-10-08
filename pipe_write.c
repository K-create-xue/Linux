//umask(0);
//char* pipe_buf="./piep_buf.fifo";
//int ret=mkfifo(pipe_buf,0664);
//if(ret<0 && errno!=EXIST){
//
//}
//int fd=open(pipe_buf,O_WRONLY);
//while(1){
//char buf[1024];
//scanf("%s",buf);
//write(fd,buf,strlen(buf));
//}
//
//close(fd);  
