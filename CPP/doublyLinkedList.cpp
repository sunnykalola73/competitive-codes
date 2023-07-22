#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* prev;
};

void printForward(Node* head){

	Node* traverser = head;

	while(traverser !=NULL ){
		cout<<"data:"<<traverser-> val<<endl;
		traverser = traverser->next;
	}


}

void printbackward(Node* tail){

	Node* traverser = tail;

	while(traverser!= NULL){
		cout<<"data:"<<traverser->val<<endl;
		traverser = traverser->prev;
	}


}

int main(){

	Node* head;
	Node* tail;

	//Add first node
	Node* node = new Node();
	node->val = 4;
	node->next = NULL;
	node->prev = NULL;

	head = node;
	tail = node;

	// Add second node
	node = new Node();
	node->val = 5;
	node->next = NULL;
	node->prev = tail;
	tail->next = node;
	tail = node;

	// Add third node
	node = new Node();
	node->val = 6;
	node->next = NULL;
	node->prev = tail;
	tail->next = node;
	tail = node;

	// Add fourth node
	node = new Node();
	node->val = 7;
	node->next = NULL;
	node->prev = tail;
	tail->next = node;
	tail = node;
	
	printForward(head);
	cout<<"new lineL:"<<endl;
	printbackward(tail);

}
