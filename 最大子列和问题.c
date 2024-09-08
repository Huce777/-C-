#include<stdio.h>

int MaxSubseqSum1(int List[],int N)
{
	int i,j,k;
	int ThisSum, MaxSum=0;
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			ThisSum=0;
			for(k=i;k<=j;k++)
				ThisSum += List[k];
			if(ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
} 

int main(){
	int lyst[]={-2,11,-4,13,-5,-2};
	int N = sizeof(lyst)/sizeof(lyst[0]);
	int result = MaxSubseqSum1(lyst,N);
	printf("%d",result);
	return 0;
}
