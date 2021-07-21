#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("read.in","w",stdout);
	srand(time(NULL));
	int n = rand()%15+1;
	printf("1\n%d %d %d",n,rand()%(1<<(n<<1))+1,rand()%(1<<(n<<1))+1);
	return 0;
}
