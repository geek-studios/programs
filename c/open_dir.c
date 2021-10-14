#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int arg,char **argv){
    struct stat buff;
    int exists;
    DIR *d;
    struct dirent *de;
    d = opendir("/home/naighu/os/c_programs/sample");
    if(d==NULL){
        printf("File does not exist");
    }
    else{
        // for(de = readdir(d); de != NULL ; de = readdir(d)){
        //     exists = stat(de->d_name,&buff);
        //     if(exists < 0){
        //         printf("Something went wrong");
        //     }
        //     else{
        //         printf("%s %lld\n",de->d_name,buff.st_size);
        //     }
        // }
        while ((de = readdir(d)) != NULL){
            exists = stat(de->d_name,&buff);
           printf("%s %lld\n",de->d_name,buff.st_size);
        }
    }
    closedir(d);
    return 0;
}
