void getSizeUTIL(Node* root, int &count){
    if (root == NULL){
        return;
    } else{
        count++;
        getSizeUTIL(root->left, count);
        getSizeUTIL(root->right, count);
    }
}

int getSize(Node* node){
    int count = 0;
    getSizeUTIL(node, count);
    return count;
}
