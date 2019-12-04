//栈的应用：括号匹配
#include <iostream>
#include <string>
#include <stdio.h>
//#include "Stack.h"
#include "LinkedStack.h"
using namespace std;

const int maxLength = 100;  //最大字符串长度

void PrintMachedPairs(char* expression)
{
	LinkedStack<int> s(maxLength);  //栈s存储
	int j, length = strlen(expression);
	for (int i = 1; i < length; i++)
	{
		if (expression[i - 1] == '(')
			s.Push(i);  //左括号，位置进栈
		else if (expression[i - 1] == ')')
		{
			if (s.Pop(j) == true)
				cout << j << "与" << i << "匹配" << endl;
			else cout << "没有与第" << i << "个右括号匹配的左括号！" << endl;
		}
	}
}