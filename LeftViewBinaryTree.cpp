/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// A wrapper over leftViewUtil()
void leftView(Node *root){
   unordered_map<int, bool> levelSeen;
   queue<pair<Node*,int>> myQueue;
   pair<Node*,int> temp = make_pair(root,0);
   myQueue.push(make_pair(root,0));

   while(temp.first != NULL){
       if(!levelSeen[temp.second]){
           cout << temp.first->data << " ";
           levelSeen[temp.second] = true;
       }

       if(temp.first->left != NULL){
           myQueue.push(make_pair(temp.first->left, (temp.second + 1)));
       }
       if(temp.first->right != NULL){
           myQueue.push(make_pair(temp.first->right, (temp.second + 1)));
       }

       myQueue.pop();
       if(!myQueue.empty()){
           temp = myQueue.front();
       } else {
           temp.first = NULL;
       }
   }
   return;
}
