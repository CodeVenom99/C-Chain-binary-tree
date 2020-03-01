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
void PreTraverseBTree(BTNode* p)//�������
{
	if (p != NULL)
	{
		printf("%c ", p->data); //�ȷ��ʸ��ڵ�
	
		PreTraverseBTree(p->pLchild);//���������������

		PreTraverseBTree(p->pRchild);//���������������	
	}

}
void InTraverseBTree(BTNode* p)//�������
{

	if (p != NULL)
	{
		InTraverseBTree(p->pLchild); //�������������

		printf("%c ", p->data); //�ٷ��ʸ��ڵ�

		InTraverseBTree(p->pRchild); //���������������
	}

}
void PostTraverseBTree(BTNode* p)//�������
{
	if (p != NULL)
	{
		PostTraverseBTree(p->pLchild); //�Ⱥ������������

		PostTraverseBTree(p->pRchild); //�ٺ������������

		printf("%c ", p->data); //�ٷ��ʸ��ڵ�
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