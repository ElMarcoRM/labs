// Laba5.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"

using namespace std;


int main() {
	
	Matrix matrA;
	matrA.input(3);
	Matrix matrB;

	cin >> matrB;

	cout << "matrA:" << endl;
	cout << matrA << endl;

	cout << "matrB:" << endl;
	cout << matrB << endl;

	cout << "matrA += matrB" << endl;
	matrA += matrB;
	cout << matrA << endl;

	cout << "matrA -= matrB" << endl;
	matrA -= matrB;
	cout << matrA << endl;

	cout << "matrA + matrB" << endl;
	cout << matrA + matrB << endl;
	cout << "matrA - matrB" << endl;
	cout << matrA - matrB << endl;
	cout << "-matrA" << endl;
	-matrA;
	cout << matrA << endl;
	cout << "matrA * matrB" << endl;
	cout << matrA * matrB << endl;
	cout << "matrA * 3" << endl;
	cout << matrA * 3 << endl;
	cout << "matrB trace()" << endl;
	cout << matrB.trace() << endl;
}