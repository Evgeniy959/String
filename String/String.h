#pragma once
#pragma warning(disable:4326)
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------------\n"

/////////////////////////////////////////////////////////////////////////////////////////////////
//////////////				CLASS DECLARATION - ОБЪЯВЛЕНИЕ КЛАССА				/////////////////

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);
bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);

class String
{
	int size;	//Размер строки в Байтах
	char* str;	//Указатель на строку в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//			Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators:
	String& operator=(const String& other);
	String& operator+=(const String& other);

	//			Methods:
	void print() const;
};

//////////////						CLASS DECLARATION END						/////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////