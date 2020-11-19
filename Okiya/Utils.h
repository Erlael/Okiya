#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Utils
{
public:
	static vector<string> split(const string& s, char delim)
	{
		vector<string> elems;
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}
};

