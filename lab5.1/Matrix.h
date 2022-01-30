#pragma once
class Matrix
{
private:// visible only from the class itself
	int col, row;
	int* matrix;//our element

public:// visible from any place
	Matrix();//(konctrokter po malchaniyo) accepts noyhing
	~Matrix();  //(destrokter) osvabadjinya pomit

	int get_elem(int i, int j);  //return (i,j) element
	void print();  // print out the matrix
	void input(int tmp_row, int tmp_col);  // entering the matrix,
	int get_columns();  // the num of col
	int get_rows();  //the num of row
	void sum(int matrix_2[], int row_2, int col_2);  // sum of matrix
	void mult(int matrix_2[], int row_2, int col_2);  // mult of matrix
	int trace();  // trace matrix(the sum of the diagonal elements of a square matrix)
	void mult_by_num(double num);  // mult matrix by any num
	int* ret_matr();// return matrix
	
};


