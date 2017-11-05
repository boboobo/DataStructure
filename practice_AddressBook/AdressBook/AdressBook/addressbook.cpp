#include "addressbook.h"

using namespace std;

// ** �ּҷ� ������ **
AddressBook::AddressBook()
{
	initAddressBook();
}

// ** �ּҷ� �Ҹ��� **
AddressBook::~AddressBook()
{
}

// ** �ּҷ� �ʱ�ȭ **
void AddressBook::initAddressBook()
{
	address = new Address[defMaxSize];	// maxSize�� �ּҷ� array ����
	count = 0;							// count ���� 0���� �ʱ�ȭ
}

// ** �ּ� �߰� �Լ� **
void AddressBook::addAddress()
{	
	getline(cin, address[count].name, '\n');			// string ������ �̸�, ��ȭ��ȣ�� getline���� �ް�
	cout << endl << "Enter his(her) name: ";
	getline(cin, address[count].name, '\n');
	cout << endl << "Enter his(her) phone number: ";
	getline(cin, address[count].phoneNo, '\n');
	cout << endl << "Enter his(her) birth year: ";		// ��������� cin���� �޾Ƽ� address ��ü�� ����
	cin >> address[count].birthYear;
	cout << endl << "Enter his(her) birth month: ";
	cin >> address[count].birthMonth;
	cout << endl << "Enter his(her) birth day: ";
	cin >> address[count].birthDay;

	count ++;											// count ���� ����
}

// ** �ּ� ���� �Լ� **
void AddressBook::delAddress()
{
	int j = -1;											// count������ ���ϱ� ���� ���� j
	string name;										// �̸��� �Է¹޾Ƽ� �ش��ϴ� �̸��� �ִ� ��� ����
	getline(cin, name, '\n');
	cout << "Enter the name to delete: ";
	getline(cin, name, '\n');
	
	for (int i=0;  i <= count; i++)
	{
		if (address[i].name == name)					// �Է°��� �̸��� ���� ���
		{
			for (i; i < count; i++)						// �ش� �ε������� Address ��ü�� ��ĭ�� �̵�
			{
				address[i] = address[i + 1];
			}

			count--;									 // �ּ� ī��Ʈ ����
		}
		else
			j++;										// �Է°��� �̸��� �ٸ��� j ���� ����
	}
	if (j == count)
		cout << "There is no such name." << endl;		// count�� j�� ������ �ش� �̸��� �ּҷϿ� ���ٴ� �޽��� ���
}

// ** ���� ������ ��� �Լ� ** 
void AddressBook::displayMonth() const				
{
	int month;
	string monthLetter;
	cout << endl << "Enter Month: ";
	cin >> month;
	int personCount = 0;
	
	for (int i = 0; i < count; i++)
	{
		if (month == address[i].birthMonth)							// �Է°��� ���� ���� ���
		{									
			cout << endl;
			cout << "Name: " << address[i].name << endl;			// �ش� �ּ� ���
			cout << "PhoneNo: " << address[i].phoneNo << endl;
			cout << "BirthDate: " << address[i].birthYear << "/";
			cout << address[i].birthMonth << "/" ;
			cout << address[i].birthDay <<  endl;
			personCount++;											// ������ ���� ī��Ʈ ��
		}
	}

	switch (month)													// ���� �ش��ϴ� ���� ���
	{
	case 1:monthLetter = "January"; break;
	case 2:monthLetter = "Feburary"; break;
	case 3:monthLetter = "March"; break;
	case 4:monthLetter = "April"; break;
	case 5:monthLetter = "May"; break;
	case 6:monthLetter = "June"; break;
	case 7:monthLetter = "July"; break;
	case 8:monthLetter = "August"; break;
	case 9:monthLetter = "September"; break;
	case 10:monthLetter = "October"; break;
	case 11:monthLetter = "November"; break;
	case 12:monthLetter = "December"; break;
	}
	cout << "Total number of birthdays in Month " <<   monthLetter << ": "<< personCount <<  endl;
}

// ** get count : private ���� count ������ �ҷ��� **
int AddressBook::getCount()
{
	return count;
}

// ** Adress ��ü ������ **
Address::Address()
{
	initAddress();
}

// ** Adress ��ü �Ҹ��� **
Address::~Address()
{
	
}

// ** Adress ��ü �ʱ�ȭ **
void Address::initAddress()
{
	char name = 0;
	char phoneNo = 0;
	char birthYear = 0;
	char birthMonth = 0;
	char birthDay = 0;
}

