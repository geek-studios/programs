// Coded by Mohammed Nihal https://github.com/nihalansar
// https://www.linkedin.com/in/nihalansar/
#include <stdio.h>
#define MAX 30

void main(){
	 int start=0,end=199,n,head,tracks[MAX],temp,h_pos,order[MAX],c=0,sum=0,diff;

	 printf("\n**** C-Scan - Disk Scheduling ****\n");
	 printf("\nEnter the number of tracks : ");
    scanf("%d", &n);
    printf("Enter the position of head : ");
    scanf("%d", &head);

    printf("Enter the tracks : ");

    for(int i=0;i<n;i++){
       scanf("%d", &tracks[i]);
    }

    tracks[n] = start;
    tracks[n+1] = end;
    tracks[n+2] = head;
    n += 3;

    for(int i=0;i<n-1;i++){
    	for(int j=i+1;j<n;j++){
    		if(tracks[i]>tracks[j]){
    			temp = tracks[j];
    			tracks[j] = tracks[i];
    			tracks[i] = temp;
    		}
    	}
    	if(tracks[i]==head){
    		h_pos = i;
    	}
    }

    if(head<(end-head)){
    	for(int i=h_pos;i>=0;i--){
    		order[c] = tracks[i];
    		c++;
    	}
    	for(int i=n-1;i>h_pos;i--){
    		order[c] = tracks[i];
    		c++;
    	}
    }else{
    	for(int i=h_pos;i<n;i++){
    		order[c] = tracks[i];
    		c++;
    	}
    	for(int i=0;i<h_pos;i++){
    		order[c] = tracks[i];
    		c++;
    	}
    }

    for(int i=0;i<n-1;i++){
    	  
        diff = order[i+1] - order[i];
        diff = (diff<0) ? diff*-1 : diff;
        sum += diff;
    }

    printf("\nScheduling order : ");

    for(int i=0;i<n;i++){
    	printf(" %d",order[i]);
    }

    printf("\nTotal head movements : %d", sum);

    printf("\n\n *** Exiting the program *** \n");

}