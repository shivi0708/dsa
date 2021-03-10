#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
};

bool isoverlap(point l1, point r1, point l2, point r2){
    if(l1.x>=r2.x || l2.x>=r1.x)
    return false;
    if(l1.y<=r2.y || l2.y<=r1.y)
    return false;

    return true;
}

int main(){
    point l1,r1,l2,r2;
    cout<<"enter x and y for l1"<<endl;
    cin>>l1.x>>l1.y;

    cin>>r1.x>>r1.y;

    cin>>l2.x>>l2.y>>r2.x>>r2.y;

    if(isoverlap)
    cout<<"Overlap"<<endl;
    else
    {
        cout<<"don't overlap"<<endl;
    }
    
}