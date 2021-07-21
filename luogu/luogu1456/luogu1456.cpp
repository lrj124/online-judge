#include <algorithm>
#include <cstdio>
using namespace std;
struct leftist_tree {
	int lson,rson,dist,key;
} heap[100001];
int n,m,father[100001];
inline int merge(int x,int y) {
	if (!x || !y) return x|y;
	if (heap[x].key < heap[y].key || (heap[x].key == heap[y].key && x > y)) swap(x,y);
	heap[x].rson = merge(heap[x].rson,y);
	father[heap[x].rson] = x;
	if (heap[heap[x].lson].dist < heap[heap[x].rson].dist) swap(heap[x].lson,heap[x].rson);
	heap[x].dist = heap[heap[x].rson].dist+1;
	return x;
}
inline int del(int x) { return merge(heap[x].lson,heap[x].rson); }
inline int find(int x) { return father[x] = (father[x] == x ? x : find(father[x])); }
int main() {
	freopen("luogu1456.in","r",stdin);
	freopen("luogu1456.out","w",stdout);
	for (;scanf("%d",&n) ^ EOF;) {
		for (int i = 1;i <= n;i++) {
			scanf("%d",&heap[i].key);
			heap[i].lson = heap[i].rson = heap[i].dist = 0;
			father[i] = i;
		}
		for (scanf("%d",&m);m--;) {
			int x,y,root;
			scanf("%d%d",&x,&y);
			x = find(x);
			y = find(y);
			if (x == y) printf("-1\n");
			else {
				heap[x].key >>= 1;
				root = del(x);
				heap[x].lson = heap[x].rson = 0;
				x = merge(root,x);
				heap[y].key >>= 1;
				root = del(y);
				heap[y].lson = heap[y].rson = 0;
				y = merge(root,y);
				root = merge(x,y);
				father[x] = father[y] = root;
				printf("%d\n",heap[root].key);
			}
		}
	}
    return 0;
}
