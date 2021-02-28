#include<bits/stdc++.h>
using namespace std;

void bfsprint(vector<vector<int>> v, int sv, vector<bool>&visited){
    int n = v.size();
    queue<int>q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int cv = q.front();
        q.pop();
        cout<<cv<<endl;
        for(int i=0;i<n;i++){
            if(v[cv][i] && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

void bfs(vector<vector<int>> matrix){
        int n = matrix.size();
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
    bfsprint(matrix,i,visited);
}
}
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
    cout<<"BFS"<<endl;
    bfs(matrix);
}