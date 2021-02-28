#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>v, int sv,vector<bool>&visited){
cout<<sv<<endl;
visited[sv]=true;
int n = v.size();
for(int i=0;i<n;i++){
    if(v[sv][i]==1 && visited[i]==false){
        print(v,i,visited);
    }
}
}

void dfs(vector<vector<int>>matrix){
    int n = matrix.size();
    int count =0;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
    print(matrix,i,visited);
}
}
cout<<"No of connected componens: "<<count<<endl;
}



int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<vector<int>> matrix(vertices,vector<int>(vertices,0));
    for(int i =1;i<=edges;i++){
        int fv,sv;
        cin>>fv>>sv;
        matrix[fv][sv]=1;
        matrix[sv][fv]=1;
    }
    vector<bool>visited(vertices,false);
    cout<<"DFS"<<endl;
    dfs(matrix);
}    