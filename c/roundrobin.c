#include<stdio.h>
#include<string.h>
int q[100],front=-1,rear=0;
struct process
{
 char pname[20];
 int at,bt,wt,tt,status,left;
 int start;
}p[20];
struct done
{
 char name[20];
 int st,ct;
}d[20];
void enque(int j)
{
 q[rear]=j;
 rear++;
 if (front==-1)
 {
 front++;
 }
}
int deque()
{
 int item;
 item=q[front];
 front++;
 if(front==rear)
 {
 front=-1;
 rear=0;
 }
 return item;
}
void main()
{
 int n,i,j,idle=0,k,num,flag=0,found=0,ls,t,nl=0;
 float sumwt=0.0,sumtt=0.0,tl,w,st;
 num=0;
 printf("\nEnter the number of Processes : ");
 scanf("%d",&n);
 for(i=0;i<n;i++) //accepting the process details
 {
 printf("\nEnter the process name : ");
 __fpurge(stdin);
 gets(p[i].pname);
 printf("\nEnter the arrival time : ");
 scanf("%d",&p[i].at);
 printf("\nEnter the burst time : ");
 scanf("%d",&p[i].bt);
 p[i].status=0;
 p[i].start=-1;
 p[i].left=p[i].bt;
 }
 printf("Time Quanta : "); //entering the time slice
 scanf("%d",&t);
 idle=0;
 ls=0;
 for(i=0;ls<n;)
 {
 for(j=0;j<n;j++)
 {
 if (p[j].at<=i && p[j].status==0)
 {
 enque(j);
 p[j].status=1;
 }
 }
 if (idle==0 && front==-1)
 {
 strcpy(d[num].name,"idle");
 d[num].st=i;
 idle=1;
 i++;
 }
 else if(front!=-1)
 {
 if(idle==1)
 {
 d[num].ct=i;
 idle=0;
 num++;
 }
 k=deque();
 d[num].st=i;
 if(p[k].start==-1)
    p[k].start =i;
 strcpy(d[num].name,p[k].pname);
 nl++;
 if(p[k].left<=t)
 {
 //printf("\n%s%d",d[num].name,d[num].ct);
 d[num].ct=i+p[k].left;
 i=d[num].ct;
 p[k].tt=i-p[k].at;
 p[k].wt=p[k].start-p[k].at;
 p[k].status=2;
 ls++;
 num++;
 }
 else
 {
 d[num].ct=i+t;
 i=i+t;
 p[k].left=p[k].left-t;
 num++;
 for(j=0;j<n;j++)
 {
 if(p[j].status==0 && p[j].at<=i)
 {
 enque(j);
 p[j].status=1;
 }
 }
 enque(k);
 }
 }
 else
 {
 i++;
 }

 }
 printf (" |pname | arrival time\t | burst time\t | status\t | wait\t turn");
for(i =0;i<n; i++)
{
printf ("\n |%s \t |%d \t \t |%d \t \t |%d \t \t |%d \t | %d \n", p[i].pname ,p[i].at , p[i].bt ,
p[i].status,p[i].wt,p[i].tt);
}
//gant chart
printf("Gant chart\n");
printf("\n--------------------------------------------------------------------------------------\n");
for(i=0;i<num;++i){
printf("|%d |\t %s \t ",d[i].st,d[i].name);
}
printf("|%d|",d[num-1].ct);
printf("\n---------------------------------------------------------------------------------------------\n");
for(i=0;i<n; i++)
{
sumwt=sumwt+p[i].wt;
sumtt=sumtt+p[i].tt;
}
w=(float)(sumwt/n);
st=(float)(sumtt/n);
printf("\nAverage waiting time=%f",w);
printf("\nAverage turnaround time=%f\n", st);
}
