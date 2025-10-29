#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

unordered_map<char, char> shiftedRight(int n) {
    unordered_map<char, char> ret;
    vector<char> x = {};
    for(char i = 'a'; i <= 'z'; i++) {
        x.push_back(i);
    }
    n = n % 26;  
    for(int i = 0; i < x.size() - n; i++) {
        ret[x[i]] = x[i + n];
    }
    for(int i = 0; i < n; i++) {
        ret[x[i + (x.size() - n)]] = x[i];
    }
    return ret;
}

unordered_map<char, char> shiftedLeft(int n) {
    unordered_map<char, char> ret;
    vector<char> x = {};
    for(char i = 'a'; i <= 'z'; i++) {
        x.push_back(i);
    }
    n = n % 26;  
    for(int i = n; i < x.size(); i++) {
        ret[x[i]] = x[i - n];
    }
    for(int i = 0; i < n; i++) {
        ret[x[i]] = x[(x.size() - n) + i]; 
    }
    return ret;
}


string caesar(string input, int n, string code) {
    if(code == "-e") {
        unordered_map<char,char> shift = shiftedRight(n);
        for(int i = 0; i < input.length(); i++) {
            if(isalpha(input[i])) {
                bool upper = isupper(input[i]);
                char lower = tolower(input[i]);
                input[i] = shift[lower];
                if(upper) {
                    input[i] = toupper(input[i]);
                }
            }
        }
    } else {
        unordered_map<char,char> shift = shiftedLeft(n);
        for(int i = 0; i < input.length(); i++) {
            if(isalpha(input[i])) {
                bool upper = isupper(input[i]);
                char lower = tolower(input[i]);
                input[i] = shift[lower];
                if(upper) {
                    input[i] = toupper(input[i]);
                }
            }
        }
    }
    return input;
}

int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    exit(1);
  }
  if(string(argv[1]) != "-e" && string(argv[1]) != "-d") {
    usage();
    exit(1);
  }
  string line; 
  int key = atoi(argv[2]);
  string code = string(argv[1]);
  while (getline(cin, line)) {
    cout << caesar(line, key, code) << std::endl;
  }
}
