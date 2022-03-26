#include<iostream>
//This is useful program //
using namespace std ;

class Node
{
public:
    int value ;
    Node* prev ;
};

void push(Node** top , int value)
{
    Node* newNode = new Node ;
    newNode->value = value ;
    
    if(*top == NULL ) 
    {
        newNode->prev = NULL ;
        *top =newNode ;
    }
    else
    {
        newNode->prev = (*top) ;
        (*top) = newNode ;
    }
}

void pop(Node** top)
{
    Node* newNode = NULL  ;
    if(*top == NULL ) 
    {
        return;
    }
    else 
    {
        newNode = *top ;
        *top = (*top)->prev ;
        delete newNode ;
    }
}

int Top(Node* top)
{
    return top->value;
}

int main()
{
    Node* top = NULL ;
    int number ;

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(&top,number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(&top,number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(&top,number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(&top,number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    push(&top,number);

    while(top != NULL)
    {
        cout <<  Top(top); 
        pop(&top); 
    }


}