#include <iostream>
#include <cstddef>
#include <string>
#include "stack.hpp"
using namespace std;

//*********************************************** DEFAULT CONSTRUCTOR ****************************************************************
    template <class T>
    Stack<T>::Stack() : top(nullptr) {   } //initializes Top variable to Nullptr


//************************************************* COPY CONSTRUCTOR *****************************************************************
    template <class T>
    Stack<T>::Stack(const Stack<T>& a_stack) //copy constructor, uses cstddef
    {
        try{
            if(a_stack.top == nullptr) {
                top = nullptr; //initializing top to nullptr if a_stack.top is also nullptr
            }
            else {
                StackFramePtr<T> temp = a_stack.top; // storing a_stack top into temporary variable which moves through a_stack from top to bottom
                StackFramePtr<T> end; // declaring end of the newly created stack

                end = new StackFrame<T>;  //creates the first node and copies data from original stack then creates rest of the nodes after.
                end->data = temp->data;
                top = end;

                temp = temp->link; //sets temp to next node in the a_stack
                while (temp != nullptr) 
                {
                end->link = new StackFrame<T>;   //creating rest of the nodes
                end = end->link;
                end->data = temp->data;
                temp = temp->link;
                }
                end->link = nullptr; //making sure that there is nothing after the end node.
            }
        }
        catch(bad_alloc) {
            cout<<"Bad memory allocation\n";
            exit(1);
        }    
    }

//******************************************************** DESTRUCTOR *****************************************************************
    template <class T>
    Stack<T>::~Stack()
    {
        T next;
        while(!empty()) //if the stack is not empty then only will it remove anything
        {
            next = pop(); //calling pop function to remove next item.
        }
    }

//********************************************************* GET TOP ********************************************************************
    template <class T>
    StackFramePtr<T> Stack<T>::getTop() const{ //accessing 'top' private member variable
        return top;
    }

//********************************************************** PUSH **********************************************************************
    template <class T>
    void Stack<T>::push(T the_symbol){
        try{
            StackFramePtr<T> temp = new StackFrame<T>; //creates new node stored in temp

            temp->data = the_symbol; // data of the_symbol is stored into data of temp
            temp->link = top; // setting top to the now be the next node (under this new node)
            top = temp;  // temp is now the new top value
        }
        catch(bad_alloc) {
            cout<<"Bad memory allocation\n";
            exit(1);
        }
    }

//********************************************************** POP ************************************************************************
    template <class T>
    T Stack<T>::pop()
    {
                    if(empty()) // corner case
                    {
                        cout << "The Stack is empty! \n";
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

//******************************************************** REVERSE **********************************************************************
    template <class T>
    void Stack<T>::reverse() // everything runs on N iterations
    {
        if(!empty()) // ! operator- N cases
        {
            T b = pop(); // = operator- runs N times
            // pops the top element. how do you count this. 
            // Runs 3N times -- but ignore the coefficient
            
            reverse(); // recursion works 
            insBottom(b); // runs an additional N times on top of the recursive reverse function (N*N)
            
        }
        //reverse runs through recursion. First checks whether stack is empty or not. If not empty, then pop out everything,
        //reverse and insert through the bottom of the stack.
    
    }

    // Therefore, this piece of code has the worst time complexity of O(N^2) 



//************************************************ HELPER FUNCTION FOR REVERSE **********************************************************
    template <class T>
    void Stack<T>::insBottom(T the_symbol)
    {
        //string ns;
        if(empty()) 
        {
            push(the_symbol); //if stack is empty, push the_symbol
        }
        else
        {
            T a = top->data; //store data of top value into a
            pop(); //pop out of the stack
            insBottom(the_symbol); //uses recursion for every item in the stack
            push(a); //push back in all nodes from the bottom
        }
    }

//********************************************************* EMPTY **********************************************************************
    template <class T>
    bool Stack<T>::empty() const       //uses cstddef
    {
        return (top == nullptr); //returns true if top is equal to nullptr
    }

//************************************************** ASSIGNMENT OVERLOAD ***************************************************************

    template <class T>
    const Stack<T> &Stack<T>::operator=(const Stack<T>& a_stack)  // see copy constructor(same code)
    {
        try{
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
            return *this; // dereferences &a_stack
        }
        catch(bad_alloc) {
            cout<<"Bad memory allocation\n";
            exit(1);
        }
    }



