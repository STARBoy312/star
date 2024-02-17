#include<iostream>
using namespace std;
#define MAXSIZE 10000 
#define MAX 1000
int main() {
	/*
		顺序表的初始化
	Status InitList(SqList & L)
	{
		L.elem = new ElemType[MAXSIZE];
		if (!L.elem) exit(OVERFLOW);
		L.length = 0;
		return ok;
	}*/



	/*
		顺序表的新增
	status listinsert(Sqlist & l, int i, elemtype e)
	{
		if ((i < 1) || (i > l.length))  return error;
		if (l.length == maxsize) return error;
		for (int j = l.length - 1; j >= i - 1; j--)
		{
			l.elem[j + 1] = l.elem[j];  //这个是将顺序表向后移
        }
			l.elem[i-1] = e;  //移动后，将新的值赋给i-1
			++l.length; //增加表长
			return ok;
		
	}*/



	/*
		顺序表的删除
	Status ListDelete(Sqlist & L, int i) //这个是删除，不需要表内元素
	{
		if ((i < 1) || (i > L.length))  return error;
		for (int j = i; j < L.length - 1; j--) // 因为删除的是第i个元素，所以下标从i开始
		{
			L.elem[j - 1] = L.elem[j];
		}
		--L.length;
		return OK;
	}*/



	/*
		单链表的初始化
	Status InitList(LinkList & L) //这个参数是一个指向单链表的指针L
	{
		L = new LNode;
		L->next = NULL;  //头节点指针，说明现在是空链表
		return OK;
	}*/



	/*
		单链表的取值
	Status GetElem(LinkList & L, int i, ElemType &e)   //用的是&e是因为，单链表需要找到指针对应的地址才能进行取值
	{
		//一个单链表需要有一个头指针L，第一个元素的地址就是L.next
		p = L->next; int j = 1; //P是开始寻找的第一个元素，j是一个计数器，初始值为1
		while (p && j < i)  //当P不为空且j<i时，进行循环
		{
			p = p->next;
			++j;
		}
		if (!p || j > i) return ERROR; //要取的第i个值不合法、
		e = p->data;
		return OK;
	}

	Status GetElem(LinkList& L, int i, ElemType &e)  //要取出来的是在一个链表中，因此要传入要取的地址
	{
		p = L->next; int j = 1;
		while (p && j < i)
		{
			p = p->next;
			++j;
		}
		if (!p || j > i) return ERROR;
		e = p->data;
		return OK;
	}*/



	/*
		单链表的插入
	Status ListInsert(LinkList & L, int i, ElemType e)
	{
		p = L; int j = 0;  //
		while (p && (j < i - 1))   //因为要插在第i个数据上，因此要查找i-1的结点上
		{
			p = p -> next;
			j++;       //用++j，换成j<=i-1就等价了
		}
		if (!p || j > i - 1) return ERROR;  //判断
		s = new LNode; //生成新的结点
		s->data = e; //s的数据域值为e
		s -> next = p->next;  //理解为，p之前的next是下一个，但是断开了，但是地址没有变，所以只是指向变了，由s指过去了
		p->next = s;  //然后p现在的屁股是s
		return OK;
	}

	Status ListInsert(LinkList& L, int i, ElemType e)
	{
		p = L; int j = 0;
		while (p && j <= i - 1)
		{
			p = p->next;
			j++;
		}
		if (!p || j > i - 1) return ERROR;
		s = new LNode;
		s->data = e;
		s->next = p->next;
		p - next = s;
		return OK;
	}*/


	
	/*
		单链表按值查找
	LNode* LocateElem(LinkList& L, ElemType e)
	{
		p = L->next;
		while (p&& p->data != e) //直到p_>data不等于e时，停止
		{
			p = p->next;	//说明这时候已经指到了或者是遍历结束了
		}
		return p;	//返回p的值，或是NULL
	}
	*/

	

    /*
		单链表的头插法 
	void CreateLinkList(LinList& L, int n)
	{
		L = new LNode;  //先生成一个带头结点的链表
		L->next = NULL;  //空链表
		for (int i = 0; i < n; i++)
		{
			p = new LNode;		//创建一个新的即将要头插的东西
			cin >> p->data;		//输入他的数据域
			p->next = L->next;		//类似于单链表的插入
			L->next = p; 
		}
		return OK;
	}
	void CreateLinkList(LinkList& L, int n)
	{
		L = new LNode;
		L->next = NULL;
		for (int i = 0; i < n; i++)
		{
			p = new LNode;
			p->next = L->next;
			L->next = p;
		}
		return OK;
	}
	*/




	/*
		单链表后插法
	void CreateList(LinkList& L, int n)
	{
		L = new LNode;
		L->next = NULL;
		r = L;
		for (int i = 0; i < n; i++)
		{
			p = new LNode;
			cin >> p->data;
			p->next = NULL;
			r->next = p;
			r = p;
		}
		return OK;
	}

	void CreatList(LinkList& L, int n)
	{
		L = new LNode;
		L->next = NULL;
		r = L;
		for (int i = 0; i < n; i++)
		{
			p = new LNode;
			p->next = NULL;
			r->next = p;
			r = p;
		}
	}
	*/

	//双向链表的存储结构
	/*typedef struct DulNode
	{
		ElemType data;
		struct DulNode* piror;
		struct DulNode* next;
	}DulNode, * DuLinkList;*/
	



	/*
	* 双向链表的插入
	Status ListInsert_Dul(DulLinkList& L, int i, ElemType e)
	{
		if (!(p = GetElem_Dul(L, i)))
		{
			return ERROR;
		}
		s = new LNode;
		s->data = e;  //数据域是e
		s->prior = p->piror; //p的前一个元素原来是a，现在把这个地址给了s的piror
		p->piror->next = s;		//p的前件元素的后面连接的地址是s
		s->next = p;	//后面的开始进来新的
		p->piror = s;  //
		return OK;
	}
	Status ListInsert_Dul(DulLinkList& L, int i, ElemType e)
	{
		if (!(p = GetElem_Dul(L, i)))
		{
			return ERROR;
		}
		s = new LNode;
		s->data = e;
		s->piror = p->piror;
		p->piror->next = s;
		s->next = p;
		p->piror = s;
		return OK;
	}
	*/





	/*
		顺序表的合并******（还没懂）
	void MergeList_Sq(Sqlist LA, Sqlist LB, Sqlit& LC)
	{
		LC.length = LA.length + LB.length; //长度进行叠加
		LC.elem = new ElemType[LC.length];	//开辟一个长度为LC.length空间
		pc = LC.elem;	//指代里面的元素
		pa = LA.elem;
		pb = LB.elem;
		pa_last = LA.elem + LA.length - 1; //列表中最后一个元素
		pb_last = LB.elem + LB.length - 1;
		while ((pa <= pa_last) && (pb <= pb_last))
		{
			if (*pa <= *pb)
			{
				*pc++ = *pa;
			}
			else
			{
				*pc++ = *pb++;
			}
		}
		while (pa <= pa_last) *pc++ = *pa++;
		while (pb <= pb_last) *pc++ = *pb++;

	}
	return OK;
	*/




	/*
		单链表的合并
	void MergeList_L(LinkList& LA, LinkList& LB, LinkList& C)
	{
		pa = LA->next;
		pb = LB->next;
		LC = LA;
		pc = LC;
		while (pa && pb)
		{
			if (pa->data <= pb->data)
			{
				pc->next = pa;
				pc = pa;
				pa = pa->next;
			}
			else
			{
				pc->next = pb;
				pc = pb;
				pb = pb->next;
			}
		}
		pc->next = pa ? pa : pb;
		delete LB;
	}

	void Merge_List_H(LinkList& LA, LinkList& LB, LinkList& LC)
	{
		pa = LA->next;
		pb = LB->next;
		LC = LA;
		pc = LC;
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		pc->next = pa ? pa : pb;
		delete LB;
		return OK;
	}*/
	



	/*
		多项式的创建（还是不是很明白）
	void createpolyn(polunomial &p, int n)
	{
		p = new pnode;
		p->next = null; //带头结点的单链表
		for (int i = 0; i <= n; i++)
		{
			s = new pnode;
			cin >> s->coef >> s->expn;	//输入该多项式的系数和指数
			pre = p;
			q = p->next;
			while (q && q->expn < s->expn)
			{
				pre = q;
				q = q->next;
			}
			s->next = q;
			pre->next = s;
		}
	}

	void createlink(linklist& p, int n)
	{
		p = new pnode;
		p->next = null;
		for (int i = 0; i <= n; i++)
		{
			s = new pnode;
			cin >> s->coef >> s->expn;
			pre = p;
			q = p->next;
			while (q && q->expn < s->expn)
			{
				pre = q;
				q = q->next;
			}
			s->next = q;
			pre->next = s;

		}
	}*/



	
	/*	多项式的相加(还是不会)
	void AddPolyn(Polynomial& Pa, Polynomial& Pb)
	{
		p1 = Pa->next;
		p2 = Pb->next;
		p3 = Pa;
		while (p1 && p2)
		{
			if (p1->expn == p2->expn)
			{
				sum = p1->coef + p2->coef;
				if (sum != 0)
				{
					p1->coef = sum;
					p3->next = p1;
					p3 = p1;
					p1 = p1->next;
					r = p2;
					p2 = p2->next;
					delete r;
				}
				else
				{
					r = p1; 
					p1 = p1->next;
					delete r;
					r = p2;
					p2 = p2 - > next;
					delete r;

				}
			}
			else if (p1->expn < p2->expn)
			{
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
			}
			else
			{
				p3->next = p2;
				p3 = p2;
				p2 = p2->next;
			}
		}
		p3->next = p1 ? p1 : p2;
		delete Pb;
	}
	*/
	



	return 0;
}   