#include<bits/stdc++.h>
using namespace std;

// LEVEL ORDER TRAVERSAL space and time complexity both O(n).

template<typename T>
class BTNode{
    public:
        T data;
        BTNode* left;
        BTNode *right;

        BTNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BTNode(){
            delete left;
            delete right;
        }
};


BTNode<int>* inputlevel(){
    int rootdata;
    cout<<"enter data"<<endl;
    cin>>rootdata;

    BTNode<int>*root = new BTNode<int>(rootdata);
    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BTNode<int>*f = q.front();
        q.pop();
        cout<<"enter left child of "<<f->data<<endl;
        int leftc;
        cin>>leftc;
        if(leftc!=-1){
            BTNode<int>*l = new BTNode<int>(leftc);
            q.push(l);
            f->left=l;
        }

        cout<<"enter right child of "<<f->data<<endl;
        int rightc;
        cin>>rightc;
        if(rightc!=-1){
            BTNode<int>*r = new BTNode<int>(rightc);
            q.push(r);
            f->right=r;
        }
    }

    return root;
}

vector<vector<int>> levelprint(BTNode<int>* root){
    vector<vector<int>>v;
    vector<int>temp;
    queue<BTNode<int>*> q;
    if(root == NULL){
        return v;
    }
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        BTNode<int>*f = q.front();
        q.pop();
        if(f == NULL){
            v.push_back(temp);
            temp.clear();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            temp.push_back(f->data);
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return v;
}

//T & S = 0(n)
bool isbst(BTNode<int>*root, long long minv=-10000000000, long long maxv=10000000000){
    if(root == NULL){
        return true;
    }
    bool lef = isbst(root->left,minv,root->data);
    bool righ = isbst(root->right,root->data,maxv);

    if(lef&&righ&&root->data>minv&&root->data<maxv)
    return true;

    return false;

}

bool ifBST(BTNode<int>*root){
    return isbst(root);
}

int main(){
    BTNode<int>*root = inputlevel();

    vector<vector<int>> v = levelprint(root);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    if(ifBST(root))
    cout<<"YEs a BST"<<endl;
    else
    {
        cout<<"Not BST"<<endl;
    }
    
   
  }



