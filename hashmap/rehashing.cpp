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

    void rehash(){
        Mapnode<V>** temp = buckets;
        buckets = new Mapnode<V>*[2*bucketsize];
        for(int i =0;i<2*bucketsize;i++){
            buckets[i] = NULL;
        }
        int oldbucketsize = bucketsize;
        bucketsize*=2;
        count =0;

        for(int i =0;i<oldbucketsize;i++){
            Mapnode<V>* head = temp[i];
            while(head!=NULL){
                string key = head->key;
                V value = head->value;
                 insert(key,value);
                head = head->next;
            }
        }
        for(int i=0;i<oldbucketsize;i++){
            delete temp[i];
        }
        delete []temp;
    }

    public:
    mymap(){
        count = 0;
        bucketsize = 5;
        buckets = new Mapnode<V>*[bucketsize];
        for(int i =0;i<bucketsize;i++){
            buckets[i] = NULL;
        }
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
        int bucketindex = getbucketindex(key);
        Mapnode<V>* head = buckets[bucketindex];
        while(head!=NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
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

        double loadfactor = (1.0*count)/bucketsize;
        if(loadfactor>0.7){
            rehash();
        }
    }

    V remove(string key){
        int bucketindex = getbucketindex(key);
        Mapnode<V>*head = buckets[bucketindex];
        Mapnode<V>* prev = NULL;
        while (head!=NULL)
        {
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketindex] = head->next;
                }
            else{
                    prev->next = head->next;
            }
            V value = head->value;
            head->next = NULL;
            delete head;
            count--;
            return value;
        }
            prev = head;
            head=head->next;
        }
        return 0;
    }
    double getloadf(){
        return (1.0*count)/bucketsize;
    }
};


int main(){
    mymap<int> ourmap;
    for(int i=0;i<10;i++){
        char c = '0'+i;
        string key = "abc";
        key = key+c;

        int value = i+1;
        ourmap.insert(key,value);
        // cout<<ourmap.getloadf()<<endl;
    }

    for(int i=0;i<10;i++){
        char c = '0'+i;
        string key = "abc";
        key = key+c;
        cout<<key<<": "<<ourmap.getvalue(key)<<endl;
    }

    cout<<"Map Size: "<<ourmap.size()<<endl;

    ourmap.remove("abc1");
    ourmap.remove("abc6");

    cout<<"Deleting abc and abc6"<<endl;
    for(int i=0;i<10;i++){
        char c = '0'+i;
        string key = "abc";
        key = key+c;
        cout<<key<<": "<<ourmap.getvalue(key)<<endl;
    }

    cout<<"Map Size: "<<ourmap.size()<<endl;
}