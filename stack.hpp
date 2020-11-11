#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
    
    template<class c>
    struct StackFrame   //creating a node "StackFrame"
    {
        c data;
        StackFrame<c> *link;
    };
    template<class c>
    typedef StackFrame<c>* StackFramePtr;

    template <class c>
    class Stack 
    {
        public:
            //default constructor
            Stack( );

        //destructor
        ~Stack();

        StackFramePtr gettop();
        void push(int the_symbol);
        int pop( );
        void reverse( );
        void insBottom(int the_symbol);
        bool empty( ) const;

            StackFramePtr gettop();
            void push(char the_symbol);
            c pop( );
            void reverse( );
            void insBottom(char the_symbol);
            bool empty( ) const;

            // friend ostream &operator=(ostream &out, Stack &stackPtr);
    
        private:
            StackFramePtr top;
    };

#endif STACK_H