/*
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==nullptr)
        return root;
        q.push(root);
        while(q.size()!=0)
        {
            // cout<<q.size()<<endl;

            Node* t=q.front();
            q.pop();
            vector<Node*> nextLevel;
            Node* n=nullptr;
            while(q.size()!=0)
            {
                n=q.front();
                q.pop();
                t->next=n;
                // cout<<t->val<<" "<<n->val<<endl;
                if(t->left!=nullptr)
                nextLevel.push_back(t->left);
                if(t->right!=nullptr)
                nextLevel.push_back(t->right);
                t=n;
            }

                if(t->left!=nullptr)
                nextLevel.push_back(t->left);
                if(t->right!=nullptr)
                nextLevel.push_back(t->right);
            for(auto i:nextLevel)
            {
                q.push(i);
            }
        }
        return root;
    }
};