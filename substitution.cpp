#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void usage() {
  cout << "USAGE: substitution [-ed] [key]\n";
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
  
  string key = argv[2];
  if(key.length() != 26) {
    usage();
    return 1;
  }
  
  bool seen[26] = {false};
  for(char c : key) {
    if(!isalpha(c)) {
      usage();
      return 1;
    }
    int dex = toupper(c) - 'A';
    if(seen[dex]) {
      usage();
      return 1;
    }
    seen[dex] = true;
  }
  
  string encrypt_key = key;
  for(char& c : encrypt_key) {
    c = toupper(c);
  }
  
  string decrypt_key(26, ' ');
  if(mode == "-d") {
    for(int i = 0; i < 26; i++) {
      decrypt_key[encrypt_key[i] - 'A'] = 'A' + i;
    }
  }
  
  string line;
  while(getline(cin, line)) {
    string res;
    for(char c : line) {
      if(isalpha(c)) {
        int dex = toupper(c) - 'A';
        char rep;
        if(mode == "-e") {
          rep = encrypt_key[dex];
        } else {
          rep = decrypt_key[dex];
        }
        if(isupper(c)) {
            res += rep;
        } else {
            res += tolower(rep);
        }
      } else { // not alphebet char
        res += c;
      }
    }
    cout << res << '\n';
  }
  
  return 0;
}