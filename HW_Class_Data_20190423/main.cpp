#include"date_.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	// 20,8,1989
	// 2020 високосный год
	date_ a(35, 13, -2101);
	//a.setDay(29);


	cout << a << a.WhatDay() << "\n\n";
	
	//cin >> a;
	//a.setYear(5);

	//a.addDays(310);
	//a.addMonth(50);
	//a.addYaers(50);

	cout<<a.DateInWords()<<"\n\n";

	//cout << a << a.WhatDay() << "\n\n";

	system("pause");
}