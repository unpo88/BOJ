#include <cstdio>

int main() {
	char s[111];
	while (scanf("%[^\n]\n", s) == 1) {
		printf("%s\n", s);
	}
	return 0;
}


/*

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        cout << s << endl;
    }
    return 0;
}

*/