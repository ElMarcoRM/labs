#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void show_menu()
{
    system("cls");
    cout << "1) One-dimensional array.\n";
    cout << "2) Two-dimensional array \n";
    cout << "3) Exit.\n";
    cout << "Enter the array type: ";
}

int show_tasks()
{
    int c;
    system("cls");
    cout << "Task 0), random array filling.\n";
    cout << "Task 1), manual array input.\n";
    cout << "Task 2), array output.\n";
    cout << "Task 3), digit sum sort.\n";
    cout << "Task 4), last digit sort.\n";
    cout << "Task 5), return to main menu.\n";
    cout << "Choose option: ";
    cin >> c;
    return c;
}

void print_array(int *arr, int line_n, int line_size)
{ // кол-во строк Х размер строки
    for (int i = 0; i < line_n; i++)
    {
        for (int j = i * line_size; j < line_size * (i + 1); j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void input_array(int *arr, int size)
{ //resize
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void rinput_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
}

int sum_check(int a)
{
    string s = to_string(a);
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - '0';
    }
    return sum;
}
int last_char(int a) { return a % 10; }
void sort1(int *arr, int n)
{
    int buffer_int;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
            if (sum_check(arr[j]) > sum_check(arr[j + 1]))
            {
                buffer_int = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer_int;
            }
    }
}
void sort2(int *arr, int n)
{
    int buffer_int;
    bool reverse = false;
    for (int j = 0; j < n - 1; j++)
    {
        if ((last_char(arr[j]) > last_char(arr[j + 1])) and reverse == false)
        {
            buffer_int = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = buffer_int;
        }
        if ((last_char(arr[j]) == last_char(arr[j + 1])) and reverse == false)
        {
            reverse = true;
            j++;
        }
        if (reverse)
        {
            for (int i = 0; i < n - j; i++)
            {
                for (int k = j; k < n; k++)
                    if (last_char(arr[k]) < last_char(arr[k + 1]))
                    {
                        buffer_int = arr[k + 1];
                        arr[k + 1] = arr[k];
                        arr[k] = buffer_int;
                    }
            }
        }
    }
}
int *sort3(int *arr, int size)
{
    cout << "\n";
    int sum = 0, count = 0;
    for (int i = 1; i < size; i += 2)
    {
        count++;
    }
    int *temp = new int[count]{};
    for (int i = 0; i < size; i += 2)
    {
        temp[i / 2] = arr[i + 1];
    }
    sort1(temp, count);
    for (int i = 0; i < size; i += 2)
    {
        arr[i + 1] = temp[i / 2];
    }
    delete[] temp;
    return arr;
}

int main()
{
    int c, n, a_s, b_s;
mmenu:
    show_menu();
    cin >> n;
    if (n == 1)
    {
        cout << "Size: ";
        cin >> a_s;
        int *od_array = new int[a_s]{};
        while (true)
        {
            switch (show_tasks())
            {
            case 1:
                input_array(od_array, a_s);
                system("pause");
                system("cls");
                break;
            case 2:
                print_array(od_array, a_s);
                system("pause");
                system("cls");
                break;
            case 3:
                print_array(od_array, a_s);
                sort3(od_array, a_s);
                print_array(od_array, a_s);
                system("pause");
                system("cls");
                break;
            case 4:
                print_array(od_array, a_s);
                sort2(od_array, a_s);
                print_array(od_array, a_s);
                system("pause");
                system("cls");
                break;
            case 5:
                delete[] od_array;
                goto mmenu;
                break;
            case 0:
                rinput_array(od_array, a_s);
                system("cls");
            }
        }
    }
    if (n == 2)
    {
        cout << "Size: ";
        cin >> a_s >> b_s;
        int *td_array = new int[a_s * b_s]{}; //кол-во строк х кол-во элементов в строке ака столбцов
        while (true)
        {
            switch (show_tasks())
            {
            case 1:
                input_array(td_array, a_s * b_s);
                system("pause");
                system("cls");
                break;
            case 2:
                print_array(td_array, a_s, b_s);
                system("pause");
                system("cls");
                break;
            case 3:
                print_array(td_array, a_s, b_s);
                sort3(td_array, a_s * b_s);
                print_array(td_array, a_s, b_s);
                system("pause");
                system("cls");
                break;
            case 4:
                print_array(td_array, a_s, b_s);
                sort2(td_array, a_s * b_s);
                print_array(td_array, a_s, b_s);
                system("pause");
                system("cls");
                break;
            case 5:
                delete[] td_array;
                goto mmenu;
                break;
            case 0:
                rinput_array(td_array, a_s * b_s);
                system("cls");
            }
        }
    }
    else
        return 0;
}