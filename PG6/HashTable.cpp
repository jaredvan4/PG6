//Jared VanEnkevort
//Contains definitions for all methods in HashTable.h
#include <iostream>
#include <string>
#include <cstdlib>
#include "HashTable.h"
#include "DRT.h"
#include "HashNode.h"
using namespace std;

HashTable::HashTable(int sz) {

	HS = sz;
	table = new HashNode * [HS];
	for (int i = 0; i < HS; i++)
		table[i] = NULL;
}

HashTable::~HashTable() {

	for (int i = 0; i < HS; i++)
		delete table[i];
	delete[] table;
}

int HashTable::hf(string key) {

	int val = 0;
	for (int i = 0; i < key.length(); i++) {
		int ch = key[i];
		if (ch == 0) ch = 256;
		val = (val * 256 + ch) % HS;
	}
	return val;
}

DRT* HashTable::add(string key, string data) { //very similar to sample code
	int val = hf(key);
	if (table[val] == nullptr) {
		DRT *temp = new DRT("", "", "");
		table[val] = new HashNode(key,data);
		return temp;
	}
	else {
		
		return table[val]->addnode(key, data);
	}

}

DRT* HashTable::searchnode(string key) { //searches the tree for the given key

	int val = hf(key);
	if (!table[val]) return new DRT("", "", "");
	return table[val]->searchnode(key);
}


DRT* HashTable::remove(string key) { //removes an item from the list
	int val = hf(key);
	if (!table[val]) {
		return new DRT("", "", "");
	}
	return table[val]->remove(key, nullptr,table[val]);
}

DRT* HashTable::search(string key) { //Database search method
	  //checks to see if we're searching on the empty string, if so builds a DRT with first() and last (), otherwise calls searchnode

	if (key == "") return new DRT("", "", "");
	return searchnode(key);
}


DRT* HashTable::modify(string key, string data) { //Database modify method

	if (key == "") return new DRT("", "", "");
	if (data == "") return remove(key);
	return add(key, data);
}
