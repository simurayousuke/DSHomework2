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
	LinkNode<T>* next();
	void insertTail(const T &item);
	T& data();
	LinkNode<T> *setPos(int pos);
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
LinkNode<T>* LinkList<T>::next()
{
	currPtr = currPtr->link;
	++position;
	return currPtr;
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