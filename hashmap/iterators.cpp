#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int>mymap;
    mymap["abc"] = 1;
    mymap["def"] = 2;
    mymap["ghi"] = 3;
    mymap["jkl"] = 4;
    mymap["mno"] = 5;
    mymap["pqr"] = 6;

    for(unordered_map<string,int>::iterator it=mymap.begin();it!=mymap.end();it++){
        cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
    }
    cout<<endl;

    for(auto it=mymap.begin();it!=mymap.end();it++){
        cout<<it->first<<"->";
    }
    cout<<endl;

    map<string, int>mymap1;
    mymap1["abc"] = 1;
    mymap1["def"] = 2;
    mymap1["ghi"] = 3;
    mymap1["jkl"] = 4;
    mymap1["mno"] = 5;
    mymap1["pqr"] = 6;

    for(map<string,int>::iterator it=mymap1.begin();it!=mymap1.end();it++){
        cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
    }

    unordered_map<string,int>::iterator it = mymap.find("abc");
        mymap.erase(it);
    

    //finding element
    if(mymap.find("abc")==mymap.end()){
        cout<<"not present"<<endl;
    }
    else{
        cout<<"present"<<endl;
    }
}