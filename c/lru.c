#include <stdio.h>
#include<string.h>
#define MAX 30

void main(){
	 int n,f,str[MAX],frames[MAX],faults=0,temp_array[MAX];
    char status[MAX];

	 printf("\n**** LRU - Page Replacement ****\n");
	 printf("\nEnter the length of reference string : ");
    scanf("%d", &n);
    printf("Enter the number of frames : ");
    scanf("%d", &f);

    printf("Enter the reference string's : ");

    for(int i=0;i<n;i++){
       scanf("%d", &str[i]);
    }

    for(int i=0;i<f;i++){
       frames[i] = -1;
    }

    
    printf("\nPage Replacement Order : \n");

    for(int i=0;i<n;i++){

      int flag = 0,temp_flag = 0,temp_c = 0,free_space=0;

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
               
               temp_array[0] = j;
               temp_c++;
               free_space = 1;
               break;

            }

         }

         // if free space is not present then this block executes
         if(free_space==0){

            int min = -1; // for checking which page is used most previously

            for(int k=0;k<f;k++){ // for loop for each frames

               for(int j=i-1;j>=0;j--){ // loop to check when the frame page was previously requested

                  if(frames[k]==str[j]){

                     min = (min==-1) ? j : min;

                     // if this page is most previously fetched then we will be replacing this page
                     if(j<min){
                        temp_array[temp_c] = k;
                        temp_c++;
                        temp_flag = 1;
                        min = j;
                     }
                     break;

                  }

               }

            }

         }

         // page adding to memory
         if(temp_flag==1 || free_space==1){
            frames[temp_array[temp_c-1]] = str[i];
         }else{
            frames[0] = str[i];
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