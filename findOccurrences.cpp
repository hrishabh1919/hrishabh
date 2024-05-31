#include <iostream>
#include <vector>
#include <string>

using namespace std;

int hash(const string& str) {
  const int MAX_SIZE = 101;
  int h = 0;
  for (char c : str) {
    h = (h * 256 + c) % MAX_SIZE;
  }
  return h;
}

int findOccurrences(const string& text, const string& pattern) {
  int patternSize = pattern.size();

  const int MAX_SIZE = 101;
  vector<pair<string, int>> table(MAX_SIZE);

  for (int i = 0; i <= text.size() - patternSize; ++i) {
    string str = text.substr(i, patternSize);
    int h = hash(str);
    int index = h % table.size();

    if (table[index].first.empty()) {
      table[index].first = str;
      table[index].second = 1;
    } else {
      if (table[index].first == str) {
        table[index].second++;
      }
    }
  }

  int h = hash(pattern);
  int index = h % table.size();

  if (table[index].first == pattern) {
    return table[index].second;
  }
  return 0;
}

int main() {
  string text, pattern;
  cout << "Enter the text string: ";
  getline(cin, text);
  cout << "Enter the pattern to search: ";
  getline(cin, pattern);

  int count = findOccurrences(text, pattern);

  cout << "Count of occurrences of pattern: " << count << endl;
  return 0;
}
