#include<bits/stdc++.h>
using namespace std;

void spiral(int ar[][5], int m, int n){
    int sr=0,sc=0,er=m-1,ec=n-1,count=0;
    vector<int>ans;
    if(m==0) return;
    if(n==0) return;
    while(sr<=er && sc<=ec){
        for(int i=sc;i<=ec;i++){
            ans.push_back(ar[sr][i]);
            count++;
        }
        sr++;
        // if(count == m*n) return;

        for(int i=sr;i<=er;i++){
            ans.push_back(ar[i][ec]);
            count++;
        }
        ec--;
        // if(count == m*n) return;

        for(int i=ec;i>=sc;i--){
            ans.push_back(ar[er][i]);
            count++;
        }
        er--;
        // if(count == m*n) return;

        for(int i=er;i>=sr;i--){
            ans.push_back(ar[i][sc]);
            count++;
        }
        sc++;
        // if(count == m*n) return;

    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int m,n;
    cin>>m>>n;
    int ar[m][5];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>ar[i][j];
        }
    }
    // vector<int>ans=
    
    spiral(ar,m,n);

    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;

}