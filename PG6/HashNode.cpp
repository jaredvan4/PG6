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
	if (k == key) {
		DRT* temp = new DRT(d, "", "");
		d = data;
		return temp;
	}
	else if (next) {
		next->addnode(key, data);
	}
}

string HashNode::getk() { return k; }
string HashNode::getd() { return d; }

DRT* HashNode::remove(string key, HashNode* p, HashNode*& listhead) {
	if (k == key) {
		DRT* temp = new DRT(this->getd(), "", "");
		//if I have don't have a next
		if (!next) {
			listhead = nullptr;
			delete this;
			return temp;
		}
		else {
			listhead = next;
			delete this;	
			return temp;
		}
		
	}
	else {
		next->remove(key, this, listhead);
	}
}


void HashNode::setnext(HashNode* p) { next = p; }

