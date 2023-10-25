#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> mrs(int base, int exp, int divisor) {
    int n = 1;
    vector<int> mods;
    while (n < exp) {
        int mod;
        if (mods.size() == 0 || n == 1) {
            mod = base % divisor;
        } else {
            int powered = pow(mods[mods.size() - 1], 2);
            mod = powered % divisor;
        }
        mods.push_back(mod);
        n *= 2;
    }
    return mods;
}

void ceasar() { 
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

int main() {
    vector<int> mods = mrs(55, 307, 721);
    for (int i: mods) {
        cout << i << endl;
    } 
    return 0;
}