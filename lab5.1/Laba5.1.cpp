// Laba5.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include "Matrix.h"
int main() {
    Matrix matr_1; // sum matrix
    matr_1.input(2, 3);// create an object of the class
    Matrix matr_2;
    matr_2.input(2, 3);
    matr_1.sum(matr_2.ret_matr(), matr_2.get_rows(), matr_2.get_columns());
    matr_1.print();

   /*Matrix matr_1;// mult matrix
    matr_1.input(2, 3);
    Matrix matr_2;
    matr_2.input(3, 2);
    matr_1.mult(matr_2.ret_matr(), matr_2.get_rows(), matr_2.get_columns());
    matr_1.print();*/ 
    
     /*Matrix matr_1;//trace matrix(the sum of the diagonal elements of a square matrix)
    matr_1.input(3, 3);
    cout << matr_1.trace() << endl; */


    /* Matrix matr_1; // mult matrix by num
    matr_1.input(2, 2);
    matr_1.mult_by_num(4);
    matr_1.print(); */

    /*Matrix matr_1;// num of colms
    matr_1.input(2, 3);
    cout << matr_1.get_columns() << endl;*/

    
    /*Matrix matr_1;// num of rows
    matr_1.input(2, 2);
    cout << matr_1.get_rows() << endl; */

    
    /*Matrix matr_1;//return (i,j) element
    matr_1.input(3, 3);
    cout << matr_1.get_elem(1,2) << endl; */
}
