#include<stdio.h>
#include<stdlib.h>
#define Max_Size 10
//����˳���ṹ
typedef struct{
	int *data;
	int length;
	int size; //������������ 
}SqList;
//��ʼ��˳���
void InitList(SqList &L){
	L.data=(int*)malloc(Max_Size*sizeof(int));
	L.length=0;
	
}
//˳���� ����
void ListInsert(SqList &L,int i,int e){
	//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
	//i�ĺϷ�ֵΪ 1<=i<=ListLength+1
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
