#include<bits/stdc++.h>
using namespace std;

int fib(int *ar, int n){
    if(n==0 || n==1){
    return n;}
    if(ar[n]!=0)
    return ar[n];

    int output = fib(ar,n-1)+fib(ar,n-2);
    ar[n] = output;
    return output;
}

int fib2(int n){
    int *ar = new int[n+1];
    ar[0]=0;
    ar[1]=1;

    for(int i=2;i<=n;i++)
    {
        ar[i] = ar[i-1]+ar[i-2];
    }

    int output=ar[n];
    delete []ar;
    return output;
}

int main(){
    int n;
    cin>>n;
    cout<<fib2(n)<<endl;

    int *arr= new int[n+1];
    memset(arr,0,n+1);
    cout<<fib(arr,n)<<endl;
    delete []arr;

}