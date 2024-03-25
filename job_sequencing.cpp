#include<stdio.h>
#define MAX 100

typedef struct job{
	char id[5];
	int deadline;
	int profit;
}job;
int minvalue(int x,int y)
{
	if(x<y) return x;
	return y;
}
void job_sequencing_with_deadline(job jobs[],int n)
{
	int i,j,k,maxprofit=0;
	int slot[MAX];
	int dmax=0;
	int filledslot=0;
	for(i=0;i<n;i++)
	{
		if(jobs[i].deadline>dmax)
		{
			dmax=jobs[i].deadline;
		}
	}
	printf("\ndmax:->%d",dmax);
	for(i=1;i<=dmax;i++)
	{
		slot[i]=-1;
	}
	for(i=1;i<=n;i++)
	{
		k = minvalue(dmax,jobs[i-1].deadline);
		while(k>=1)
		{
		if(slot[k]==-1)
		{
			slot[k]=i-1;
			filledslot++;
			break;
		}
	k--;
	}
	if(filledslot==dmax)
	{
		break;
	}
}
	printf("\nrequired job:");
	for(i=1;i<=dmax;i++)
	{
		printf("%s",jobs[slot[i]].id);
		if(i<dmax) //no of `-->` this notation
		printf("-->");
	}
	for(i=1;i<=dmax;i++)
	{
		maxprofit+=jobs[slot[i]].profit;
	}
	printf("\nmaximum profit is:->%d",maxprofit);
}
int main()
{
	int i,j,n=5;
	job jobs[5] =
		{
    {"j1", 2,  60},
    {"j2", 1, 100},
    {"j3", 3,  20},
    {"j4", 2,  40},
    {"j5", 1,  20},
	};
  job temp; // third variable 
  // sorting tha data with respect to profit
  	for(i = 0; i <=n; i++) {
    for(j = i+1; j < n ; j++) {
      if(jobs[j].profit > jobs[i].profit) {
        temp = jobs[j];
        jobs[j] = jobs[i];
        jobs[i] = temp;
		  }
	  }
  }
    printf("\tJOB\tDEADLINE\tPROFIT\n");
   for(i = 0; i < n; i++) {
    printf("\t%s\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }

 job_sequencing_with_deadline(jobs, n);

  return 0;
}

