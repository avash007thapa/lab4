 #ifndef STACK_H
 #define STACK_H
 
 
 #include <iostream>
 using namespace std;
 
 namespace ENSC251_lab4
 {
    struct StackFrame   //creating a node "StackFrame"
        {
            char data;
            StackFrame *link;
        };
    typedef StackFrame* StackFramePtr;

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
            void push(char the_symbol);
            char pop( );
            char reverse( );
            bool empty( ) const;

            // friend ostream &operator=(ostream &out, Stack &stackPtr);
    
        private:
            StackFramePtr top;
    };
 }

 #endif STACK_H