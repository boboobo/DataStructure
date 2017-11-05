/*
 ----------------------------
 * Name: Hwang Eo Jun
 * Last modified: 2017-10-15
 * content: Calculator
 ----------------------------
*/
#include "stackarr.cpp"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define _Maxname 20

float Calcul(char* postfix);  //this is function which calculate postfix
void main(void)
{
   char post[_Maxname];                //this is array that allocated the character of postfix

   cout << "This is calculator" << endl;
   cout << "Please input the postfix: ";
   cin >> post;                         //save the postfix on post array

   
   cout << "result: ";				//Show the result
   cout.precision(4);
   cout << Calcul(post);
   cout << endl;   
   

   cin >> post;
}

float Calcul(char* postfix)
{
	Stack<float> tmpStack(_Maxname);		// cin�� ���� ������,�ǿ����� ���� �Է��� �޾ƿ�
	Stack<float> testStack(_Maxname);		// tmpStack�� ����� ���� pop�Ͽ� ����
											// tmpStack�� ������ ����� testStack�� �ְ� ��
	Stack<float> testStack2(_Maxname);		// �ӽ÷� ���� �����ϴ� ������ stack
			

	for (int i = 0; i < _Maxname; i++)
	{
		if (postfix[i] == NULL)
			break;
		tmpStack.push(postfix[i]);
	}

	while(!tmpStack.empty())
	{
		testStack.push(tmpStack.pop());
	}

	while (!testStack.empty())
	{
		char tmp = testStack.pop();			// top�� ���� tmp�� �����ϰ�
		testStack.push(tmp);				// top�� ������� �ǵ���


		// Stack�� top�� �����ڰ� �ƴ� ������ ��� testStack2�� push��
		if (tmp != '+' && tmp != '-' && tmp != '*' && tmp != '/')
		{
			char c[1];
			c[0]= testStack.pop();
			float i = atof(c);
			testStack2.push(i);
		}
		// Stack�� top�� �������� ��� testStack2�� �����س��� ���� pop�Ͽ� ����
		// ���� ���� tmpStack�� �Ͻ������� ����ǰ�
		// testStack2�� ���̻� ������ ���� ������ tmpStack�� ���� ���������� testStack�� ����
		// ���������� testStack�� ����� ���� return
		else
		{
			testStack.pop();
			if (tmp == '+')
			{
				if (testStack2.empty() && !tmpStack.empty())
				{
					testStack.push(tmpStack.pop() + tmpStack.pop());
				}
				else
					tmpStack.push(testStack2.pop() + testStack2.pop() );
			}

			else if (tmp == '-')
			{
				if (testStack2.empty() && !tmpStack.empty())
				{
					testStack.push(tmpStack.pop() - tmpStack.pop());
				}
				else
					tmpStack.push(testStack2.pop() - testStack2.pop());
			}

			// �������� ��� testStack���� �����ִ� ���� �Ʒ��� �ִ� ���� ������ �ϹǷ� �ӽú����� ��Ʈ����
			else if (tmp == '/')
			{
				if (testStack2.empty() && !tmpStack.empty())
				{
					float f1 = tmpStack.pop();
					float f2 = tmpStack.pop();
					testStack.push( f2 / f1 );
				}
				else
				{
					float f1 = testStack2.pop();
					float f2 = testStack2.pop();
					tmpStack.push(f2/ f1);
				}
					
			}
			else if (tmp == '*')
			{
				if (testStack2.empty() && !tmpStack.empty())
				{
					testStack.push(tmpStack.pop() * tmpStack.pop());
				}
				else
					tmpStack.push(testStack2.pop() * testStack2.pop());
			}
		}

		// testStack�� ���� �ְ�, testStack2, tmpStack�� ����ִ� ��� ������ ���� ������ �����Ͽ�
		// �ش� ���� �����Ѵ�
		if (testStack.empty() && testStack2.empty())
		{
			return tmpStack.pop();
		}
		else if (!testStack.empty() && testStack2.empty() && tmpStack.empty() )
		{
			return testStack.pop();
		}
			
	}
}