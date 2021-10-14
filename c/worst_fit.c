#include<stdio.h>

int main()
{
	int blocks[10],p[10],n,m;
	printf("Enter the number of blocks : ");
	scanf("%d",&m);
	printf("Enter the blocks : ");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&blocks[i]);
	}
	
	printf("Enter the number of process : ");
	scanf("%d",&n);
	printf("Enter the process : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=0;i<n;i++)
	{
		int flag=0,k;
		for(int j=0;j<m;j++)
		{
			if(p[i] <= blocks[j])
			{
				if(flag == 1 && blocks[j] > blocks[k])
				{
					k=j;
				}
				else
				{
					flag = 1;
					k = j;
				}
				
			}
		}
		if(flag == 1)
		{
			blocks[k] -= p[i];
			printf("\nThe process %d goes to block No %d",p[i],k+1);
		}
		else
		{
			printf("\nThe process %d cannot be allocated\n",p[i]);
		}
	}
return 0;
	
}
