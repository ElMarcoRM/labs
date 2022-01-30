#pragma once
#include <iostream>

class Matrix
{
private:// visible only from the class itself
	int col, row;

public:// visible from any place
	double* matr;//our element
	Matrix();
	Matrix(int i, int j);
    void matrix(int i, int j, double* arr);
	void input(int tmp_row, int tmp_col);
	void print();
	void print(double* arr);
	void print(int i);
	int matrixsum(double* matr1, double* matr2, int col1, int rows2);
	void matrixsum(double* matr1);
	int matrixsum(double* matr1, int size);

	int matrixmult(double* matr1, int col1, int rows1, double* matr2, int col2, int rows2);
	int matrixmult(double* matr1, int col1, int rows1); 

	void mult_by_num(int num);

    int get_size();
	int get_columns();
	int get_rows();
	int get_elem(int i, int j);
	int trace();
};

