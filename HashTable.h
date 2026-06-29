#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class HashTable
{
private:
    int tableSize;
    int itemCount;

    // Each bucket stores a list of key-value pairs.
    // This allows multiple keys to exist in the same bucket if a collision occurs.
    vector<list<pair<string, int>>> table;

    int hashFunction(const string& key) const;

public:
    HashTable(int size);

    void insert(const string& key, int value);
    bool search(const string& key) const;
    void remove(const string& key);
    void printTable() const;
    double loadFactor() const;
};

#endif
