#include "HashTable.h"

HashTable::HashTable(int size)
{
    tableSize = size;
    itemCount = 0;
    table.resize(tableSize);
}

int HashTable::hashFunction(const string& key) const
{
    int hashValue = 0;

    // Convert each character into an integer value.
    // Multiplying by 31 helps spread similar strings into different buckets.
    for (char ch : key)
    {
        hashValue = (hashValue * 31 + ch) % tableSize;
    }

    return hashValue;
}

void HashTable::insert(const string& key, int value)
{
    int index = hashFunction(key);

    // If the key already exists, update its value instead of inserting a duplicate.
    for (auto& pair : table[index])
    {
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }

    // Collision handling:
    // If another key is already in this bucket, the new pair is added to the same list.
    table[index].push_back({key, value});
    itemCount++;
}

bool HashTable::search(const string& key) const
{
    int index = hashFunction(key);

    for (const auto& pair : table[index])
    {
        if (pair.first == key)
        {
            return true;
        }
    }

    return false;
}

void HashTable::remove(const string& key)
{
    int index = hashFunction(key);

    for (auto it = table[index].begin(); it != table[index].end(); it++)
    {
        if (it->first == key)
        {
            table[index].erase(it);
            itemCount--;
            return;
        }
    }
}

double HashTable::loadFactor() const
{
    return static_cast<double>(itemCount) / tableSize;
}

void HashTable::printTable() const
{
    cout << "Hash Table\n\n";

    for (int i = 0; i < tableSize; i++)
    {
        cout << "Bucket " << i << ": ";

        if (table[i].empty())
        {
            cout << "Empty";
        }
        else
        {
            for (const auto& pair : table[i])
            {
                cout << "(" << pair.first << ", " << pair.second << ") ";
            }
        }

        cout << endl;
    }

    cout << "\nLoad Factor: " << loadFactor() << endl;
}
