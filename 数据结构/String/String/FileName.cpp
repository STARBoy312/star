#define MAXLEN 255
typedef struct {
	char ch[MAXLEN + 1]; //����ʱҪ��1��ʼ
	int length;
}SString;



////BF�㷨
//int Index(SString S, SString T, int pos)  //pos�����ƥ��Ľ�㳤��
//{
//	int i = pos;
//	int j = 1;
//	while (j <= T.length && i <= S.length)
//	{
//		if (S.ch[i] == T.ch[j])
//		{
//			i++;
//			j++;
//		}
//		else  //jָ���ͷ����   iָ����������ǻر��λ��
//		{
//			i = i - j + 2;
//			j = 1;
//		}
//	}
//
//	if (j > T.length)
//		return i - T.length;
//	else return 0;
//}


////KMP�㷨
//int KMP_Index(SString S, SString T, int pos)
//{
//	int i = pos;
//	int j = 1;
//	while (i < S.length && j < T.length)
//	{
//		if (j = 0 || S.ch[i] == T.ch[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j]; //  ����ͷ��ʼ����next������ֵ��ʼ����
//		}
//	}
//	if (j > T.length)
//	{
//		return i - T.length;
//	}
//	else return 0;
//}
//
////KMP�µ�next����
//void next(SString T, int next[])
//{
//	int i = 1;
//	next[1] = 0;
//	int j = 0;
//	while (i < T.length)
//	{
//		if (j == 0 || T.ch[i] == T.ch[j])
//		{
//			++i;
//			++j;
//			next[i] = j;
//		}
//		else
//		{
//			j = next[j];	//����ģʽ����ƥ��Ԫ�ص�j
//		}
//	}
//}
//
////KMP�µ�next��������ֵ
//void get_nextval(SString T, int nextval[])
//{
//	int i = 1;
//	nextval[1] = 0;
//	int j = 0;
//	while (i < T.length)
//	{
//		if (j == 0 || T.ch[i] == T.ch[j])
//		{
//			++i;
//			++j;
//			if (T.ch[i] != T.ch[j])
//			{
//				nextval[i] = j;
//			}
//			else
//			{
//				nextval[i] = nextval[j];
//			}
//		}
//		else
//		{
//			j = nextval[j];
//		}
//	}
//}