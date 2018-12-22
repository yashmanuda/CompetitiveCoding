void connect(Node *p){
    queue<pair<Node*,int>> levelOrder;
    levelOrder.push(make_pair(p,0));

    pair<Node*,int> tempNode = levelOrder.front();
    map<int,vector<Node*>> levelMap;
    while(tempNode.first != NULL){

        levelMap[tempNode.second].push_back(tempNode.first);

        if(tempNode.first->left != NULL){
            levelOrder.push(make_pair(tempNode.first->left,tempNode.second + 1));
        }
        if(tempNode.first->right != NULL){
            levelOrder.push(make_pair(tempNode.first->right,tempNode.second + 1));
        }

        levelOrder.pop();

        if(!levelOrder.empty()){
            tempNode = levelOrder.front();
        } else{
            tempNode.first = NULL;
        }
    }
    for(auto x : levelMap){
        for(int i = 0; i < x.second.size() - 1; i++){
            x.second.at(i)->nextRight = x.second.at(i + 1);
        }
        x.second.at(x.second.size() - 1)->nextRight = NULL;
    }
    return;
}
