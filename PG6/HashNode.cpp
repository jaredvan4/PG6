#include <iostream>
#include <string>
#include <cstdlib>
#include "HashNode.h"
#include "DRT.h"
using namespace std;

HashNode::HashNode(string key, string data) {

	k = key; d = data; next = NULL;
}

HashNode::~HashNode() { //destructor

	delete next;
}


DRT* HashNode::searchnode(string key) {

	if (k == key) return new DRT(d, "", "");
	if (!next) return new DRT("", "", "");
	return next->searchnode(key);
}

DRT* HashNode::addnode(string key, string data) {

}

string HashNode::getk() { return k; }
string HashNode::getd() { return d; }

DRT* HashNode::remove(string key, HashNode* p, HashNode*& listhead) {

}


void HashNode::setnext(HashNode* p) { next = p; }

