#pragma once
#include <iostream>
#include <assert.h>
#include "LinkNode.h"
#include "Stack.h"
using namespace std;

template <typename T>
class LinkedStack :public Stack<T> {
private:
	LinkNode<T>* top;  //栈顶指针，即链头指针
public:
	LinkedStack() :top(NULL) {}  //构造函数，置空栈
	~LinkedStack() { makeEmpty(); }  //析构函数
	void Push(const T& x);  //进栈
	bool Pop(T& x);  //退栈
	bool getTop(T& x)const;  //读取栈顶元素
	bool isEmpty()const { return (top == NULL) ? true : false; }
	//bool isFull() const {};
	int getSize()const;  //求栈的元素个数
	void makeEmpty();  //清空栈的内容
	friend ostream& operator<<(ostream& os, LinkedStack<T>& s);  //输出栈中元素的重载操作<<
};

//该函数尚未测试
template<typename T>
inline void LinkedStack<T>::Push(const T& x)
{
	//将元素值x插入到链式栈的栈顶，即链头
	//top = new LinkedStack<T>(x, top);  //创建新的含x结点
	LinkNode<T>* p = new LinkNode<T>;
	p->data = x;
	p->link = top;
	top = p;
	assert(top != NULL);  //创建结点失败退出
}

template<typename T>
inline bool LinkedStack<T>::Pop(T& x)
{
	//删除栈顶结点，返回被删栈顶元素的值
	if(isEmpty()==true)
		return false;  //若栈空则不退栈，返回
	LinkNode<T>* p = top;  //否则暂存栈顶元素
	top = top->link;  //栈顶指针退到新的栈顶位置
	x = p->data;  //返回退出元素的值
	delete p;  //释放结点
	return true;
}

template<typename T>
inline bool LinkedStack<T>::getTop(T& x) const
{
	//返回栈顶元素的值
	if (isEmpty() == NULL)
		return false;  //若栈空则返回false
	x = top->data;  //栈不空则返回栈顶元素的值
	return true;
}

template<typename T>
inline int LinkedStack<T>::getSize() const
{
	LinkNode<T>* p = top;
	int k = 0;
	while (p != NULL)
	{
		p = p->link;
		k++;
	}
	return k;
}

template<typename T>
inline void LinkedStack<T>::makeEmpty()
{
	//逐次删去链式栈中的元素直至栈顶指针为空
	LinkNode<T>* p;
	while (top != NULL)
	{
		p = top;
		top = top->link;
		delete p;
	}
}

template<typename T>
ostream& operator<<(ostream& os, LinkedStack<T>& s)
{
	// 输出栈中元素的重载操作<<
	os << "栈中元素个数 = " << s.getSize() << endl;
	LinkNode<T>* p = s.top;
	int i = 0;
	while (p != NULL)
	{
		os << ++i << ":" << p->data << endl;
		p = p->link;
	}
	return os;
}