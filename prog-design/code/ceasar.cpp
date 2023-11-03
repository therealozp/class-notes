#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<long long> mrs(int base, int exp, int divisor) {
    long long n = 1;
    vector<long long> mods;
    while (n < exp) {
        long long mod;
        if (mods.size() == 0 || n == 1) {
            mod = base % divisor;
        } else {
            long long powered = pow(mods[mods.size() - 1], 2);
            mod = powered % divisor;
        }
        mods.push_back(mod);
        n *= 2;
    }
    return mods;
}

string getBinaryVal(long number) {
    if (number == 0) {
        return "0";
    } else if (number == 1) {
        return "1";
    }
    int mod = number % 2;
    string mod_str = to_string(mod);
    return mod_str + getBinaryVal(number/2);
}

void getMods(int base, int exp, int divisor) {
    vector <long long>mods = mrs(base, exp, divisor);
    vector <long long>rems; 
    int n = 1; 
    string binary_string = getBinaryVal(exp);
    vector <long long> base2; 
    for (int i = 0; i < binary_string.length(); i ++) {
        if (binary_string[i] == '1') {
            base2.push_back(i);
        }
    }
    
    for (int i = 1; i < base2.size(); i++) {
        if (rems.size() == 0) {
            long long res = (mods[base2[i]] * mods[base2[i - 1]]) % divisor;
            cout << mods[base2[i]] << "*" << mods[base2[i - 1]] << " % " << divisor << " is " << res << endl;
            rems.push_back(res);
        } else {
            long long res = (mods[base2[i]] * rems[rems.size() - 1]) % divisor;
            cout << mods[base2[i]] << "*" << rems[rems.size() - 1] << " % " << divisor << " is " << res << endl;
            rems.push_back(res);
            // rems.push_back((mods[base2[i]] * rems[rems.size() - 1]) % divisor);
        }
    }

    return; 
}; 

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

char getcharfromindex(int shift) {
    return char(int('A') + shift - 1);
}

int main() {
    string input;
    cout << "What would you like to do? ";
    cin >> input;

    while (input != "q") {
        if (input == "1") {
            int base, power, modulus;
            cout << "Enter base: ";
            cin >> base; 
            cout << "Enter power: ";
            cin >> power;
            cout << "Enter modulus: ";
            cin >> modulus;
            vector<long long> mods = mrs(base, power, modulus);
            int pwr = 1;


            for (int i = 0; i < mods.size(); i++, pwr*=2) {
                cout << base << '^' << pwr << " % " << modulus << " is " << mods[i] << endl;
            } 
        } else if (input == "2") {
            int base, power, modulus;
            cout << "Enter base: ";
            cin >> base; 
            cout << "Enter power: ";
            cin >> power;
            cout << "Enter modulus: ";
            cin >> modulus;
            getMods(base, power, modulus);
        } else {
            int index; 
            char ch;
            // cout << "Enter character: "; 
            // cin >> ch;
            cout << "Enter shift : ";
            cin >> index;
            ch = getcharfromindex(index);
            cout << ch << endl;
        }
        cout << "What else would you like to do? ";
        cin >> input;
    }
    
    cout << "goodbye! " << endl;

    return 0;
}