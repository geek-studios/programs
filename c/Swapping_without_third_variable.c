#include<stdio.h>
int main(){
	int x=2,y=4;
	printf("Before Swapping x=%d & y=%d",x,y);
	x=x+y;
	y=x-y;
	x=x-y;
	printf("\n\nAfter Swapping x=%d & y=%d",x,y);
	return 0;
}
