//quadratic probing (mid square method)

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

    HashTable(int n) : size(n) {
        table.resize(size);
    }

    long long hash_func(const string &key) {
        long long hash = 0;
        long long base = 31;
        for (char c : key) {
            hash = (hash * base + c) % size;
        }
        return hash % size;
    }

    void insert(const string &key, int value) {
        int h = hash_func(key);
        int first_deleted = -1;

        for (int i = 0; i < size; i++) {
            int index = (h + i*i) % size;  // квадратичное пробирование

            if (!table[index].occupied) {
                if (first_deleted != -1) index = first_deleted;
                table[index].key = key;
                table[index].value = value;
                table[index].occupied = true;
                table[index].deleted = false;
                return;
            }

            if (!table[index].deleted && table[index].key == key) {
                table[index].value = value; // обновляем существующий ключ
                return;
            }

            if (table[index].deleted && first_deleted == -1) {
                first_deleted = index; // запоминаем место удалённого
            }
        }

        cout << "Hash table is full!" << endl;
    }

    bool search(const string &key) {
        int h = hash_func(key);
        for (int i = 0; i < size; i++) {
            int index = (h + i*i) % size;
            if (!table[index].occupied) return false;
            if (!table[index].deleted && table[index].key == key) return true;
        }
        return false;
    }

    void remove(const string &key) {
        int h = hash_func(key);
        for (int i = 0; i < size; i++) {
            int index = (h + i*i) % size;
            if (!table[index].occupied) return;
            if (!table[index].deleted && table[index].key == key) {
                table[index].deleted = true;
                return;
            }
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
    HashTable ht(7);

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

    ht.insert("grape", 50);
    cout << "\nAfter inserting 'grape':\n";
    ht.print();

    return 0;
}
