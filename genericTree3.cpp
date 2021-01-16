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

int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* left = new TreeNode<int>(2);
    // TreeNode<int>* right = new TreeNode<int>(3);

    // root->children.push_back(left);
    // root->children.push_back(right);

    TreeNode<int> *root = takeinputlevel();

    print(root);
}