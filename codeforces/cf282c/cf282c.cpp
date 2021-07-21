#include <iostream>
#include <string>
using namespace std;
string a,b;
int cnt;
int main() {
	cin >> a >> b;
	if (a.size() ^ b.size() || (a.size() == 1 && a != b)) return cout << "NO",0;
	for (size_t i = 0;i < a.size();i++) cnt += a[i] == '1';
	if (!cnt) {
		cnt = 0;
		for (size_t i = 0;i < b.size();i++) cnt += b[i] == '1';
		if (!cnt) cout << "YES";
		else cout << "NO";
	} else {
		cnt = 0;
		for (size_t i = 0;i < b.size();i++) cnt += b[i] == '1';
		if (cnt) cout << "YES";
		else cout << "NO";
	}
	return 0;
}
