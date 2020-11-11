// driver code belongs here

#include <iostream>
#include "stack.hpp"
#include "stack.cpp"
using namespace std;

template<class c>
void printStack(Stack<c> s)
{
    cout << "This is Print Stack \n";
    if(!s.empty())
    {
        char x = s.gettop()->data;
        s.pop();
        std::cout << x << "\n";
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
    sint1.reverse();

    printStack(s);
    return 0;
}