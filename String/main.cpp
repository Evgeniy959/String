#include"String.h"

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define OPERATOR_PLUS_CHECK
//#define CONSTRUCTORS_CALLING

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	String str;		//Default constructor
	str.print();

	String str1 = "Hello";	//Single argument constructor
	str1.print();
	cout << "str1:" << str1 << endl;
	String str2 = str1;		//Copy constructor
	cout << "str2:" << str2 << endl;

	str = str2;		//Copy assignment
	cout << str << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	str1.print();
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;

	int a = 2;
	a = a;
	cout << a << endl;
#endif // ASSIGNMENT_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;//Operator + будет выполнять конкатенацию (слияние, объединение) строк
	cout << delimiter << endl;
	cout << str3 << endl;
	String str4 = str3;
	cout << str4 << endl;
#endif // OPERATOR_PLUS_CHECK

	//cout << delimiter << endl;
	//str1 += str2;
	//cout << delimiter << endl;
	//cout << str1 << endl;
	//String str3 = str1;//Copy constructor
	//String str4;
	//str4 = str2;	//Operator=

	/*int a = 2;
	int* pa = &a;
	int** ppa = &pa;
	int*** pppa = &ppa;
	cout << ***pppa << endl;*/

#ifdef CONSTRUCTORS_CALLING
	String str;		//Default constructor
	str.print();
	String str1(5);
	str1.print();
	String str2 = "Hello";	//Single-argument constructor
	str2.print();
	String str3("Hello");	//Single-argument constructor
	str3.print();

	String str4();	//Здесь НЕ вызывается конструктор по умолчанию, 
					//здесь объявляется функция str4, которая ничего не принмает, 
					//и возвращает значение типа String.
	//str4.
	String str5;	//Неявный вызов конструктора по умолчанию
	str5.print();
	String str6{};	//Явный вызов конструтора по умолчанию
	str6.print();

	String str7(String str);
	//str7("Hello");
	String("Привет") == str3;	//Явный вызов конструктора для создания временного безымяного объекта.  
#endif // CONSTRUCTORS_CALLING

}