#define MAXLEN 255
typedef struct {
	char ch[MAXLEN + 1]; //检索时要从1开始
	int length;
}SString;



////BF算法
//int Index(SString S, SString T, int pos)  //pos是完成匹配的结点长度
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
//		else  //j指针从头再来   i指针继续，但是回变个位置
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


////KMP算法
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
//			j = next[j]; //  不从头开始，从next给定的值开始进行
//		}
//	}
//	if (j > T.length)
//	{
//		return i - T.length;
//	}
//	else return 0;
//}
//
////KMP下的next数组
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
//			j = next[j];	//调回模式串的匹配元素的j
//		}
//	}
//}
//
////KMP下的next函数修正值
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