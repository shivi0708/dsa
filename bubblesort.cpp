#include<bits/stdc++.h>
using namespace std;

void bubblesort(int a[], int n){
    for(int count = 1;count<=n-1;count++){
        for(int j=0;j<=n-2;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }   
}

void optimizesort(int a[], int n){
    for(int count = 1;count<=n-1;count++){
        int flag=0;
        for(int j=0;j<=n-2;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }   
}

int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    optimizesort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}