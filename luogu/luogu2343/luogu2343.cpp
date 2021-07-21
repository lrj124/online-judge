/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.15.20:27
*Mail          :  1584634848@qq.com
*Problem       :  luogu2343
************************************************/
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> tree;
int m,q,cnt;
int main() {
	freopen("luogu2343.in","r",stdin);
	freopen("luogu2343.out","w",stdout);
	scanf("%d%d",&m,&q);
	for (int x;m--;cnt++) {
		scanf("%d",&x);
		tree.insert(lower_bound(tree.begin(),tree.end(),x),x);
	}
	for (int x,y;q--;) {
		scanf("%d%d",&x,&y);
		if (x == 1) printf("%d\n",tree[cnt-y]);
		else tree.insert(upper_bound(tree.begin(),tree.end(),y),y),cnt++;
	}
	return 0;
}
