// Laba6.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cout << "enter your num" << endl;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > pq;// class for custom datatypes(int,store elements,from the smallest to the greatest 
    for (int i : { 2, 3, 5 }) pq.push(i);// looping a vector which it is initialized with int 2,3,5

    while (n--) {
        int v = pq.top();
        while (pq.top() == v) pq.pop();// we get the first element then we pop it then we find a new top
        cout << v << ' '; // print the elements
        for (int i : { v * 2, v * 3, v * 5}) pq.push(i);// add to our queue just the prime factorization includes only 2,3,5
    }

    return 0;
}
