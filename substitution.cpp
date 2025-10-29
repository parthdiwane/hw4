#include <cctype>
#include <iostream>
#include <string>

void usage() {
  std::cout << "USAGE: substitution [-ed] [key]\n";
}

int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }
  // TODO: Finish the program
}
