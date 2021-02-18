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
			//HACK: �������� �������
		}
		else if (command == "CreateSet") {
			string name = GetStr();
			auto placeAfter = FindPlace(name);

			if (placeAfter == setsList.end() || placeAfter->name != name) {
				auto set = setsList.insert(placeAfter, name);
				cout << "\t" << "Set inseted, insert elements or write EndProcess" << endl;
				//HACK: �������� ����������� ��������� �������� � ���������
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
			if (set != setsList.end() && set->name == name)
				setsList.erase(set);
			else
				cout << "\t" << "No such set";
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
			string name1 = GetStr();
			auto set1 = FindPlace(name1);
			string name2 = GetStr();
			auto set2 = FindPlace(name2);
			if (set1 != setsList.end() && set2 != setsList.end() && set1->name == name1 && set2->name == name2)
				WorkWith2Sets(set1, set2);
			else
				cout << "\t" << "No such set";
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

	void WorkWithSet(list<Sets>::iterator set) {
		string command = GetStr();
		while (command != "EndProcess") {
			if (command == "PrintPower") {
				cout << set->Power() << endl;
			}
			else if (command == "AddElement") {
				cout << "\t" << "Pass element" << endl;
				string el = GetStr();
				set->AddEl(el);
			}
			else if (command == "DeleteElement") {
				string el = GetStr();
				set->DeleteEl(el);
			}
			else if (command == "CheckElement") {
				string el = GetStr();
				if (set->CheckEl(el))
					cout << "\t" << "In set" << endl;
				else
					cout << "\t" << "Not in set" << endl;
			}
			else {
				cout << "There is no such command in this mode, tap EndProcess for main menu" << endl;
			}
			cin >> command;
		}
	}

	void WorkWith2Sets(list<Sets>::iterator set1, list<Sets>::iterator set2) {
		string command = GetStr();
		while (command != "EndProcess") {
			if (command == "Union") {

			}
			else if (command == "Intersection") {

			}
			else if (command == "Difference") {

			}
			else if (command == "SymetricDifference") {

			}
			else if (command == "Inclusion") {

			}
			else {
				cout << "There is no such command in this mode, tap EndProcess for main menu" << endl;
			}
			cin >> command;
		}
	}
};