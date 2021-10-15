#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
struct process
{
char pname[20];
int at,bt,tt,wt,status;
}p[20],t;
struct done
{
char name[20];
int ct,st;
}d[20];
void main()
{
int n,i,j,k,num,idle;
float sumwt=0.0,sumtt=0.0,st,w;
printf(&quot;Enter the number of processes : &quot;);
scanf(&quot;%d&quot;,&amp;n);
for(i=0;i&lt;n;i++)
{
printf(&quot;\nEnter the Process Name : &quot;);
__fpurge(stdin);
gets(p[i].pname);
printf(&quot;\nEnter the Arrival Time : &quot;);
scanf(&quot;%d&quot;,&amp;p[i].at);
printf(&quot;\nEnter the Burst Time : &quot;);
scanf(&quot;%d&quot;,&amp;p[i].bt);
p[i].status=0;
}
for(i=0;i&lt;n;i++)
{
for(j=0;j&lt;n-i-1;j++)
{
if(p[j].at&gt;p[j+1].at)
{
t=p[j];
p[j]=p[j+1];
p[j+1]=t;
}
}
}
idle=0;

for(i=0,k=0,num=0;k&lt;n;)
{
if(p[k].at&lt;=i&amp;&amp;p[k].status==0)
{
if(idle==1)
{
d[num].ct=i;
num++;
}
strcpy(d[num].name,p[k].pname);
d[num].st=i;
d[num].ct=i+p[k].bt;
p[k].wt=d[num].st-p[k].at;
p[k].tt=p[k].wt+p[k].bt;
i=d[num].ct;
p[k].status=1;
k++;
num++;
idle=0;
}
else if(idle==0)
{
strcpy(d[num].name,&quot;idle&quot;);
d[num].st=i;
i++;
idle=1;
}
else
{
i++;
}
}
printf(&quot;| pname\t | arrival time\t | burst time\t | status\t | waiting time\t | turnaround time\t
&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;\n |%s \t |%d \t\t|%d \t\t\|%d \t|%d\t |%d\t
\n&quot;,p[i].pname,p[i].at,p[i].bt,p[i].status,p[i].wt,p[i].tt);
}
printf(&quot;\n\nGANTT CHART \n\n&quot;);
for(int x=0;x&lt;num;x++)
{
printf(&quot;|&quot;);
printf(&quot;%s\t&quot;,d[x].name);
}
printf(&quot; |&quot;);
printf(&quot;\n----------------------------------------------------------\n&quot;);
printf(&quot;%d\t&quot;,d[0].st);
for(int x=0;x&lt;num;x++)
{
printf(&quot;%d\t&quot;,d[x].ct);
}

for(i=0;i&lt;n;i++)
{
sumwt=sumwt+p[i].wt;
sumtt=sumtt+p[i].tt;
}
w=(float)(sumwt/n);
st=(float)(sumtt/n);
printf(&quot;\nAverage waiting time=%f&quot;,w);
printf(&quot;\nAverage turnaround time=%f\n&quot;,st);
}