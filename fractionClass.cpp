#include<bits/stdc++.h>
using namespace std;

class fraction{
    int numer,denom;

    public:
    fraction( int n, int d){
        numer = n;
        denom = d;
    }

    void print(){
        cout<<"numerator: "<<numer<<" "<<"denominator is: "<<denom<<endl;
    }

    void add(fraction f2){
        int lcm = this->denom * f2.denom;
        int x = lcm/denom;
        int y = lcm/f2.denom;
        int num = x*numer + y*f2.numer;

        this->numer = num;
        this->denom = lcm;
    }
}

int main(){

}