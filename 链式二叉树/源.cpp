#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct BTNode
{
	int data;
	struct BTNode* pLchild;
	struct BTNode* pRchild;
}BTNode;
BTNode* CreateBTree(void);
void PreTraverseBTree(BTNode* p);
void InTraverseBTree(BTNode* p);
void PostTraverseBTree(BTNode* p);
int main()
{
	BTNode* p = CreateBTree();
	PreTraverseBTree(p);
	InTraverseBTree(p);
	PostTraverseBTree(p);
	return 0;
}
void PreTraverseBTree(BTNode* p)//先序遍历
{
	if (p != NULL)
	{
		printf("%c ", p->data); //先访问根节点
	
		PreTraverseBTree(p->pLchild);//再先序访问左子树

		PreTraverseBTree(p->pRchild);//再先序访问右子树	
	}

}
void InTraverseBTree(BTNode* p)//中序遍历
{

	if (p != NULL)
	{
		InTraverseBTree(p->pLchild); //中序遍历左子树

		printf("%c ", p->data); //再访问根节点

		InTraverseBTree(p->pRchild); //再中序遍历右子树
	}

}
void PostTraverseBTree(BTNode* p)//后序遍历
{
	if (p != NULL)
	{
		PostTraverseBTree(p->pLchild); //先后序遍历左子树

		PostTraverseBTree(p->pRchild); //再后序遍历右子树

		printf("%c ", p->data); //再访问根节点
	}

}
BTNode* CreateBTree(void)
{
	struct BTNode* pA = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pB = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pC = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pD = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pE = (struct BTNode*)malloc(sizeof(struct BTNode));
	if (pA == NULL || pB == NULL || pC == NULL || pD == NULL || pE == NULL)
		exit(-1);
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}