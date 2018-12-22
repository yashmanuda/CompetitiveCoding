void verticalOrderUTIL(Node *root, int depth, int dist, map<int, vector<int>> &m){
    if(root == NULL){
        return;
    } else{
        m[dist].push_back(root->data);

        if(root->left != NULL){
            verticalOrderUTIL(root->left,depth + 1, dist - 1, m);
        }

        if(root->right != NULL){
            verticalOrderUTIL(root->right,depth + 1, dist + 1, m);
        }
    }
    return;
}

void verticalOrder(Node *root){
    map<int, vector<int>> m;
    map<int, vector<int>>::iterator it;
    verticalOrderUTIL(root,0,0,m);

    for( it = m.begin(); it != m.end(); ++it ){
        for(int i = 0; i < it->second.size(); i++){
            cout << it->second.at(i) <<" ";
        }
    }
}
