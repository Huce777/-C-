#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20 //线性表存储空间的初始分配量
#define OK 1 //成功标识
#define ERROR 0 //失败标识

//Status是函数的类型，其值是函数结果状态代码，如OK等 
typedef int Status; 
//ElemType的类型根据实际情况而定，这里假定为int
typedef int ElemType;

//顺序表数据结构
typedef struct
{
	ElemType *elem;
	int length;
  } SqList;
 
 //构造一个空的顺序表L
Status InitList(SqList *L){
	//构造一个空的线性表L
	L->elem = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));
	if(!L->elem){
		return ERROR;
	}
	L->length = 0;
	return OK;
}

/*
插入操作
初始条件：顺序表L已存在
操作结果：在L中的第i个位置之前插入新的
		数据元素e，L的长度加1
*/
Status ListInsert(SqList *L,int i,ElemType e){
	int k;
	if(L->length == MAXSIZE){ //线性表已满
		return ERROR; 
	}
	if(i<1 || i>L->length+1){ //当i不在范围内
		return ERROR; 
	}
	if(i<=L->length-1){ //若插入位置不在表尾 
		for(k=L->length-1;k>=i-1;k--){
			L->elem[k+1] = L->elem[k];
		}
	}
	L->elem[i-1] = e; //将新元素插入 
	L->length++; //长度加1 
	return OK;
}

/*
删除操作
初始条件:顺序表L已存在
操作结果:删除L的第i个数据元素，并用e返回其值，L的长度减1
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
		//如果删除位置不在最后位置
		for(k=i;k<L->length;k++){
			L->elem[k-1] = L->elem[k];
		} 
	}
	L->length--; // 长度减1
	return OK; 
}

/*
获取元素操作
初始条件：顺序表L已存在
操作结果：用e返回L中第i个数据元素的值
*/
Status GetElem(SqList L,int i,ElemType *e){
	if(L.length==0 || i<1 || i>L.length){
		return ERROR;
	}
	*e = L.elem[i-1];
	return OK;
}

/*打印线性表中的所有元素*/
void OutPut(SqList L){
	int i;
	printf("当前顺序表的长度：%d\n",L.length);
	for(i=0;i<L.length;i++){
		printf("%d",L.elem[i]);
	}
	printf("\n");
}

//运行测试
int main()
{
	int i;
    SqList L;
    printf("------构造一个空的线性表L------\n");
    InitList(&L);
    OutPut(L);  //打印结果
    printf("------测试插入10个数------\n");
    for(i = 1;i <= 10; i++){
        ListInsert(&L,i,i);
    }
    OutPut(L);  //打印结果
    printf("------在第三位之前插入0------\n");
    ListInsert(&L,3,0);
    OutPut(L);  //打印结果
    printf("------删除第6位的数据------\n");
    ElemType e;
    ListDelete(&L,6,&e);
    printf("删除的数据为：%d\n", e);
    OutPut(L);  //打印结果
    printf("------获取元素操作------\n");
    GetElem(L,5,&e);
    printf("得到第5个元素：%d", e);
}

