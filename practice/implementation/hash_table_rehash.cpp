//rehashing for open addressing

#include <iostream>
#include <vector>
using namespace std;

struct HashTable {
    struct Item {
        string key;
        int value;
        bool occupied;
        bool deleted;
        Item() : key(""), value(0), occupied(false), deleted(false) {}
    };

    vector<Item> table;
    int size;
    int count;

    HashTable(int n) : size(n), count(0) {
        table.resize(size);
    }

    // Simple hash function
    int hash_func(const string &key) {
        unsigned long long hash = 0;
        for (char c : key)
            hash = (hash * 31 + c) % size;
        return hash;
    }

    void insert(const string &key, int value) {
        if ((double)count / size > 0.7)  // load factor > 0.7 → rehash
            rehash();

        int index = hash_func(key);
        while (table[index].occupied && !table[index].deleted && table[index].key != key)
            index = (index + 1) % size;

        table[index].key = key;
        table[index].value = value;
        table[index].occupied = true;
        table[index].deleted = false;
        count++;
    }

    void rehash() {
        cout << "Rehashing... new size: " << size * 2 << endl;

        vector<Item> old_table = table;
        size *= 2;
        count = 0;
        table.clear();
        table.resize(size);

        for (auto &item : old_table) {
            if (item.occupied && !item.deleted)
                insert(item.key, item.value);  // re-insert into new table
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            if (table[i].occupied && !table[i].deleted)
                cout << i << ": " << table[i].key << " -> " << table[i].value << endl;
            else
                cout << i << ": [empty]" << endl;
        }
    }
};

int main() {
    HashTable ht(5);
    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("orange", 30);
    ht.insert("melon", 40);
    ht.insert("grape", 50);

    cout << "\nFinal table:\n";
    ht.print();
    return 0;
}
