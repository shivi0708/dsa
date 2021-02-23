#include<bits/stdc++.h>
using namespace std;

template<typename V>
class Mapnode{

    public:
        string key;
        V value;
        Mapnode *next;

    Mapnode(string key, V value){
        this->key  = key;
        this->value = value;
    }
    ~Mapnode(){
        delete next;
    }
};

template<typename V>
class mymap{
    Mapnode<V>** buckets;
    int count;
    int bucketsize;
    int getbucketindex(string key){
        int hashcode = 0;
        int base=1,p=37;
        for(int i=key.size()-1;i>=0;i--){
            hashcode = key[i]*base;
            base*=p;

            hashcode = hashcode%bucketsize;
            base=base%bucketsize;
        }

        return hashcode%bucketsize;
    }

    public:
    mymap(){
        count = 0;
        bucketsize = 5;
        buckets = new Mapnode<V>*(bucketsize);
        memset(buckets,NULL,bucketsize);

    }

    ~mymap(){
        for(int i=0;i<bucketsize;i++){

            delete buckets[i];
        }
        delete []buckets;
    }

    int size(){
        return count;
    }
    
    V getvalue(string key){

    }

    void insert(string key, V value){
        int bucketindex = getbucketindex(key);
        Mapnode<V>* head = buckets[bucketindex];
        while(head!=NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        Mapnode<V>* node = new Mapnode<V>(key,value);
        node->next=buckets[bucketindex];
        buckets[bucketindex] = node;
        count++;
    }

    V remove(string key){

    }
};