#include <iostream>
#include <cstddef>
#include "stack.hpp"
using namespace std;

namespace ENSC251_lab4
{

//************************************************************************************************************************************
template <class c>
Stack<c>::Stack() : top(nullptr) //default constructor
    {
    
    } 

//************************************************************************************************************************************
template <class c>
Stack<c>::Stack(const Stack& a_stack) //copy constructor, uses cstddef
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
template <class c>
Stack<c>::~Stack() //destructor
    {
        char next;
        while(!empty()) //if the stack is not empty then only will it remove anything
        {
            next = pop(); //calling pop function to remove item.
        }

    }

//***************************************************************************************************************************************

template <class c>
StackFramePtr Stack<c>::gettop()
{
    return top;
}

//******************************************************** PUSH *************************************************************************
template <class c>
void Stack<c>::push(c the_symbol)
    {
        StackFramePtr temp;
        temp = new StackFrame;

        temp->data = the_symbol;
        temp->link = top;
        top = temp;
    }

//********************************************************* POP *************************************************************************
template <class c>
char Stack<c>::pop() // uses iostream
{
    if(empty()) // corner case
    {
        if(empty()) // corner case
        {
            cout << "The Stack is already empty! Cannot Pop an Empty Stack. \n";
            exit(1);
        }

    c result = top->data;

    StackFramePtr temp; // WHERE DOES POPPING GO
    temp = top;
    top = top->link;

        delete temp;

        return result;
    }

}
//******************************************************** REVERSE **********************************************************************
template <class c>
char Stack<c>::reverse()
{

//---------------------------------------------------------------------------------------------------------------------------------------

char Stack::insBottom(char the_symbol)
    {
        string ns;
            if(empty())
            {
                push(the_symbol);
            }
            else
            {
                char a = top->data;
                pop();
                insBottom(the_symbol);
                push(a);
            }
            
    }

//********************************************************* EMPTY ***********************************************************************
template <class c>
bool Stack<c>::empty() const  //uses cstddef
{
    return (top == nullptr);
}



}
