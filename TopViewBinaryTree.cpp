// vector : dist, <data,depth>
bool comparator(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
    if(a.second.second == b.second.second){
        return a.first < b.first;
    } else{
        return a.second.second < b.second.second;
    }
}

void topView(struct Node *root)
{
    // <node, dist> depth
    queue<pair<pair<Node*,int>, int>> levelOrder;
    levelOrder.push(make_pair(make_pair(root,0),0));
    pair<pair<Node*,int>,int> tempNode = levelOrder.front();
    // map : dist, <data,depth>
    map<int,pair<int,int>> TreeMap;
    while(tempNode.first.first != NULL){
        TreeMap.insert(make_pair(tempNode.first.second, make_pair(tempNode.first.first->data,tempNode.second)));
        if(tempNode.first.first->left != NULL){
            levelOrder.push(make_pair(make_pair(tempNode.first.first->left,tempNode.first.second - 1), tempNode.second + 1));
        }
        if(tempNode.first.first->right != NULL){
            levelOrder.push(make_pair(make_pair(tempNode.first.first->right,tempNode.first.second + 1), tempNode.second + 1));
        }

        levelOrder.pop();
        if(!levelOrder.empty()){
            tempNode = levelOrder.front();
        } else{
            tempNode.first.first = NULL;
        }
    }

    // vector : dist, <data,depth>
    vector<pair<int, pair<int,int>>> depthWise;

    //map : dist, <data,depth>
    for(map<int,pair<int,int>>::iterator it = TreeMap.begin(); it != TreeMap.end(); ++it ){
        depthWise.push_back((*it));
    }

    sort(depthWise.begin(), depthWise.end(), comparator);
    for(vector<pair<int, pair<int,int>>>::iterator it = depthWise.begin(); it != depthWise.end(); ++it){
        cout << (*it).second.first <<" ";
    }
    return;
}
