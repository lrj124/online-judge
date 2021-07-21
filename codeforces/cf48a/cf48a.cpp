#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string,string> los;
string a,b,c;
int main() {
	los["scissors"] = "rock";
	los["rock"] = "paper";
	los["paper"] = "scissors";
	cin >> a >> b >> c;
	if (b != los[a] && b != a && c != los[a] && c != a) printf("F");
	else if (c != los[b] && c != b && a != los[b] && a != b) printf("M");
	else if (a != los[c] && a != c && b != los[c] && b != c) printf("S");
	else printf("?");
	return 0;
}
