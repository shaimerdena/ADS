//linear probing

#include <iostream>
#include <vector>
using namespace std;

long long base = 31;

struct hashtable{
    struct item{
        string key;
        int value;
        bool occupied;
        bool deleted;
        item() : key(""), value(0), deleted(false), occupied(false){}
    };

    vector<item> table;
    int size;

    hashtable(int n){
        size = n;
        table.resize(size);
    }

    long long hash_func(const string &key){
        unsigned long long hash = 0;
        for(char c : key){
            hash = (hash * 31 + c) % size;
        }
        return hash % size;
    }

    void insert(const string &key, int value){
        int index = hash_func(key);
        int start = index;
        int first_deleted = -1;

        while (table[index].occupied) {
            if (!table[index].deleted && table[index].key == key) {
                // Если ключ уже есть, обновляем значение
                table[index].value = value;
                return;
            }
            if (table[index].deleted && first_deleted == -1) {
                first_deleted = index; // Запоминаем первый удалённый слот
            }
            index = (index + 1) % size;
            if (index == start) break; // Обошли всю таблицу
        }

        if (first_deleted != -1) index = first_deleted; // Вставляем на удалённое место

        table[index].key = key;
        table[index].value = value;
        table[index].occupied = true;
        table[index].deleted = false;
    }

    bool search(const string &key){
        int index = hash_func(key);
        int start = index;

        while(table[index].occupied){
            if(!table[index].deleted && table[index].key == key){
                return true;
            }
            index = (index + 1)%size;
            if(index == start){
                break;
            }
        }
        return false;
    }

    void remove(const string &key){
        int index = hash_func(key);
        int start = index;

        while(table[index].occupied){
            if(!table[index].deleted && table[index].key == key){
                table[index].deleted = true;
                return;
            }
            index = (index + 1)%size;
            if(index == start){
                break;
            }
        }
    }

    void print(){
        for(int i=0; i<size; i++){
            if(table[i].occupied && !table[i].deleted){
                cout << i << ": " << table[i].key << " -> " << table[i].value << endl;
            }
            else{
                cout << i << ": " << "[empty]" << endl;
            }
        }
    }
};

int main(){
    hashtable ht(7);

    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("orange", 30);
    ht.insert("melon", 40);

    cout << "Initial table:\n";
    ht.print();

    cout << "\nSearching 'banana': " << (ht.search("banana") ? "found" : "not found") << "\n";

    ht.remove("banana");
    cout << "\nAfter deleting 'banana':\n";
    ht.print();

    return 0;
}