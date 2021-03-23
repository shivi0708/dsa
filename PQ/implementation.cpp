#include<bits/stdc++.h>
using namespace std;

class priorityqueue{
    vector<int>pq;
    public:
        priorityqueue(){

        }
        bool isempty(){
            return pq.size()==0;
        }

        int getsize(){
            return pq.size();
        }

        int getmin(){
            if(isempty()){
                return 0;
            }
            return pq[0];
        }

        void insert(int data){
            pq.push_back(data);
            int childindex=pq.size()-1;

            while(childindex>0){
            int parentindex = (childindex-1)/2;

            if(pq[childindex]<pq[parentindex]){
                swap(pq[childindex], pq[parentindex]);
                childindex = parentindex;
            }
            else{
                break;
            }
        }
        }
}
;

int main(){

}