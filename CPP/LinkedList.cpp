#include<bits/stdc++.h>

using namespace std;

class Node {
public:
	int Value;
	Node* Next;

	Node(){
		Value =0;
		Next = NULL;
	}


	Node(int x){
		Value = x;
		Next = NULL;
	}

};

void printList(Node* node){
	Node* tmp = node;
	while(tmp != NULL){
		cout<<tmp->Value<<endl;
		tmp = tmp->Next;
	}
}

void insertAtFront(Node** node, int n){
	Node * zeroth = new Node();
	zeroth->Value = n;

	zeroth->Next = *node ;

	*node = zeroth;
}

void intsertAtEnd(Node** tmp, int n){
	Node* tail = new Node(n);
	// tail->Value = n;
	// tail->Next = NULL;

	if(*tmp==NULL){
		*tmp = tail;
		return;
	} 
	Node* node = *tmp;

	while(node->Next != NULL){
		node = node->Next;
	}
	node->Next = tail;
}

void insertAfter(Node* node, int n){
	if(node == NULL){
		cout<<"Error: Can not be null";
		return;
	}
	Node* newNode = new Node(n);

	newNode->Next = node->Next;
	node->Next = newNode;
}

int main(){
	
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 1;
	head->Next = second;
	second->Value = 2;
	second->Next = third;
	third->Value = 3;
	third->Next = NULL;

	cout<<"Before:";
	printList(head);
	insertAtFront(&head, 0);
	cout<<"After at Front:";
	printList(head);

	cout<<"after Adding at end:";
	intsertAtEnd(&head, 4);
	printList(head);

	cout<<"with Empty List:";
	Node* eHead = NULL; 
	intsertAtEnd(&eHead, 50);
	printList(eHead);

	cout<<"Insert in the middle:";
	insertAfter(third, 5);
	printList(head);

	return 0;
}