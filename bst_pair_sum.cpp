#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


vector<int>datas;
unordered_set<int> uset;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}



Node* insert(Node* root, int data){
    if(root == NULL){
        root = newNode(data);
        return root;
    }
    if(data > root->data){
        root->right = insert(root->right, data);
    }
    else if(data < root->data){
        root->left = insert(root->left,data);
    }
    return root;

}

void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    datas.push_back(root->data);
    uset.insert(root->data);
    inorder(root->right);
}

 void findPair(int sum){
     
     int i ;
     for(i=0;i<datas.size();i++){
        if(sum - datas[i] != datas[i] && uset.find(sum - datas[i]) != uset.end()){
            cout << datas[i] << " " << sum-datas[i] << endl;

        }
     }

    
 }




int main(){
    int i;
    Node* root = NULL; 
    root = insert(root, 15); 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 12); 
    root = insert(root, 16); 
    root = insert(root, 25); 
    root = insert(root, 10); 
  
    int sum = 33; 
    inorder(root);
    for(i=0;i<datas.size();i++){
        cout << datas[i] << " ";
    }
    cout << endl;
    findPair(sum); 
  
    return 0; 
}