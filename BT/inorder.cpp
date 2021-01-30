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

//INORDER

void inord(BTNode<int>*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    inord(root->left,ans);
    ans.push_back(root->data);
    inord(root->right,ans);
}

vector<int>inorder(BTNode<int>*root){
    vector<int>ans;
    inord(root,ans);
    return ans;
}

//PREORDER

void preord(BTNode<int>*root, vector<int>&preans){
    if(root==NULL) return;

    preans.push_back(root->data);
    preord(root->left,preans);
    preord(root->right,preans);
}

vector<int> preorder(BTNode<int>* root){
    vector<int>preans;
    preord(root,preans);
    return preans;
}

//POSTORDER
void postord(BTNode<int>*root, vector<int>&postans){
    if(root==NULL) return;

    postord(root->left,postans);
    postord(root->right,postans);
    postans.push_back(root->data);
}

vector<int> postorder(BTNode<int>* root){
    vector<int>postans;
    postord(root,postans);
    return postans;
}


int main(){
    BTNode<int>*root = inputlevel();
    cout<<"LevelOrder"<<endl;
  vector<vector<int>> v = levelprint(root);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    vector<int>ans = inorder(root);
    cout<<"inorder traversal"<<endl;
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl;

    vector<int>preans = preorder(root);
    cout<<"preorder traversal"<<endl;
    for(int i=0;i<preans.size();i++)
    cout<<preans[i]<<" ";
    cout<<endl;

     vector<int>postans = postorder(root);
    cout<<"postorder traversal"<<endl;
    for(int i=0;i<postans.size();i++)
    cout<<postans[i]<<" ";
    cout<<endl;

    delete root;
}



// tree input : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 