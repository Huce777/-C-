/*≥ı ºªØ*/
#include<stdio.h>
#define Max_length 10

typedef struct{
	int data[Max_length];
	int length;
} SqList;

void InitList(SqList &L){
	for(int i=0;i<Max_length;i++)
		L.data[i]=0;
	L.length=0;
}

int main(){
	SqList L;
	InitList(L);
	return 0;
}
