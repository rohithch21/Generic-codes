#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
};

Node* newNode(int val){
    Node* node = new Node;
    node->data = val;
    node->left = node->right = NULL; 
}

Node* createBst(Node* root, int val){
    if(root == NULL){
        root = newNode(val);
        return root;
    }
    else if(val < root->data){
        root->left = createBst(root->left,val);
    }
    else{
        root->right = createBst(root->right,val);
    }
    return root;
    
    
}
void inorder(Node* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int heightBST(Node* root){ // max(left_subtree,right_subtree) + 1
    if(root == NULL) return -1;
    return max(heightBST(root->left),heightBST(root->right)) + 1;
}

void level_order(Node* root) {
    queue<Node*>q;

}

int main() {
    Node* root = NULL;
    vector<int>vec{15,10,20,25,8,12,35};
    int i = 0;
    for(i=0;i<vec.size();i++){
        root = createBst(root,vec[i]);
    }
    inorder(root);
    cout << endl;
    cout << "height of bst = " << heightBST(root) << endl;


}