#include <iostream>
#include "ListDbl.h"

using namespace std;

// ** ListNode ������ **
template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode *priorPtr, ListNode *nextPtr)
	:element(elem),
	prior(priorPtr),
	next(nextPtr)
{}

// ** List ������ **
template<class LE>
List<LE>::List(int ignored)
{
	head = new ListNode<LE>(0, NULL, NULL);
	cursor = head;
}

// ** List �Ҹ��� ** 
template<class LE>
List<LE>::~List()
{
	clear();
}

// ** ��� ���� ** 
template<class LE>
void List<LE>::insert(const LE &newElement)
{
	if (empty())	// �� ����� ���
	{
		ListNode<LE> * newNode = new ListNode<LE>(newElement, head, NULL);
		cursor = newNode;
		head->next = newNode;
	}

	else           
	{
		
		if (cursor->next == NULL)  // ����Ʈ�� �� ���� ��带 ������ ���
		{
			ListNode<LE> * newNode = new ListNode<LE>(newElement, cursor, NULL);
			cursor->next = newNode;
		}
		else                       
		{
			ListNode<LE> * newNode = new ListNode<LE>(newElement, cursor, cursor->next);
			cursor->next->prior = newNode;
			cursor->next = newNode;
		}
		cursor = cursor->next;
	}
}

// ** ��� ���� **
template<class LE>
void List<LE>::remove()
{
	if (!empty())
	{
		ListNode<LE> * tmp = cursor;

		if (cursor->next == NULL)       // ����Ʈ�� ������ ����� ���
		{
			cursor->prior->next = NULL;
			cursor = head->next;        // Ŀ���� ó�� ���� ����
		}
		else if (cursor->prior == head) // ����Ʈ�� ó�� ����� ���
		{
			cursor->next->prior = head;
			head->next = cursor->next;
			cursor = cursor->next;
		}
		else
		{
			cursor->next->prior = cursor->prior;
			cursor->prior->next = cursor->next;
			cursor = cursor->next;
		}

		delete tmp;
	}
	else
		cout << "Empty list" << endl;
}


// ** ��� ��ü **
template<class LE>
void List<LE>::replace(const LE &newElement)
{
	ListNode<LE> * tmp = cursor;		// ���� Ŀ���� �ӽ� �����Ϳ� ���� ��
	cursor = new ListNode<LE>(newElement, cursor->prior, cursor->next);	// �� ��带 ���� Ŀ�� ��ġ�� ����
	tmp->prior->next = cursor;
	if (tmp->next != NULL)
		tmp->next->prior = cursor;
	delete tmp;							// �ӽ� �����Ϳ� ������ ��� �޸� �󿡼� ����
}

// ** �ʱ�ȭ **
template<class LE>
void List<LE>::clear()
{
	while (!empty())
	{
		remove();
	}
}
								
// ** �� ����Ʈ���� Ȯ�� **
template<class LE>
int List<LE>::empty() const
{
	if (head->next==NULL)
		return 1;
	else
		return 0;
}
	
template<class LE>
int List<LE>::full() const
{
	return 0;
}
						
// ** Ŀ���� ó������ ** 
template<class LE>
bool List<LE>::gotoBeginning()
{
	if (!empty())
	{
		cursor = head->next;
		return true;
	}
	return false;
}

// ** Ŀ���� ���������� ** 
template<class LE>
bool List<LE>::gotoEnd()
{
	if (!empty())
	{
		while (cursor->next != NULL)	// ����� next�� NULL�� �ƴ� ����
			cursor = cursor->next;		// Ŀ���� ���� ���� �̵�
		return true;
	}
	return false;
}
	
// ** ���� ���� Ŀ�� �̵� ** 
template<class LE>
bool List<LE>::gotoNext()
{
	if (cursor->next != NULL)			// ����� next�� NULL�� �ƴϸ�
	{
		cursor = cursor->next;			// Ŀ���� ���� ���� �̵�
		return true;
	}
	return false;
		
}

// ** ���� ���� Ŀ�� �̵� ** 
template<class LE>
bool List<LE>::gotoPrior()
{
	if (cursor->prior == head)			// Ŀ���� ���� ��尡 head�̸�
		return false;					// �̵����� ����
	else
	{
		cursor = cursor->prior;			// Ŀ���� ���� ���� �̵�
		return true;
	}
		
}
	
// ** Ŀ���� ����Ű�� ����� element ���� ** 
template<class LE>
LE List<LE>::getCursor() const
{
	if(!empty())
		return cursor->element;
	cout << "Empty list" << endl;
	return 0;
}
										
// ** ����Ʈ ���� ��� ** 
template<class LE>
void List<LE>::showStructure() const
{
	if(empty())
		cout << "Empty List" << endl;
	else
	{
		ListNode<LE> * tmp = head->next;	// �ӽ� �����ʹ� ó�� ������ ����
		while (tmp->next != NULL)			// �ӽ� �������� next�� NULL�� �ƴ� ����
		{
			cout << tmp->element << '\t';	// �����Ͱ� ����Ű�� ����� element�� ����ϰ�
			tmp = tmp->next;				// ���� ���� �̵�
		}
		cout << tmp->element << endl;		// ������ ����� element ���
	}	
}

// ** ����Ʈ ���� **
template<class LE>
void List<LE>::reverse()
{
	if (empty())
		cout << "Empty List" << endl;
	else
	{
		int len = length();						// ���� ����Ʈ�� ��� ��尡 �ִ��� ���
		LE * arr = new LE[len];					// ��� ��ŭ�� LEŬ���� �迭 ����

		ListNode<LE> * tmpNode = head->next;	// �ӽ� �����͸� ó�� ���� ����

		for (int i = 0; i < len; i++)			// ��� ������ŭ for loop�� ���鼭
		{
			if (tmpNode->next != NULL)			// �ӽ� �������� next�� NULL�� �ƴ� ����
			{
				arr[i] = tmpNode->element;		// �迭�� �� ����� element ����
				tmpNode = tmpNode->next;		// �ӽ� �����͸� next�� �̵�
			}
		}
		arr[len - 1] = tmpNode->element;		// �迭�� ������ �ε����� ������ ����� element ����

		int index = 0;							// ����Ʈ�� �ʱ�ȭ �ϱ� ����, ���� Ŀ���� ��ġ�� index�� �����ϱ� ���� ����
		ListNode<LE> *tmpCursor = head->next;	// �ӽ� �����Ͱ� ó�� ������ �����Ͽ�,
		while (tmpCursor != cursor)				// �ӽ� �����Ͱ� cursor�� ������ �� ����
		{
			index++;							// index�� ������Ű��
			tmpCursor = tmpCursor->next;		// �ӽ� �����Ͱ� ���� ��带 ����Ű�� ��
		}
		
		clear();								// ����Ʈ �ʱ�ȭ

		for (int i = len-1; i >=0; i--)
		{
			insert(arr[i]);						// �迭�� �ִ� element�� ����Ʈ�� �ݴ� ������ insert
		}

		gotoBeginning();						// Ŀ���� ó�� ���� ��ġ��Ű��
		for (int i = 0; i < len-index-1; i++)	// ��ü ����� ���̿��� index-1�� �� ��ŭ ��带 �̵���Ų��. (����Ʈ�� �������� ����)
		{
			cursor = cursor->next;
		}

	}
	
	
}

// ** ����� ���� ��� ** 
template<class LE>
int List<LE>::length() const
{
	int len = 1;

	if (empty())	// �� ����Ʈ�� ��� ��� 0��
		return 0;
	else
	{
		ListNode<LE> * tmpCursor = head->next;	// ó�� ������ ���
		while (tmpCursor->next != NULL)
		{
			len++;								// ��尡 ������ ��� len ����
			tmpCursor = tmpCursor->next;		// ���� ���� �̵�
		}
		return len;								// ��� ���� ����
	}
}