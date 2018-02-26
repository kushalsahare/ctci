#include<bits/stdc++.h>

using namespace std;

struct tNode{
    int data;
    tNode *left;
    tNode *right;

    tNode(int d){
	data = d;
	left = NULL;
	right = NULL;
    }
};

tNode* createMinimalBST(int arr[], int low, int high){

    if( high < low)
	return nullptr;

    int mid = low + (high - low)/2;

    tNode* root = new tNode(arr[mid]);
    root->left = createMinimalBST(arr, low, mid-1);
    root->right = createMinimalBST(arr, mid+1, high);

    return root;
}

void inOrder(tNode *root){
    if( root == nullptr)
	return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void createListOfDepth( vector<list<tNode*> >& result, tNode *root){

    list<tNode*> temp;
    temp.push_back(root);
    result.push_back(temp);

    int depth = 0;

    while( !result[depth].empty()){

	list<tNode*> l;
	list<tNode*>::iterator it;

	for(it = result[depth].begin(); it != result[depth].end(); ++it){

	    tNode *ptr = *it;

	    if( ptr->left)
		l.push_back(ptr->left);

	    if( ptr->right)
		l.push_back(ptr->right);
	}
	result.push_back(l);
	depth++;
    }
}


void printLevelLinkedList( vector<list<tNode*> >& result){

    for( auto it = result.begin(); it != result.end(); ++it){
	for(auto i = it->begin(); i != it->end(); ++i){
	    std::cout << (*i)->data << " ";
	}
	std::cout << "\n";
    }

}


int main(){

    int arr[] = {1,2,3,4,5,6,7};
    tNode* root = nullptr;

    root = createMinimalBST(arr, 0, 6);
    //inOrder(root);

    vector<list<tNode*> > res;
        createListOfDepth(res, root);
	printLevelLinkedList(res);
    std::cout << "\n";

    return 0;
}




