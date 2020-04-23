//Jared VanEnkevort
//Contains definitions for all methods in HashNode.h
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

//if this is node, return else tell next node to search
DRT* HashNode::searchnode(string key) {

	if (k == key) return new DRT(d, "", "");
	if (!next) return new DRT("", "", "");
	return next->searchnode(key);
}
//if this is the key, increment else send add to next node
DRT* HashNode::addnode(string key, string data) {
	if (k == key) {
		DRT* temp = new DRT(d, "", "");
		d = data;
		return temp;
	}else {
		next = new HashNode(key,"");
		next->setnext(nullptr);
		return new DRT("", "", "");
	}
}

string HashNode::getk() { return k; }
string HashNode::getd() { return d; }
//if this is key handle removing, else tell next node to remove
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
		 return next->remove(key, nullptr, listhead);
	}
}

//sets my next
void HashNode::setnext(HashNode* p) { next = p; }

