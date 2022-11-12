
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <time.h>
using namespace std;

string DecimalTo(int n, int base);
vector<string> toString(vector<int> arr, int base);
vector<int> genRandomNum(int size);
void MSD(vector<string>&vec, int pos, int base);
void print(vector<string>arr);
string addZero(string num, int base);
string removeZero(string num);
string revStr(string str);
int max_len(int base);