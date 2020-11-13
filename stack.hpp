#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstddef>
#include <string>

using namespace std;
    
    template<class T>
    struct StackFrame   //creating a node "StackFrame"
    {
        T data;
        StackFrame *link;
    };
    
    template <typename T> 
    using StackFramePtr = StackFrame<T>*;

    template <class T>
    class Stack 
    {
        // typedef StackFrame<T>* StackFramePtr;
        
        public:
            //default constructor
            Stack( );

            //copy constructor
            Stack(const Stack<T>& a_stack);

            //destructor
            ~Stack();

            StackFramePtr<T> gettop() const;


            void push(T the_symbol);


            T pop( ); // worst case not empty: 


            void reverse(); // assuming N elements in Stack
            

            void insBottom(T the_symbol);


            bool empty( ) const;

            // friend ostream &operator=(ostream &out, Stack &stackPtr);
    
        private:
            StackFramePtr<T> top;
    };

#endif 