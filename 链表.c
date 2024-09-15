#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
	int val;
	struct ListNode *next;
} ListNode;

ListNode *newListNode(int val){
	ListNode* node;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->val = val;
	node->next = NULL;
	return node;
}
/*
//初始化各个节点 
ListNode* n0 = newListNode(1);
ListNode* n1 = newListNode(3);
ListNode* n2 = newListNode(2);
ListNode* n3 = newListNode(5);
ListNode* n4 = newListNode(4);
//构建节点之间的引用
n0->next = n1;
n1->next = n2;
n2->next = n3;
n3->next = n4;
*/

//插入节点 
void insert(ListNode* n0,ListNode* p){
	ListNode *n1 = n0->next;
	p->next = n1;
	n0->next = p;
}
//删除节点 
void remove(ListNode* n0){
	if(!n0->next)
		return;
	ListNode *p = n0->next;
	ListNode *n1 = p->next;
	n1 = n0->next;
	//释放内存 
	free(p);
} 
//访问节点
ListNode *access(ListNode *head,int index){
	for(int i=0;i<index;i++){
		if(head==NULL)
			return NULL;
		head = head->next;
	}
	return head;
} 
//查找节点
int find(ListNode *head,int target){
	int index = 0;
	while(head){
		if(head->val == target)
			return index;
		head = head->next;
		index++;
	}
	return -1;
} 
