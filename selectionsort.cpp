#include<bits/stdc++.h>
using namespace std;

void selectionsort(int a[],int n){
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i+1;j<=n-1;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        
            swap(a[i],a[min]);
        
    }
}

int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    selectionsort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}