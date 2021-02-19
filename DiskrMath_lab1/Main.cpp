#include"Sets.h"
#include"Interface.h"
#include<iostream>
using namespace std;


int main(void) {
	setlocale(LC_ALL, "Russian");
	cout <<"\t" << "Tap \"Help\" for info" << endl;

	Interface session;
	string command;
	cin >> command;
	while (command != "Exit") {
		session.CheckCommand(command);
		cin >> command;
	} 
	return 0;
}