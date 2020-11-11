// driver code belongs here

#include <iostream>
#include "stack.hpp"

using namespace ENSC251_lab4;
//using namespace std;

void printStack(Stack& s)
{
    cout << "This is Print Stack \n";
    if(!s.empty())
    {
        int x = s.gettop()->data;
        s.pop();
        std::cout << x << "\n";
        printStack(s);
        s.push(x);
        
    }
}

int main()
{
    Stack s;
    Stack sint1;
    
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