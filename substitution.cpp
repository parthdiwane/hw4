#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
void usage() {
  std::cout << "USAGE: substitution [-ed] [key]\n";
}

unordered_map<char, char> encrypt(string input) {
  unordered_map<char,char> ret;
  int dex = 0;
  for(char i = 'a'; i <= 'z'; i++) {
    ret[i] = input[dex];
    dex += 1;
  }
  return ret;
}

unordered_map<char, char> decrypt(string input) {
  unordered_map<char, char> ret;
  int dex = 0;
  for(char i = 'a'; i <= 'z'; i++) {
    ret[input[dex]] = i;
    dex += 1;
  }
  return ret;
}

string sub(string line,string input, string code) {
  if(code == "-e") {
    unordered_map<char, char> x = encrypt(input);
    for(int i = 0; i < line.length(); i++) {
      if(isalpha(line[i])) {
        bool upper = isupper(line[i]);
        char lower = tolower(line[i]);
        line[i] = x[lower];
        if(upper) {
          line[i] = toupper(line[i]);
        }
      }
    }
  } else {
    unordered_map<char,char> x = decrypt(input);
    for(int i = 0; i < line.length(); i++) {
      if(isalpha(line[i])) {
        bool upper = isupper(line[i]);
        char lower = tolower(line[i]);
        line[i] = x[lower];
        if(upper) {
          line[i] = toupper(line[i]);
        }
      }
    }
  }
  return line;
}
int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }
  if(strlen(argv[2]) != 26 || (string(argv[1]) != "-e" && string(argv[1]) != "-d")) {
    usage();
    return 1;
  }
  string line;
  string code = string(argv[1]);
  string input = string(argv[2]);
  while (getline(cin, line)) {
    cout << sub(line,input, code) << endl;
  }
}
