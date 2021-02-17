#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> mymap;
    pair<string,int>p("abc",1);
    mymap.insert(p);

    mymap["def"] = 2;
    cout<<mymap["abc"]<<endl;

    cout<<mymap.at("abc")<<endl;

    // cout<<mymap.at("ghi")<<endl;

    cout<<mymap["ghi"]<<endl; //push "ghi" def value 0

    cout<<"Size: "<<mymap.size()<<endl;
    //check if key is present
    if(mymap.count("ghi")){
        cout<<"present"<<endl;
    }
    else{
        cout<<"not present"<<endl;
    }

    //update keys
    mymap["abc"] = 20;
    mymap.erase("ghi");

    cout<<"Size: "<<mymap.size()<<endl;


}