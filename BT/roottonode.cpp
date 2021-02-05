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

bool getpath(BTNode<int>*root, int val,vector<int>&v){
    if(root == NULL) return false;
    v.push_back(root->data);
    if(root->data == val){
        return true;
    }
    bool leftf = getpath(root->left,val,v);
    bool rightf = getpath(root->right,val,v);

    if(leftf||rightf){
        return true;
    }
    v.pop_back();
    return false;
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
    int val;
    cout<<"enter node value"<<endl;
    cin>>val;

    vector<int>ans;
    if(getpath(root,val,ans)){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"no path"<<endl;
    }
 }



// tree input : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 