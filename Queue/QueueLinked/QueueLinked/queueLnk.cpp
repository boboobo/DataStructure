//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueLnk.cpp
//
//  SOLUTION: Linked list implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queueLnk.h"

//--------------------------------------------------------------------

// ** QueueNode ������ ** 
template < class QE >
QueueNode<QE>::QueueNode(const QE &elem, QueueNode<QE> *nextPtr)

// Creates a queue node containing element elem and next pointer
// nextPtr.

: element(elem),
next(nextPtr)
{}

//--------------------------------------------------------------------

// ** Queue ������ ** 
template < class QE >
Queue<QE>::Queue(int ignored)

// Creates an empty queue. Parameter is provided for compatability
// with the array implementation and is ignored.

: front(0),
rear(0)
{}

//--------------------------------------------------------------------

// ** Queue Destructor ** 
template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	// pre-lab (Linked)
	clear();
}

//--------------------------------------------------------------------

// ** ��� ���� ** 
template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.

{
	// pre-lab (Linked)
	if (empty())										// �� ����� ���
	{
		front = new QueueNode<QE>(newElement, 0);		// ���ο� ��带 ����� front�� �̰��� ����Ŵ
		rear = front;									// ��尡 �ϳ��̱� ������ rear�� front�� ������ ��带 ����Ŵ
		front->next = rear;
		rear->next = 0;
	}
	else
	{													// �� ��尡 �ƴ� ���
		QueueNode<QE> * tmp = rear;						// rear�� ���� �ӽ� �����Ϳ� �����ϰ�
		rear = new QueueNode<QE>(newElement, 0);		// rear�� ���ο� ��带 ����
		tmp->next = rear;								// �� ��尡 ���Ե� rear�� �ӽ� �����Ϳ� ����� ������ rear�� ����Ŵ
	}


}

//--------------------------------------------------------------------

// ** ��� ���� **
template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently (front) element from a queue and
// returns it.

{
	// pre-lab (Linked)
	if (!empty())							// �� ��尡 �ƴ� ���
	{	
		QueueNode<QE> * tmp = front;		// �ӽ� �����Ϳ� front�� �����ϰ�
		front = front->next;				// front ���� front ���� ��带 ����Ŵ
		return tmp->element;				// �ӽ� �����Ϳ� ������ ����� element�� ����
	}
	else
		cout << "Empty queue" << endl;

}

//--------------------------------------------------------------------

// ** �ʱ�ȭ **
template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.

{
	// pre-lab (Linked)
	while (!empty())					// �� ��尡 �ƴ� ���
	{
		QueueNode<QE> * tmp = front;	// �ӽ� �����Ϳ� front��带 ����
		front = front->next;			// front�� front ������ ��带 ����Ű�� ��
		delete tmp;						// �ӽ� �����Ϳ� ����� ��带 ����
	}

}


//--------------------------------------------------------------------

// ** �� ������� Ȯ�� **
template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	if (front == 0)			// front�� 0�̸� �� ���� ����
		return 1;
	else
		return 0;

}


//--------------------------------------------------------------------

// ** ��� ���� �ð�ȭ�Ͽ� ��� ** 
template < class QE >
void Queue<QE>::showStructure() const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
	// pre-lab (Linked)
	if (empty())								// �� ����� ���
		cout << "Empty queue" << endl;			// �� �޼��� ���

	else                                        // �� ��尡 �ƴ� ��� 
	{
		QueueNode<QE> * tmp = front;			// �ӽ� �����Ϳ� front��带 ����
		while (tmp!=rear)						// �ӽ� �����Ͱ� rear�� ���� ���� ������
		{
			cout << tmp->element << "\t";		// �ӽ� �������� element�� ����ϰ�
			tmp = tmp->next;					// �ӽ� �����Ͱ� �� ���� ��带 ����Ű�� ��
		}
		if (tmp == rear)						// while loop�� ���� ������ tmp == rear�� ����
			cout << tmp->element << endl;		// ��尡 �Ѱ��� ����̱� ������ ���������� �̸� ����ϰ� �Լ� ����
	}

}