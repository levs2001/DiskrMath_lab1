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
	
	Sets(const Sets& copyFrom) : name(copyFrom.name), elems(copyFrom.elems)
	{}

	size_t Power() {
		return elems.size();
	}

	void AddEl(string el) {
		auto placeAfter = FindPlace(el);
		elems.insert(placeAfter, el);
	}

	void DeleteEl(string el) {
		if (CheckEl(el))
			elems.remove(el);
		else
			cout << "\t" << "No such element";
	}

	bool CheckEl(string el) {
		auto place = FindPlace(el);
		if (place != elems.end() && *place == el)
			return true;
		return false;
	}

	void PrintElements() {
		auto elemP = elems.begin();
		for (elemP; elemP != elems.end(); elemP++) {
			cout << *elemP << endl;
		}
	}

	
	Sets& operator=(const Sets& copyFrom)
	{
		if (this != &copyFrom)
		{
			name = copyFrom.name;
			elems = copyFrom.elems;
		}
		return *this;
	}


	/*~Sets() {
		elems.clear();
	}*/

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