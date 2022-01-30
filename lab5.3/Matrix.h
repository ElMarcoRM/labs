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
	
	friend istream& operator>>(istream& in, Matrix& matr1);// ���������� ��������� �������� ��� input()
	friend ostream& operator<<(ostream& out, const Matrix& matr1);//���������� ��������� �������� ��� print()
	friend Matrix operator+(const Matrix& matr1, const Matrix& matr2);//���������� ��������� �������� �������
	friend Matrix operator-(const Matrix& matr1, const Matrix& matr2);//�������� �������� - ������������ ���������
	void operator-();//������� �������� - � ��������� ��������� ������ ���� 
	friend Matrix operator*(const Matrix& matr1, const Matrix& matr2);//�������� �������� - ��������� ������
	friend Matrix operator*(const Matrix& matr1, const int num);//�������� �������� - ��������� �� ����� 
	void operator+=(const Matrix& matr2);//�������� ��������� += �������� ����������� ������� ������� |3 2 4|  |1 3 2|
	void operator-=(const Matrix& matr2);//�������� ��������� -= �������� ����������� ������� �������   |3+1 3+2 4+2|
};

