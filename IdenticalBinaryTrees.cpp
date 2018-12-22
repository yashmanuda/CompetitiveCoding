bool isIdenticalUTIL(Node *r1, Node *r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    } else if (r1 == NULL && r2 != NULL){
        return false;
    } else if(r1 != NULL && r2 == NULL){
        return false;
    } else{
        if(r1->data != r2->data){
            return false;
        } else{
            return (isIdenticalUTIL(r1->left,r2->left) && isIdenticalUTIL(r1->right,r2->right));
        }
    }
    return true;
}

bool isIdentical(Node *r1, Node*r2){
    return isIdenticalUTIL(r1,r2);
}
