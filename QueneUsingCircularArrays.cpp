#include<iostream>

using namespace std ;

const int SIZE = 10 ;
int arr[10] = {0};
int front = -1 ;
int rear = -1  ;

bool isEmpty()
{
    if(rear == -1 && front == -1)
        return 1 ;
    else 
        return 0;
}

void Enquene(int value)
{
    if((rear+1)%SIZE == front) return ;
    else if(isEmpty()) rear = front = 0 ;
    else rear = (rear+1) % SIZE ;
    arr[rear] = value;
}

void Dequene()
{
    if(isEmpty()) return ;
    else if(front == rear) front = rear = -1 ; 
    else front = front+1 ;
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