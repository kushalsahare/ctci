#include<iostream>
#include<algorithm>

class BiNode{

public:
    BiNode(int data);
    ~BiNode();
private:
    int data;
    BiNode *node1;
    BiNode *node2;
};

BiNode* convert(BiNode *root){
if(root == nullptr) return nullptr;

BiNode node_1 = convert(root->node1);
BiNode node_2 = convert(root->node2);

if( node_1 != nullptr){
    concat(getTail(node_1), root);
}

if(node_2 != nullptr){
    concat(root, node2);
}

return node_1 = (node_1 == nullptr)? root: node_1;
}

BiNode* getTail(BiNode* node){
if(node == nullptr) return nullptr;
BiNode* tail = node;
while(tail->node2 != nullptr){
    tail = tail->node2;
}
return tail;
}
