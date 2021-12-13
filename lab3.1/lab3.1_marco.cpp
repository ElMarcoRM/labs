#include <iostream>


using namespace std;

void Task1()
{
    int arr[1000];
    int n;
    cout << "Enter n for the Matrix " << endl;
    cin >> n;
    int A;
    cout << "Enter n to complet the Matrix " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                A = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = A;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "";
    }
    cout << endl;
}

void Sort(char *abc, int n)
{
    const int alp = 26;
    int mat[alp] = {0};
    int base = 'a';
    int j;
    for (int i = 0; i < n; i++)
    {
        j = abc[i] - base;
        mat[j]++;
    }
    int k = 0;
    for (j = 0; j < alp; j++)
    {
        for (int i = 0; i < mat[j]; i++)
        {
            abc[k] = j + base;
            k++;
        }
    }
}

void Task2()
{
    char abc[1000];
    int n;
    cout << "Enter n for the Matrix " << endl;
    cin >> n;
    cout << "Enter n to complete the Matrix " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> abc[i];
    }
    Sort(abc, n);
    for (int i = 0; i < n; i++)
    {
        cout << abc[i];
    }
    cout << endl;
}

int main()
{
    int choise = 0;
    while (true)
    {
        cout << "1) Task 1, int" << endl;
        cout << "2) Task 2, char" << endl;
        cout << "3) EXIT" << endl;
        cout << "Select task: ";
        cin >> choise;
        switch (choise)
        {
        case 1:
        {
            Task1();
            break;
        }
        case 2:
        {
            Task2();
            break;
        }
        case 3:
            return 0;
        default:
            break;
        }
    }
    return 0;
}