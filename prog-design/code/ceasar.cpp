#include <iostream>

using namespace std;

int main() {
    string s = "NHHSV WKH GRFWRU DZDB";
    int shift_val = -3;
    for (int i = 0; i < s.length(); i++) {
        char ch = char(int(s[i]));
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            char shift = ( int(s[i]) - int('A') + shift_val ) % 26 + int('A');
            cout << char(shift);
        } else {
            cout << ch;
        }
    }
}