#include <cstdio>

int main() {
	char c;
	while ((c = getchar()) && c != EOF) {
		printf("%c", c);
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