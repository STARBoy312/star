#include<iostream>
using namespace std;
#define MAX 1000

//	˳���Ĵ洢�ṹ
// typedef struct
//{
//	SElemType* base;
//	SElemType* top;
//	int stackList;
//};

//	����Ĵ洢�ṹ
// typedef struct StackNode
//{
//	ElemType  data;
//	struct StackNode* next;
//} StackNode* LinkStack;

int main()
{	
	/*
		ջ�ĳ�ʼ��
	status InitStack(SqStack & S)  //ջ�ĳ�ʼ������
	{
		S.base = new SElemType[MAX];	//˳��ջ����һ�����������MAX������
		if (!base) exit(OVERFLOW);  //�жϣ�����ײ㲻���ڣ���OVERFLOW
		S.top = S.base;	//ջ�ĳ�ʼʱ��base �� top����һ���ģ����԰�base����top
		S.stacksize = MAX;	//S����󳤶�ΪMAX
		return OK;
	}
	Status InitStack(SqStack & S)
	{
		S.base = new ElemType[MAX];
		if (!base) exit(ERROR);
		S.top = S.base;
		S.StackSize = MAX;
		return OK;
	}*/

	/*
		��ջ����
	Status Push(SqStack & S, SElemType e)
	{
		if (S.top - S.base == S.StackSize) return ERROR;  //�жϳ��ȣ�������ȸպõ����ܳ����������ټ�
		*S.top++ = e;	//���ݵ�ַ����ʽ����top����++e
		return OK;
	}
	Status Push(SqStack &S,SElemType e)
	{
		if(S.top-S.base == S.StackSize) return ERROR;
		*S.top ++=e;
		return OK;
	}

	*/

	/*
		ջ�ĳ�ջ����
	Status Pop(SqStack & S, SElemType e)
	{
		if (S.top == S.base) return ERROR;
		e = *--S.top;
		return OK;
	}

	Status Pop(SqStack& S, SElemType e)
	{
		if (S.top == S.base) return ERROR;
		e = *--S.top;
		return OK;
	}*/
	

	/*
		ȡջ����Ԫ��
	SElemType(SqSatck & S)
	{
		if (S.top != S.base) return ERROR;
		return *(S.top-1)  //�����˵һ��top���Ǿ���һ���յģ������������Ǹ������ҪTOP-1��Ȼ��*ȡֵ
	}
	SElemType(SqStack& S)
	{
		if (S.top != S.base)	return ERROR;
		return *(S.top - 1);
	}*/


	
	/*
		��ջ�ĳ�ʼ��
	Status InitStack(SqStack & S)
	{
		S = NULL;
		return OK;
	}*/




	/*
		ջ�������ջ
	Status Push(LinkStack & S, SElemType e)
	{
		p = new StackNode;   //����һ���µĽ�㣬��������µ�����
		p->data = e;	//p����������e
		p->next = S;	//ԭ����Sͷ���ĵط������ڷ���p->next��Ҳ����p����ǰ����
		S = p;		//Ȼ������ڵ�p�ĵ�ַ����S����Ϊ�µ�ͷ��㣬�������½���
		return OK;
	}
	
	Status Push(LinkStack &S,SElemtype e)
	{
		p = new StackNode;
		p->data = e;
		p->next = s;
		S= p;
		return OK;
	}
	*/


	/*
		��ջ�ĳ�ջ 
	Status Pop(LinkStack& S, SElemType e)
	{
		if (S == NULL) return ERROR;  //�ж��Ƿ�Ϊ��
		e = S->data;	//��e����Ŵ˽���������
		p = S;	//����ʱ��p���S
		S = S->next;	//S��������ƶ���Ҳ�����޸�ջ��ָ��
		delete p;	//�ͷſռ�
		return OK;
	}
	Status Pop(LinkStack& S, SElemType)
	{
		if (S == NULL) return ERROR;
		e = S->data;
		p = S;
		S = S->next;
		delete p;
		return OK;
	}
	*/

	/*
		ȡ��ջԪ��
	SElemType GetTop(LinkStack s)
	{
		if (S != NULL) return S->data;
	}*/
		


	return 0;
}