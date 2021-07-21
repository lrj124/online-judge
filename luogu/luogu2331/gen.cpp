#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("luogu2331.in","w",stdout);
	srand(time(NULL));
	printf("100 2 2\n");
	for (int i = 1;i <= 100;i++) printf("%d %d\n",rand()%100-50,rand()%100-20);
	return 0;
}
