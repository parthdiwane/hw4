CXX = g++
CXXFLAGS = --std=c++17 -g -O0 -Wall -Werror -Wextra

all: caesar substitution

caesar: caesar.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

substitution: substitution.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f caesar substitution *.o