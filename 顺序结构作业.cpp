#include<stdio.h>
#include<stdlib.h>
#define Max_Size 10
//定义顺序表结构
typedef struct{
	int *data;
	int length;
	int size; //数组的最大容量 
}SqList;
//初始化顺序表
void InitList(SqList &L){
	L.data=(int*)malloc(Max_Size*sizeof(int));
	L.length=0;
	
}
//顺序表的 插入
void ListInsert(SqList &L,int i,int e){
	//在顺序线性表L中第i个位置之前插入新的元素e
	//i的合法值为 1<=i<=ListLength+1
	if(i<1 || i>L.length+1)
		return false;
	
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1]; 
	L.data[i-1]=e;
	L.length++;
}
int main(){
	SqList L;
	InitList(L);
	ListInsert(L,3,3);
	return 0;
}
