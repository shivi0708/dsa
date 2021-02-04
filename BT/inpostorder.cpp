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


BTNode<int>* helper(vector<int>In,vector<int>Post,int ins, int ine, int pos, int poe){
    if(ins>ine ){
        return NULL;
    }
    int rootdata = Post[poe];
    int rootindex=-1;
    for(int i=ins;i<=ine;i++){
        if(In[i]==rootdata){
            rootindex=i;
            break;
        }
    }
    int leftins = ins;
    int leftine = rootindex-1;
    int leftpos = pos;
    int leftpoe = leftpos+leftine-leftins;

    int rightins = rootindex+1;
    int rightine = ine;
    int rightpos = leftpoe+1;
    int rightpoe = poe-1;

    BTNode<int>*root = new BTNode<int>(rootdata);
    root->left = helper(In,Post,leftins,leftine,leftpos,leftpoe);
    root->right = helper(In,Post,rightins,rightine,rightpos,rightpoe);

    return root;
}

BTNode<int>* buildtree(vector<int>&In,vector<int>&Pre){
    int n = In.size();
    return helper(In,Pre,0,n-1,0,n-1);

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
 }



// tree input : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 