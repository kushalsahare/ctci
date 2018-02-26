#include<bits/stdc++.h>
 
using namespace std;
struct tNode{
    int d;
    tNode * left;
    tNode * right;

    tNode(int n){
     d = n;
     left = NULL;
     right = NULL;
    }
};

tNode * findLCAUtil(tNode* root, int n1, int n2, bool& v1, bool& v2){

    if(root == NULL){
	return NULL;
    }

    if( root->d == n1){
	v1 = true;
	return root;
    }

    if(root->d == n2){
	v2 = true;
	return root;
    }

    tNode * left = findLCAUtil( root->left, n1, n2, v1, v2);
    tNode * right = findLCAUtil( root->right, n1, n2, v1, v2);

    if( left !=NULL && right !=NULL){
	return root;
    }

    return ((left !=NULL)? left: right);
}

bool find(tNode * root, int n){

    if(root==NULL){
	return false;
    }

    if( root->d == n || find(root->left, n) || find(root->right, n))
	return true;

    return false;
}

tNode * findLCA(tNode* root, int n1, int n2){

    bool v1 = false;
    bool v2 = false;

    tNode* lca = findLCAUtil( root, n1, n2, v1, v2);

    if( (v1 && v2) || (v1 && find(lca, n2)) || (v2 && find(lca, n1)))
	return lca;

    return NULL;
}

int main(){
    // Let us create binary tree given in the above example
    tNode * root = new tNode(1);
    root->left = new tNode(2);
    root->right = new tNode(3);
    root->left->left = new tNode(4);
    root->left->right = new tNode(5);
    root->right->left = new tNode(6);
    root->right->right = new tNode(7);
    tNode *lca =  findLCA(root, 4, 5);
    if (lca != NULL)
	cout << "LCA(4, 5) = " << lca->d <<"\n";
    else
	cout << "Keys are not present \n";

    lca =  findLCA(root, 4, 10);
    if (lca != NULL)
	cout << "nLCA(4, 10) = " << lca->d<<"\n";
    else
	cout << "nKeys are not present \n";
    return 0;
}
