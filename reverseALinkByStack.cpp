#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Node
{
public:
	int data_value ;//integer data value
	Node* link ;//saving next node address 	
};

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
    Node* head = NULL ;
    Node* current = NULL ;
    functionToAddAtTheEndOfNode(&head,&current,1);
    functionToAddAtTheEndOfNode(&head,&current,2);
    functionToAddAtTheEndOfNode(&head,&current,3);
    functionToAddAtTheEndOfNode(&head,&current,4);
    functionToAddAtTheEndOfNode(&head,&current,5);

    print(head);

    std::stack<Node*> linkList ;
    Node* newNode = head ;
    Node* newNode1 = head  ;

    while(newNode != NULL )
    {
        linkList.push(newNode);
        newNode = newNode->link ; 
    }

    
    Node* newNode2 = linkList.top();
    head = newNode2 ;
    linkList.pop();

    while(!linkList.empty())
    {
        newNode2->link = linkList.top();
        linkList.pop();
        newNode2 = newNode2->link;
    }
    
    newNode2->link = NULL ;
    print(head);
}    

