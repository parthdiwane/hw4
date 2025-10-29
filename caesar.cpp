#include <cctype>
#include <iostream>
#include <string>
using namespace std;

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }
  
  string mode = argv[1];
  if(mode != "-e" && mode != "-d") {
    usage();
    return 1;
  }
  
  string key_str = argv[2];
  for(char c : key_str) {
    if(!isdigit(c)) {
      usage();
      return 1;
    }
  }
  int key = std::stoi(key_str);
  
  if(mode == "-d") {
    key = -key;
  }
  
  string line;
  while(getline(cin, line)) {
    string result;
    for(char c : line) {
      if(isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        int offset = (c - base + key) % 26;
        if(offset < 0) {
          offset += 26;
        }
        result += base + offset;
      } else {
        result += c;
      }
    }
    cout << result << endl;
  }
  
  return 0;
}