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

void printlevel(TreeNode<int>*root){
  
    queue<TreeNode<int>*>q1;
    q1.push(root);
    while(!q1.empty()){
        TreeNode<int>* f = q1.front();
        q1.pop();
        cout<<f->data<<": ";
        for(int i=0;i<f->children.size();i++){
            cout<<f->children[i]->data<<", ";
        }
        cout<<endl;

        for(int i=0;i<f->children.size();i++){
            q1.push(f->children[i]);
        }
    }

}


TreeNode<int>* takeinputlevel(){
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>*front = q.front();
        q.pop();
        cout<<"enter no. of children of "<<front->data<<endl;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int child;
            cout<<"enter "<<i+1<<"th child of "<<front->data<<endl;
            cin>>child;

            TreeNode<int>*childd = new TreeNode<int>(child);
            q.push(childd);
            front->children.push_back(childd);
        }
    }
    return root;
}


void preorder(TreeNode<int>* root){
    if(root == NULL ){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}


void postorder(TreeNode<int>* root){
     if(root == NULL ){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
        cout<<root->data<<" ";

}

int main(){
    
    TreeNode<int> *root = takeinputlevel();

    printlevel(root);
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal: "<<endl;
    postorder(root);
    
    }