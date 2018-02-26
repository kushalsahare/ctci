#include<iostream>

struct node{
    int data;
    node *next;
    node(int i){
	data = i;
	next = nullptr;
    }
};

node* add_list(node* head1, node *head2){

int carry = 0;
int sum = 0;
node *result = nullptr;
node *temp = result;

while ( !head1 || !head2){

int a = !(head1)? 0 : head1->data;
int b = !(head2)? 0 : head1->data;

sum = a+b+carry;
carry = sum/10;
sum %= 10;

if( result == nullptr){
node *temp = new node(sum);
}else{
temp->next = new node(sum);
}

temp= temp->next;

if( head1 )  head1 = head1->next;
if( head2 )  head2 = head2->next;
}

if( carry != 0){
temp->next = new node(carry);
}

return result;

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

	node *head1 = new node(5);
	node *head2 = new node(3);
	node *temp1 = head1;
	node *temp2 = head2;

	for( int i=0; i < 5 ; i++){
	    temp1->next = new node(i*2);
	    temp2->next = new node(i);
	    temp1 = temp1->next;
	    temp2 = temp2->next;
	}


	print_list(head1);
	print_list(head2);

	node *result = add_list(head1, head2);
	print_list(result);
	return 0;
    }
