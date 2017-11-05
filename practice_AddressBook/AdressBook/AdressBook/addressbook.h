#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

const int defMaxSize = 100;			// �ּҷ� ũ��

class AddressBook;

class Address
{
public:
	Address();
	virtual ~Address();
	void initAddress();

private:	
	string name;					// string ���� �̸�, ��ȭ��ȣ
	string phoneNo;
	int birthYear;					// int ���� �������
	int birthMonth;
	int birthDay;

	friend class AddressBook;		// Adressbook�� friend class�� �����Ͽ� �ּҷϿ��� ������ �����
};

class AddressBook				
{
public:
	AddressBook();					// �ּҷ� ������
	virtual ~AddressBook();			// �ּҷ� �Ҹ���
	void initAddressBook();			// �ּҷ� �ʱ�ȭ
	void addAddress();				// �ּ� �߰�
	void delAddress();				// �ּ� ����
	void displayMonth() const;		// ���� ������ ���
	int getCount();					

private:
	int count;
	Address * address;				// �ּҷ��� �ּҸ� ������ ����
	
};



