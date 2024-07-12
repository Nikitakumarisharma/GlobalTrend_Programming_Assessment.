#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                ss << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null ";
            }
        }
        
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return NULL;
        
        stringstream ss(data);
        string item;
        getline(ss, item, ' ');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (getline(ss, item, ' ')) {
                if (item != "null") {
                    TreeNode* leftNode = new TreeNode(stoi(item));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }
            
            if (getline(ss, item, ' ')) {
                if (item != "null") {
                    TreeNode* rightNode = new TreeNode(stoi(item));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        
        return root;
    }
};

// Function to create a new node
TreeNode* newNode(int data)
{
    TreeNode* node = new TreeNode(data);
    node->left = node->right = NULL;
    return (node);
}

int main() {
    Codec codec;

    // Create the binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);

    // Serialize the tree
    string serializedTree = codec.serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    // Deserialize the tree
    TreeNode* deserializedTree = codec.deserialize(serializedTree);
    string checkSerialization = codec.serialize(deserializedTree);
    cout << "Check Serialization: " << checkSerialization << endl;

    return 0;
}
