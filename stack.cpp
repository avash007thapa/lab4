#include <iostream>
#include <cstddef>
#include "stack.hpp"
using namespace std;

namespace ENSC251_lab4
{
//************************************************************************************************************************************

Stack::Stack() : top(nullptr) //default constructor
    {
    
    } 

//************************************************************************************************************************************

Stack::Stack(const Stack& a_stack) //copy constructor, uses cstddef
    {
        if(a_stack.top == nullptr)
            {
                top = nullptr;
            }
        else
        {
            StackFramePtr temp = a_stack.top;
            StackFramePtr end;

            end = new StackFrame;
            end->data = temp->data;
            top = end;

            temp = temp->link;
            while (temp != nullptr)
            {
                end->link = new StackFrame;
                end = end->link;
                end->data = temp->data;
                temp = temp->link;
            }
            end->link = nullptr;

        }
        
    }

//************************************************************************************************************************************

Stack::~Stack() //destructor
    {
        char next;
        while(!empty()) //if the stack is not empty then only will it remove anything
        {
            next = pop(); //calling pop function to remove item.
        }

    }

//************************************************************************************************************************************

StackFramePtr Stack::gettop()
{
    return top;
}

//******************************************************** PUSH *************************************************************************

void Stack::push(char the_symbol)
    {
        StackFramePtr temp;
        temp = new StackFrame;

        temp->data = the_symbol;
        temp->link = top;
        top = temp;
    }

//********************************************************* POP *************************************************************************

char Stack::pop() // uses iostream
{
    if(empty()) // corner case
    {
        cout << "The Stack is already empty! Cannot Pop an Empty Stack. \n";
        exit(1);
    }

    char result = top->data;

    StackFramePtr temp;
    temp = top;
    top = top->link;

    delete temp;

    return result;
}


//******************************************************** REVERSE **********************************************************************

char Stack::reverse()
{

}

//********************************************************* EMPTY ***********************************************************************

bool Stack::empty() const  //uses cstddef
{
    return (top == nullptr);
}



}
