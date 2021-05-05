#include <iostream>
using namespace std;

// шаблонный класс Матрица
template <typename T>
class MATRIX
{
private:
	T** M; // матрица
	int m; // количество строк
	int n; // количество столбцов

public:
	// конструкторы
	MATRIX()
	{
		n = m = 0;
		M = nullptr; // необязательно
	}

	// конструктор с двумя параметрами
	MATRIX(int _m, int _n)
	{
		m = _m;
		n = _n;

		// Выделить память для матрицы
		// Выделить пам'ять для массива указателей
		M = (T**) new T*[m]; // количество строк, количество указателей

		// Выделить память для каждого указателя
		for (int i = 0; i < m; i++)
			M[i] = (T*)new T[n];

		// заполнить массив M нулями
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = 0;
	}

	// Конструктор копирования - обязательный
	MATRIX(const MATRIX& _M)
	{
		// Создается новый объект для которого виделяется память
		// Копирование данных *this <= _M
		m = _M.m;
		n = _M.n;

		// Выделить память для M
		M = (T**) new T*[m]; // количество строк, количество указателей

		for (int i = 0; i < m; i++)
			M[i] = (T*) new T[n];

		// заполнить значениями
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = _M.M[i][j];
	}

	// методы доступа
	T GetMij(int i, int j)
	{
		if ((m > 0) && (n > 0))
			return M[i][j];
		else
			return 0;
	}

	void SetMij(int i, int j, T value)
	{
		if ((i < 0) || (i >= m))
			return;
		if ((j < 0) || (j >= n))
			return;
		M[i][j] = value;
	}

	// метод, выводящий матрицу
	void Print(const char* ObjName)
	{
		cout << "Object: " << ObjName << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << M[i][j] << "\t";
			cout << endl;
		}
		cout << "---------------------" << endl << endl;
	}

	// оператор копирования - обязательный
	MATRIX operator=(const MATRIX& _M)
	{
		if (n > 0)
		{
			// освободить память, выделенную ранее для объекта *this
			for (int i = 0; i < m; i++)
				delete[] M[i];
		}

		if (m > 0)
		{
			delete[] M;
		}

		// Копирование данных M <= _M
		m = _M.m;
		n = _M.n;

		// Выделить память для M опять
		M = (T**) new T*[m]; // количество строк, количество указателей
		for (int i = 0; i < m; i++)
			M[i] = (T*) new T[n];

		// заполнить значениями
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = _M.M[i][j];
		return *this;
	}

	// Деструктор - освобождает память, выделенную для матрицы
	~MATRIX()
	{
		if (n > 0)
		{
			// освободить выделенную память для каждой строки
			for (int i = 0; i < m; i++)
				delete[] M[i];
		}

		if (m > 0)
			delete[] M;
	}
};

void main()
{
	// тест для класса MATRIX
	MATRIX<int> M(2, 3);
	M.Print("M");

	// Заполнить матрицу значеннями по формуле
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			M.SetMij(i, j, i + j);

	M.Print("M");

	MATRIX<int> M2 = M; // вызов конструктора копирования
	M2.Print("M2");

	MATRIX<int> M3; // вызов оператора копирования - проверка
	M3 = M;
	M3.Print("M3");

	MATRIX<int> M4;
	M4 = M3 = M2 = M; // вызов оператора копирования в виде "цепочки"
	M4.Print("M4");
}