#include<iostream>

struct node{
    int data;
    node *next;
    node(int i){
	data = i;
	next = nullptr;
    }
};

node* partition_list(node* head, int k){

    node *left_begin = nullptr;
    node *left_end = nullptr;
    node *right_begin = nullptr;
    node *right_end = nullptr;

    node *temp = head;

    while( temp != nullptr){

	if( temp->data <= k){
	    if(left_begin == nullptr){
	      left_begin = new node(temp->data);
	      left_end = left_begin;
	    }else{
	    left_end->next = new node(temp->data);
	    left_end = left_end->next;
	    }
	}else{
	    if( right_begin == nullptr){
		right_begin = new node(temp->data);
		right_end = right_begin;
	    }else{
		right_end->next = new node(temp->data);
		right_end = right_end->next;
	    }
	}
	temp = temp->next;
    }

    if( left_begin == nullptr) return right_begin;

    left_end->next = right_begin;
    return left_begin;
    
}
    void print_list(node *head){
	if( head == nullptr) return;

	while( head != nullptr){
	    std::cout << head->data << " ";
	    head = head ->next;
	}
	std::cout<< "\n";

    }

    int main(){

	node *head = new node(5);
	node *temp = head;

	for( int i=0; i < 20 ; i++){
	    temp->next = new node(i*2);
	    temp = temp->next;
	}

	temp->next = new node(2);
	temp->next->next = new node(1);

	print_list(head);

	node * k = partition_list(head, 20);
	print_list(k);
	return 0;
    }
