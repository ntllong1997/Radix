#include "radix.hpp"
int getMax(int arr[], int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

string DecimalTo(int n, int base) {
  string convert = "";
  while (n > 1) {
    int remainder = n % base;
    char ch;
    if (remainder >= 10) {
      ch = remainder + 55;
    } else {
      ch = remainder + 48;
    }
    convert += ch;
    n = n / base;
  }

  convert = addZero(convert, base);
  convert = revStr(convert);
  return convert;
}

void print(vector<string> arr) {
  for (int i = 0; i < arr.size(); i++) {
    arr[i] = removeZero(arr[i]);
    cout << arr[i] << " ";
  }
  cout << endl;
}

vector<string> toString(vector<int> arr, int base) {
  vector<string> arrStr;
  for (int i = 0; i < arr.size(); i++) {
    string a = DecimalTo(arr[i], base);
    arrStr.push_back(a);
  }


  return arrStr;
}

vector<int> genRandomNum(int size) {
  srand(time(0));
  vector<int> arr;
  for (int i = 0; i < size; i++) {
    int num = rand() % 10000;
    arr.push_back(num);
  }
  return arr;
}

void MSD(vector<string> &vec, int pos, int base) {
  int val;
  int numBucket;
  if (vec.size() <= 1 || pos >= 4) {
    return;
  }

  vector<vector<string>> bucket(base);
  for (int i = 0; i < vec.size(); i++) {
    val = vec[i].at(pos) - 48;
    if (val > 9) {
      val = val - 7;
    }
    numBucket = val % base;
    bucket[val % base].push_back(vec[i]);
  }
  pos++;
  int out_pos = 0;
  for (int i = 0; i < base; i++) {
    MSD(bucket[i], pos, base);
    for (int j = 0; j < bucket[i].size(); j++) {
      vec[out_pos] = bucket[i][j];
      out_pos++;
    }
  }
}

string addZero(string num, int base) {
  int len = max_len(base);
  while (num.size() < len) {
    num += '0';
  }
  return num;
}

string removeZero(string num) {
  int pos = 0;
  while (num[0] == 48) {
    num.erase(0, 1);
    pos++;
  }
  return num;
}

string revStr(string str) {
  reverse(str.begin(), str.end());
  return str;
}

int max_len(int base) {
  int a = 9999;
  int len = 0;
  while (a > 1) {
    a = a / base;
    len++;
  }
  return len;
}