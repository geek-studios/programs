#include <stdio.h>
#include<string.h>
#define MAX 30

void main(){
	 int n,f,str[MAX],frames[MAX],faults=0,temp_c=0;
    char status[MAX];

	 printf("\n**** FIFO - Page Replacement ****\n");
	 printf("\nEnter the no of pages : ");
    scanf("%d", &n);
    printf("Enter the number of frames : ");
    scanf("%d", &f);

    printf("Enter the pages : ");

    for(int i=0;i<n;i++){
       scanf("%d", &str[i]);
    }

    for(int i=0;i<f;i++){
       frames[i] = -1;
    }

    
    printf("\nPage Replacement Order : \n");

    for(int i=0;i<n;i++){

      int flag = 0,temp_flag = 0,free_space=0;

      // checking if the page is present
      for(int j=0;j<f;j++){

         if(str[i]==frames[j]){
            flag = 1;
            strcpy(status, "Hit");
            break;
         }

      }

      // if the page is not present this block gets executed
      if(flag==0){
         
         faults++;
         strcpy(status, "Fault");

         // checking if there is any free space
         for(int j=0;j<f;j++){

            if(frames[j]==-1){
               
               frames[temp_c] = str[i];
               temp_c++;
               free_space = 1;
               break;

            }

         }

         // if free space is not present then this block executes
         if(free_space==0){

            temp_c = (temp_c==f) ? 0 : ++temp_c;
            frames[temp_c] = str[i];
            
         }

      }

      // printing the pages in memory
      for(int j=0;j<f;j++){
         printf(" %d", frames[j]);
      }
      printf("\t\t- %s\n", status);

    }

    printf("\nTotal page faults : %d", faults);

    printf("\n\n *** Exiting the program *** \n");

}