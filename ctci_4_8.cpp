#include<iostream>


struct TreeNode{

    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value){
    data = value;
    left = nullptr;
    right = nullptr;
    }

};

bool covers(TreeNode* root, int p){
if( root == nullptr) return false;
if(root->data == p) return true;

return covers(root->left, p) || covers(root->right, p);
}


TreeNode* commonAncestorHelper(TreeNode* root, int p, int q){
    if( root == nullptr || root->data == p || root->data == q){
        return root;
    }

    bool isPonLeft = covers(root->left, p);
    bool isQonLeft = covers(root->left, q);

    if( isPonLeft != isQonLeft){
        return root;
    }

    TreeNode* child = isPonLeft?root->left: root->right;
    return commonAncestorHelper(child, p, q);
}

TreeNode* commonAncestor(TreeNode* root, int p, int q){
    if( !covers(root, p) || !covers(root, q) )
        return nullptr;
return commonAncestorHelper(root, p, q);
}
int main(){

TreeNode* root = new TreeNode(20);
root->left = new TreeNode(10);
root->left->left = new TreeNode(5);
root->left->left->left = new TreeNode(3);
root->left->left->right = new TreeNode(7);
root->left->right = new TreeNode(15);
root->left->right->right = new TreeNode(17);
root->right = new TreeNode(30);
int p = 7;
int q = 30;
TreeNode* common = commonAncestor(root, p, q);

if(common != nullptr){
    std::cout << common ->data << "\n";
}

return 0;

}
