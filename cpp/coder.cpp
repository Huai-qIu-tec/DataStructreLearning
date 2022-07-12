#include <iostream>
#include <unordered_map>
using namespace std;

int main(void){
    int j = 1;
    string str = "abc";
    unordered_map<string, string> mp;
    mp["test"] = str;
    cout << mp["test"] << endl;
    auto it = mp.find("test");
    if(it != mp.end())
        it->second = "bcd";
    cout << (str.size());
    system("pause");
}