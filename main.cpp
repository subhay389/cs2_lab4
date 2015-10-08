#include <iostream> 
#include <fstream>
using namespace std; 

struct node {
	int value; 
	node* next; 
};


node* head = NULL;
void populate(int num);
void printlist();
void sortpopulate(int num);
void deleteRepeat();
void reverseList();

int main() {
	int num;
	ifstream infile; 
	infile.open("integers.txt");

	while (!infile.eof()) {
		infile >> num;
		populate(num);

	}

	cout << "printing the list" << endl;

	printlist();

	cout << " Deleating the repeats"<<endl;

	deleteRepeat();
	
	printlist();

	cout << "reversing the list" << endl;

	reverseList();

	printlist();

	cin >> num; 

	return 0;
}

void populate(int num) {
	node* temp1;
	node* temp = new node; 
	temp->value = num; 
	temp->next = NULL; 
	
	if (head == NULL) 
	{ 
		head = temp; 
	}


	else {
		temp1 = head;
		while (temp1->next != NULL) {
			temp1 = temp1->next;
		};
		temp1->next = temp;
	}
};

void printlist() {
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->value<<endl;
		temp = temp->next;
	}
}

/*
void sortpopulate(int num) {
	node* temp1 = new node; 
	temp1->value = num;
	temp1->next = NULL;
	node* temp;
	temp = head; 
	int check = 0;
	while (head != NULL && temp->value < num ) {
		temp = temp->next;
		int check = 1;
	}
	if (check == 0) {
		temp1->next = head;
		head = temp1;
	}
	else {
		temp1->next = temp->next;
		temp->next = temp1;
	}
}
*/

void sortpopulate(int num) {
	int count = 0;
	node *temp = new node;
	
	if (head = NULL) {
		head = temp;
		temp->value = num; 
		temp->next = NULL;
		return;
	}
	else 
	{
		node* temp2 = head;
		if (temp2->value > num) {
			temp->next = temp2->next;
			head = temp;

		}
		else {
			
			while (temp2->next != NULL && temp2->next->value < num) {
				temp2 = temp2->next;
				if (temp2->next == NULL) {
					temp->value = num;
					temp2->next = temp; 
					temp->next = NULL;
					return;
				}
			}
			temp->value = num;
			temp->next = temp2->next;
			temp2->next = temp;
		}	
	}
	
}


void deleteRepeat() {
	node *temp = head, *temp1; 
	while (temp != NULL) {
		if (temp->value = temp->next->value) {
			temp1 = temp->next;
			temp->next = temp1->next;
			free(temp1);
		}
		temp = temp->next;
	}
}

void reverseList() {
	node *temp, *prev, *next; 
	temp = head; 
	prev = NULL;
	while (temp != NULL) {
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;

	}
	head = prev;

}
