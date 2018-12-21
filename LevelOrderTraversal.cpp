#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
};

struct Node* getNode(int x){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->left = NULL;
    node->right= NULL;
    return node;
}

void levelOrderTraversal(Node *root){
    queue<Node*> myQueue;
    myQueue.push(root);
    Node* temp = myQueue.front();
    while(temp != NULL){
        cout << temp->data << " ";
        if(temp->left != NULL){
            myQueue.push(temp->left);
        }
        if(temp->right != NULL){
            myQueue.push(temp->right);
        }
        myQueue.pop();
        if(!myQueue.empty()){
            temp = myQueue.front();
        } else{
            temp = NULL;
        }
    }
    return;
}

int main(){
    Node *root = getNode(10);
    root->left = getNode(5);
    root->right = getNode(15);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->left->left = getNode(12);
    root->left->left->left = getNode(20);
    levelOrderTraversal(root);
    return 0;
}
