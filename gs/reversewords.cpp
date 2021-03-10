#include<bits/stdc++.h>
using namespace std;

void reverseword(string s){
    vector<string>ans;
    string st="";

    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            ans.push_back(st);
            st="";
        }

        else{
            st+=s[i];
        }
    }
    ans.push_back(st);

    for(int i=ans.size()-1;i>0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<ans[0];
    cout<<endl;
}

int main(){
    string s;
    cout<<"Enter the string"<<endl;
    getline(cin,s);
   reverseword(s);

}