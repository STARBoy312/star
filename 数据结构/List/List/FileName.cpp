#include<iostream>
using namespace std;
#define MAXSIZE 10000 
#define MAX 1000
int main() {
	/*
		˳���ĳ�ʼ��
	Status InitList(SqList & L)
	{
		L.elem = new ElemType[MAXSIZE];
		if (!L.elem) exit(OVERFLOW);
		L.length = 0;
		return ok;
	}*/



	/*
		˳��������
	status listinsert(Sqlist & l, int i, elemtype e)
	{
		if ((i < 1) || (i > l.length))  return error;
		if (l.length == maxsize) return error;
		for (int j = l.length - 1; j >= i - 1; j--)
		{
			l.elem[j + 1] = l.elem[j];  //����ǽ�˳��������
        }
			l.elem[i-1] = e;  //�ƶ��󣬽��µ�ֵ����i-1
			++l.length; //���ӱ�
			return ok;
		
	}*/



	/*
		˳����ɾ��
	Status ListDelete(Sqlist & L, int i) //�����ɾ��������Ҫ����Ԫ��
	{
		if ((i < 1) || (i > L.length))  return error;
		for (int j = i; j < L.length - 1; j--) // ��Ϊɾ�����ǵ�i��Ԫ�أ������±��i��ʼ
		{
			L.elem[j - 1] = L.elem[j];
		}
		--L.length;
		return OK;
	}*/



	/*
		������ĳ�ʼ��
	Status InitList(LinkList & L) //���������һ��ָ�������ָ��L
	{
		L = new LNode;
		L->next = NULL;  //ͷ�ڵ�ָ�룬˵�������ǿ�����
		return OK;
	}*/



	/*
		�������ȡֵ
	Status GetElem(LinkList & L, int i, ElemType &e)   //�õ���&e����Ϊ����������Ҫ�ҵ�ָ���Ӧ�ĵ�ַ���ܽ���ȡֵ
	{
		//һ����������Ҫ��һ��ͷָ��L����һ��Ԫ�صĵ�ַ����L.next
		p = L->next; int j = 1; //P�ǿ�ʼѰ�ҵĵ�һ��Ԫ�أ�j��һ������������ʼֵΪ1
		while (p && j < i)  //��P��Ϊ����j<iʱ������ѭ��
		{
			p = p->next;
			++j;
		}
		if (!p || j > i) return ERROR; //Ҫȡ�ĵ�i��ֵ���Ϸ���
		e = p->data;
		return OK;
	}

	Status GetElem(LinkList& L, int i, ElemType &e)  //Ҫȡ����������һ�������У����Ҫ����Ҫȡ�ĵ�ַ
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
		������Ĳ���
	Status ListInsert(LinkList & L, int i, ElemType e)
	{
		p = L; int j = 0;  //
		while (p && (j < i - 1))   //��ΪҪ���ڵ�i�������ϣ����Ҫ����i-1�Ľ����
		{
			p = p -> next;
			j++;       //��++j������j<=i-1�͵ȼ���
		}
		if (!p || j > i - 1) return ERROR;  //�ж�
		s = new LNode; //�����µĽ��
		s->data = e; //s��������ֵΪe
		s -> next = p->next;  //���Ϊ��p֮ǰ��next����һ�������ǶϿ��ˣ����ǵ�ַû�б䣬����ֻ��ָ����ˣ���sָ��ȥ��
		p->next = s;  //Ȼ��p���ڵ�ƨ����s
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
		������ֵ����
	LNode* LocateElem(LinkList& L, ElemType e)
	{
		p = L->next;
		while (p&& p->data != e) //ֱ��p_>data������eʱ��ֹͣ
		{
			p = p->next;	//˵����ʱ���Ѿ�ָ���˻����Ǳ���������
		}
		return p;	//����p��ֵ������NULL
	}
	*/

	

    /*
		�������ͷ�巨 
	void CreateLinkList(LinList& L, int n)
	{
		L = new LNode;  //������һ����ͷ��������
		L->next = NULL;  //������
		for (int i = 0; i < n; i++)
		{
			p = new LNode;		//����һ���µļ���Ҫͷ��Ķ���
			cin >> p->data;		//��������������
			p->next = L->next;		//�����ڵ�����Ĳ���
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
		�������巨
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

	//˫������Ĵ洢�ṹ
	/*typedef struct DulNode
	{
		ElemType data;
		struct DulNode* piror;
		struct DulNode* next;
	}DulNode, * DuLinkList;*/
	



	/*
	* ˫������Ĳ���
	Status ListInsert_Dul(DulLinkList& L, int i, ElemType e)
	{
		if (!(p = GetElem_Dul(L, i)))
		{
			return ERROR;
		}
		s = new LNode;
		s->data = e;  //��������e
		s->prior = p->piror; //p��ǰһ��Ԫ��ԭ����a�����ڰ������ַ����s��piror
		p->piror->next = s;		//p��ǰ��Ԫ�صĺ������ӵĵ�ַ��s
		s->next = p;	//����Ŀ�ʼ�����µ�
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
		˳���ĺϲ�******����û����
	void MergeList_Sq(Sqlist LA, Sqlist LB, Sqlit& LC)
	{
		LC.length = LA.length + LB.length; //���Ƚ��е���
		LC.elem = new ElemType[LC.length];	//����һ������ΪLC.length�ռ�
		pc = LC.elem;	//ָ�������Ԫ��
		pa = LA.elem;
		pb = LB.elem;
		pa_last = LA.elem + LA.length - 1; //�б������һ��Ԫ��
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
		������ĺϲ�
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
		����ʽ�Ĵ��������ǲ��Ǻ����ף�
	void createpolyn(polunomial &p, int n)
	{
		p = new pnode;
		p->next = null; //��ͷ���ĵ�����
		for (int i = 0; i <= n; i++)
		{
			s = new pnode;
			cin >> s->coef >> s->expn;	//����ö���ʽ��ϵ����ָ��
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



	
	/*	����ʽ�����(���ǲ���)
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