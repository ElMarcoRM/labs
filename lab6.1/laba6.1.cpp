
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool skobok(string expr)
{
    stack<char> s;
    char x;
    
    for (int i = 0; i < expr.length(); i++)// Traversing the Expression
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            s.push(expr[i]);// Push the element in the stack
            continue;
        }

        
        if (s.empty())
        return false;
              
        switch (expr[i]) {
        case ')':
            
            x = s.top();// Store the top element
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            x = s.top();// Store the top element
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            x = s.top();// Store the top element
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    return (s.empty());// Check Empty Stack
}


int main()
{
    string expr;
    cout << "Enter your Text" << endl;
    cin >> expr;
    
    if (skobok(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
