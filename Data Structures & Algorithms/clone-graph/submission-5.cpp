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
    unordered_map<Node *, Node *> mp;
public:
    Node* cloneGraph(Node* node) {
        return dfs(node, mp);
    }

    Node * dfs(Node * node, unordered_map<Node *, Node *>&mp) {
        if (node == nullptr) {
            return nullptr;
        }

        // if visited
        if (mp.count(node)) {
            return mp[node];
        }

        Node * newNode = new Node(node->val);
        mp[node] = newNode;

        // neighbor is a Node*
        for (auto & neighbor : node->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor, mp));
        }
        return newNode;
    }
};
