#include <iostream>
#include <string>
#define mod 1000000
using namespace std;

char secret[5001];
int dp[5001];
int secretSize;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0] = 1;
	dp[1] = 1;
	
	string N;
	cin >> secret;
	N = secret;
	secretSize = N.size();

	cout << dp[secretSize];
	return 0;
}