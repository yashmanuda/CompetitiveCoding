
void getCountOfNodeUTIL(Node* root, int l, int h, int &count){

    if(root == NULL){
        return;
    } else{
        if(root->data < l){
            getCountOfNodeUTIL(root->right,l,h,count);
        } else if(root->data > h){
            getCountOfNodeUTIL(root->left,l,h,count);
        } else{
            count++;
            getCountOfNodeUTIL(root->left,l,h,count);
            getCountOfNodeUTIL(root->right,l,h,count);
        }
    }
    return;
}

int getCountOfNode(Node *root, int l, int h){
    int count = 0;
    getCountOfNodeUTIL(root,l,h,count);
    return count;
}
