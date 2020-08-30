#include <iostream>
#include <string>

using namespace std;

string solution(string T) {
  string answer = "";
  if (T[0] == '?') {
    if (T[1] == '?' || T[1] <= '3') {
      answer += "2";
    } else answer += "1";
  } else answer += T[0];

  if (T[1] == '?') {
    if (T[0] == '?') {
      answer += '2';
    } else if (T[0] == '2') {
      answer += '3';
    } else answer += '9';
  } else answer+= T[1];

  answer += ':';

  if (T[3] == '?') {
    if (T[1] == '?') {
      if (answer[0] == '1') {
        answer[1] = '5';
      } else if (answer[0] == '2' && T[0] != '?'){
        answer[1] = '3';
      } else if (answer[0] == '2') {
        answer[1] = '2';
      }
      answer += answer[1];
    } else if (T[0] == '?') {
      answer += answer[2];
    } else answer += "5";
  } else answer += T[3];
  if (T[4] == '?') {
    if (T[3] == '?') {
      answer += answer[3];
    } else if (T[1] == '?') {
      answer += answer[1];
    } else if (T[0] == '?') {
      answer += answer[0];
    } else {
       answer += "9";
    }
  } else answer += T[4];

  return answer;
}

int main() {
  // Read from stdin, solve the problem, write answer to stdout.
  string input;
  cin >> input;
  cout << "\"" << solution(input.substr(1, 5)) << "\"";
}
