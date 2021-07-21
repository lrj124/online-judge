//I am hunting for the golden stag.
#include <cstdio>
char str[8];
inline int to(char ch) {
	if ('0' <= ch && ch <= '9') return ch-'0';
	return ch-'A'+10;
}
inline char To(int x) {
	if (x < 10) return '0'+x;
	return 'A'+x-10;
}
int main() {
	scanf("%s",str);
	int a = 255-to(str[1])*16-to(str[2]);
	int b = 255-to(str[3])*16-to(str[4]);
	int c = 255-to(str[5])*16-to(str[6]);
	printf("#%c%c%c%c%c%c",To(a/16),To(a%16),To(b/16),To(b%16),To(c/16),To(c%16));
	return 0;
}
