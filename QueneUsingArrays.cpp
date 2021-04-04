
#include<iostream>

using namespace std ;

const int SIZE = 10 ;
int arr[10] = {1,2,3,4,5};
int front = -1 ;
int rear = -1  ;

bool isFull()
{
    if(rear == SIZE - 1)
        return 1 ;
    else 
    return 0 ;    
}

bool isEmpty()
{
    if(rear == -1 && front == -1)
        return 1 ;
    else 
        return 0;
}

void Enquene(int value)
{
    if(isFull())
        return ;
    if(isEmpty())
    {
        rear = front = 0 ;
    }
    else
    {
        rear++ ;
    } 
    arr[rear] = value ;
}

void Dequene()
{
    if(isEmpty()) return ;
    if(front == rear) front = rear = -1 ;
    else front++ ;
}

int Top()
{
    return arr[front];
}

int main()
{
    int number ;
    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(number);
    
    while (!isEmpty())
    {
        cout << Top();
        Dequene();
    }
    
}