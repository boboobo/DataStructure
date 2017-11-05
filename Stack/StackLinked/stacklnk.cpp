//--------------------------------------------------------------------
//
//  Laboratory 5                                        stacklnk.cpp
//
//  SOLUTION: Linked list implementation of the Stack ADT
//
//--------------------------------------------------------------------

#include <assert.h>
// #include <alloc.h>
#include "stacklnk.h"

//--------------------------------------------------------------------

// ** StackNode ������ **
template < class SE >
StackNode<SE>::StackNode(const SE &elem, StackNode<SE> *nextPtr)
// Creates a stack node containing element elem and next pointer
// nextPtr.
: element(elem),
next(nextPtr)
{

}

//--------------------------------------------------------------------

// ** Stack ������ **
template < class SE >
Stack<SE>::Stack(int ignored)
// Creates an empty stack. The parameter is provided for compatability
// with the array implementation and is ignored.
: top(0)
{

}

//--------------------------------------------------------------------

// ** Stack Destructor ** 
template < class SE >
Stack<SE>:: ~Stack()
// Frees the memory used by a stack.
{
	while(!empty())						// �� ��尡 �ƴ� ���
	{
		StackNode<SE> * tmp = top;		// �ӽ� �����Ͱ� top�� ����Ű�� ��
		top = top->next;				// top�� top�� ���� ��带 ����Ŵ
		elementCount--;					// ����� ������ ���� ���� ����
		delete tmp;						// tmp�� ����� ��� ����
	}
}

//--------------------------------------------------------------------

// ** ��� ���� �Լ� **
template < class SE >
void Stack<SE>::push(const SE &newElement)
// Inserts newElement onto the top of a stack.
{
	if (full())								
	{
		cout << "stack is full" << endl;
		return;
	}
	
	if (empty())								 // �� ����� ���
	{
		top = new StackNode<SE>(newElement, 0);  // top�� ���ο� ��带 ����
		elementCount++;
	}				
	
	else
	{
		StackNode<SE> * tmp = top;					// �ӽ� �����Ͱ� ���� top�� ����Ű�� ��
		top = new StackNode<SE>(newElement, tmp);	// top�� ���ο� ��带 ����Ű��, top->next = tmp
		elementCount++;								// // ����� ������ ���� ���� ����
	}

}

//--------------------------------------------------------------------

// ** ��� ���� �Լ� **
template < class SE >
SE Stack<SE>::pop()
// Removes the topmost element from a stack and returns it.
{
	if (empty())
	{
		cout << "empty stack" << endl;
		return 0;
	}
	else                                     // �� ��尡 �ƴ� ���
	{
		StackNode<SE> * tmp = top;			 // �ӽ� ������ tmp�� top�� ����Ű�� ��
		SE tmpElement = top->element;		 // ������ ���� �ӽ� ���� tmpElement�� top�� element���� ���� 
		top = top->next;					 // top�� top�� ���� ��带 ����Ŵ
		elementCount--;						 // ����� ������ ���� ���� ����
		delete tmp;							 // tmp�� ����Ű�� ��� ����
		return tmpElement;					 // �ӽ� ���� tmpElement�� ����� ���� ����
	}
}

//--------------------------------------------------------------------

// ** ��� �ʱ�ȭ �Լ� **
template < class SE >
void Stack<SE>::clear()
// Removes all the elements from a stack.
{
	
	while (!empty())					// �� ��尡 �ƴ� ���� ���� ����
	{
		StackNode<SE> * tmp = top;		// �ӽ� ������ ���� tmp�� top�� ����Ű�� ��
		top = top->next;				// top�� top ���� ��带 ����Ű�� ��
		delete tmp;						// tmp�� ����� ��� ����
	}
}

//--------------------------------------------------------------------

// ** �� ������� Ȯ�� **
template < class SE >
int Stack<SE>::empty() const
// Returns 1 if a stack is empty. Otherwise, returns 0.
{
	if (top == 0)			// top==0�̸� �� ���� ����
		return 1;
	else
		return 0;
}

//--------------------------------------------------------------------

// ** ��尡 �� á���� Ȯ�� **
template < class SE >
int Stack<SE>::full() const
// Returns 1 if a stack is full. Otherwise, returns 0. Cannot be
// done cleanly in generic C++ because there is sometimes overhead
// associated with a memory allocation.
{
	if (elementCount >= defMaxStackSize)	// ** elementCount������ defMaxStackSize �̻��̸� full�� ����
		return 1;
	else
		return 0;
}

//--------------------------------------------------------------------

// ** ��� ���� �ð�ȭ�Ͽ� ��� **
template < class SE >
void Stack<SE>::showStructure() const
// Linked list implementation. Outputs the elements in a stack. If
// the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.
{
	if (empty())							
		cout << "empty stack" << endl;		
	else
	{
		StackNode<SE> *tmp = top;						// �ӽ� ������ ���� tmp�� top�� ����Ŵ
		while (tmp!=0)									// tmp�� 0�� �ƴ� ����
		{
			cout << tmp->element << endl;				// tmp�� element�� ���
			tmp = tmp->next;							// tmp�� tmp�� ���� ��带 ����Ŵ
		}	
	}
}