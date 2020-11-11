#ifndef STACK_H
#define STACK_H
 
#include <iostream>
using namespace std;
   
struct StackFrame   //creating a node "StackFrame"
{
    char data;
    StackFrame *link;
};
typedef StackFrame* StackFramePtr;

//template <class c>
class Stack 
{
    public:
        //default constructor
        Stack( );

        //copy constructor
        Stack(const Stack& a_stack);

        //destructor
        ~Stack();

        StackFramePtr gettop();
        void push(int the_symbol);
        int pop( );
        void reverse( );
        void insBottom(int the_symbol);
        bool empty( ) const;

        // friend ostream &operator=(ostream &out, Stack &stackPtr);

    private:
        StackFramePtr top;
};
 

#endif STACK_H