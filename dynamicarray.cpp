#include<bits/stdc++.h>
using namespace std;

class dynamicarray{
    int *data;
    int nextindex;
    int capacity;

    public:
    dynamicarray(){
        data=new int[5];
        nextindex=0;
        capacity=5;
    }

    void add(int element){
        if(nextindex==capacity){
            int *newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
            delete []data;
            data=newdata;
            capacity=capacity*2;
        }
        data[nextindex]=element;
        nextindex++;
    }

    void add(int element, int i){
        if(i<nextindex){
            data[i]=element;
        }
        else if(i==nextindex){
            add(element);
        }
        else{
            return;
        }
    }

    int get(int i){
        if(i>=0 && i<nextindex){
            return data[i];      
        }
        else
        {
            return -1;
        }
        
    }

    void print(){
        for(int i=0;i<nextindex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    dynamicarray d;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    d.add(i+1);

    d.print();

    d.add(10,5);
    d.print();

}