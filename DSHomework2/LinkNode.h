#ifndef LINKNODE_H
#define LINKNODE_H
template<class T>
class LinkNode
{
public:
	T data;
	LinkNode<T> *link;
	LinkNode(const T &el, LinkNode<T> *ptr = 0);
};
template<class T>
LinkNode<T>::LinkNode(const T &el, LinkNode<T> *ptr = 0)
{
	data = el;
	link = ptr;
}
#endif