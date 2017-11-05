//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueArr.cpp
//
//  SOLUTION: Array implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queuearr.h"

//--------------------------------------------------------------------

// ** Queue ������ **
template < class QE >
Queue<QE>::Queue(int maxNumber)

// Creates an empty queue. Allocates enough memory for maxNumber
// elements (defaults to defMaxQueueSize).

: maxSize(maxNumber+1),
front(-1),
rear(-1)
{
	element = new QE[maxNumber+1];
}

//--------------------------------------------------------------------

// ** Queue Destructor ** 
template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	delete[] element;
}

//--------------------------------------------------------------------

// ** ���� �Լ� **
template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.

{
	// pre-lab (Array)
	if (empty())							// �� Queue�� ��� 
	{
		rear = (rear + 1) % maxSize;		// rear�� ���� 1 �ø���
		element[rear] = newElement;			// element�� rear�ε����� ���ο� ���� ���� 
		if(front == -1)						// �� ó�� ���α׷��� �����ϴ� ��� front==-1�ε�,
			front = maxSize-1;				// �� ��쿡 front�� �� �� �ε����� ����Ű�� ��
	}

	else if(!full())						// �� Queue�� �ƴ� ���
	{
		rear = (rear + 1) % maxSize;		// rear�� ���� 1 �ø���
		element[rear] = newElement;			// element�� rear�ε����� ���ο� ���� ����
	}

	else
		cout << "Queue is full" << endl;
	
}

//--------------------------------------------------------------------

// ** ���� �Լ� **
template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently added (front) element from a queue and
// returns it.

{
	// pre-lab (Array)
	if (!empty())							// �� Queue�� �ƴ� ���
	{
		front = (front + 1) % maxSize;		// front�� ���� 1�ø���
		return element[front];				// element�� front�ε����� ����
	}										// circular queue�� ��� front�� �� ĭ�� ���� ����ؾ� �ϱ� ������
	else                                    // [front+1]�� �ִ� ���� ���Ǵ� ��
		cout << "Queue is empty" << endl;
}

//--------------------------------------------------------------------

// ** �ʱ�ȭ �Լ� **
template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.

{
	// pre-lab (Array)
	front = -1;					// Array�� �����ϴ� Queue �����̱� ������
	rear = -1;					// �ܼ��� front�� rear�� �ʱⰪ�� -1�� �����ش�.
}

//--------------------------------------------------------------------

// ** �� Queue���� Ȯ�� ** 
template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	// pre-lab (Array)
	return (rear == front);		// rear == front �̸� �� Queue�� ����
}

//--------------------------------------------------------------------

// ** Queue�� �� á���� Ȯ�� ** 
template < class QE >
int Queue<QE>::full() const

// Returns 1 if a queue is full. Otherwise, returns 0.

{
	return ((rear + 1) % maxSize == front);			// rear+1 �� front�� ������ Queue�� full�� ����
}													// circular�̱� ������ %maxszie�� ó��

//--------------------------------------------------------------------

// ** ���� �ð�ȭ�Ͽ� ��� ** 
template < class QE >
void Queue<QE>::showStructure() const

// Array implementation. Outputs the elements in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{

	if (empty())
	{
		cout << "front = " << front << "  rear = " << rear << endl;
		cout << "Empty queue" << endl;
	}
		
	else
	{
		cout << "front = " << front << "  rear = " << rear << endl;

		// pre-lab (Array)
		int tmp = front;									// �ӽ� ���� tmp�� front ���� �����ϰ�
		while (rear != tmp)									// tmp���� rear�� ������ �� ����
		{
			cout << element[(tmp +1) % maxSize] << "\t";	// element�� front�� �ش��ϴ� index�� ���� ���
			tmp = (tmp + 1) % maxSize;						// tmp�� ���� �þ�� front�� dequeue�� ��ó�� index�� ó����
		}
	}
}

// ** Queue�� �� �տ� ���� ���� ** 
template < class QE >
void Queue<QE>::putFront(const QE &newDataItem){
	//In-Lab. 2
	if (empty())							// �� Queue�� ���
	{
		enqueue(newDataItem);				// enqueue�Լ��� ����
	}

	else if (!full())						// �� Queue�� �ƴ� ��� 
	{
		element[front] = newDataItem;		// �� ���� front�� ����
		if (front != 0)						// front�� 0�� �ƴϸ�
			front = (front - 1) % maxSize;	// front�� ���� 1 �ٿ���
		else // front == 0					// front�� 0�̸�
			front = maxSize - 1;			// �ε��� ���� ������ �Ǵ� ���� ���� ���� ���� ��ȯ������ 
	}

	else
		cout << "Queue is full" << endl;
}

// ** Queue�� �� �ڿ��� ���� ���� ** 
template < class QE >
QE Queue<QE>::getRear(){
	//In-Lab. 2
	if (!empty())								// �� Queue�� �ƴ� ���
	{
		int tmp = rear;							// �ӽ� ���� tmp�� rear���� �����ϰ�
		if (rear != 0)							// rear�� 0�� �ƴ� ���
			rear = (rear - 1) % maxSize;		// rear�� ���� 1 �ٿ���
		else // rear == 0						// rear�� 0�̸�
			rear = maxSize - 1;					// �ε��� ���� ������ �Ǵ� ���� ���� ���� ���� ��ȯ������
		return element[tmp];					// �ӽ� ���� tmp�� ������ ��ŭ�� index�� element�� �� ����
	}
	else
		cout << "Queue is empty" << endl;
}

// ** Queue�� ���� ��� ** 
template < class QE >
int Queue<QE>::getLength(){
	//In-Lab. 3

	int len = 0;							//���̸� ������ ���� ���� 

	if (empty())
		cout << "Empty queue" << endl;
	else
	{
		// pre-lab (Array)
		int tmp = front;					// �ӽú��� tmp�� front���� �����ϰ�
		while (rear != tmp)					// tmpr�� rear�� ���� �� ���� ������ ����
		{ 
			len++;							// ������ �� ������(���� ���� ������) ���� 1 ����
			tmp = (tmp + 1) % maxSize;		// tmp���� 1�� ������Ű�� rear�� �ٰ���
		}
	}

	return len;								// len�� ����� ���̸� ����
}
