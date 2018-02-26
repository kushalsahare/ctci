#include<iostream>

struct node{
    int data;
    node *next;
    node(int i){
	data = i;
	next = nullptr;
    }
};

node* get_k_node(node *head, int k){

    node *p1 = head;
    node *p2 = head;

    for( int i = 0; i < k; i++){
	if( p2 == nullptr) return nullptr;
	p2 = p2->next;
    }
    while( p2 != nullptr){
	p2 = p2->next;
	p1 = p1->next;
    }
    return p1;
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

    print_list(head);

    node *kk = get_k_node(head, 5);
    std::cout << kk->data << "\n";

    return 0;
}
