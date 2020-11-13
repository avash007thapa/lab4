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
    //typedef StackFrame<c>* StackFramePtr;

    template <class T>
    class Stack 
    {
        typedef StackFrame<T>* StackFramePtr;
        
        public:
            //default constructor
            Stack( ) : top(nullptr) {}

            //copy constructor
            Stack(const Stack& a_stack)
            {
            if(a_stack.top == nullptr) 
                {
                    top = nullptr;
                }
                else 
                {
                    StackFramePtr temp = a_stack.top;
                    StackFramePtr end;

                    end = new StackFrame<T>;
                    end->data = temp->data;
                    top = end;

                    temp = temp->link;
                    while (temp != nullptr) 
                    {
                    end->link = new StackFrame<T>;
                    end = end->link;
                    end->data = temp->data;
                    temp = temp->link;
                    }
                 end->link = nullptr;
                }
            }

            //destructor
            ~Stack()
            {
                T next;
                while(!empty()) //if the stack is not empty then only will it remove anything
                {
                    next = pop(); //calling pop function to remove item.
                }
            }

            StackFramePtr gettop()
            {
                return top;
            }


            void push(T the_symbol)
                {
                    StackFramePtr temp = new StackFrame<T>;

                    temp->data = the_symbol;
                    temp->link = top;
                    top = temp;
                    //cout << "Pushing " << top->data << endl;
                }


            T pop( ) // worst case not empty: 
                {
                    if(empty()) // corner case
                    {
                        cout << "The Stack is already empty! Cannot Pop an Empty Stack. \n";
                        exit(1);
                    }

                    T result;
                    result = top->data; 

                    StackFramePtr temp; // declares temporary variable of StackFramePtr
                    temp = top; // saves the value of current top
                    top = top->link; //changes current top to the next item in the stack
                    
                    // = operator 3N times

                    delete temp; //deletes the top value saved in temp (deletes old top)

                    //cout << "popped " << result << endl;
                    return result;
                }


            void reverse() // assuming N elements in Stack
            {
                 if(!empty()) // ! operator- N cases
                    {
                        T b = top->data; // = operator- runs N times
                        pop(); // pops the top element. how do you count this. 
                        // Runs 3N times 
                       
                        reverse(); // Runs 
                        insBottom(b);
                        
                    }
                    else
                    {
                        //cout<<"This Stack is now empty \n";
                    }

                    //cout << "Stack has been reversed. \n";
            }

            void insBottom(T the_symbol)
            {
                string ns;
                if(empty())
                {
                    push(the_symbol);
                }
                else
                {
                    T a = top->data;
                    pop();
                    insBottom(the_symbol);
                    push(a);
                }
            }


            bool empty( ) const
            {
                return (top == nullptr);
            }

            // friend ostream &operator=(ostream &out, Stack &stackPtr);
    
        private:
            StackFramePtr top;
    };

#endif STACK_H