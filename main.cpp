// driver code belongs here

#include <iostream>
#include "stack.hpp"
using namespace std;

template<class T>
void printStack(Stack<T> s)
{
    
    if(!s.empty())
    {
        T x = s.gettop()->data;
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
    //Stack<int> sint2;
    
   // Stack<int> sint2;
    sint1.push(1);
    sint1.push(2);
    sint1.push(3);
    sint1.push(4);
    sint1.push(5);
    sint1.push(6);
    sint1.pop();
    //Stack<int> sint2(sint1);

    printStack(sint1);
    // printStack(sint2);

    // sint2.reverse();

    // printStack(sint1);
    // printStack(sint2);
    return 0;
}