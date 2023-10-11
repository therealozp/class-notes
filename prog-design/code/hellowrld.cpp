#include <iostream>
#include <string>

int string_type(std::string str) {
    using namespace std; 
    char repl, replt; 
    cout << "Enter character and new character separated by whitespace: ";
    cin >> repl >> replt; 

    string::size_type i; 
    for (i = 0; i < str.length(); i++) {
        if (str[i] == repl) {
            str[i] = replt;
        }
    }
    cout << str << endl; 
}

int reverse(std::string str) {
    using namespace std; 
    string::size_type s = 0, e = str.length() - 1;
    while (s < e) {
        char tmp; 
        tmp = str[s];
        str[s] = str[e];
        str[e] = tmp;
        s++;
        e--;
    }
    cout << str; 
    return 0;
}

std::string extensions(std::string filename) {
    using namespace std; 
    string::size_type i;
    string ext;
    bool found = false;
    for (i = 0; i < filename.length(); i++) {
        if (filename[i] == '.' && !found) {
            found = true;
            continue;
        }

        if (found) {
            ext += filename[i];
        }
    }
    return ext; 
} 

int main() { 
    using namespace std;
    string str;
    cout << "Enter string: ";
    cin >> str;

    // reverse(str);
    string ext = extensions(str);
    cout << "Your extension is " << ext << endl;  
    // cout << str;
    return 0; 
}