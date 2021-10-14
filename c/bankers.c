// Coded by Mohammed Nihal https://github.com/nihalansar
// https://www.linkedin.com/in/nihalansar/
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct process{
int a[MAX], max[MAX], need[MAX], done;
}p[MAX];

void main(){

int n,m,pnum,safe=0,flag=0,status=0,s_c=0,n_flag,a_flag=0;
int avail[MAX/2],req[MAX/2],work[MAX/2],sequence[MAX/2];

printf("\n*** Bankers Algorithm ***\n");
printf("\nEnter the number of resources : ");
scanf("%d", &m);
printf("\nEnter the number of process : ");
scanf("%d", &n);

for(int i=0;i<n;i++){
   printf("\nEnter allocation of p%d : ", i);
   for(int j=0;j<m;j++){
      scanf("%d", &p[i].a[j]); 
   }
   printf("Enter max of p%d : ", i);
   for(int j=0;j<m;j++){
      scanf("%d", &p[i].max[j]);
   }
   // calculating need
   for(int j=0;j<m;j++){
      p[i].need[j] = p[i].max[j] - p[i].a[j];
   }
   p[i].done = 0;
}

printf("\nEnter the available resource : ");
for(int j=0;j<m;j++){
   scanf("%d", &avail[j]);
   work[j] = avail[j];
}

printf("\nEnter the requested process number : ");
scanf("%d", &pnum);

printf("Enter the requested resource : ");
for(int j=0;j<m;j++){
   scanf("%d", &req[j]);
   if(req[j]>avail[j]){
      a_flag = 1;
   }
   if(req[j]>p[pnum].need[j]){
      n_flag = 1;
   }
   avail[j] -= req[j];
}

if(n_flag==1){
   printf("\n**** Request Not Granted - Needed resource is less than requested ****");
   printf("\n *** Exiting the program *** \n");
   exit(0);
}

if(a_flag==1){
   printf("\n**** Request Not Granted - Available resource is less than requested ****");
   printf("\n *** Exiting the program *** \n");
   exit(0);
}


// first safety checking the requested process pnum
flag = 1;
for(int j=0;j<m;j++){
  if(p[pnum].need[j]>work[j]){
     flag = 0;
  }
}
if(flag!=0){
  for(int j=0;j<m;j++){
      work[j] += p[pnum].a[j];
  }
  printf("p%d is visited (", pnum);
  for(int j=0;j<m;j++){
      printf(" %d ", work[j]);
  }
  printf(")\n");
  p[pnum].done = 1;
  sequence[s_c] = pnum;
  s_c++;
  status++;
}

// rest process safety checker
while(status<n){

  for(int c=0;c<n;c++){
     flag = 1;
     if(p[c].done==0){
        for(int j=0;j<m;j++){
           if(p[c].need[j]>work[j]){
              flag = 0;
           }
        }
        if(flag!=0){
           for(int j=0;j<m;j++){
               work[j] += p[c].a[j];
           }
           printf("p%d is visited (", c);
           for(int j=0;j<m;j++){
               printf(" %d ", work[j]);
           }
           printf(")\n");
           p[c].done = 1;
           sequence[s_c] = c;
           s_c++;
           status++;
        }
     }
  }
  
}

if(status==n){
 safe = 1;
}

if(safe==0){
   printf("\n**** Request Not Granted - Deadlock Occured ****");
   printf("\n**** System is in unsafe state ****");
}else{
   printf("\n**** System is in safe state ****");
   printf("\n**** Safe Sequence : (");
   for(int j=0;j<s_c;j++){
      printf(" p%d ", sequence[j]);
   }
   printf(") ****\n");
   for(int j=0;j<m;j++){
      p[pnum].a[j] += req[j];
      p[pnum].need[j] -= req[j];      
   }
   
   printf("\nProcess Name \t| Allocation \t| Max \t\t| Need \t\t|\n");
   for(int i=0;i<n;i++){
      printf("p%d\t\t",i);
      printf("|");
      for(int j=0;j<m;j++){
          printf(" %d ", p[i].a[j]);
      }
      printf("\t|");
      for(int j=0;j<m;j++){
          printf(" %d ", p[i].max[j]);
      }
      printf("\t|");
      for(int j=0;j<m;j++){
          printf(" %d ", p[i].need[j]);
      }
      printf("\t|\n");
   }
   
   printf("\n**** Request Granted Successfully ****");
   printf("\n\n *** Exiting the program *** \n");
}

}
