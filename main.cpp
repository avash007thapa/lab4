#include "stack.hpp"
#include <iostream>
using namespace ENSC251_lab4;
using namespace std;

void printStack(Stack<int> s)
{
    if(s.empty())
    {
        int x = s.gettop()->data;
        s.pop();
        cout << x << "\n";
        printStack(s);
        s.push(x);
    }
}

int main()
{
    Stack<int> s;
    Stack<int> sint1;
    
   // Stack<int> sint2;
    sint1.push(1);
    sint1.push(2);
    sint1.push(3);
    sint1.push(4);
    sint1.push(5);
    sint1.push(6);

    printStack(s);
    return 0;
}