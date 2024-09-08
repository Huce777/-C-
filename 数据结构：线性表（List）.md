### 数据结构：线性表（List）

#### 目录

##### 线性表

【知识框架】
一、**线性表的定义**

**线性表的顺序存储结构**
一、顺序表
1、顺序表的基本概念
2、顺序表存储结构
3、构造一个空的顺序表L
4、顺序表的插入
5、顺序表的删除
6、获取顺序表某一位置上的元素
7、读取顺序表所有元素
8、运行测试
**小结**
1、顺序表时间复杂度
2、顺序表的优缺点

**线性表的链式存储结构**
**一、单链表**
1、单链表的基本概念
2、单链表的存储结构
3、构造单链表
4、单链表的插入
5、单链表的删除
6、清空单链表
7、销毁单链表
8、遍历打印单链表
9、测试运行

**二、静态链表**
1、静态链表的基本概念
2、静态链表的插入操作
3、静态链表的删除操作

**三、循环链表**
1、循环链表的基本概念
2、仅设尾指针的循环链表

**四、双向链表**
1、双向链表的基本概念
2、双向链表的插入操作
3、双向链表的删除操作

**总结**
**一、顺序表和链表的比较**
1、存取(读写)方式
2、逻辑结构与物理结构
3、查找、插入和删除操作
4、空间分配
**二、在实际中应该怎样选取存储结构呢?**
1、基于存储的考虑
2、基于运算的考虑
3、基于环境的考虑

![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/c8b3abeb72098a922a9ac4f6ff62f563.png#pic_center)

#### 一、线性表的定义

##### 线性表（List）：零个或多个数据元素的有限序列。

线性表的数据集合为{a1, a2, ...an}，假定每个元素的类型均为 DataType 。其中，除了第一个元素 a1外，每个元素有且只有一个直接前驱元素，除了最后一个元素 an 外，每一个元素有且只有一个直接后继元素。数据元素之间的关系是一对一的关系。

![线性表](https://i-blog.csdnimg.cn/blog_migrate/85ca53f3441483bd448f2c1b3f9467f1.png#pic_center)

在较复杂的线性表中，一个数据元素可以由若干个数据项组成。在这种情况下，常把数据元素称为**记录**，含有大量记录的线性表又称为**文件**

#### 线性表的顺序存储结构

##### 一、顺序表

##### 1、顺序表的基本概念

##### 概念：用一组地址连续的存储单元依次存储线性表的数据元素，这种存储结构的线性表称为顺序表。

##### 特点：逻辑上相邻的数据元素，物理次序也是相邻的。

只要确定好了存储线性表的起始位置，线性表中任一数据元素都可以随机存取，所以线性表的顺序存储结构是一种随机存取的储存结构，因为高级语言中的数组类型也是有随机存取的特性，所以通常我们都使用数组来描述数据结构中的顺序储存结构，用动态分配的一维数组表示线性表。

```c
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

```

#### *小结*

##### 1.顺序表时间复杂度

从以上代码可以明显看出，**线性表的顺序存储结果在读、存数据是的时间复杂度是O(1)，插入、删除操作的时间复杂度是O(n)。**

##### 2、顺序表的优缺点

优点：无须为表中元素之间的逻辑关系而增加额外的存储空间；可以快速的存取表中任一位置的元素。
缺点：插入和删除操作需要移动大量元素；当线性表长度较大时，难以确定存储空间的容量；造成存储空间的“碎片”。

