#pragma once
#include"Interface.h"
#include"Sets.h"
#include<iostream>
#include <vector>

#define LINE true

using namespace std;


class Interface {
public:
	void CheckCommand(string command) {
		if (command == "Help") {
			cout << "Interface works with commands" << endl << "Command list:" << endl;
			cout << "\"Exit\"" << "\t" << "This command ends work of programm, if you are in main menu" << endl;
			cout << "\"CreateSet name\"" << "\t" << "After that com you need to write all elements and than write \"EndProcess\"" << endl;
			cout << "\"DeleteSet name\"" << "\t" << "This com will delete set" << endl;
			cout << "\"PrintSet name\"" << "\t" << "This com will write all elements of given set" << endl;
			cout << "\"PrintSets\"" << "\t" << "This com will write all names of sets" << endl;

			cout << "\"WorkWithSet name\"" << "\t" << "This com moves you in WorkWithSet mode, to go out from this mode tap \"EndProcess\". After any command pass enter, and than element, if need."
				<< " Here you have coms:" << endl;
			cout << "\t" << "AddElement" << endl;
			cout << "\t" << "DeleteElement" << endl;
			cout << "\t" << "Power" << endl;
			cout << "\t" << "CheckElement" << endl;

			cout << "\"WorkWith2Sets\"" << "\t" << "After that com you shoud tap enter and then two names of sets with enter between,"
				<< "This com moves you in WorkWith2Sets mode, to go out from this mode tap \"EndProcess\". Here you have coms:" << endl;
			cout << "\t" << "Union" << endl;
			cout << "\t" << "Intersection" << endl;
			cout << "\t" << "Difference" << endl;
			cout << "\t" << "SymetricDifference" << endl;
			cout << "\t" << "Inclusion" << endl << endl;

			cout << "\t" << "Warning: when you are working in any mode(set, 2sets), you should pass enter after all commands! ";
			cout << "Also after some coms interface print info about what you should write. Good luck!" << endl << endl;
		}
		else if (command == "CreateSet") {
			string name = GetStr();
			auto placeAfter = FindPlace(name);

			if (placeAfter == setsList.end() || placeAfter->name != name) {
				auto set = setsList.insert(placeAfter, name);
				cout << "\t" << "Set inseted, insert elements or write EndProcess" << endl;
				string el = GetStr(LINE);
				while (el != "EndProcess") {
					set->AddEl(el);
					el = GetStr(LINE);
				}
				cout << "\t" << "Created" << endl;
			}
			else
				cout << "\t" << "There is a set with this name" << endl;
		}
		else if (command == "DeleteSet") {
			string name = GetStr();
			auto set = FindPlace(name);
			if (set != setsList.end() && set->name == name) {
				setsList.erase(set);
				cout << "\t" << "Set deleted" << endl;
			}
			else
				cout << "\t" << "No such set" << endl;
		}
		else if (command == "WorkWithSet") {
			string name = GetStr();
			auto set = FindPlace(name);
			if (set != setsList.end() && set->name == name) {
				cout << "\t" << "In WorkWithSet mode" << endl;
				WorkWithSet(set);
			}
			else
				cout << "\t" << "No such set";

		}
		else if (command == "WorkWith2Sets") {
			cout << "\t" << "Tap two name of sets:" << endl;
			string name1 = GetStr();
			auto set1 = FindPlace(name1);
			string name2 = GetStr();
			auto set2 = FindPlace(name2);
			if (set1 != setsList.end() && set2 != setsList.end() && set1->name == name1 && set2->name == name2) {
				cout << "\t" << "In WorkWith2Sets mode" << endl;
				WorkWith2Sets(set1, set2);
			}
			else
				cout << "\t" << "No such set" << endl;
		}
		else if (command == "PrintSets") {
			if (setsList.begin() == setsList.end())
				cout << "\t" << "No sets" << endl;
			auto set = setsList.begin();
			for (set; set != setsList.end(); set++) {
				cout << (*set).name << endl;
			};
		}
		else if (command == "PrintSet") {
			string name = GetStr();
			auto set = FindPlace(name);

			if (set != setsList.end() && set->name != name) {
				cout << "\t" << "No such set" << endl;
			}
			else {
				set->PrintElements();
			}
		}
		else {
			cout << "\t" << "No such command" << endl;
		}
	}

	string GetStr(bool getLine = false) {
		string str;
		if (getLine) {
			getline(cin, str);
		}
		else {
			string rub;
			cin >> str;
			getline(cin, rub);
			if (rub != "") {
				cout << "\t" << "All coms after the first were ignored, check warning!" << endl;
			}
		}
		return str;
	}

	~Interface() {
		setsList.clear();
	}
private:
	list<Sets> setsList;

	list<Sets>::iterator FindPlace(string name) {
		auto set = setsList.begin();

		for (; set != setsList.end() && set->name < name; set++) {
		}
		return set;
	}

	void WorkWithSet(list<Sets>::iterator set) {
		string command = GetStr();
		while (command != "EndProcess") {
			if (command == "Power") {
				cout << set->Power() << endl;
			}
			else if (command == "AddElement") {
				cout << "\t" << "Pass element" << endl;
				string el = GetStr(LINE);
				set->AddEl(el);
			}
			else if (command == "DeleteElement") {
				string el = GetStr(LINE);
				set->DeleteEl(el);
			}
			else if (command == "CheckElement") {
				string el = GetStr(LINE);
				if (set->CheckEl(el))
					cout << "\t" << "In set" << endl;
				else
					cout << "\t" << "Not in set" << endl;
			}
			else {
				cout << "There is no such command in this mode, tap EndProcess for main menu" << endl;
			}
			command = GetStr();
		}
	}

	void WorkWith2Sets(list<Sets>::iterator set1, list<Sets>::iterator set2) {
		cout << "\t" << "Tap command:" << endl;
		string command = GetStr();
		while (command != "EndProcess") {
			if (command == "Union") {
				InsForCom(setsOper::Union, set1, set2);
			}
			else if (command == "Intersection") {
				InsForCom(setsOper::Intersection, set1, set2);
			}
			else if (command == "Difference") {
				InsForCom(setsOper::Difference, set1, set2);
			}
			else if (command == "SymetricDifference") {
				InsForCom(setsOper::SymetricDifference, set1, set2);
			}
			else if (command == "Inclusion") {
				string ans = set1->Inclusion(*set2) ? "Included" : "Not included";
				cout << "\t" << ans << endl;
			}
			else {
				cout << "There is no such command in this mode, tap EndProcess for main menu" << endl;
			}
			command = GetStr();
		}
	}

	void InsForCom(Sets(*Command)(const Sets&, const Sets&, string), list<Sets>::iterator set1, list<Sets>::iterator set2) {
		cout << "\t" << "Tap name of new set to save:" << endl;
		string name = GetStr();
		auto placeAfter = FindPlace(name);

		if (placeAfter == setsList.end() || placeAfter->name != name) {
			setsList.insert(placeAfter, Command(*set1, *set2, name));
			cout << "\t" << "Created" << endl;
		}
		else
			cout << "\t" << "There is a set with this name, now you are in main menu" << endl;
	}
};