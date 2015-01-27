/*
 Name:          Nick Peacock and Giovanni Briggs
 Date:          2/18/2014
 Lab:           Tuesday 215
 Assignment:    Lab 7
 */
#ifndef MAP_H
#define MAP_H

#include "Pair.h"
#include <iostream>
#include <list>

using namespace std;

template<typename K, typename V>
class Map
{
public:
    /**
     Inserts a value into the map.
     @param key the key to insert
     @param value the value to insert
     */
    void insert(K key, V value);
    /**
     Determines whether the map contains a given key.
     @param key the key to check for
     */
    bool contains_key(K key);
    /**
     Retrieves the value of a given key.
     @param key the key to find
     @return the value
     */
    V value_of(K key);
    /**
     Removes the key and value.
     @param key the key to find
     */
    void remove_key(K key);
    /**
     prints out the contents of the map (key, value)
     */
    void print();

private:
    list< Pair<K, V> > data;
};

//insert at end of list
template <typename K, typename V>
void Map<K,V>::insert(K key, V value) {
    Pair<K,V> p(key, value);
    data.insert(data.end(), p);
}

//check if list contains key, if it does return true, else return false
template<typename K, typename V>
bool Map<K, V>::contains_key(K key) {
    
    typename list< Pair<K, V> >::iterator it;
    for(it = data.begin(); it != data.end(); ++it) {
        if (it->get_first() == key) {
            return true;
        }
    }
    return false;
}

//return the value associated with the key.  If the key does not exist return a garbage value
template<typename K, typename V>
V Map<K, V>::value_of(K key) {
    typename list< Pair<K, V> >::iterator it;
    for(it = data.begin(); it != data.end(); ++it) {
        if (it->get_first() == key) {
            return it->get_second();
        }
    }
    cout << "Key does not exist!\n";
    V stupid;
    return stupid;
}

//remove the pair with the particular key.  If the key does not exist, print out error message
template<typename K, typename V>
void Map<K, V>::remove_key(K key) {
    typename list< Pair<K, V> >::iterator it;
    for(it = data.begin(); it != data.end(); ++it) {
        if (it->get_first() == key) {
            data.erase(it);
            return;
        }
    }
    cout << "Key does not exist!\n";
}

//print each pair in the list
template<typename K, typename V>
void Map<K,V>::print() {
    typename list< Pair<K, V> >::iterator it;
    for(it = data.begin(); it != data.end(); ++it) {
        cout << "(" << it->get_first() << ", " << it->get_second() << ") ";
    }
    cout << endl;
}
#endif