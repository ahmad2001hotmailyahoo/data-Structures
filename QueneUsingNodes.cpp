#include<iostream>

using namespace std ;

class Node
{
public:
    int value ;
    Node* next ;
};

void Enquene(Node** head ,Node** current , int value)
{
    Node* newNode = new Node ;
    newNode->value = value ;
    newNode->next = NULL ;

    if((*head) == NULL ) 
    {
        (*current) = (*head) = newNode ;
    }
    else
    {
        (*current)->next = newNode ;
        (*current) = newNode ;
    }
}

void Denquene(Node** head ,Node** current)
{
    Node* newNode = NULL  ;
    if((*head) == NULL ) 
    {
        return;
    }
    if((*current) == (*head)) 
    {
        newNode = (*current) ;
        delete newNode ;
        (*current) = (*head) = NULL ;
    }
    else 
    {
        newNode = (*head) ;
        (*head) = (*head)->next ;
        delete newNode ;
    }
}

int Top(Node* head)
{
    return head->value;
}

bool isEmpty(Node* head , Node*current)
{
    if(head == NULL && current == NULL)
        return 0 ;
    else 
        return 1 ;
}

int main()
{
    Node* head = NULL ;
    Node* current = NULL ;
    int number ;
    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(&head,&current,number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(&head,&current,number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(&head,&current,number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(&head,&current,number);

    cout << "Enter the value you want to add" << endl ;
    cin  >> number ;
    Enquene(&head,&current,number);

    while(isEmpty(head,current))
    {
        cout << Top(head);
        Denquene(&head,&current);
    }


}