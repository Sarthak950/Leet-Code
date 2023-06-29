#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:


    void connectHelp(Node* root){
        if( root == NULL )  return;

        queue<Node*> q;
        q.push(root);

        while( !q.empty() ){
    
            int size = q.size();
            Node* prev = NULL;

            for( int i = 0; i < size; i++ ){
                Node* curr = q.front();
                q.pop();

                if( prev != NULL )  prev->next = curr;
                prev = curr;

                if( curr->left != NULL )    q.push(curr->left);
                if( curr->right != NULL )   q.push(curr->right);
            }

        }
    }

/* Here is the explanation for the code above:
1. We will use BFS to traverse the tree. We will use a queue to store the nodes of the tree.
2. We will use a prev pointer to keep track of the previous node of the current node.
3. We will pop the nodes from the queue one by one. 
4. If prev is not null, it means we have already processed a node before the current node. 
So, we will make the next pointer of prev to point to the current node.
5. After that, we will update the prev pointer to point to the current node.
6. Then we will check if the left child of the current node exists, if it exists we will push it into the queue.
7. Then we will check if the right child of the current node exists, if it exists we will push it into the queue.
8. After we have processed all the nodes in the current level, we will go to the next level and process all the nodes in that level.
9. We will do this until the queue becomes empty which means we have processed all the nodes of the tree. */

    Node* connect(Node* root) {
       connectHelp(root);
       return root;
    }
};



int main(){
    return 0;
}
