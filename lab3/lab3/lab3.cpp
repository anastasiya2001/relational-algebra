#include <iostream>
#include <vector>

using namespace std;

int search_num(char a, char* x, int n) {
	for (int i = 0; i < n; i++)
		if (x[i] == a)
			return i;
}

bool commutativity(char** mat, int n, char* x) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mat[i][j] != mat[j][i])
				return false;
	return true;
}

bool associativity(char** mat, int n, char* x) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (mat[search_num(mat[i][j], x, n)][k] != mat[i][search_num(mat[j][k], x, n)])
					return false;
	return false;
}

bool idenpotivity(char** mat, int n, char* x) {
	for (int i = 0; i < n; i++) 
			if (mat[i][i] != x[i])
				return false;
	return true;
}

void distributivity(char** peres, char** uni, int n, char* x) {
	int chek = 0;
	int chek2 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				if (uni[search_num(peres[i][j], x, n)][k] = peres[search_num(uni[i][k], x, n)][search_num(uni[j][k], x, n)]) {
					chek++;
				}
				if (peres[search_num(uni[i][j], x, n)][k] = uni[search_num(peres[i][k], x, n)][search_num(peres[j][k], x, n)]) {
					chek2++;
				}
			}
	if (chek > 0) cout << "Решетка объединения является дистрибутивной\n";
	else cout << "Решетка объединения не является дистрибутивной\n";
	if (chek2 > 0) cout << "Решетка пересечения является дистрибутивной\n";
	else cout << "Решетка пересечения не является дистрибутивной\n";
}

void zad1() {
	int n;
	cout << "n=";
	cin >> n;

	cout << "\nВведите элементы:\n";
	char* x = new char[n];
	for (int i = 0; i < n; i++)
		cin >> x[i];

	cout << "\nВведите таблицу Кэли для операции пересечения:\n";
	char** peres = new char* [n];
	for (int i = 0; i < n; i++) {
		peres[i] = new char[n];
		for (int j = 0; j < n; j++) {
			cin >> peres[i][j];
		}
	}
	cout << endl;

	cout << "\nВведите таблицу Кэли для операции объединения:\n";
	char** uni = new char* [n];
	for (int i = 0; i < n; i++) {
		uni[i] = new char[n];
		for (int j = 0; j < n; j++) {
			cin >> uni[i][j];
		}
	}
	cout << endl;

	if (commutativity(peres, n, x))
		cout << "Операция пересечения обладает свойством коммутативности\n";
	else cout << "Операция пересечения не обладает свойством коммутативности\n";
	if (associativity(peres, n, x))
		cout << "Операция пересечения обладает свойством ассоциативности\n";
	else cout << "Операция пересечения не обладает свойством ассоциативности\n";
	if (idenpotivity(peres, n, x))
		cout << "Операция пересечения обладает свойством идемпотентность\n\n";
	else cout << "Операция пересечения не обладает свойством идемпотентность\n\n";

	if (commutativity(uni, n, x))
		cout << "Операция объединения обладает свойством коммутативности\n";
	else cout << "Операция объединения не обладает свойством коммутативности\n";
	if (associativity(uni, n, x))
		cout << "Операция объединения обладает свойством ассоциативности\n";
	else cout << "Операция объединения не обладает свойством ассоциативности\n";
	if (idenpotivity(uni, n, x))
		cout << "Операция объединения обладает свойством идемпотентность\n\n";
	else cout << "Операция объединения не обладает свойством идемпотентность\n\n";

	distributivity(peres, uni, n, x);
}

void uni_bin(int** a, int** a2, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res[i][j] == 1 || a2[i][j] == 1)
				res[i][j] = 1;
				cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	//delete a, a2, res;
}

void pere_bin(int** a, int** a2, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res[i][j] == 1 && a2[i][j] == 1)
				res[i][j] = 1;
			else res[i][j] = 0;
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}

	//delete a, a2, res;
}

void multi_bin(int** a, int** a2, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res[i][j] == 1 && a2[i][j] == 1)
				res[i][j] = 1;
			else res[i][j] = 0;
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}

	//delete a, a2, res;
}

void add_bin(int** a, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res[i][j] == 1)
				res[i][j] = 0;
			else res[i][j] = 1;

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	//delete a, a2, res;
}


void reverse_bin(int** a, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = a[j][i];
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	//delete a, a2, res;
}


void bin_relation() {
	int x = 0;
	cout << "1 - объединение \n2 - пересечение \n3 - произведене \n4 - дополнение \n5 - нахождение обратного" << endl;
	cin >> x;
	if (x == 1 || x == 2 || x == 3) {
		int n;
		cout << "n = ";
		cin >> n;

		int** a;
		a = new int* [n];
		cout << "Введите первую матрицу бинарного отношения:" << endl;
		for (int i = 0; i < n; i++) {
			a[i] = new int[n];
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		int** a2;
		a2 = new int* [n];
		cout << "Введите вторую матрицу бинарного отношения:" << endl;
		for (int i = 0; i < n; i++) {
			a2[i] = new int[n];
			for (int j = 0; j < n; j++) {
				cin >> a2[i][j];
			}
		}
		cout << endl;

		if (x == 1)
			uni_bin(a, a2, n);
		if (x == 2)
			pere_bin(a, a2, n);
		if (x == 3)
			multi_bin(a, a2, n);
	}

	else {
		int n;
		cout << "n = ";
		cin >> n;

		int** a;
		a = new int* [n];
		cout << "Введите матрицу бинарного отношения:" << endl;
		for (int i = 0; i < n; i++) {
			a[i] = new int[n];
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		cout << endl;

		if (x == 4)
			add_bin(a, n);
		if (x == 5)
			reverse_bin(a, n);
	}
	cout << endl;
}

void add_matr(int** a, int** a2, int n, int m, int che) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[m];
		for (int j = 0; j < m; j++) {
			res[i][j] = (a[i][j] + a2[i][j]) % che;
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	//delete a, a2, res;
}

void transponir(int** a, int n, int m, int che) {
	int** res;
	res = new int* [m];
	for (int i = 0; i < m; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = a[j][i];
			cout << res[i][j] % che << ' ';
		}
		cout << endl;
	}

	//delete a, a2, res;
}

void multi_matr(int** a, int** a2, int n, int m, int n2, int m2, int che) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[m];
		for (int j = 0; j < m; j++) {
			res[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m2; j++) {
			for (int k = 0; k < n2; k++) {
				res[i][j] += a[i][k] * a2[k][j];
			}
			cout << res[i][j] % che << ' ';
		}
		cout << endl;
	}

	//delete a, a2, res;
}

void transponir_obr(double** a, double** res, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res[j][i] = a[i][j];
}

void get_matr(vector<vector<int>> a, int n, vector<vector<int>>& temp_matr, int row, int col) {
	int ki = 0;
	for (int i = 0; i < n; i++)
		if (i != row) {
			int kj = 0;
			for (int j = 0; j < n; j++)
				if (j != col) {
					temp_matr[ki][kj] = a[i][j];
					kj++;
				}
			ki++;
		}
}

int Det (vector<vector<int>> a, int n, int che) {
	int temp = 0;
	int k = 1;
	if (n == 1)
		temp = a[0][0];
	else if (n == 2)
		temp = a[0][0] * a[1][1] - a[1][0] * a[0][1];
	else {
		for (int i = 0; i < n; i++) {
			int n2 = n - 1;
			vector<vector<int>> temp_matr(n2);
			for (int j = 0; j < n2; j++)
				temp_matr[j].resize(n2);
			get_matr(a, n, temp_matr, 0, i);
			temp = temp + k * a[0][i] * Det(temp_matr, n2, che);
			k = -k;
		}
	}
	while (temp < 0)
		temp += che;
	temp = temp % che;
	return temp;
}

void appeal(vector<vector<int>> a, int n, int che) {
	double** obr_matr = new double* [n];
	double** tobr_matr = new double* [n];

	for (int i = 0; i < n; i++) {
		obr_matr[i] = new double[n];
		tobr_matr[i] = new double[n];
	}

	int det = Det(a, n, che);
	while (det < 0)
		det = det + che;
	det = det % che;

	cout << "\nОпределитель матрицы = " << det << endl;

	int inv_det;
	for (int i = 1; i < 100000; ++i)
		if ((i * det) % che == 1) {
			inv_det = i;
			break;
		}

	if (det) {
		for (int i = 0; i < n; i++)	{
			for (int j = 0; j < n; j++)	{
				int n2 = n - 1;
				vector<vector<int>> temp_matr(n2);
				for (int k = 0; k < n2; k++)
					temp_matr[k].resize(n2);
				get_matr(a, n, temp_matr, i, j);
				int A = pow(-1.0, i + j + 2) * Det(temp_matr, n2, che);
				while (A < 0)
					A = A + che;
				A = A % che;
				obr_matr[i][j] = A * inv_det;
				obr_matr[i][j] = (int)obr_matr[i][j] % che;
			}
		}
	}
	else
		cout << "Матрица является вырожденной" << endl;

	if (det) {
		transponir_obr(obr_matr, tobr_matr, n);
		cout << "Обратная матрица:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << tobr_matr[i][j] << " ";
			cout << endl;
		}
	}
}

void matrix() {
	int che;
	int x = 0;
	cout << "1 - сложение \n2 - умножение \n3 - транспонирование \n4 - обратная матрица" << endl;
	cin >> x;
	if (x == 1) {
		int n, m;
		cout << "Введите количество строк и столбцов матриц:" << endl;
		cin >> n >> m;

		int** a;
		a = new int* [n];
		cout << "Введите первую матрицу:" << endl;
		for (int i = 0; i < n; i++) {
			a[i] = new int[m];
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		int** a2;
		a2 = new int* [n];
		cout << "Введите вторую матрицу:" << endl;
		for (int i = 0; i < n; i++) {
			a2[i] = new int[m];
			for (int j = 0; j < m; j++) {
				cin >> a2[i][j];
			}
		}
		cout << endl;

		cout << "Введите простое число:";
		cin >> che;
		cout << endl;
		add_matr(a, a2, n, m, che);
	}
	if (x == 2) {
		int n, m, n2, m2;
		cout << "Введите количество строк и столбцов первой матрицы:" << endl;
		cin >> n >> m;

		int** a;
		a = new int* [n];
		cout << "Введите первую матрицу:" << endl;
		for (int i = 0; i < n; i++) {
			a[i] = new int[m];
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		cout << "Введите количество строк и столбцов второй матрицы:" << endl;
		cin >> n2 >> m2;

		int** a2;
		a2 = new int* [n2];
		cout << "Введите вторую матрицу:" << endl;
		for (int i = 0; i < n2; i++) {
			a2[i] = new int[m2];
			for (int j = 0; j < m2; j++) {
				cin >> a2[i][j];
			}
		}
		cout << endl;
		cout << "Введите простое число:";
		cin >> che;
		cout << endl;
		if (m == n2)
			multi_matr(a, a2, n, m, n2, m2, che);
		else cout << "Невозможно выполнить умножение матриц" << endl;
	}
	if (x == 3) {
		int n, m;
		cout << "Введите количество строк и столбцов матрицы:" << endl;
		cin >> n >> m;

		int** a;
		a = new int* [n];
		cout << "Введите матрицу:" << endl;
		for (int i = 0; i < n; i++) {
			a[i] = new int[m];
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		cout << endl;
		cout << "Введите простое число:";
		int che;
		cin >> che;
		cout << endl;
		transponir(a, n, m, che);
	}
	cout << endl;
	if (x == 4) {
		int n;
		cout << "Введите количество строк и столбцов матрицы:" << endl;
		cin >> n;
		vector<vector<int>> a(n);
		cout << "Введите матрицу:" << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
			{
				int m;
				cin >> m;
				a[i].push_back(m);
			}
		}
		cout << "Введите простое число:";
		int che;
		cin >> che;
		cout << endl;
		appeal(a, n, che);
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	for (;;) {
		cout << "1 - Проверка свойств операций \n2 - Операции над бинарными отношениями \n3 - Операции над матрицами \n";
		int x;
		cin >> x;
		switch (x) {
		case 1:
			zad1();
			cout << endl;
			break;
		case 2:
			bin_relation();
			cout << endl;
			break;
		case 3:
			matrix();
			cout << endl;
			break;
		}
	}
}

