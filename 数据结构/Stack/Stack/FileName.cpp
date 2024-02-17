#include<iostream>
using namespace std;
#define MAX 1000

//	顺序表的存储结构
// typedef struct
//{
//	SElemType* base;
//	SElemType* top;
//	int stackList;
//};

//	链表的存储结构
// typedef struct StackNode
//{
//	ElemType  data;
//	struct StackNode* next;
//} StackNode* LinkStack;

int main()
{	
	/*
		栈的初始化
	status InitStack(SqStack & S)  //栈的初始化操作
	{
		S.base = new SElemType[MAX];	//顺序栈分配一个最大容量的MAX的数组
		if (!base) exit(OVERFLOW);  //判断，如果底层不存在，则OVERFLOW
		S.top = S.base;	//栈的初始时，base 和 top层是一样的，所以把base赋给top
		S.stacksize = MAX;	//S的最大长度为MAX
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
		入栈操作
	Status Push(SqStack & S, SElemType e)
	{
		if (S.top - S.base == S.StackSize) return ERROR;  //判断长度，如果长度刚好等于总长，则不允许再加
		*S.top++ = e;	//传递地址的形式，往top上面++e
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
		栈的出栈操作
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
		取栈顶的元素
	SElemType(SqSatck & S)
	{
		if (S.top != S.base) return ERROR;
		return *(S.top-1)  //如果光说一个top，那就是一个空的，就是最上面那个，因此要TOP-1，然后*取值
	}
	SElemType(SqStack& S)
	{
		if (S.top != S.base)	return ERROR;
		return *(S.top - 1);
	}*/


	
	/*
		链栈的初始化
	Status InitStack(SqStack & S)
	{
		S = NULL;
		return OK;
	}*/




	/*
		栈链表的入栈
	Status Push(LinkStack & S, SElemType e)
	{
		p = new StackNode;   //生成一个新的结点，用力存放新的数据
		p->data = e;	//p的数据域是e
		p->next = S;	//原来放S头结点的地方，现在放了p->next，也就是p插在前面了
		S = p;		//然后把现在的p的地址给了S，作为新的头结点，依次往下进行
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
		链栈的出栈 
	Status Pop(LinkStack& S, SElemType e)
	{
		if (S == NULL) return ERROR;  //判断是否为空
		e = S->data;	//用e来存放此结点的数据域
		p = S;	//用临时的p存放S
		S = S->next;	//S结点向下移动，也就是修改栈顶指针
		delete p;	//释放空间
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
		取顶栈元素
	SElemType GetTop(LinkStack s)
	{
		if (S != NULL) return S->data;
	}*/
		


	return 0;
}