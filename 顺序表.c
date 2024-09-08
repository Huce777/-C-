#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20 //���Ա�洢�ռ�ĳ�ʼ������
#define OK 1 //�ɹ���ʶ
#define ERROR 0 //ʧ�ܱ�ʶ

//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK�� 
typedef int Status; 
//ElemType�����͸���ʵ���������������ٶ�Ϊint
typedef int ElemType;

//˳������ݽṹ
typedef struct
{
	ElemType *elem;
	int length;
  } SqList;
 
 //����һ���յ�˳���L
Status InitList(SqList *L){
	//����һ���յ����Ա�L
	L->elem = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));
	if(!L->elem){
		return ERROR;
	}
	L->length = 0;
	return OK;
}

/*
�������
��ʼ������˳���L�Ѵ���
�����������L�еĵ�i��λ��֮ǰ�����µ�
		����Ԫ��e��L�ĳ��ȼ�1
*/
Status ListInsert(SqList *L,int i,ElemType e){
	int k;
	if(L->length == MAXSIZE){ //���Ա�����
		return ERROR; 
	}
	if(i<1 || i>L->length+1){ //��i���ڷ�Χ��
		return ERROR; 
	}
	if(i<=L->length-1){ //������λ�ò��ڱ�β 
		for(k=L->length-1;k>=i-1;k--){
			L->elem[k+1] = L->elem[k];
		}
	}
	L->elem[i-1] = e; //����Ԫ�ز��� 
	L->length++; //���ȼ�1 
	return OK;
}

/*
ɾ������
��ʼ����:˳���L�Ѵ���
�������:ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
*/
Status ListDelete(SqList *L,int i,ElemType *e){
	int k;
	if(L->length == 0){
		return ERROR;
	}
	if(i<1 || i>L->length){
		return ERROR;
	}
	*e = L->elem[i-1];
	if(i<L->length){
		//���ɾ��λ�ò������λ��
		for(k=i;k<L->length;k++){
			L->elem[k-1] = L->elem[k];
		} 
	}
	L->length--; // ���ȼ�1
	return OK; 
}

/*
��ȡԪ�ز���
��ʼ������˳���L�Ѵ���
�����������e����L�е�i������Ԫ�ص�ֵ
*/
Status GetElem(SqList L,int i,ElemType *e){
	if(L.length==0 || i<1 || i>L.length){
		return ERROR;
	}
	*e = L.elem[i-1];
	return OK;
}

/*��ӡ���Ա��е�����Ԫ��*/
void OutPut(SqList L){
	int i;
	printf("��ǰ˳���ĳ��ȣ�%d\n",L.length);
	for(i=0;i<L.length;i++){
		printf("%d",L.elem[i]);
	}
	printf("\n");
}

//���в���
int main()
{
	int i;
    SqList L;
    printf("------����һ���յ����Ա�L------\n");
    InitList(&L);
    OutPut(L);  //��ӡ���
    printf("------���Բ���10����------\n");
    for(i = 1;i <= 10; i++){
        ListInsert(&L,i,i);
    }
    OutPut(L);  //��ӡ���
    printf("------�ڵ���λ֮ǰ����0------\n");
    ListInsert(&L,3,0);
    OutPut(L);  //��ӡ���
    printf("------ɾ����6λ������------\n");
    ElemType e;
    ListDelete(&L,6,&e);
    printf("ɾ��������Ϊ��%d\n", e);
    OutPut(L);  //��ӡ���
    printf("------��ȡԪ�ز���------\n");
    GetElem(L,5,&e);
    printf("�õ���5��Ԫ�أ�%d", e);
}

