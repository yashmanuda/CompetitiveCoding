void BToDLLUtil(Node *root, Node **head, Node *&prev){
    if(root == NULL) return;
    BToDLLUtil(root->left,head,prev);
    if(prev == NULL)
        *head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BToDLLUtil(root->right,head,prev);
}

void BToDLL(Node *root, Node **head_ref){
    Node* prev = NULL;
    BToDLLUtil(root,head_ref, prev);
}
