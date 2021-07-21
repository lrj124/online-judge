#include <cstdlib>
#include <cstdio>
#include <ctime>
int main() {
	freopen("luogu4092.in","w",stdout);
	srand(time(NULL));
	int n = 20,q = 20;
	printf("%d %d\n",n,q);
	for (int i = 2;i <= n;i++) printf("%d %d\n",i,n%(i-1)+1);
	for (int i = 1;i <= q;i++) printf("%c %d\n",rand()%2 ? 'C' : 'Q',rand()%n+1);
	return 0;
}
