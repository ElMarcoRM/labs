#include <iostream>
#pragma once
using namespace std;
class Matrix {
private://visible only from the class itself
	short n;
	double* matrix;
public:// visible from any place
	Matrix();//(konctrokter po malchaniyo) accepts noyhing
	Matrix(const Matrix& temp);

	~Matrix();//(destrokter) osvabadjinya pomit
	
	void input();
	void input(int size);// entering the matrix,
	void print() const;// print out the matrix
	short get_columns() const;// the num of col
	double get_elem(short i, short j) const;//return (i,j) element
	void set_elem(short i, short j, double num);
	double trace() const;// trace matrix(the sum of the diagonal elements of a square matrix)
	
	friend istream& operator>>(istream& in, Matrix& matr1);// Перегрузка оператора работает как input()
	friend ostream& operator<<(ostream& out, const Matrix& matr1);//Перегрузка оператора работает как print()
	friend Matrix operator+(const Matrix& matr1, const Matrix& matr2);//Перегрузка оператора сложение матрицы
	friend Matrix operator-(const Matrix& matr1, const Matrix& matr2);//бинарный оператор - поэлементное вычитание
	void operator-();//унарный оператор - у ненулевых элементов меняем знак 
	friend Matrix operator*(const Matrix& matr1, const Matrix& matr2);//бинарный оператор - умножение матриц
	friend Matrix operator*(const Matrix& matr1, const int num);//бинарный оператор - умножение на число 
	void operator+=(const Matrix& matr2);//бинарные операторы += изменить поэлементно текущую матрицу |3 2 4|  |1 3 2|
	void operator-=(const Matrix& matr2);//бинарные операторы -= изменить поэлементно текущую матрицу   |3+1 3+2 4+2|
};

