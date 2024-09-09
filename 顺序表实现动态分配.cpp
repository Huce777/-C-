/*˳���ʵ�ֶ�̬����*/
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10

typedef struct{
	int *data;
	int length;
	int listSize;
} SqList;
/*��malloc��������һƬ�����Ĵ洢�ռ�*/
void InitList(SqList &L){
	L.data=(int*)malloc(InitSize*sizeof(int));
	L.length=0;
	L.listSize=InitSize;
}
/*���Ӷ�̬����ĳ���*/
void IncreaseSize(SqList &L,int len){
	int *p=L.data;
	L.data=(int*)malloc((L.listSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++){
		L.data[i] = p[i];
	}
	L.listSize = L.listSize+len;
	free(p);
}

int main(){
	SqList L;
	InitList(L);
	IncreaseSize(L,5);
	return 0;
}
