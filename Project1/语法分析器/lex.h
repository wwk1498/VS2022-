#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<cctype>
#include<regex>
#include<string>
#include<algorithm>
using namespace std;

extern vector<string> myvef;
extern map<int, string> myMap;

class Lexical{
public:
	void getFilename(ifstream& file);
	vector<pair<string, string>> InputFile(ifstream& file, vector<pair<string, string>> tok);
	bool isword(string str);
	bool isnumb(string str);
	bool isFStrb(string str);
};