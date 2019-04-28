#include"date_.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	// 20,8,1989
	date_ a(29, 4, 2019);
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