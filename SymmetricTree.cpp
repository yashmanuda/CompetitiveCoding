bool isSymmetricUTIL(Node* l, Node* r){
    if(l == NULL && r == NULL){
        return true;
    } else if((l == NULL && r != NULL) || (l != NULL && r == NULL)){
        return false;
    }
    else{
        if(l->key == r->key){
            return (isSymmetricUTIL(l->left,r->right) && isSymmetricUTIL(l->right,r->left));
        } else{
            return false;
        }
    }
    return true;
}

bool isSymmetric(struct Node* root){
    return isSymmetricUTIL(root->left, root->right);
}
