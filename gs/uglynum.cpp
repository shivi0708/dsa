#include<bits/stdc++.h>
using namespace std;

unsigned getnum(unsigned n){
    unsigned ugly[n];
    unsigned i2=0,i3=0,i5=0;
    unsigned next2 = 2;
    unsigned next3 = 3;
    unsigned next5 = 5;
    unsigned nextno=1;

    ugly[0]=1;

    for(int i=1;i<n;i++){
        nextno = min(next2, min(next3,next5));
        ugly[i]=nextno;

        if(nextno == next2){
            i2+=1;
            next2 = ugly[i2]*2;
        }

        if(nextno==next3){
            i3+=1;
            next3 = ugly[i3]*3;
        }

        if(nextno == next5){
            i5+=1;
            next5 = ugly[i5]*5;
        }
    }

    return nextno;
}

int main(){
    int n;
    cin>>n;
    cout<<getnum(n)<<endl;
}