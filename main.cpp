// driver code belongs here

#include <iostream>
#include <string>
#include "stack.hpp"
#include "stack.cpp"
using namespace std;

template<class T>
void printStack(Stack<T> s)
{
    if(s.empty())
    cout << "This stack is empty.\n";

    else if(!s.empty())
    {
        StackFramePtr<T> x = s.getTop();
        while(x != nullptr)
        {
            cout << x->data << " ";
            x = x->link;
        }

    }
}


template<class T>
void palindrome(Stack<T> s){
    
    string myStr;

    cout<<"\nenter an input:  ";
        cin.get();
        getline(cin,myStr);

        for(int i = 0; i < myStr.length(); i++) {
            s.push(myStr[i]);
        }
    
    s.reverse();
    printStack(s);
    s.reverse();
    printStack(s);
    cout << endl << "************************************ end of palindrome ************************************";
}

template<class T>
void doubleStack(Stack<T> sdouble1){
    int doubleMenu =-1;
    sdouble1.push(1.5);
    sdouble1.push(2.5);
    sdouble1.push(3.5);
    sdouble1.push(4.5);
    sdouble1.push(5.5);
    sdouble1.push(6.5);

    Stack<double> sdouble2(sdouble1);
    sdouble2.reverse();

    while(doubleMenu != 0) {
        cout<<"\n\n 0-Perform no operations and go back to Primary menu \n 1-Print out the entire stack of sdouble1"<< 
        "\n 2-Print out the entire Stack of sdouble2 \n 3-Print out the top of sdouble1 \n 4-Print out the top of sdouble2 \n";
        cin>>doubleMenu;

        if (doubleMenu == 1) {
            cout<< "\nThis is sdouble1: \n";
            printStack(sdouble1);
        }
        else if(doubleMenu==2) {
            cout<< "\nThis is sdouble2: \n";
            printStack(sdouble2);
        }
        else if(doubleMenu==3) {
            double x = sdouble1.getTop()->data;
            cout << "\n The top value of sdouble1 is  " << x;
        }
        else if(doubleMenu==4) {
            double y = sdouble2.getTop()->data;
            cout << "\n The top value of sdouble2 is  " << y;
        }    
    }

    return;
}

template<class T>
void intStack(Stack<T> sint1){
    int intMenu =-1;
    
    sint1.push(1);
    sint1.push(2);
    sint1.push(3);
    sint1.push(4);
    sint1.push(5);
    sint1.push(6);

    Stack<int> sint2;
    sint2 = sint1;
    sint2.reverse();

    while(intMenu != 0) {
        cout<<"\n\n 0-Perform no operations and go back to Primary menu \n 1-Print out the entire stack of sint1"<< 
        "\n 2-Print out the entire Stack of sint2 \n 3-Print out the top of sint1 \n 4-Print out the top of sint2 \n";
        cin>>intMenu;

        if (intMenu == 1) {
            cout<< "\nThis is sint1: \n";
            printStack(sint1);
        }
        else if(intMenu==2) {
            cout<< "\nThis is sint2: \n";
            printStack(sint2);
        }
        else if(intMenu==3) {
            double x = sint1.getTop()->data;
            cout << "\n The top value of sint1 is  " << x;
        }
        else if(intMenu==4) {
            double y = sint2.getTop()->data;
            cout << "\n The top value of sint2 is  " << y;
        }    
    }

    return;
}



int main()
{
    
    Stack<int> sint1;
    Stack<double> sdouble1;
    Stack<char> test;
    int menu = -1;

    while(!(menu == 0)) {
        cout<<"\n\n 0-Exit code \n 1-Palindrome \n 2-Double stuff\n 3-Int stuff \n";
        cin>>menu;


//******************************************************************** 4(c) *****************************************************
        if (menu == 1) {

            palindrome(test);
        }
//******************************************************************** 4(b) *****************************************************

        else if (menu == 2) {
            
            doubleStack(sdouble1);    
        }
    
    
//******************************************************************** 4(a) *****************************************************
        else if (menu == 3)
        {
        
            intStack(sint1); 
        }
    }

    return 0;



    
}