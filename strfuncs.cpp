#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char str1[20];
    char str2[20];
    cin.getline(str1,20);
    cin.getline(str2,20);
    cout<<"before strcpy: "<<str1<<" "<<str2<<endl;
    // strcpy(str1,str2);
    // cout<<"after strcpy: "<<str1<<" "<<str2<<endl;
    strncpy(str1,str2,4);
    cout<<"after strncpy: "<<str1<<" "<<str2<<endl;
    cout<<"after concatenate: "<<strcat(str1,str2)<<endl;
}