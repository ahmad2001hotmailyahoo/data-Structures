
#include<iostream>

using namespace std ;

int arr[10] = {0};
int top = 0 ;

void push(int value)
{
    arr[top] = value ;
    top++ ;
}

void pop()
{
    top-- ;
}

int Top()
{
    return arr[top];
}

int main()
{
    int number ;
    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(number);
    
    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(number);
    
    while(top != 0)
    {
        pop();
        cout << Top();
    }
}