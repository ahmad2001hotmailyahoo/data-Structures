#include<iostream>

// circular linked list

struct LinkedListCircular {
	int value;
	LinkedListCircular* next;
};

// insertion

LinkedListCircular* insertLinkListInCircular(LinkedListCircular* head, int value=0) {
	LinkedListCircular* _new_circular_node = new LinkedListCircular ;
	_new_circular_node->value = value;
	_new_circular_node->next = head;
	LinkedListCircular* current = head;
	if (head == NULL) {
		head = _new_circular_node;
		head->next = head;
	}
	else{

		while (current->next != head) {
			current = current->next;
		}
		current->next = _new_circular_node;
	}

	return head;

}

//deletion
LinkedListCircular* deleteLinkListInCircular(LinkedListCircular* head, int value) {
	LinkedListCircular* current = head;
	LinkedListCircular* prev = head;
	while (current->value != value && current != head) {
		prev = current;
		current = current->next;
	}
	if (current == head) return head;
	else {
		prev->next = current->next;
		delete current;
	}

	return head;
}

//updation
LinkedListCircular* updateLinkListInCircular(LinkedListCircular* head, int value, int _updated_value) {
	LinkedListCircular* current = head;
	while (current->value != value && current != head) {
		current = current->next;
	}
	if (current == head) return head;
	else {
		current->value = _updated_value;
	}
	return head;
}


// printing LinkedListCircular

void print(LinkedListCircular* head) {
	LinkedListCircular* current = head;
	while (current->next != head) {
		std::cout << current->value;
		current = current->next;
	}
	std::cout << current->value;
}

bool findLoop(LinkedListCircular* head) {
	LinkedListCircular* firstList = head;
	LinkedListCircular* seconedList = head;
	bool _founded = false;
	while (!_founded && firstList != NULL && seconedList != NULL) {
		firstList = firstList->next;
		seconedList = seconedList->next;
		std::cout << firstList->value << std::endl;
		std::cout << seconedList->value << std::endl;
		if (firstList == seconedList) {
			_founded = true;
		}
	}
	return _founded;
}

int main() {
	LinkedListCircular* head = NULL;
	head = insertLinkListInCircular(head, 12); 
	head = insertLinkListInCircular(head, 13);
    //head = insertLinkListInCircular(head, 14);
	//head = insertLinkListInCircular(head, 15);
	//head = insertLinkListInCircular(head, 16);
	//head = insertLinkListInCircular(head, 17);

	print(head);
}