//Jared VanEnkevort
//Contains prototpyes for all methods present in PG6.cpp
#ifndef _PG6_
#define _PG6_

#include <string>
#include <cstdlib>
#include "Database.h"
using namespace std;

Database* Studs;

int main(int argc, char** argv);
bool ProcessCommand();
void AddCommand(string cmd);
void RemoveCommand(string cmd);
void LookupCommand(string cmd);

#endif
