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
    cout<<"Level Order print"<<endl;
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

int countnode(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int count =1;
    for(int i=0;i<root->children.size();i++){
        count += countnode(root->children[i]);
    }

    return count;
}

int height(TreeNode<int>*root){
    if(root == NULL){
        return 0;
    }
    int mx = 0;
    for(int i=0;i<root->children.size();i++){
        // int childheight = height(root->children[i]);
        // if(childheight>max){
        //     max = childheight;
        // }
        mx = max(mx,height(root->children[i]));
    }

    return mx+1;
}

int main(){
    TreeNode<int> *root = takeinputlevel();

    printlevel(root);

    cout<<"number of nodes are: "<<countnode(root)<<endl;

    cout<<"height of the tree is: "<<height(root)<<endl;
}