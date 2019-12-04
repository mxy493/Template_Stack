#pragma once
const int maxSize = 50;
//enum bool{ false, true };

template<typename T>
class Stack {  //ջ���ඨ��
public:
	Stack() {};
	virtual void Push(const T& x) = 0;  //��Ԫ��x��ջ
	virtual bool Pop(T& x) = 0;  //ջ��Ԫ�س�ջ����x����
	virtual bool getTop(T& x) const = 0;  //��ȡջ��Ԫ�أ���x����
	virtual bool isEmpty() const = 0;  //�ж�ջ�շ�
	//virtual bool isFull() const = 0;  //�ж�ջ����
	virtual int getSize() const = 0;  //����ջ��Ԫ�ظ���
};