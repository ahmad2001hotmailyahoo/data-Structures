#include<iostream>
#include<stdlib.h>
using namespace std ;
class Node
{
public:
	int data_value ;//integer data value
	Node* link ;//saving next node address 	
};

// function to edit at the node 

void functionToEditTheNode(Node* head,int count)
{
	if(count == 1) cout << "List is empty" << endl ;
	else
	{
		int value ;
		int position ;
		cout << "Enter the position of value you want to edit :" << endl ;
		START :
		cin >> position ;
		if(position > count )
		{
			cout << "The value is greater the size of link list Enter again:" << endl ;
			goto START ;
			cout << "";	
		}
		else
		{
			if(position > 1)
			{
				head = head->link ;
				count-- ;
			}
			cout << "Enter the value you want to re-write at the following position" << endl ;
			cin >> value ;
			head->data_value = value ;
		}
	}
}

// function to delete at the start 

void functionToDeleteAtTheStartOfNode(Node** head)
{	
	if((*head)== NULL)
	{
		cout << "link list is empty" << endl ;
	}
	else
	{
		Node* ptr = (*head)->link ;
		delete (*head) ;
		(*head) = ptr ;	
	}
}
// function to delete at the end 
void functionToDeleteAtTheEndOfNode(Node** head,Node** current)
{
	if((*head)== NULL)
	{
		cout << "link list is empty" << endl ;
	}
	else if((*head)->link == NULL)
	{
		delete(*head);
		(*head) = NULL ;
	}
	else
	{
		Node* ptr1 = (*head) ;
		Node* ptr = (*current) ;
		
		while( ptr1->link == NULL )  
		{
			ptr1= ptr1->link ;  
		}
		
		delete (ptr) ;
		ptr = NULL ;
		(*current) = ptr1 ;	
		(*current)->link = NULL ;
	}
}
//function to delete at the position 
void deletionAtPosition(Node** head,int position,int value)
{
	Node* current  = (Node*)malloc(sizeof(Node));
	Node* current1 = (Node*)malloc(sizeof(Node));
	Node* placement = (Node*)malloc(sizeof(Node));
	current = (*head) ;
	int count = position ;
	while(count > 1)
	{
		current1 = current ; 
		current = current->link ;
		count-- ;
	}
	current1->link = current->link ;
	delete current ; 
}
//function to add at the end of node 
void functionToAddAtTheEndOfNode(Node** head,Node** current, int new_value )
{
	Node*	newNode = (Node*)calloc(sizeof(Node),1) ;
	
	newNode->data_value = new_value ;
	newNode->link = NULL  ;
	
	if((*head)== NULL)
	{
		(*head) = newNode ;
		(*current) = (*head);
	}
	else
	{
		(*current)->link = newNode;
		(*current) = newNode ;	
	}
}
// function to add at the start of node 
void functionToAddAtTheStartOfNode(Node** head, Node** current,int new_value )
{
	Node*	newNode = (Node*)calloc(sizeof(Node),1) ;
	
	newNode->data_value = new_value ;
	
	if((*head)== NULL)
	{
		newNode->link = NULL  ;
		(*head) = newNode ;
		(*current) = (*head) ;
	}
	else
	{
		newNode->link = (*head) ;
		(*head) = newNode ;
	}
}

// function to add node at particular position
void insertionAtPosition(Node**head,int position,int value)
{
	Node* current  = (Node*)malloc(sizeof(Node));
	Node* current1 = (Node*)malloc(sizeof(Node));
	Node* placement = (Node*)malloc(sizeof(Node));
	current = (*head) ;
	int count = position ;
	while(count > 1)
	{
		current1 = current ; 
		current = current->link ;
		count-- ;
	}
	placement->data_value = value ;
	current1->link = placement ; 
	placement->link = current;
}

void print(Node* head)
{
	while(head != NULL)
	{
		cout << head->data_value << ",";
		head = head->link ;
	}
	cout << endl ;
}


int main()
{
	Node* head  = NULL ;
	Node* current = NULL ;
	char option = '\0';
	int index =  0 , count = 1,value = 0;
	while(true)
	{
		cout << "Press A for adding the node" << endl ;
		cout << "press D for deleting the node"<< endl ;
		cout << "press E updating the node" << endl ;
		cout << "press P for printing the node" << endl ;
		cout << "press X for finishing the program" << endl ;
		cin  >> option ;
		if(option == 'A' || option == 'a')
		{
			char check ;
			cout << "Enter the value you want to add : " << endl ;
			cin >> value ;
			if(head == NULL || count == 1)
			{
				functionToAddAtTheStartOfNode(&head,&current,value);
				count++ ;
				goto START ;
			}
			cout << "do you want to add at first" << endl ;
			cin >> check ;
			if(check == 'Y' || check == 'y')
			{
				functionToAddAtTheStartOfNode(&head,&current,value);
				count++ ;
				goto START ;
			}
			cout << "do you want to add at last" << endl ;
			cin >> check ;
			if(check == 'Y' || check == 'y')
			{
				functionToAddAtTheEndOfNode(&head,&current,value);
				count++ ;			
				goto START ;
			}
			else 
			{
				cout << "Enter the position at which you want to add the node(start writing from 1 Not 0) " << endl ;
				cin >> index ;
				insertionAtPosition(&head,index,value);			
			}
		}
		
		else if(option == 'D' || option == 'd')    
		{
			if(head == NULL || count == 2 || count == 1 )		 
			{
				functionToDeleteAtTheStartOfNode(&head) ;
				count-- ;
				goto START ;
			}
			char check ;
			cout << "Do yo want to delete from start click y for yes and n for N" << endl ;
			cin >> check ;
			if(check == 'y' || check == 'Y')	
			{
				functionToDeleteAtTheStartOfNode(&head) ;
				count-- ;
				goto START ;
			}
			cout << "Do yo want to delete from end click y for yes and n for N" << endl ;
			cin >> check ;
			if(check == 'y' || check == 'Y')
			{
				
				functionToDeleteAtTheEndOfNode(&head,&current) ;
				count--;
				goto START ;				
			}
			else
			{
				cout << "Enter the position at which you want to delete the node(start writing from 1 Not 0) " << endl ;
				cin >> index ;
				if(index == 1)functionToDeleteAtTheStartOfNode(&head) ;
				else if(index == count)functionToDeleteAtTheEndOfNode(&head,&current) ;
				else deletionAtPosition(&head,index,value);
				count-- ;
				goto START ;
			}
		}
		
		else if(option == 'E' || option == 'e')      functionToEditTheNode(head,count);
		
		else if(option == 'P' || option == 'p')		print(head);
		
		else if(option == 'X' || option == 'x')     break ;
		START :
		cout << "" ;	
	
	}
	
	cout << "The program is finished" << endl ;
	
	return 0 ;
}
