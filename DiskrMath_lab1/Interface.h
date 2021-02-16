#pragma once
#include"Interface.h"
#include"Sets.h"
#include<iostream>
#include <vector>

#define LINE true

using namespace std;

class Interface {
public:
	Interface() {
		//	CheckCommand();
	}

	void CheckCommand(string command) {
		if (command == "Help") {
			cout << "Interface works with commands" << endl << "Command list:" << endl;
			cout << "CreateSet name" << "\t" << "after that com you need to write all els and than write EndProcess com" << endl;
			//HACK: Дописать справку
		}
		else if (command == "CreateSet") {
			string name = GetStr();
			auto placeAfter = FindPlace(name);

			if (placeAfter == setsList.end() || placeAfter->name != name) {
				auto set = setsList.insert(placeAfter, name);
				cout << "\t" << "Set inseted, insert els or write EndProcess" << endl;
				//HACK: Добавить возможность создавать элементы с пробелами
				string el = GetStr(LINE);
				while (el != "EndProcess") {
					set->AddEl(el);
					el = GetStr(LINE);
				}
				cout << "\t" << "Created" << endl;
			}
			else
				cout << "\t" << "There is a set with this name";
		}
		else if (command == "DeleteSet") {
			string name = GetStr();
			auto set = FindPlace(name);
			if (set != setsList.end() && set->name == name)
				setsList.erase(set);
			else
				cout << "\t" << "No such set";
		}
		else if (command == "WorkWithSet") {
			string name = GetStr();
		}
		else if (command == "WorkWith2Sets") {
			string name1 = GetStr(), name2 = GetStr();
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

			if (set->name != name) {
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
			return str;
		}
		else {
			string rub;
			cin >> str;
			getline(cin, rub);
			return str;
		}

	}

	~Interface() {

	}
private:
	list<Sets> setsList;

	list<Sets>::iterator FindPlace(string name) {
		auto set = setsList.begin();
		/*if (set == setsList.end())
			return set;*/

		for (; set != setsList.end() && set->name < name; set++) {
		}
		return set;
	}
};