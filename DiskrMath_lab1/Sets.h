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

	Sets& operator=(const Sets& copyFrom)
	{
		if (this != &copyFrom)
		{
			name = copyFrom.name;
			elems = copyFrom.elems;
		}
		return *this;
	}

	size_t Power() const {
		return elems.size();
	}

	void AddEl(string el) {
		auto placeAfter = FindPlace(el);
		if (el.size() > 80)
			cout << "\t" << "Too many syms, max = 80" << endl;
		else if (placeAfter != elems.end() && el == *placeAfter)
			cout << "\t" << "There is this element already" << endl;
		else {
			elems.insert(placeAfter, el);
			cout << "\t" << "Inserted" << endl;
		}
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

	void PrintElements() const {
		auto elemP = elems.begin();
		for (elemP; elemP != elems.end(); elemP++) {
			cout << *elemP << endl;
		}
	}

	bool Inclusion(const Sets& inclSet) const {
		auto elemIncl = inclSet.elems.begin();
		auto elem = this->elems.begin();
		while (elemIncl != inclSet.elems.end() && elem != this->elems.end()) {
			if (*elemIncl < *elem) {
				return false;
			}
			else if (*elemIncl > * elem)
				elem++;
			else {
				elemIncl++;
				elem++;
			}
			return elemIncl == inclSet.elems.end();
		}
	}

	/*~Sets() {
		elems.clear();
	}*/

	string name;
	list<string> elems;
private:
	list<string>::iterator FindPlace(string el) {
		auto elem = elems.begin();
		/*if (elem == elems.end())
			return elem;*/

		for (elem; elem != elems.end() && *elem < el; elem++) {
		};
		return elem;
	}
};

namespace setsOper {
	Sets Union(const Sets& set1, const Sets& set2, string name) {
		Sets crSet(name);
		auto els1 = set1.elems.begin();
		auto els2 = set2.elems.begin();

		while (els1 != set1.elems.end() && els2 != set2.elems.end())
		{
			if (*els1 < *els2)
			{
				crSet.elems.push_back(*els1);
				els1++;
			}
			else if (*els1 > * els2)
			{
				crSet.elems.push_back(*els2);
				els2++;
			}
			else
			{
				crSet.elems.push_back(*els1);
				els1++;
				els2++;
			}
		}

		for (; els1 != set1.elems.end(); els1++)
			crSet.elems.push_back(*els1);

		for (; els2 != set2.elems.end(); els2++)
			crSet.elems.push_back(*els2);

		return crSet;
	}

	Sets Intersection(const Sets& set1, const Sets& set2, const string name) {
		Sets crSet(name);
		auto els1 = set1.elems.begin();
		auto els2 = set2.elems.begin();

		while (els1 != set1.elems.end() && els2 != set2.elems.end())
		{
			if (*els1 < *els2)
				els1++;
			else if (*els1 > * els2)
				els2++;
			else {
				crSet.elems.push_back(*els1);
				els1++;
				els2++;
			}

		}

		return crSet;
	}

	Sets Difference(const Sets& setMin, const Sets& setSub, const string name) {
		Sets crSet(name);
		auto elsMin = setMin.elems.begin();
		auto elsSub = setSub.elems.begin();

		while (elsMin != setMin.elems.end() && elsSub != setSub.elems.end()) {
			if (*elsMin < *elsSub) {
				crSet.elems.push_back(*elsMin);
				elsMin++;
			}
			else if (*elsMin > * elsSub) {
				elsSub++;
			}
			else {
				elsMin++;
				elsSub++;
			}
		}

		for (; elsMin != setMin.elems.end(); elsMin++)
			crSet.elems.push_back(*elsMin);

		return crSet;
	}

	Sets SymetricDifference(const Sets& set1, const Sets& set2, const string name) {
		Sets crSet(name);
		auto els1 = set1.elems.begin();
		auto els2 = set2.elems.begin();

		while (els1 != set1.elems.end() && els2 != set2.elems.end()) {
			if (*els1 < *els2) {
				crSet.elems.push_back(*els1);
				els1++;
			}
			else if (*els1 > * els2) {
				crSet.elems.push_back(*els2);
				els2++;
			}
			else {
				els1++;
				els2++;
			}
		}

		for (; els1 != set1.elems.end(); els1++)
			crSet.elems.push_back(*els1);

		for (; els2 != set2.elems.end(); els2++)
			crSet.elems.push_back(*els2);

		return crSet;
	}
}