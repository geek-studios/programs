// Coded by Mohammed Nihal https://github.com/nihalansar
// https://www.linkedin.com/in/nihalansar/
#include <stdio.h>
#define MAX 30

void main(){
	 int n,tracks[MAX],sum=0,diff,avg;

	 printf("\n**** FCFS - Disk Scheduling ****\n");
	 printf("\nEnter the number of tracks : ");
    scanf("%d", &n);
    n++;
    printf("Enter the current head position : ");
    scanf("%d", &tracks[0]);

    printf("Enter the tracks : ");

    for(int i=1;i<n;i++){
       scanf("%d", &tracks[i]);
    }

    for(int i=0;i<n-1;i++){
    	  
        diff = tracks[i+1] - tracks[i];
        diff = (diff<0) ? diff*-1 : diff;
        sum += diff;
    }

    avg = sum/(n-1);

    printf("\nTotal head movements : %d", sum);
    printf("\nAvg head movements : %d", avg);

    printf("\n\n *** Exiting the program *** \n");

}