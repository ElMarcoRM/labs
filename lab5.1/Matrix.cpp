#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
	this->row = 0;
	this->col = 0;

	this->matrix = nullptr;
}

Matrix::~Matrix()
{
	if (matrix != nullptr)
		delete matrix;
}

int Matrix::get_elem(int i, int j)//return (i,j) element
{
	return this->matrix[i * col + j];
}

void Matrix::print()// print out the matrix
{
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			cout << this->get_elem(i, j);
			cout << endl;
		}
	}
}

void Matrix::input(int tmp_row, int tmp_col)// entering the matrix,
{
	cout << "Enter matrix:\n";
	this->matrix = new int[tmp_row * tmp_col];  
	for (int i = 0; i < tmp_row * tmp_col; i++)
		cin >> *&this->matrix[i];

	this->col = tmp_col;
	this->row = tmp_row;
	cout << endl;
}

int Matrix::get_columns()
{
	return this->col;
}

int Matrix::get_rows()
{
	return this->row;
}

void Matrix::sum(int matrix_2[], int row_2, int col_2)
{
	if ((this->row == row_2) and (this->col == col_2)) {  
		for (int i = 0; i < this->row * this->col; i++) {
			this->matrix[i] += matrix_2[i];
		}
	}
	else {
		std::cout << "MATRIX INCORRECT\n";
	}
}

void Matrix::mult(int matrix_2[], int row_2, int col_2)
{
	if (this->col == row_2) {
		int* res = new int[this->row * col_2];
		int summ = 0;
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < col_2; j++) {
				summ = 0;
				for (int k = 0; k < this->col; k++) {
					summ += this->matrix[i * this->col + k] * matrix_2[k * col_2 + j];
				}
				res[i * col_2 + j] = summ;
			}
		}
		
		delete this->matrix;
		this->matrix = res;
		this->col = col_2;
	}
	else {
		std::cout << "INCORRECT SIZE\n";
	}
}

void Matrix::mult_by_num(double num)
{
	for (int i = 0; i < this->row * this->col; i++)
		*&this->matrix[i] *= num;
}



int Matrix::trace()
{
	if (this->col == this->row) {  
		int summ = 0;
		for (int i = 0; i < this->col; i++) {
			for (int j = 0; j < this->row; j++) {
				if ((i == j) or (j == this->col - i - 1)) {
					summ += this->matrix[i * this->col + j];
					cout << this->get_elem(i, j) << endl;
				}
			}
		}
		return summ;
	}
	else {
		cout << "INCORRECT SIZE\n";
		return -1;
	}
}

int* Matrix::ret_matr()
{
	return &this->matrix[0];
}