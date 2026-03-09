#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<int,std::string> m1;
    std::map<int,std::string> m2 = { {1, "Geeks"}, {2,"For"}, {3, "Geeks"}};
    for (auto &t1 : m2) {
        std::cout << t1.first  << " " << t1.second << std::endl;
    }
    return 0;
}