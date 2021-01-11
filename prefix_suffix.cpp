#include<iostream>
#include<cstring>
using namespace std;

void printPrefix(char str[]){
    for(int e=0;str[e]!='\0';e++){
        for(int s=0;s<=e;s++){
        cout<<str[s];
    }
    cout<<endl;
    }
}

void printSuffix(char str[]){
     for(int s=strlen(str);s>=0;s--){
        for(int e=strlen(str);e>=s;e--){
            cout<<str[strlen(str)-e+s];
        }
        cout<<endl;
    }
}

int main(){
    char str[20];
    cin>>str;
    printPrefix(str);
    cout<<"suffix now"<<endl;
    printSuffix(str);
}