//using unordered_map
#include<bits/stdc++.h>
using namespace std;

vector<int>remove(int *arr,int n){
    vector<int>ans;
    unordered_map<int,bool>mymap;
    for(int i=0;i<n;i++){
        if(mymap.count(arr[i])==0){
            ans.push_back(arr[i]);
            mymap[arr[i]]=true;
        }
    }
    return ans;
}

int main(){

int a[]={2,3,4,1,5,6,1,2,4,6,7};
vector<int>output = remove(a,11);
for(int i=0;i<output.size();i++){
    cout<<output[i]<<" ";
}
cout<<endl;
}