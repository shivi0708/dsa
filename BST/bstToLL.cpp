#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BTNode{

    public:
    T data;
    BTNode *left;
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

class Pair{
    public:
    BTNode<int>* head;
    BTNode<int>* tail;
};

class BST{
    BTNode<int>* root;
    void print(BTNode<int>*root){
        if(root == NULL) return;
        cout<<root->data<<": ";
        if(root->left != NULL){
            cout<<"L:"<<root->left->data;
        }
        if(root->right != NULL){
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        print(root->left);
        print(root->right);
    }

    //T = O(height)
    bool hasdata(BTNode<int>*node, int data){
        if(node == NULL) return false;

        if(node->data == data){
            return true;
        }
        if(node->data > data){
            return hasdata(node->left,data);
        }
        else{
            return hasdata(node->right,data);
        }
    }

    //T = O(height)
    BTNode<int>* insert(BTNode<int>*node, int data){
        if(node == NULL){
            BTNode<int>* n = new BTNode<int>(data);
            return n;
        }
        if(data < node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }

    //T = O(2h) = O(h)
    BTNode<int>* deleteData(BTNode<int>* node, int data){
        if(node == NULL) return NULL;

        if(data > node->data){
            node->right = deleteData(node->right,data);
        }
        else if(data < node->data){
            node->left = deleteData(node->left, data);
        }
        else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->right == NULL){
                BTNode<int>*temp = node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else if(node->left == NULL){
                BTNode<int>*temp = node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else{
                BTNode<int>*minNode = node->right;
                while(minNode->left!=NULL){
                    minNode=minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right,rightMin);
            }
        }
        return node;
    }

    Pair convertll(BTNode<int>* root){
        if(root == NULL){
            Pair ans;
            ans.head = NULL;
            ans.tail = NULL;
            return ans;
        }
        if(root->left == NULL && root->right == NULL){
            Pair p;
            p.head = root;
            p.tail = root;
            return p;
        }
        else if(root->left!=NULL && root->right == NULL){
            Pair leftll = convertll(root->left);
            leftll.tail->right = root;
            Pair ans;
            ans.head = leftll.head;
            ans.tail = root;
            return ans;
        }
        else if(root->left == NULL && root->right!=NULL){
            Pair rightll = convertll(root->right);
            root->right = rightll.head;
            Pair ans;
            ans.head = root;
            ans.tail = rightll.tail;
            return ans;
        }
        else{
            Pair leftll = convertll(root->left);
            Pair rightll = convertll(root->right);
            leftll.tail->right = root;
            root->right = rightll.head;

            Pair ans;
            ans.head = leftll.head;
            ans.tail = rightll.tail;
            return ans;
        }
    }

    public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    void deleteData(int data){
        root = deleteData(root,data);
    }
    void insert(int data){
        root = insert(root,data);
    }
    bool hasdata(int data){
        return hasdata(root,data);
    }
    void print(){
        print(root);
    }
    BTNode<int>*convertll(){
        Pair p = convertll(root);
        BTNode<int>*temp = p.head;
        while(temp!=NULL){
            temp->left = NULL;
            temp = temp->right;
        }
        return p.head;
    }
};


int main(){
    BST b;
    b.insert(4);
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(6);
    b.insert(5);
    b.insert(7);
    b.print();

    BTNode<int>*head = b.convertll();
    BTNode<int>* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }

    cout<<endl;
}