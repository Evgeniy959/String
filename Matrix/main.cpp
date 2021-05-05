/*Реадизовать класс , описывающий матрицу,
и обеспечивающий все операции над матрицами :
-determinant()
- operator+
-operator-
-operator* */

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
		M[i][j] = value;
	}
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
		//1 Создаем массив указателей:
			M = new int*[m];
		//2 Выделяем память под строки двумерного массива:
		for (int i = 0; i < m; i++)
			M[i] = new int[n] {};
		// Заполняем массив нулями:
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = 0;
		cout << "Constructor2:\t" << this << endl;
	}
	void Rand() 
	{ 
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = rand()%100;
	}
	void print() 
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << M [i][j] << "\t";
			}
			cout << endl;
		}  
	}

	Matrix(const Matrix& right )
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
	Matrix operator+(const Matrix& right)
	{
		Matrix result(m, n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				result.M[i][j] = M[i][j] + right.M[i][j];
			}
		}
		return result;
	}
	Matrix operator-(const Matrix& right)
	{
		Matrix result(m, n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				result.M[i][j] = M[i][j] - right.M[i][j];
			}
		}
		return result;
	}
	Matrix operator+=(const Matrix& right)
	{
		return *this = *this + right;
	}
	Matrix operator-=(const Matrix& right)
	{
		return *this = *this - right;
	}
	Matrix operator*(const Matrix& right)
	{
		//Matrix M[m][n]{};
		Matrix result(m, n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
					result.M[i][j] += M[i][k] * M[k][j];
			}
		}
		return result;
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

void main()
{
	setlocale(LC_ALL, "");
	int x, y;
	cout << "Введите размер матрицы (количество строк и столбцов):" << endl;
	cin >> x >> y;
	Matrix M(x, y);
	M.Rand();
	M.print();
	Matrix M1(x, y);
	M1.Rand();
	M1.print();
	Matrix M3;
	cout << delimiter << endl;
	M3 = M + M1;
	cout << delimiter << endl;
	M3.print();
	cout << delimiter << endl;
	M3 = M - M1;
	cout << delimiter << endl;
	M3.print();
	M += M1;
	M.print();
	M -= M1;
	M.print();
	cout << delimiter << endl;
	M3 = M * M1;
	cout << delimiter << endl;
	M3.print();

}