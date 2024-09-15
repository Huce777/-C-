#include<stdio.h>
#include<stdlib.h>

/*双向链表节点结构体*/
typedef struct ListNode{
	int val;
	struct ListNode *next; //后继节点的指针
	struct ListNode *prev; //前驱节点的指针 
} ListNode;

/*构造函数*/
ListNode *newListNode(int val){
	ListNode *node;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
