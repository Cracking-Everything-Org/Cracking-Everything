#include <iostream>
#include <string>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    bool shouldBeUpperCase = true;
    for (int i = 0; i < line.length(); i++) {
      if (line[i] != ' ') {
        line[i] = shouldBeUpperCase ? toupper(line[i]) : tolower(line[i]);
        shouldBeUpperCase = !shouldBeUpperCase;
      }
    }
    cout << line << endl;
  }
}
