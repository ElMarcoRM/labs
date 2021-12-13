#include <iostream>
using namespace std;
double fact(double a)
{
	double facto = 1;
	for (int i = 2; i <= a; i++)
	{
		facto *= i;
	}
	return facto;
}

void task1()
{
	int n;
	cout << "Enter n.";
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << j;
		}
		cout << endl;
	}
	return;
}

void task2()
{
	double n, k = 0, C;
	cout << "Enter n :" << endl;
	cin >> n;
	C = fact(n);
	while (k <= n)
	{
		double K = C / (fact(n - k) * fact(k));
		cout << K << " ";
		k++;
	}
	return;
}

void task3()
{
	int i, n, num, sum = 0;
	float avg;

	cout << "How many numbers you want to enter : ";
	cin >> n;

	for (i = 1; i <= n; ++i)
	{
		cout << "\nEnter n " << i << " : ";
		cin >> num;

		sum += num;
	}

	avg = (float)sum / (float)n;

	cout << "\nAverage of " << n << " Numbers : " << avg;
	return;
}

int main()
{
	int choice = 0;
	while (true)
	{
		cout << "\n Chouse your Task\n1. Task 1.\n2 Task 2. \n3 Task 3. \n4 EXIT" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:

			task1();
			break;

		case 2:

			task2();
			//break;

		case 3:

			task3();
			break;

		default:

			return 0;
		}
	}
}
