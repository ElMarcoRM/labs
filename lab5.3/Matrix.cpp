#include "Matrix.h"
using namespace std;

Matrix::Matrix()
{
	this->n = 0;
	this->matrix = nullptr;
}

Matrix::Matrix(const Matrix& temp)
{
	this->n = temp.n;
	this->matrix = new double[3 * this->n];
	for (int i = 0; i < 3 * this->n; i++) {
		this->matrix[i] = temp.matrix[i];
	}
}

Matrix::~Matrix()
{
	if (matrix != nullptr)
		delete matrix;
}

void Matrix::input()
{
	short size;

	cout << "Enter the size of the matrix: ";
	cin >> size;

	if (this->matrix != nullptr) {
		delete[]this->matrix;
	}

	this->n = size;
	this->matrix = new double[3 * size];

	for (int i = 0; i < 3 * size; i++) {
		if (i != size - 1 && i != 2 * size) {
			cin >> this->matrix[i];
		}
	}
	this->matrix[size - 1] = 0;
	this->matrix[2 * size] = 0;
}
void Matrix::input(int size)
{
	this->n = size;

	if (this->matrix != nullptr) {
		delete[]this->matrix;
	}

	this->matrix = new double[3 * size];

	for (int i = 0; i < 3 * size; i++) {
		this->matrix[i] = i + 1;
	}
	this->matrix[size - 1] = 0;
	this->matrix[2 * size] = 0;
}

void Matrix::print() const
{
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->n; j++) {
			cout << this->get_elem(i, j) << "\t";
		}
		cout << endl;
	}
}

short Matrix::get_columns() const
{
	return this->n;
}

double Matrix::get_elem(short i, short j) const
{
	if (i >= 0 && j >= 0 && i < this->n && j < this->n) {
		if (i == j) {
			return this->matrix[this->n + i];
		}
		else if (i == j + 1) {
			return this->matrix[2 * this->n + i];
		}
		else if (i + 1 == j) {
			return this->matrix[i];
		}
		else {
			return 0;
		}
	}
	cout << "\nError.\n";
	return 0;
}

void Matrix::set_elem(short i, short j, double num)
{
	if (i >= 0 && j >= 0 && i < this->n && j < this->n) {
		if (i == j) {
			this->matrix[this->n + i] = num;
		}
		else if (i == j + 1) {
			this->matrix[2 * this->n + i] = num;
		}
		else if (i + 1 == j) {
			this->matrix[i] = num;
		}
	}
}

double Matrix::trace() const
{
	double sumD = 0;
	for (int i = this->n; i < 2 * this->n; i++) {
		sumD += this->matrix[i];
	}
	return sumD;
}
void Matrix::operator+=(const Matrix& matr2)
{
	for (int i = 0; i < 3 * this->n; i++) {
		this->matrix[i] += matr2.matrix[i];
	}
}
void Matrix::operator-=(const Matrix& matr2)
{
	for (int i = 0; i < 3 * this->n; i++) {
		this->matrix[i] -= matr2.matrix[i];
	}
}


std::istream& operator>>(std::istream& in, Matrix& matr1)
{
	short size;

	cout << "Enter the size of the matrix : ";
	in >> size;

	if (matr1.matrix != nullptr) {
		delete[]matr1.matrix;
	}

	matr1.n = size;
	matr1.matrix = new double[3 * size];

	for (int i = 0; i < 3 * size; i++) {
		if (i != size - 1 && i != 2 * size) {
			in >> matr1.matrix[i];
		}
	}
	matr1.matrix[size - 1] = 0;
	matr1.matrix[2 * size] = 0;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matr1)
{
	for (int i = 0; i < matr1.n; i++) {
		for (int j = 0; j < matr1.n; j++) {
			out << matr1.get_elem(i, j) << "\t";
		}
		out << std::endl;
	}
	return out;
}

Matrix operator+(const Matrix& matr1, const Matrix& matr2)
{
	Matrix matrSum(matr2);

	for (int i = 0; i < 3 * matr2.n; i++) {
		matrSum.matrix[i] += matr1.matrix[i];
	}

	return matrSum;
}

Matrix operator-(const Matrix& matr1, const Matrix& matr2)
{
	Matrix matrSum(matr2);

	for (int i = 0; i < 3 * matr2.n; i++) {
		matrSum.matrix[i] -= matr1.matrix[i];
	}

	return matrSum;
}

void Matrix:: operator-()
{

	for (int i = 0; i < 3 * n; i++) {
		matrix[i] *= -1;
	}
}

Matrix operator*(const Matrix& matr1, const Matrix& matr2)
{
	Matrix matrMult(matr2);

	for (int i = 0; i < 3 * matr1.n; i++) {
		matrMult.matrix[i] = 0;
	}

	for (int i = 0; i < matr1.n; i++) {
		for (int j = 0; j < matr2.n; j++) {
			for (int k = 0; k < matr1.n; k++) {
				matrMult.set_elem(i, j, matrMult.get_elem(i, j) + matr1.get_elem(i, k) * matr2.get_elem(k, j));
			}
		}
	}

	return matrMult;
}

Matrix operator*(const Matrix& matr1, const int num)
{
	Matrix matrUmn(matr1);

	for (int i = 0; i < 3 * matrUmn.n; i++) {
		matrUmn.matrix[i] *= num;
	}

	return matrUmn;
}
