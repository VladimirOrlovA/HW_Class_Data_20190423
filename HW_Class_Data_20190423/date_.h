#pragma once
#include <iostream>
#include<string>
#include<locale.h>
using namespace std;

class date_
{
private:
	int day;
	int month;
	int year;
	int DaysOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
public:
	date_(int day = 1, int month = 1, int year = 1970);
	
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	
	int getDay() const;
	int getMonth()const;
	int getYear()const;
	
	void addDays(int days);
	void addMonth(int month);
	void addYaers(int years);

	string WhatDay() const;
	string DateInWords() const;

	
	
	friend ostream& operator<<(ostream &os, const date_& d);
	friend istream& operator>>(istream &is, date_ & d);
};

