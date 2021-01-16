#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data = data;
    }
};

void print(TreeNode<int>*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
}


int main(){
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* left = new TreeNode<int>(2);
    TreeNode<int>* right = new TreeNode<int>(3);

    root->children.push_back(left);
    root->children.push_back(right);

    print(root);
}