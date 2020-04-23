//Jared VanEnkevort
//Contains prototpyes for all methods present in HashTable.cpp
#ifndef _HASHTABLE_
#define _HASHTABLE_

#include <iostream>
#include <string>
#include <cstdlib>
#include "DRT.h"
#include "Database.h"
#include "HashNode.h"
using namespace std;

class DRT;
class Database;
class HashNode;
class HashTable : public Database {
private:
    int HS;
    HashNode** table;
public:
    HashTable(int sz);
    ~HashTable(); //destructor
    int hf(string key);
    DRT* add(string key, string data);
    DRT* searchnode(string key);
    DRT* remove(string key);
    virtual DRT* search(string key); //Database search method
      //checks to see if we're searching on the empty string, if so builds a DRT with first() and last (), otherwise calls searchnode
    virtual DRT* modify(string key, string data); //Database modify method
};

#endif
