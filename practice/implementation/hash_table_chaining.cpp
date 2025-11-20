//chaining

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int hash_function(const string &key, int table_size){
    int h = 0;
    for(char c : key){
        h = (h + c) % table_size;
    }
    return h;
}

struct hashtable{
    int size;
    vector<list<string>> table;

    hashtable(int s){
        size = s;
        table.resize(size);
    }
    void insert(const string &key){
        int idx = hash_function(key, size);
        table[idx].push_back(key);
    }
    bool search(const string &key){
        int idx = hash_function(key,size);
        for(string item : table[idx]){
            if(item == key){
                return true;
            }
        }
        return false;
    }
    void print(){
        for(int i=0; i<size; i++){
            cout << i << ": ";
            for(string item : table[i]){
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    hashtable ht(7);
    ht.insert("abs");
    ht.insert("ub");
    ht.insert("sba");
    ht.insert("god");
    ht.print();
    cout << (ht.search("dog") ? "Found" : "Not found") << endl;
    cout << (ht.search("cow") ? "Found" : "Not found") << endl;
    return 0;
}