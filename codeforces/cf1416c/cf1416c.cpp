//I am hunting for the golden stag.
#include <cstdio>
int n,tot(1);
inline void insert(int x) {
	int u = 1;
	for (int i = 30;~i;i--) {
		int bit = (x>>i)&1;
		if (!ch[u][bit]) ch[u][bit] = ++tot;
		u = ch[u][bit];
	}
}
int main() {
	freopen("cf1416c.in","r",stdin);
	freopen("cf1416c.out","w",stdout);
	
	return 0;
}
