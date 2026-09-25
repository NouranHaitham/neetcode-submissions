/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

public:
    Node* cloneGraph(Node* node) {
    
    if(!node) return node;

    queue<pair<Node*,Node*>> q;
    unordered_map<int,Node*> vis;

    Node*root = new Node(node->val);

    q.push({node,root});
    vis.insert({node->val,root});

    while(q.size())
    {
        auto [curr_node, curr_temp]  = q.front();
        q.pop();

        for(auto child: curr_node->neighbors)
        {  
            if(vis.count(child->val) == 0)
            {
                curr_temp->neighbors.push_back(new Node(child->val));
                q.push({child,curr_temp->neighbors.back()});
                vis.insert({child->val,curr_temp->neighbors.back()});
            }
            else
            {
                  curr_temp->neighbors.push_back(vis[child->val]);
            }

        }

    }
    
    return root;
        
    }
};
