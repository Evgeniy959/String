#include<iostream>
using namespace std;

#define delimiter "\n---------------------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//Ðàçìåð ñòðîêè â Áàéòàõ
	char* str;	//Óêàçàòåëü íà ñòðîêó â äèíàìè÷åñêîé ïàìÿòè
public:
	int get_size()const
	{
		return size;
	}
	/* v âîçâðàùàåò êîíñòàíòíûé óêàçàòåëü (íåëüçÿ èçìåíèòü çíà÷åíèå ïî àäðåñó)*/
	const char* get_str()const//Ïîêàçûâàåò ÷òî ýòî êîíñòàíòíûé ìåòîä
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//			Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;//Óêàçàòåëü íà íîëü (NULL pointer) - óêàçàòåëü â íèêóäà.
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	//			Methods:
	void print() const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);	//-1 óáèðàåò ëèøíèé íîëü íà êîíöå
	for (int i = 0; i < left.get_size(); i++)
		*(result.get_str() + i) = *(left.get_str() + i);
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
	//		CPU/RAM
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

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

	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;//Operator + áóäåò âûïîëíÿòü êîíêàòåíàöèþ (ñëèÿíèå, îáúåäèíåíèå) ñòðîê
	cout << delimiter << endl;
	cout << str3 << endl;


	//cout << delimiter << endl;
	//str1 += str2;
	//cout << delimiter << endl;
	//cout << str1 << endl;
	//String str3 = str1;//Copy constructor
	//String str4;
	//str4 = str2;	//Operator=

	int a = 2;
	int* pa = &a;
	int** ppa = &pa;
	int*** pppa = &ppa;
	cout << ***pppa << endl;
}