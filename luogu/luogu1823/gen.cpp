#include <cstdlib>
#include <cstdio>
#include <ctime>
int n = 10;
int main() {
	freopen("luogu1823.in","w",stdout);
	srand(time(NULL));
	printf("%d\n",n);
	for (int i = 1;i <= n;i++) printf("%d ",rand()%10+1);
	return 0;
}
