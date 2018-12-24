void serialize(Node *root,vector<int> &A){
    if(root == NULL){
        A.push_back(-1);
    } else{
        A.push_back(root->data);
        serialize(root->left,A);
        serialize(root->right,A);
    }
}

Node* deSerializeUTIL(int val, vector<int> &A){
    A.erase(A.begin());
    if(val != -1){
        Node* tempNode = newNode(val);

        tempNode->left = deSerializeUTIL(*A.begin(),A);
        tempNode->right = deSerializeUTIL(*A.begin(),A);
        return tempNode;
    } else{
        return NULL;
    }
}

Node * deSerialize(vector<int> &A){
    return deSerializeUTIL(*A.begin(),A);
}
