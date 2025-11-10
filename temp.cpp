#include <string>
#include <iostream>
using namespace std;
int main()
{
    std::string s = "986";
    int i = stoi(s);
    int j = stoi("");
    cout << stoi(s) << endl;
    return 0;
}