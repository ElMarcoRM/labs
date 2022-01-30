#include "Matrix.h"
using namespace std;


Matrix::Matrix()
{
	this->row = 0;
	this->col = 0;

	this->matr = nullptr;
}

Matrix::Matrix(int i, int j)
{
	col = i, row = j;
	matr = new double[i * j]{ 0 };
}
void Matrix::matrix(int i, int j, double* arr) {
	col = i, row = j;
	matr = new double[i * j];
	for (int i = 0; i < row * col; i++) {
		matr[i] = arr[i];
	}
}

void Matrix::input(int tmp_row, int tmp_col)
{
	std::cout << "Enter matrix:\n";
	this->matr = new double[tmp_row * tmp_col];
	for (int i = 0; i < tmp_row * tmp_col; i++)
		cin >> *&this->matr[i];

	this->col = tmp_col;
	this->row = tmp_row;
	cout << endl;
}

void Matrix::print()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << matr[i * (col)+j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Matrix::print(double* arr)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << arr[i * (col)+j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Matrix::print(int i)
{
}

int Matrix::matrixsum(double* matr1, double* matr2, int col1, int rows2)
{
	if (col1 != rows2) return 0;
	matr = new double[col1 * rows2];
	col = col1; row = rows2;
	for (int i = 0; i < col1 * rows2; i++) {
		matr[i] = matr1[i] + matr2[i];
	}
	return 1;
}

void Matrix::matrixsum(double* matr1)
{
	for (int i = 0; i < this->get_size(); i++) {
		matr[i] += matr1[i];
	}
}

int Matrix::matrixsum(double* matr1, int size)
{
	if (this->get_size() != size) return 0;
	for (int i = 0; i < size; i++) {
		matr[i] += matr1[i];
	}
	return 1;
}

int Matrix::matrixmult(double* matr1, int col1, int rows1, double* matr2, int col2, int rows2)
{
	if (col1 == rows2) {
		col = col2; row = rows1;
		matr = new double[rows1 * col2];
		for (int i = 0; i < rows1; i++)
			for (int j = 0; j < col2; j++)
			{
				matr[i * col2 + j] = 0;
				for (int k = 0; k < col1; k++)
					matr[i * col2 + j] += matr1[i * col1 + k] * matr2[k * col2 + j];
			}
		return 0;
	}
	else {
		std::cout << "Error of mult: sizes are not equal.";
		col = row = 0;
		return 1;
	}
}

int Matrix::matrixmult(double* matr1, int col1, int rows1)
{
	if (col == rows1) {
		double* temp_matr = new double[rows1 * col]{ 0 };

		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < col; j++) {
				temp_matr[i * col1 + j] = 0;
				for (int k = 0; k < col; k++)
					temp_matr[i * col + j] += matr1[i * col + k] * matr[k * col1 + j];
			}
		}
		matr = new double[rows1 * col];
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < col; j++) {
				matr[i * col + j] = temp_matr[i * col + j];
			}
		}
		return 0;
		row = rows1;
	}
	else {
		std::cout << "Error of mult: sizes are not equal.";
		return 1;
	}
}

void Matrix::mult_by_num(int num)
{
	for (int i = 0; i < row * col; i++) {
		matr[i] *= num;
	}
	std::cout << "Multiplied by " << num << ".\n\n";
}



int Matrix::get_size()
{
	return col * row;
}

int Matrix::get_columns()
{
	return col;
}

int Matrix::get_rows()
{
	return row;
}

int Matrix::get_elem(int i, int j)
{
	return matr[i * col + j];
}

int Matrix::trace()
{
	int sum = 0;
	int diag = this->get_size() / 2;
	for (int i = 0; i < diag; i++) {
		sum += matr[i * diag];
	}
	return sum;
}






