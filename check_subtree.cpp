#include<iostream>
#include<string>

struct tnode{
    int data;
    tnode *left;
    tnode *right;

    tnode(int d){
	data = d;
	left = nullptr;
	right = nullptr;
    }
};

bool match(tnode *r1, tnode *r2){

    if( r1 == nullptr && r2 == nullptr){ // match null trees
	return true;
    }else if( r1 == nullptr || r2 == nullptr){
	return false;
    }else if( r1->data != r2->data){
    return false;
    }else{
    return match(r1->left, r2->left) && match(r1->right, r2->right);
    }
}


bool subtree(tnode *r1, tnode* r2){
    if(r1 == nullptr){
	return false;
    }else if( r1->data == r2->data && match(r1, r2)){
	return true;
    }
    return subtree(r1->left, r2) || subtree(r1->right, r2);

}

bool containtree(tnode* large_tree, tnode* small_tree){

    if( small_tree == nullptr) return true;

    return subtree(large_tree, small_tree);

}


int main(){

    tnode *root1 = new tnode(10);

    root1->left = new tnode(11);
    root1->right = new tnode(5);

    root1->left->left= new tnode(89);
    root1->left->right = new tnode(77);

    root1->right->left = new tnode(65);
    root1->right->right = new tnode(34);

    root1->left->left->left= new tnode(90);
    root1->left->left->right= new tnode(18);

    root1->left->right->left= new tnode(22);
    root1->left->right->right= new tnode(11);

    root1->right->left->left = new tnode(45);
    root1->right->left->right = new tnode(95);

    root1->right->right->left = new tnode(15);
    root1->right->right->right = new tnode(25);


    tnode *root2 = new tnode(34);
    root2->left = new tnode(15);
    root2->right = new tnode(25);

    bool isSubtree = containtree(root1, root2);

    std::cout << isSubtree << "\n";


    return 0;

}


