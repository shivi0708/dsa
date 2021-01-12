#include <bits/stdc++.h>
using namespace std;

int main(){
    string str="hello";
    string str1="cabs";
    vector<string>v;
    v.push_back(str);
    v.push_back(str1);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
        sort(v[i].begin(),v[i].end());
        cout<<"after sort: "<<v[i]<<endl;
    }

    string s3;

    getline(cin,s3);
    cout<<s3<<endl;

    string s4 = "abcabc";
    cout<<s4[2]<<endl;

    string s5[10];
    for(int i=0;i<3;i++)
    getline(cin,s5[i]);

     for(int i=0;i<10;i++)
    cout<<s5[i]<<"  *  ";

    string s = str1 + str + " heyaa 1";
    cout<<s.size()<<endl;
    cout<<s<<endl;
    cout<<s.length()<<endl;
    // s.substr(start,no.of.char);
    cout<<s.substr(3)<<endl;

    int a=45678;
    string ss = to_string(a);
    cout<<ss[2]<<endl;

    int b = atoi(ss.c_str());
    cout<<b<<endl;

}