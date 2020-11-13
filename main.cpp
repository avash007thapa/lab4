// driver code belongs here

#include <iostream>
#include <string>
#include "stack.hpp"
#include "stack.cpp"
using namespace std;

template<class T>
void printStack(Stack<T> s)
{
    
    if(!s.empty())
    {
        T x = s.gettop()->data;
        s.pop();
        std::cout << x << " ";
        printStack(s);
        s.push(x);
        
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


int main()
{
    
    Stack<int> sint1;
    Stack<int> sint2;
    Stack<double> sdouble1;
    //Stack<double> sdouble2;
    Stack<char> test;
    int menu = -1;

    while(!(menu == 0)) {
        cout<<"\n0-Exit code \n 1-Palindrome \n 2-Double stuff\n 3- \n";
        cin>>menu;

//******************************************************************** 4(c) *****************************************************
        if (menu == 1) {
            menu = -1;
            palindrome(test);
        }
//******************************************************************** 4(b) *****************************************************

        else if (menu == 2) {
            
            sdouble1.push(1.5);
            sdouble1.push(2.5);
            sdouble1.push(3.5);
            sdouble1.push(4.5);
            sdouble1.push(5.5);
            sdouble1.push(6.5);
            cout<< "\nThis is sdouble1: \n";
            printStack(sdouble1);

            Stack<double> sdouble2(sdouble1);
            sdouble2.reverse();
            cout<< "\nThis is sdouble2: \n";
            printStack(sdouble2);    
        }
    }
    
//******************************************************************** 4(b) *****************************************************
    



   // Stack<int> sint2;

    // sint1.push(1);
    // sint1.push(2);
    // sint1.push(3);
    // sint1.push(4);
    // sint1.push(5);
    // sint1.push(6);

    //Stack<int> sint2(sint1);    
    //printStack(sint1);
    // printStack(sint2);

    // sint2.reverse();

    // printStack(sint1);
    // printStack(sint2);

    return 0;



    
}