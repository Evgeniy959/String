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
	void set_m(int m)
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
				M[i][j] = rand() % 10;
	}
	void print()
	{
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
	Matrix(Matrix&& right)
	{
		this->M = right.M;
		this->m = right.m;
		this->n = right.m;
		right.M = nullptr;//Указатель на ноль (NULL pointer) - указатель в никуда.
		cout << "MoveConstructor:\t" << this << endl;
	}

	// Операторы:

	Matrix operator=(const Matrix& right)
	{
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
	Matrix& operator=(Matrix&& right)
	{
		if (this == &right)return *this;
		delete[] this->M;
		this->M = right.M;
		this->m = right.m;
		this->n = right.n;
		right.M = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
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
		Matrix result(m, n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
					result.M[i][j] += M[i][k] * right.M[k][j];
			}
		}
		return result;
	}

	~Matrix()
	{
		delete[]M;
		cout << "Destructor:\t\t" << this << endl;
	}
	//Methods:

	void determinant()
	{

		Matrix result(m, n * 2);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				result.M[i][j] = result.M[i][j + n] = M[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n * 2; j++)
			{
				cout << result.M[i][j] << "\t";
			}
			cout << endl;
		}

		if (m == 3 && n == 3)
		{
			int determinant = 0;
			int sum_main_diag = 0;
			int sum_aux_diag = 0;
			for (int i = 0; i < m; i++)
			{
				int product_main = 1;
				int product_aux = 1;
				for (int j = 0; j < n; j++)
				{
					product_main *= result.M[j][j + i];
					product_aux *= result.M[n - 1 - j][j + i];
				}
				sum_main_diag += product_main;
				sum_aux_diag += product_aux;
			}
			cout << "Сумма произведений элементов главной диагонали: " << sum_main_diag << endl;
			cout << "Сумма произведений элементов второстепенной диагонали: " << sum_aux_diag << endl;
			cout << "Определитель: " << (determinant = sum_main_diag - sum_aux_diag) << endl;
		}
		else if (m == 4 && n == 4)
		{
			int determinant = 0;
			int sum_main_diag = 0;
			for (int i = 0; i < m; i++)
			{
				int product_main = 1;
				for (int j = 0; j < n; j++)
				{
					product_main *= result.M[j][j + i];
				}
				sum_main_diag += product_main;
			}
			cout << "Сумма произведений элементов главной диагонали: " << sum_main_diag << endl;
			cout << "Определитель: " << (determinant = -sum_main_diag) << endl;
		}
		else if (m == 2 && n == 2)
		{
			int determinant = 0;
			int diag_1 = 0;
			int diag_2 = 0;
			for (int i = 0; i < m; i++)
			{
				int product_1 = 1;
				int product_2 = 1;
				for (int j = 0; j < n; j++)
				{
					product_1 *= result.M[1 - j][j + i];
					product_2 *= result.M[j][j + i];
				}
				diag_1 = product_1;
				diag_2 = product_2;
			}
			cout << "Произведение первой диагонали: " << diag_1 << endl;
			cout << "Произведение второй диагонали: " << diag_2 << endl;
			cout << "Определитель: " << (determinant = diag_1 - diag_2) << endl;
		}
	}

};
ostream& operator<<(ostream& os, Matrix& obj)
{
	obj.print();
	return os;
}

void main()
{
	setlocale(LC_ALL, "");
	int m, n;
	cout << "Введите размер матрицы М (количество строк и столбцов):" << endl;
	cin >> m >> n;
	Matrix M(m, n);
	M.Rand();
	M.print();
	cout << "Введите размер матрицы М1 (количество строк и столбцов):" << endl;
	cin >> m >> n;
	Matrix M1(m, n);
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
	cout << delimiter << endl;
	M += M1;
	cout << delimiter << endl;
	M.print();
	cout << delimiter << endl;
	M -= M1;
	cout << delimiter << endl;
	M.print();
	cout << delimiter << endl;
	M3 = M * M1;
	cout << delimiter << endl;
	cout << M3 << endl;
	M.determinant();
}