#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int main()
{

     /* task 1 */

     string name = "Marco Antonio Rojas Miranda 211-353 ";

     cout << name << endl;

     /* task 2 */

     cout << '\n'
          << '\n';

     /* int */
     cout << "min int:" << numeric_limits<int>::min() << endl;

     cout << "max int:" << numeric_limits<int>::max() << endl;

     cout << "size of int:" << sizeof(int) << endl;

     /* short*/

     cout << "min short:" << numeric_limits<short>::min() << endl;

     cout << "max short:" << numeric_limits<short>::max() << endl;

     cout << "size of short:" << sizeof(short) << endl;

     /* unsigned int */

     cout << "min  unsigned int:  " << numeric_limits<unsigned int>::min() << endl;

     cout << "max  unsigned int:  " << numeric_limits<unsigned int>::max() << endl;

     cout << "size of unsigned int=" << sizeof(unsigned int) << endl;

     /* short */

     cout << "min short:" << numeric_limits<short>::min() << endl;

     cout << "max short:" << numeric_limits<short>::max() << endl;

     cout << "size of short:" << sizeof(short) << endl;

     /* unsigned short */

     cout << "min  unsigned short:  " << numeric_limits<short>::min() << '\n';

     cout << "max  unsigned short:  " << numeric_limits<short>::max() << '\n';

     cout << "of unsigned short=" << sizeof(short) << endl;

     /* long */

     cout << "min long:" << numeric_limits<long>::min() << endl;

     cout << "max long:" << numeric_limits<long>::max() << endl;

     cout << "size of long:" << sizeof(long) << endl;

     /* long long */

     cout << "min long long:" << numeric_limits<long long>::min() << endl;

     cout << "max long long:" << numeric_limits<long long>::max() << endl;

     cout << "size of long long:" << sizeof(long long) << endl;

     /* double */

     cout << "min double:" << numeric_limits<double>::min() << endl;

     cout << "max double:" << numeric_limits<double>::max() << endl;

     cout << "size of double:" << sizeof(double) << endl;

     /* char */

     cout << "min char:" << numeric_limits<char>::min() << endl;

     cout << "max char:" << numeric_limits<char>::max() << endl;

     cout << "size of char:" << sizeof(char) << endl;

     /* bool */

     cout << "min bool:" << numeric_limits<bool>::min() << endl;

     cout << "max bool:" << numeric_limits<bool>::max() << endl;

     cout << "size of bool:" << sizeof(bool) << endl;

     /* task 3 */

     cout << '\n'
          << '\n';

     cout << "введите число" << endl;

     int number;

     cin >> number;

     bitset<16> bs1(number);
     cout << "в бинарном виде:" << bs1 << endl;

     stringstream stream;
     stream << std::hex << number;
     string result(stream.str());
     cout << "в шестнадцатиричном виде:" << result << endl;

     bool bi = !!number;
     cout << "bool:  " << bi << endl;

     double d = (double)number;
     cout << "double:  " << d << endl;

     char charValue = number;
     cout << "char:  " << charValue << endl;

     /* task 4 */

     cout << '\n'
          << '\n';

     int a; 
     int b;
     float x;
     cout << "введите коэффициенты a * x = b " << endl;
     cout << "введите коэффициент a:" << endl;
     cin >> a;
     if (a < 1)
     {

          cout << "а должно быть больше 0" << endl;
     }
     else
     {

          cout << "введите коэффициент b:" << endl;
          cin >> b;
          x = (double(b) / double(a));

          cout << a << "*"
               << "x"
               << "=" << b << endl;

          cout << "x"
               << "=" << b << "/" << a << endl;

          cout << "x"
               << "=" << double(x) << endl;
     }

     /* task 5 */
     {
          int a, b;
          cout << "введите координаты отрезка на прямой:" "";
          cin >> a >> b;
          cout << "середина отрезка находится в точке с координатой" << (double(a) + double(b)) / 2 << endl;
     }

     system("pause");
     return 0;
}