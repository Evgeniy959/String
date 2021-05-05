#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------------\n"
#define tab "\t"

class Matrix
{
	int** M;
	int m; //Количество строк
	int n; //Количество элементов строки
public:
	int get_M()const
	{
		return **M;
	}
	int get_m()const
	{
		return m;
	}
	int get_n()const
	{
		return n;
	}
	void set_M(int i, int j, int value)
	{
		/*if ((i < 0) || (i >= m))
			return;
		if ((j < 0) || (j >= n))
			return;*/
		M[i][j] = value;
	}
	/*void set_M(int M)
	{
		this->M = *M;
	}*/
	void set_m(int M)
	{
		this->m = m;
	}
	void set_n(int n)
	{
		this->n = n;
	}

	//           Consctructors:
	Matrix()
	{
		m = n = 0;
		M = 0;

		cout << "Constructor0:\t" << this << endl;
	}

	Matrix(int m, int n)
	{
		this->m = m;
		this->n = n;
		/*M = (int**) new int*[m]; // количество строк, количество указателей

		for (int i = 0; i < m; i++)
			M[i] = (int*) new int[n];*/
			//1 Создаем массив указателей
		M = new int*[m];
		//2 Выделяем память под строки двумерного массива
		for (int i = 0; i < m; i++)
			M[i] = new int[n] {};
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = 0;
		cout << "Constructor2:\t" << this << endl;
	}
	void Rand()
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = rand() % 100;
	}
	void print()
	{
		//cout << "Object: " << Obj << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << M[i][j] << "\t";
			}
			cout << endl;
		}
	}

	Matrix(const Matrix& right)
	{
		m = right.m;
		n = right.n;
		M = new int*[m];
		for (int i = 0; i < m; i++)
		{
			M[i] = new int[n] {};
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				M[i][j] = right.M[i][j];
			}
		}
		cout << "CopyConstructor:\t" << this << endl;
	}

	// операторы:

	Matrix operator=(const Matrix& right)
	{
		/*if (m != right.m || n != right.n)
		{
			cout << "Массивы разного размера!\n";
			return *this;
		}*/
		delete[] this->M;
		m = right.m;
		n = right.n;
		M = new int*[m];
		for (int i = 0; i < m; i++)
		{
			M[i] = new int[n] {};
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				M[i][j] = right.M[i][j];
			}
		}
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	~Matrix()
	{
		delete[]M;
		cout << "Destructor:\t\t" << this << endl;
		/*if (n > 0)
		{
			// освободить выделенную память для каждой строки
			for (int i = 0; i < m; i++)
				delete[] M[i];
		}

		if (m > 0)
			delete[] M;
		cout << "Destructor:\t\t" << this << endl;*/
	}

};

Matrix operator+(const Matrix& left, const Matrix& right)
{
	int m1 = left.get_m();
	int n1 = left.get_n();
	Matrix result (m1, n1);
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			result.set_M[i][j] = left.get_M[i][j]() + right.get_M[i][j]();
		}
		cout << endl;
	}
	return result;
}
/*ostream& operator<<(ostream& os, const Matrix& obj)
{
	int m, int n;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				os << obj.get_M[i][j] << "\t";
				//os << obj[i][j] << "\t";
			}
			cout << endl;
		}

	//return os << obj.get_M();
}*/

void main()
{
	setlocale(LC_ALL, "");
	int x, y;
	cout << "Введите размер матрицы (количество строк и столбцов):" << endl;
	cin >> x >> y;
	Matrix M(x, y);
	//cout << M << endl;
	M.Rand();
	M.print();
	Matrix M1(x, y);
	M1.Rand();
	M1.print();
	Matrix M3;
	cout << delimiter << endl;
	M3 = M + M1;
	cout << delimiter << endl;
	//cout << "M3" << endl;
	M3.print();
}