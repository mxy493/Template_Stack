#pragma once
#include <iostream>
#include <assert.h>
#include "LinkNode.h"
#include "Stack.h"
using namespace std;

template <typename T>
class LinkedStack :public Stack<T> {
private:
	LinkNode<T>* top;  //ջ��ָ�룬����ͷָ��
public:
	LinkedStack() :top(NULL) {}  //���캯�����ÿ�ջ
	~LinkedStack() { makeEmpty(); }  //��������
	void Push(const T& x);  //��ջ
	bool Pop(T& x);  //��ջ
	bool getTop(T& x)const;  //��ȡջ��Ԫ��
	bool isEmpty()const { return (top == NULL) ? true : false; }
	//bool isFull() const {};
	int getSize()const;  //��ջ��Ԫ�ظ���
	void makeEmpty();  //���ջ������
	friend ostream& operator<<(ostream& os, LinkedStack<T>& s);  //���ջ��Ԫ�ص����ز���<<
};

//�ú�����δ����
template<typename T>
inline void LinkedStack<T>::Push(const T& x)
{
	//��Ԫ��ֵx���뵽��ʽջ��ջ��������ͷ
	//top = new LinkedStack<T>(x, top);  //�����µĺ�x���
	LinkNode<T>* p = new LinkNode<T>;
	p->data = x;
	p->link = top;
	top = p;
	assert(top != NULL);  //�������ʧ���˳�
}

template<typename T>
inline bool LinkedStack<T>::Pop(T& x)
{
	//ɾ��ջ����㣬���ر�ɾջ��Ԫ�ص�ֵ
	if(isEmpty()==true)
		return false;  //��ջ������ջ������
	LinkNode<T>* p = top;  //�����ݴ�ջ��Ԫ��
	top = top->link;  //ջ��ָ���˵��µ�ջ��λ��
	x = p->data;  //�����˳�Ԫ�ص�ֵ
	delete p;  //�ͷŽ��
	return true;
}

template<typename T>
inline bool LinkedStack<T>::getTop(T& x) const
{
	//����ջ��Ԫ�ص�ֵ
	if (isEmpty() == NULL)
		return false;  //��ջ���򷵻�false
	x = top->data;  //ջ�����򷵻�ջ��Ԫ�ص�ֵ
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
	//���ɾȥ��ʽջ�е�Ԫ��ֱ��ջ��ָ��Ϊ��
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
	// ���ջ��Ԫ�ص����ز���<<
	os << "ջ��Ԫ�ظ��� = " << s.getSize() << endl;
	LinkNode<T>* p = s.top;
	int i = 0;
	while (p != NULL)
	{
		os << ++i << ":" << p->data << endl;
		p = p->link;
	}
	return os;
}