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


int height(BTNode<int>*root){
    if(root == NULL) return 0;
    return 1+max(height(root->left),height(root->right));

}

int diameter(BTNode<int>* root){
    if(root == NULL) return 0;

    int ans1 = height(root->left) + height(root->right);
    int ans2 = diameter(root->left);
    int ans3 = diameter(root->right);

    return max(ans1, max(ans2, ans3));
}

pair<int,int> height1(BTNode<int>*root){
    if(root == NULL){
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>leftans = height1(root->left);
    pair<int,int>rightans = height1(root->right);

    int lh = leftans.first;
    int ld = leftans.second;

    int rh=rightans.first;
    int rd=rightans.second;

    int height = 1+max(lh,rh);
    int diameter = max(lh+rh,max(ld,rd));
    pair<int,int>p;
    p.first = height;
    p.second = diameter;

    return p;
}

int diameterother(BTNode<int>*root){
    pair<int,int>p = height1(root);
    return p.second;
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

    cout<<"Diameter of the tree is: "<<diameter(root)<<endl;
    cout<<"Other way diameter: "<<diameterother(root)<<endl;
 }



// tree input : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 