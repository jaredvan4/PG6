//Jared VanEnkevort
//Contains definitions for all methods in DRT.h
#include <string>
#include "DRT.h"
using namespace std;

DRT::DRT(string d, string n, string p) {

    data = d; next = n; prev = p;
}
//returns data
string DRT::getdata() { return data; }
//return the next
string DRT::getnext() { return next; }
//returns the prev
string DRT::getprev() { return prev; }
