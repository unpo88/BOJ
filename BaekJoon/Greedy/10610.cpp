#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int sum = 0;

int main() {
    string s;
    cin >> s;

    for (char c : s) {
        sum += c - '0';
    }
    sort(s.begin(), s.end());

    if (s[0] == '0' && sum % 3 == 0) {
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }else {
        cout << "-1\n";
    }

    return 0;
}