#ifndef TOOLBOX
#define TOOLBOX

#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using std::string;
using std::vector;

string removeChar(const string& input, const char& unwanted);

string int_toStr(int input);

int str_toInt(const string& input);

bool isNumeric(const string& input);

bool checkRange(const string& input, int min, int max);

int string_tokenizer (const string& input, vector <string> &container , const char& delimiter = ' ');

void getDivisors(const int& input, vector <int> &container );

bool compareVectors(const vector <int> &first, const vector <int> &second);

int vectorSearch(const std::string& input, std::vector <std::string> &container);

#endif
