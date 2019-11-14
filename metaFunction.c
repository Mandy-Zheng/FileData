#include "header.h"

void printStats(){
  struct stat data;
  stat("makefile",&data);
  int xbytes=data.st_size/1000000;
  char permissions[9];
  int mode=data.st_mode;
  if(mode & S_IRUSR){
    permissions[0]='r';
  }else{
    permissions[0]='-';
  }
  if(mode & S_IWUSR){
    permissions[1]='w';
  }else{
    permissions[1]='-';
  }
  if(mode & S_IXUSR){
    permissions[2]='x';
  }else{
    permissions[2]='-';
  }
  if(mode & S_IRGRP){
      permissions[3]='r';
    }else{
      permissions[3]='-';
  }
  if(mode & S_IWGRP){
    permissions[4]='w';
  }else{
    permissions[4]='-';
  }
  if(mode & S_IXGRP){
    permissions[5]='x';
  }else{
    permissions[5]='-';
  }
  if(mode & S_IROTH){
      permissions[6]='r';
    }else{
      permissions[6]='-';
  }
  if(mode & S_IWOTH){
    permissions[7]='w';
  }else{
    permissions[7]='-';
  }
  if(mode & S_IXOTH){
    permissions[8]='x';
  }else{
    permissions[8]='-';
  }
  printf("File Size: %d B, %d KB, %d MB, %d GB \nFile Permissions: %s \nLast Access: %s\n",data.st_size,xbytes*1000,xbytes,xbytes/1000,permissions, ctime(&data.st_atime));

}
