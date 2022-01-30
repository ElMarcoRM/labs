// Laba5.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Matrix.h"


int main() {
	Matrix matr1;
	matr1.input(3, 3);
	matr1.print();

	Matrix matr2;
	matr2.input(3, 3);
	matr2.print();

	Matrix matr3;
	matr3.matrix(3, 3, matr1.matr);
	matr3.matrixsum(matr2.matr);
	matr3.print();

	matr2.matrixmult(matr1.matr, matr1.get_columns(), matr1.get_rows());
	matr2.print();

	matr3.mult_by_num(4);
	matr3.print();

	std::cout << matr1.trace() << std::endl;
}
