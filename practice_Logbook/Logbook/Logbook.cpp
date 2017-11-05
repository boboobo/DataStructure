// Logbook.cpp: implementation of the Logbook class.
//
//////////////////////////////////////////////////////////////////////

#include "Logbook.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// ������ ; ��ü ���� �� ��Ʈ�� �ʱ�ȭ
Logbook::Logbook()
{
	setCurrentTime();
	initEntry();
}

Logbook::~Logbook()
{

}

// ������ ; ��ü ���� �� ��Ʈ�� �ʱ�ȭ, ���� �� �� �Է�
Logbook::Logbook(int month, int year)
{
	setCurrentTime();
	// Implementation here
	this->logMonth = month;
	this->logYear = year;

	initEntry();
}

// ��Ʈ���� �� �Է�
void Logbook::putEntry(int day, int value)
{
	// Implementation here
	entries[day - 1] = value;
}

// ��Ʈ���� ����� �� ���
int Logbook::getEntry(int day) const
{
	// Implementation here
	return entries[day - 1];
}

// �� ���
int Logbook::getMonth() const
{
	// Implementation here
	return logMonth;
}

// ���� ���
int Logbook::getYear() const
{
	// Implementation here
	return logYear;
}

// �ش��ϴ� ���� �ϼ� ���
int Logbook::getDaysInMonth() const
{
	// Implementation here
	if (isLeapYear(logYear) == 1)	// Leap year
		return DaysOfMonth[1][this->logMonth - 1];
	else
		return DaysOfMonth[0][this->logMonth - 1];
}

// ���� ���. �����̸� 1, ����̸� 0 ����
int Logbook::isLeapYear(int year) const
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;		// Leap year
	else
		return 0;		// Normal years
}

// ��Ʈ���� �� �Է�
void Logbook::putEntry(int value)
{
	entries[(currentTime->tm_mday - 1)] = value;
}

void Logbook::setCurrentTime()
{
	// tm structure Used by asctime, gmtime, localtime, mktime, 
	// and strftime to store and retrieve time information.  

	// tm�� ����ü�� �ð� ������ �����ϰ� �ҷ����� ���� asctime, gmtime, localtime, mktime,
	// �׸��� strftime �� ���ؼ� ���˴ϴ�.

	time_t		now;
	time(&now);
	currentTime = localtime(&now);

	logYear = currentTime->tm_year + 1900;
	logMonth = currentTime->tm_mon + 1;
}

// ��Ʈ�� �ʱ�ȭ
void Logbook::initEntry()
{
	int iDays = getDaysInMonth();
	for (int i = 0; i < iDays; i++)
		entries[i] = 0;
}

// ��Ʈ��(�޷�) �ܼ�ȭ�鿡 ���
void Logbook::displayCalendar() const
{
	//In-Lab
	int day = 1;
	cout << "Logbook:" << endl;
	for (day = 1; day <= getDaysInMonth(); day++)
	{
		cout << day << " " << getEntry(day) << '\t';
		if (day % 7 == 0)
			cout << endl;
	}
	cout << endl;
}

// �ش��ϴ� ���� ���� �������� ����
int Logbook::getDayOfWeek(int day) const
{
	tm		when;
	time_t	result;

	when = *currentTime;
	when.tm_mday = day;

	if ((result = mktime(&when)) != (time_t)-1)
	{
		// Implementation here
		when.tm_year = logYear;
		when.tm_mon = logMonth;
		return when.tm_wday;
	}

	else
	{
		// Implementation here
		
		return 0;
	}
}


