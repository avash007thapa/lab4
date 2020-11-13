#include <iostream>
#include <cstddef>
#include <string>
#include "stack.hpp"
using namespace std;

//************************************************************************************************************************************
    template <class T>
    Stack<T>::Stack() : top(nullptr) {   } //default constructor

//************************************************************************************************************************************
    template <class T>
    Stack<T>::Stack(const Stack<T>& a_stack) //copy constructor, uses cstddef
    {
        if(a_stack.top == nullptr) 
                {
                    top = nullptr;
                }
                else 
                {
                    StackFramePtr<T> temp = a_stack.top;
                    StackFramePtr<T> end;

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

//**************************************************************************************************************************************
    template <class T>
    Stack<T>::~Stack()
    {
                T next;
                while(!empty()) //if the stack is not empty then only will it remove anything
                {
                    next = pop(); //calling pop function to remove item.
                }
            }

//**************************************************************************************************************************************
    template <class T>
    StackFramePtr<T> Stack<T>::gettop() const{
                return top;
            }

//******************************************************** PUSH *************************************************************************
    template <class T>
    void Stack<T>::push(T the_symbol){
                    StackFramePtr<T> temp = new StackFrame<T>;

                    temp->data = the_symbol;
                    temp->link = top;
                    top = temp;
                    //cout << "Pushing " << top->data << endl;
                }

//********************************************************* POP *************************************************************************
    template <class T>
    T Stack<T>::pop()
    {
                    if(empty()) // corner case
                    {
                        cout << "The Stack is already empty! Cannot Pop an Empty Stack. \n";
                        exit(1);
                    }

                    T result;
                    result = top->data; 

                    StackFramePtr<T> temp; // declares temporary variable of StackFramePtr
                    temp = top; // saves the value of current top
                    top = top->link; //changes current top to the next item in the stack
                    
                    // = operator 3N times

                    delete temp; //deletes the top value saved in temp (deletes old top)

                    //cout << "popped " << result << endl;
                    return result;
                }

//******************************************************** REVERSE ***************************************************************
    template <class T>
    void Stack<T>::reverse()
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

//********************************************************** HELPER FUNCTION FOR REVERSE *****************************************
    template <class T>
    void Stack<T>::insBottom(T the_symbol)
    {
        //string ns;
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

//********************************************************* EMPTY ****************************************************************
    template <class T>
    bool Stack<T>::empty() const       //uses cstddef
    {
        return (top == nullptr);
    }

//********************************************************* EMPTY ***********************************************************************

    template <class T>
    const Stack<T> &Stack<T>::operator=(const Stack<T>& a_stack)
    {
        cout << "Assignment running\n";
        if(a_stack.top == nullptr) 
                {
                    top = nullptr;
                }
                else 
                {
                    StackFramePtr<T> temp = a_stack.top;
                    StackFramePtr<T> end;

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
        return *this;
    }



