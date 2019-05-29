#include "date_.h"



date_::date_(int day, int month, int year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

void date_::setDay(int day)
{
	try {
		if (day <= 0)
			throw exception("\n���� �� ����� ���� ���������� ������������� ������, ���� ������ \"0\"..");
	}
	catch (exception&e) {
		cout << "! ������: " << e.what() << "\n����������� �������� �� ��������� - ���� = 1\n\n";
		this->day = 1;
	}

	if (this->year % 4 == 0)
		this->DaysOfMonth[2] = 29;

	try {
		if (day > DaysOfMonth[this->month])
			throw exception("\n�������� �������� ��� ��������� ���-�� ���� � ������������� ������.");
	}
	catch (exception&e) {
		cout << "! ������: " << e.what() << "\n����������� �������� ��� �� ��������� -"
			<< " � ������� ������ " << DaysOfMonth[this->month] << " �. \n\n";
		this->day = DaysOfMonth[this->month];
	}
}

void date_::setMonth(int month)
{
	try {
		if (month <= 0)
			throw exception("\n����� �� ����� ���� ���������� ������������� ������, ���� ������ \"0\".");
	}
	catch (exception&e) {
		cout << "! ������: " << e.what() << "\n����������� �������� �� ��������� - ����� = 1\n\n";
		this->month = 1;
	}
	try {
		if (month > 12)
			throw exception("\n�������� �������� ������ ��������� ���-�� ������� � ����.");
	}
	catch (exception&e) {
		cout << "! ������: " << e.what() << "\n����������� �������� �� ��������� - ����� = 12\n\n";
		this->month = 12;
	}

}

void date_::setYear(int year)
{
	try {
		if (year < 1970) {
			this->year = 1970;
			throw exception("\n������������ �������� ���� ����������� ����������"
				"\n��������� � ��������� ��� = 1970.");
		}
		if (year > 2100)
			this->year = 1970;
		throw exception("\n������������ �������� ���� ����������� �����������"
			"\n��������� � ��������� ��� = 2100.");
	}
	catch (exception&e) {
		cout << "! ������: " << e.what() << "\n����������� �������� �� ��������� - ��� = "
			<< this->year << "\n\n";
	}
}

int date_::getDay() const
{
	return this->day;
}

int date_::getMonth() const
{
	return this->month;
}

int date_::getYear() const
{
	return this->year;
}

void date_::addDays(int days)
{
	if (this->day + days <= this->DaysOfMonth[this->month])
		this->day += days;

	else
	{
		int bufDay;

		bufDay = this->day + days - DaysOfMonth[this->month];
		this->month++;

		while (bufDay >= DaysOfMonth[this->month])
		{
			bufDay -= DaysOfMonth[this->month];
			this->month++;

			if (this->month > 12)
			{
				this->month = 0;
				addYaers(1);
			}
		}
		this->day = bufDay;
	}
}

void date_::addMonth(int month)
{
	if (this->month + month <= 12)
		this->month += month;
	else
	{
		this->month += month;
		do
		{
			this->month -= 12;
			addYaers(1);
		} while (this->month > 12);

		int tmpDay;
		tmpDay = this->day;
		this->day = 0;
		addDays(tmpDay);
	}
}

void date_::addYaers(int years)
{
	if (year == 1) this->year++;
	else
	{
		this->year += years;
		if (this->year >= 2100)
			this->year = 2100;
	}
	if (this->year % 4 == 0)
		this->DaysOfMonth[2] = 29;
	else
		this->DaysOfMonth[2] = 28;
}

string date_::WhatDay() const
{
	int a = (14 - this->month) / 12;
	int y = this->year - a;
	int m = this->month + 12 * a - 2;
	int day = (this->day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

	//string days[7] = { "Sunday","Monday","Tuesday", "Wednesday", "Thursday","Friday", "Saturday" };
	string days[7] = { "�����������","�����������","�������", "�����", "�������","�������", "�������" };

	return days[day];
}

string date_::DateInWords() const
{
	string str = WhatDay() + ',';

	string str1 = " ������";
	string str2 = " ������";
	string str3 = " ������";
	string str4 = " ���������";
	string str5 = " �����";
	string str6 = " ������";
	string str7 = " �������";
	string str8 = " �������";
	string str9 = " �������";

	string str10 = " �������";

	string str11 = " �����������";
	string str12 = " �����������";
	string str13 = " �����������";
	string str14 = " �������������";
	string str15 = " �����������";
	string str16 = " ������������";
	string str17 = " �����������";
	string str18 = " �������������";
	string str19 = " �������������";

	string str20 = " ���������";
	string str30 = " ���������";

	string str21 = " �������";
	string str31 = " ��������";

	string strYear = " ����";

	switch (this->day)
	{
	case 1: {str += str1; }; break;
	case 2: {str += str2; }; break;
	case 3: {str += str3; }; break;
	case 4: {str += str4; }; break;
	case 5: {str += str5; }; break;
	case 6: {str += str6; }; break;
	case 7: {str += str7; }; break;
	case 8: {str += str8; }; break;
	case 9: {str += str9; }; break;
	case 10: {str += str10; }; break;
	case 11: {str += str11; }; break;
	case 12: {str += str12; }; break;
	case 13: {str += str13; }; break;
	case 14: {str += str14; }; break;
	case 15: {str += str15; }; break;
	case 16: {str += str16; }; break;
	case 17: {str += str17; }; break;
	case 18: {str += str18; }; break;
	case 19: {str += str19; }; break;
	case 20: {str += str20; }; break;
	case 21: {str += str21 + str1; }; break;
	case 22: {str += str21 + str2; }; break;
	case 23: {str += str21 + str3; }; break;
	case 24: {str += str21 + str4; }; break;
	case 25: {str += str21 + str5; }; break;
	case 26: {str += str21 + str6; }; break;
	case 27: {str += str21 + str7; }; break;
	case 28: {str += str21 + str8; }; break;
	case 29: {str += str21 + str9; }; break;
	case 30: {str += str30; }; break;
	case 31: {str += str31 + str1; }; break;
	}

	string strM01 = " ������";
	string strM02 = " �������";
	string strM03 = " �����";
	string strM04 = " ������";
	string strM05 = " ���";
	string strM06 = " ����";
	string strM07 = " ����";
	string strM08 = " �������";
	string strM09 = " ��������";
	string strM10 = " �������";
	string strM11 = " ������";
	string strM12 = " �������";

	switch (this->month)
	{
	case 1: {str += strM01; }; break;
	case 2: {str += strM02; }; break;
	case 3: {str += strM03; }; break;
	case 4: {str += strM04; }; break;
	case 5: {str += strM05; }; break;
	case 6: {str += strM06; }; break;
	case 7: {str += strM07; }; break;
	case 8: {str += strM08; }; break;
	case 9: {str += strM09; }; break;
	case 10: {str += strM10; }; break;
	case 11: {str += strM11; }; break;
	case 12: {str += strM12; }; break;
	}

	str += ' ' + to_string(this->year);
	str += strYear;

	return str;
}

ostream & operator<<(ostream & os, const date_ & d)
{
	if (d.month < 10)
		cout << d.day << ".0" << d.month << "." << d.year << endl;
	else cout << d.day << "." << d.month << "." << d.year << endl;
	return os;
}

istream & operator>>(istream & is, date_ & d)
{
	cout << "Entering new date" << endl;
	int date;

	cout << "Year -> ";
	cin >> date;
	d.setYear(date);

	cout << "Month -> ";
	cin >> date;
	d.setMonth(date);

	cout << "Day -> ";
	cin >> date;
	d.setDay(date);

	return is;
}



// �� ok - addDay  addMonth addYear

