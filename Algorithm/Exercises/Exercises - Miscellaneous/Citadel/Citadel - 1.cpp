/*
Given an input string, reverse the word order in place.
Assume input string contains only letters and spaces, no other punctuation.
Example:


"This    is an input string"
                      si   sihT
 --> "string input an is   This"

"This is"

"si sitT"
*/

#include <iostream>
#include <algorithm>

using namespace std;


void reverseWord(string& word) {

  if (word.length() == 0) return;

  reverse(word.begin(), word.end());

  int startPointer = 0;
  int endPointer = 0;
  for (int c = 0; c < word.length(); c++) {
    if (word[c] != ' ') {
      endPointer = c;
    }
    else {
      reverse(word.begin() + startPointer, word.begin() + endPointer + 1);
      bool foundNewWord = false;
      startPointer = endPointer + 1;
      while (startPointer < word.length() && !foundNewWord) {
        if (word[startPointer] != ' ') {
          foundNewWord = true;
        } else {
          startPointer++;
        }
      }
    }
  }
  if (word[word.length() - 1] != ' ') {
    reverse(word.begin() + startPointer, word.begin() + endPointer + 1);
  }
}



// To execute C++, please define "int main()"
int main() {

  string example = "execute";
  reverseWord(example);
  cout << example;
}
