#include <iostream>
#include <string>
#include <cstdlib>
#include "HashTable.h"
#include "DRT.h"
#include "PG6.h"
using namespace std;

int main(int argc, char** argv) {
	Studs = new HashTable(100003);
	while (ProcessCommand());
	delete Studs;
	return 0;
}

bool ProcessCommand() {
	string cmd;
	getline(cin, cmd);
	if (cmd == "EXIT") return false;
	else if (cmd.substr(0, 3) == "ADD") AddCommand(cmd);
	else if (cmd.substr(0, 6) == "REMOVE") RemoveCommand(cmd);
	else if (cmd.substr(0, 6) == "LOOKUP") LookupCommand(cmd);
	else cout << "Invalid Command!" << endl;
	return true;
}

void AddCommand(string cmd) {
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* R = Studs->search(k);
	if (R->getdata() == "") {
		Studs->modify(k, "1");
		cout << "one copy of " << k << " has been added to the library!" << endl;
	}
	else {
		string modify = to_string(stoi(R->getdata()) + 1);
		Studs->modify(k, modify);
		cout << "one copy of " << k << " has been added to the library!" << endl;
	}
}

void RemoveCommand(string cmd) {
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* T = Studs->search(k);
	if (T->getdata() == "")
		cout << "\"" << k << "\" does not exist in the library." << endl;
	else {
		if (T->getdata() == "1") {
			delete T;
			T = Studs->modify(k, "");
		}
		else {
			string d = to_string(stoi(T->getdata()) - 1);
			delete T;
			T = Studs->modify(k, d);
		}
		cout << "1 copy of \"" << k << "\" has been removed from the library." << endl;
		delete T;
	}
}
//Doesen't say before and after
void LookupCommand(string cmd) {
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* R = Studs->search(k);
	if (R->getdata() == "") {
		cout << k << " does not exist!\n "<< endl;
	}
	else {
		cout << "Name: " << k << "       Number of copies:"<< R->getdata() << endl;
	}
}