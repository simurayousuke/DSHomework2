#include <iostream>
#include "LinkList.h"

bool Merge(LinkList<int>&a, LinkList<int>&b)
{
	LinkNode<int> *pa = a.setPos(-1)->link;
	LinkNode<int> *pb = b.setPos(-1)->link;
	LinkNode<int> *pc = new LinkNode<int>(0, 0);
	bool mainA = true;
	if (pa->data > pb->data)
		mainA = false;
	while (pa&&pb)
	{
		if (mainA)
		{
			if (pa->data <= pb->data)
			{
				if (pa->link != 0)
				{
					if (pb->data <= pa->link->data)
					{
						pc = pb->link;
						pb -> link = pa -> link;
						pa->link = pb;
						pb = pc;
					}
					else
					{
						pa = pa->link;
					}
				}
				else
				{
					pa->link = pb;
					break;
				}
			}
		}
		else
		{
			if (pb->data <= pa->data)
			{
				if (pb->link != 0)
				{
					if (pa->data <= pb->link->data)
					{
						pc = pa->link;
						pa->link = pb->link;
						pb->link = pa;
						pa = pc;
					}
					else
					{
						pb = pb->link;
					}
				}
				else
				{
					pb->link = pa;
					break;
				}
			}
		}

	}
	return mainA;
}

int main()
{
	LinkList<int> a, b;
	int numA, numB,temp;
	//��������
	std::cout << "������ha�����ݸ�����";
	std::cin >> numA;
	std::cout << "������ha�����ݣ�" << std::endl;
	for (int i = 0; i < numA; ++i)
	{
		std::cin >> temp;
		a.insertTail(temp);
	}
	std::cout << "������hb�����ݸ�����";
	std::cin >> numB;
	std::cout << "������hb�����ݣ�" << std::endl;
	for (int i = 0; i < numB; ++i)
	{
		std::cin >> temp;
		b.insertTail(temp);
	}
	//ִ�к�������¼����
	bool res = Merge(a, b);
	//��ӡ���
	std::cout << "�ϲ���" << std::endl;
	temp = numA + numB;
	if (res)
	{
		a.reset();
		for (int i = 0; i < temp; ++i)
		{						
			std::cout << a.data() << "  ";
			a.next();
		}
	}
	else
	{
		b.reset();
		for (int i = 0; i <temp; ++i)
		{						
			std::cout << b.data() << "  ";
			b.next();
		}
	}
	std::cout << std::endl;
	return 0;
}