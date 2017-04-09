
#include<stdio.h>
void main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		//printf("Entered");
		int a,b;
		scanf("%d%d",&a,&b);
		//printf("Scaned");
		if(a+2 == b || b+2 == a)
		{
			printf("\nYES");
		}
		else
		{
			int i = (a-1)/2;
			//printf("\ni = %d",i);
			int i1 = (b-1)/2;
			//printf("\ni1 = %d",i);
			if((2*i)+2 == b)
			{
				printf("\nYES");
			}
			else if((2*i1)+2 == a)
			{
				printf("\nYES");
			}
			else
			{
			printf("\nNO");
			}
		}
		t--;	
	}
}
 

