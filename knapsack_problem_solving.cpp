#include<stdio.h>
#include<stdlib.h>

int main()
{
	float totalval=0,capacity,weight[10],ratio[10],profit[10];
	int n,i,j;
	//how many items are there
	printf("Enter the value of n:->\n");
	scanf("%d",&n);
	//total capacity of the bag
	printf("Enter the total capacity of the bag:->\n");
	scanf("%f",&capacity);
	//to take input from the user for knapsack problem {weight & profit}
	for(i=0;i<n;i++)
	{
		printf("Enter the value of weight & profit of the [%d]th item:->",i);
		scanf("%f %f",&weight[i],&profit[i]);	
	}
	//calculate the ratio
	for(i=0;i<n;i++)
	{
		ratio[i]=profit[i]/weight[i];
	}
	// arrenge in decresing order
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(ratio[j]>ratio[i])
			{
				float temp = ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
				
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;
				
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
			}
		}
	}
	printf("<-: Solution of the knapsack problem :->");
	for(i=0;i<n;i++)
	{
		if(weight[i]>capacity)
			break;
		else{
			totalval+=profit[i];
			capacity-=weight[i];
		}
	}
	if(i<n)
	{
		totalval+=(capacity*ratio[i]);
	}
	printf("\nMaximum profit is:->%f",totalval);
	return 0;
}
