#ifndef LINKLIST_H
#define LINKLIST_H
#include "LinkNode.h"
template<class T>
class LinkList
{
private:
	LinkNode<T> *head = new LinkNode<T>(0, 0),*tail=0;
	LinkNode<T>  *currPtr;
	int position;
	
public:
	int length;
	LinkList();
	~LinkList();
	int getSize() const;
	bool isEmpty() const;
	//void reset(int pos = 0);
	LinkNode<T>* next();
	bool endOfList() const;
	int currentPosition(void);
	void insertHead(const T &item);
	void insertTail(const T &item);
	//void insertAt(const T &item);
	//void insertAfter(const T &item);
	//T deleteHead();
	//void deleteCurrent();
	T& data();
	//const T& data() const;
	//void clear();
	LinkNode<T> *setPos(int pos);
	bool insertPos(const int i, const T value);
	bool deletePos(const int i);
	void reset() { currPtr = head->link; }
};

template<class T>
LinkNode<T>* LinkList<T>::setPos(int pos)
{
	if (pos == -1)
		return head;
	int count = 0;
	LinkNode<T> *p = head->link;
	while (p != NULL && count < pos)
	{
		p = p->link;
		count++;
	}
	position = count;
	currPtr = p;
	return p;
}

template<class T>
bool LinkList<T>::insertPos(const int i, const T value)
{
	LinkNode<T> *p, *q;
	if ((p = setPos(i - 1)) == NULL)
	{
		std::cout << "插入操作不允许" << std::endl;
		return false;
	}
	q = new LinkNode<T>(value, p->link);
	p->link = q;
	if (p == tail)
		tail = q;
	++length;
	return true;
}

template<class T>
bool LinkList<T>::deletePos(const int i)
{
	LinkNode<T> *p, *q;
	if ((p = setPos(i - 1)) == NULL || p == tail)
	{
		std::cout << "非法删除节点" << std::endl;
		return false;
	}
	q = p->link;
	if (q == tail)
	{
		tail = p;
		p->link = NULL;
		delete q
	}
	else if (q != NULL)
	{
		p->link = q->link;
		delete q;
	}
	--length;
	return true;
}

template<class T>
LinkList<T>::LinkList()
{
	head->link = 0;
	tail = 0;
	length = 0;
	position = 0;
	currPtr = head;
}

template<class T>
LinkList<T>::~LinkList()
{

}

template<class T>
void LinkList<T>::insertHead(const T &item)
{
	LinkNode<T> *p = new LinkNode<T>(item, head->link);
	head->link = p;
	if (tail == 0)
		tail = p;
	++length;
}

template<class T>
int  LinkList<T>::getSize() const
{
	return length;
}

template<class T>
bool LinkList<T>::isEmpty() const
{
	if (length == 0)
		return true;
	return false;
}

template<class T>
LinkNode<T>* LinkList<T>::next()
{
	currPtr = currPtr->link;
	++position;
	return currPtr;
}

template<class T>
int LinkList<T>::currentPosition(void)
{
	return position;
}

template<class T>
bool LinkList<T>::endOfList() const
{
	if (currPtr == tail)
		return true;
	return false;
}

template<class T>
void LinkList<T>::insertTail(const T &item)
{
	LinkNode<T> *p = new LinkNode<T>(item, 0);
	if (tail == 0)
		head->link = p;
	else
		tail->link = p;
	tail = p;
	++length;
}

template<class T>
T& LinkList<T>::data()
{
	return currPtr->data;
}
#endif