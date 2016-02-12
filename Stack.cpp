/*Create a Stack with two methods push and pop. Use your LinkedList class to keep track of the elements internally.

The input will consist of the number t followed by t test cases. Each test case will consist of a number n, followed by n numbers of actual input.

For each number of the actual input, if the number is -1, pop off a value from your stack and print it. Otherwise, push the number onto your stack.*/

#include<iostream>
#include<cstdlib>

using namespace std;

class Node {
	public:
	int data;
	Node *next;
};

class Stack {
	public:
	Node *top=NULL;
	
	void push(int item) {
		if(top==NULL) {
			top = (Node*)malloc(sizeof(Node*));
			top->data = item;
			top->next = NULL;
		}
		else {
			Node *newNode = (Node*)malloc(sizeof(Node*));
			newNode->data = item;
			newNode->next = top;
			top = newNode;
		}
	}
	
	int pop() {
		if(top==NULL) {
			cout<<endl<<"Stack is empty"<<endl;
			return 999;
		}
		else {
			Node *popped = top;
			top=top->next;
			return popped->data;
		}		
	}
	
};

int main() {
	
	Stack stack;
	int no_of_test;
	int no_of_op;
	int typ_of_op;
	
	Node *out1 = NULL; Node *out2 = NULL; Node *newN;
	
	cin>>no_of_test;
	
	while(no_of_test--) {
		cin>>no_of_op;
		while(no_of_op--) {
			cin>>typ_of_op;
			if(typ_of_op == -1) {
				if(out1==NULL) {
					out1 = (Node*)malloc(sizeof(Node));
					out1->data = stack.pop();
					out1->next=NULL;
				}
				else {
					out2 = out1;
					while(out2->next!=NULL) { out2=out2->next; }
					newN = (Node*)malloc(sizeof(Node));
					newN->data = stack.pop();
					out2->next = newN;
				}
			}
			else {
				stack.push(typ_of_op);
			}
		}
		out2 = out2->next;
		newN = (Node*)malloc(sizeof(Node));
		out2->next = newN;
		newN->data = -999;
	}
	cout<<endl;
	for(Node *temp=out1;temp->next!=NULL;temp=temp->next) {
		if((temp->data)==-999) {
			cout<<endl;
		}
		else {
			cout<<(temp->data)<<" ";
		}
	}
	return 0;
}
