#include"Sets.h"
#include"Interface.h"
#include<iostream>
using namespace std;
//elems.sort
//elems.size
//elems.insert(it, el)
//advance(it, stepC)
//elems.erace(it)
//elems.remove(el)
//list<int> myList = {15, 4, 2};
//list<int> myList2 = { 9, 9, 7, 6 };
//myList.assign(myList2.begin(), myList2.end());



int main(void) {
	Interface session;
	string command;
	cin >> command;

	while (command != "Exit") {
		session.CheckCommand(command);
		cin >> command;
	} 
	return 0;
}