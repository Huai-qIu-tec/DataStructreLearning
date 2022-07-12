#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(string s){
    int len = s.length();
    int a = 0;
    int b = len;
    if(len == 1)
        return true;
    while(a <= b)
    {
        if(s[a++] != s[--b])
            return false;
    }
    return true;
}
int countSubstrings(string s) {
    int count = 0;
    for(int i = 1; i < s.size(); i++){
        for(int j = 0; j < s.size(); j++){
            cout << s.substr(j, i) << endl;
            if(isPalindrome(s.substr(j, i)))
                count++;
            else
                continue;
        }
    }
    return count;
}
int main(void){
    string s = "abc";
    cout << countSubstrings(s);
    system("pause");
}