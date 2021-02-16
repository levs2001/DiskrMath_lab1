#pragma once
#include <string>
#include<list>
#include<iostream>
#include <vector>

using namespace std;

class Sets {
public:
	Sets(string name) :name(name) {
	}

	size_t Power() {
		return elems.size();
	}

	void AddEl(string el) {
		auto placeAfter = FindPlace(el);
		elems.insert(placeAfter, el);
	}

	void DeleteEl(string el) {
		elems.remove(el);
	}

	bool CheckEl(string el) {
		auto place = FindPlace(el);
		if (*place == el)
			return true;
		return false;
	}

	void PrintElements() {
		auto elemP = elems.begin();
		for (elemP; elemP != elems.end(); elemP++) {
			cout << *elemP << endl;
		}
	}

	~Sets() {
		elems.clear();
	}

	string name;
private:
	list<string> elems;

	list<string>::iterator FindPlace(string el) {
		auto elem = elems.begin();
		/*if (elem == elems.end())
			return elem;*/

		for (elem; elem != elems.end() && *elem < name; elem++) {
		};
		return elem;
	}
};