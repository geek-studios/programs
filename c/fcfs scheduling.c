#include<stdio.h>
#include<string.h>

struct process{
  int at,bt,ct,tt,wt;
  char name[50];
}p[20],temp;

int main()
{
  int n,k=0,g_time=0,time_taken=0;
  float sum_tt=0.0,sum_wt=0.0;
  printf("\n **** First Come First Serve (FCFS) ****\n");
  printf("\nEnter the number of process : ");
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    printf("\n%d. Enter the name of the process : ", (i+1));
    __fpurge(stdin);
    fgets(p[i].name, 20, stdin);
    printf("   Enter the arrival time of the process : ");
    scanf("%d", &p[i].at);
    printf("   Enter the burst time of the process : ");
    scanf("%d", &p[i].bt);
    p[i].name[strcspn(p[i].name, "\n")] = 0;
  }

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(p[i].at>p[j].at){
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }

  int i = 0,j = 0;
  printf("\n*** Process Table ***");
  printf("\nProcess Name \t| Process AT \t| Process BT \t| Process CT \t| Process TT \t| Process WT\n");

  while(i<n){
    if(time_taken >= p[i].at){

      time_taken += p[i].bt;
      p[i].ct = time_taken;
      p[i].tt = p[i].ct - p[i].at;
      p[i].wt = time_taken - p[i].bt - p[i].at;
      sum_tt += p[i].tt;
      sum_wt += p[i].wt;
      printf("\n%s \t\t| %d \t\t| %d \t\t| %d \t\t| %d \t\t| %d\n",p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
      i++;
    }else{
      time_taken = p[i].at;
    }
  }

  printf("\n\n*** Gantt Chart ***");
  printf("\n{ 0 }");
  while(k<n){
    if(p[k].at<=g_time){
      printf("    %s    { %d }", p[k].name, p[k].ct);
      g_time += p[k].bt;
      k++;
    }else{
      g_time = p[k].at;
      printf("    idle    { %d }", g_time);
    }
  }

  printf("\n\n->Average Waiting Time : %f",(sum_wt/n));
  printf("\n->Average Turnaround Time : %f",(sum_tt/n));
  printf("\n\n *** Exiting the program *** \n");

}
