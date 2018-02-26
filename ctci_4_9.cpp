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

vector<vector<int>> BST_sequence(const TreeNode* root){

    vector<vector<int>> result;

    vector<vector<int>> left = BST_sequence(root->left);
    vector<vector<int>> right = BST_sequence(root->right);

    for_each(
    }

}

int main(){
TreeNode* root = new TreeNode(50);

root->left = new TreeNode(20);
root->left->left = new TreeNode(10);
root->left->left->left = new TreeNode(5);
root->left->left->right = new TreeNode(15);
root->left->right = new TreeNode(25);

root->right = new TreeNode(60);
root->right->right = new TreeNode(70);
root->right->right->left = new TreeNode(65);
root->right->right->right = new TreeNode(80);


return 0;

}
