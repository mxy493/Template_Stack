//ջ��Ӧ�ã�����ƥ��
#include <iostream>
#include <string>
#include <stdio.h>
//#include "Stack.h"
#include "LinkedStack.h"
using namespace std;

const int maxLength = 100;  //����ַ�������

void PrintMachedPairs(char* expression)
{
	LinkedStack<int> s(maxLength);  //ջs�洢
	int j, length = strlen(expression);
	for (int i = 1; i < length; i++)
	{
		if (expression[i - 1] == '(')
			s.Push(i);  //�����ţ�λ�ý�ջ
		else if (expression[i - 1] == ')')
		{
			if (s.Pop(j) == true)
				cout << j << "��" << i << "ƥ��" << endl;
			else cout << "û�����" << i << "��������ƥ��������ţ�" << endl;
		}
	}
}