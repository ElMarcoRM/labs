#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
//P.S внёс изменения после загрузки из powershell'а, смутило выделение массивов str_*[] при просмотре из github'а, сменил названия с str_s -> str_source, str_t -> str_target
bool palindrome(char *text);
int show_tasks();
void find_substring(char *source_str, char *substring_str);
void print_arr(int *arr, int n);
void cesar(char *source_str);
void q_output(char *source_str);

int main()
{
    char text[255]{'0'};
    char str_source[100];
    char str_source1[100];
    char str_target[100];
    cout << "Enter string and substring for tasks 2-4:\n";
    cin.getline(str_source, 100);
    cin.getline(str_target, 100);
    strcpy(str_source1, str_source);
mmenu:
    while (true)
    {
        switch (show_tasks())
        {
        case 0:
            goto mmenu;
            break;
        case 1:
            system("cls");
            if (palindrome(text))
                cout << "This C-string is a palindrome\n";
            else
                cout << "This C-string is not a palindrome\n";
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            find_substring(str_source, str_target);
            system("pause");
            system("cls");
            break;
        case 3:
            cesar(str_source1);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            q_output(str_source);
            system("pause");
            system("cls");
            break;
        case 5:
            return 0;
            break;
        }
    }
}

//function sector
void cesar(char *source_str)
{
    int k;
    cout << "Enter the shift offset: ";
    cin >> k;
    cout << source_str << endl;
    for (int i = 0; i < strlen(source_str); i++)
    {
        if (source_str[i] == 'z')
            source_str[i] = 'a' + k - 1; //смещение на указанный key, если не а, иначе уход в начало алфавита и сдвиг на key - 1
        else
            source_str[i] += k;
    }
    cout << source_str << endl;
}
bool palindrome(char *text)
{
    cout << "Enter your text, ending with '.':\n";
    int i = 0;
    char buff;
    while (true)
    {
        cin >> buff;
        if (buff == '.')
            break;
        else
        {
            text[i] = buff;
            i++;
        }
    }
    bool match = true;
    for (int i = 0, j = strlen(text) - 1; i < j; i++, j--)
    {
        if ((char)tolower(text[i]) != (char)tolower(text[j]))
            match = false;
    } //сравнение чаров с изменением маркера совпадения
    if (match)
        return true;
    else
        return false;
}
int show_tasks()
{
    int c;
    system("cls");
    cout << "Task 1), palindrome check.\n";
    cout << "Task 2), substring search.\n";
    cout << "Task 3), CESAR.\n";
    cout << "Task 4), inside quotes output.\n";
    cout << "Task 5), exit.\n";
    cout << "Choose option: ";
    cin >> c;
    return c;
}
void find_substring(char *source_str, char *substring_str)
{
    int *occ_arr = new int[100];
    char buffer[100];
    strcpy(buffer, source_str);
    for (int i = 0; i < strlen(buffer); i++)
    {
        cout << buffer[i];
    }
    cout << endl;
    for (int i = 0; i < strlen(substring_str); i++)
    {
        cout << substring_str[i];
    }
    cout << endl;
    char *itr_str;
    int i = 0;
    int pos;
    while (true)
    {
        itr_str = strstr(buffer, substring_str); //запись указателя найденую подстроку в строке
        if (itr_str == NULL)
            break;
        pos = itr_str - buffer + 1;
        if (pos > 0)
            occ_arr[i] = pos;
        i++;
        for (int j = 0; j < strlen(substring_str); j++)
        {
            buffer[(pos - 1) + j] = 'a';
        }
    }                      //замена найдённой подстроки
    print_arr(occ_arr, i); // вывод (!) позиции в массиве (не индекса) начала подстроки
    delete[] occ_arr;
}
void q_output(char *source_str)
{
    for (int i = 0; i < strlen(source_str); i++)
    {
        cout << source_str[i];
    }
    cout << endl;
    bool inside = false;
    for (int i = 0; i < strlen(source_str); i++)
    {
        if (source_str[i] == '"' and inside == false)
        { // детектор отк. кавычки
            i++;
            inside = true;
        }
        if (inside)
        { //вывод до получения зак. кавычки
            do
            {
                cout << source_str[i];
                i++;
            } while (source_str[i] != '"');
            inside = false;
            cout << endl;
        }
    }
}
void print_arr(int *arr, int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}
