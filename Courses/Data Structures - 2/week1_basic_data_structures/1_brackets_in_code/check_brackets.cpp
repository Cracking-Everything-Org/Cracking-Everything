#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int wrongPos = 0;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket newBracket(next, position + 1);
            opening_brackets_stack.push(newBracket);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
                wrongPos = position + 1;
                break;
            }
            Bracket top = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if (!top.Matchc(next)) {
                wrongPos = position + 1;
                break;
            }
        }
    }

    // Printing answer, write your code here
    if (wrongPos == 0 && opening_brackets_stack.empty()) {
        std::cout << "Success";
    } else {
        if (wrongPos == 0) {
            while(opening_brackets_stack.size() > 1) {
                opening_brackets_stack.pop();
            }
            wrongPos = opening_brackets_stack.top().position;
        }
        std::cout << wrongPos;
    }
}
