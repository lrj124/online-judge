#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1000000 + 10;
struct leftist_tree {
    int lson,rson,dist,key;
}heap[maxn];
int n,m,father[maxn];
bool vis[maxn];
inline int merge(int x,int y) {
    if (!x || !y) return x|y;
    if (heap[x].key > heap[y].key || (heap[x].key == heap[y].key && x > y)) swap(x,y);
    heap[x].rson = merge(y,heap[x].rson);
    if (heap[heap[x].lson].dist < heap[heap[x].rson].dist) swap(heap[x].lson,heap[x].rson);
    heap[x].dist = heap[heap[x].rson].dist+1;
    return x;
}
inline int del(int x) { return merge(heap[x].lson,heap[x].rson); }
inline int find(int x) { return father[x] = (father[x] == x ? x : find(father[x])); }
int main() {
    scanf("%d",&n);
    for (int i = 1;i <= n;i++) {
        scanf("%d",&heap[i].key);
        heap[i].lson = 0;
        heap[i].rson = 0;
        heap[i].dist = 0;
        father[i] = i;
    }
    for (scanf("%d",&m);m--;) {
		char v[10];
        int x,y;
        scanf("%s%d",v,&x);
        if (v[0] == 'M') {
            scanf("%d",&y);
            if (vis[x] || vis[y]) continue;
            x = find(x);
            y = find(y);
            if (x == y) continue;
            father[x] = father[y] = merge(x,y);
        } else {
            if (vis[x]) {
				puts("0");
				continue;
			}
            x = find(x);
            printf("%d\n",heap[x].key);
            father[x] = father[heap[x].lson] = father[heap[x].rson] = del(x);
            heap[x].lson = 0;
            heap[x].rson = 0;
            heap[x].dist = 0;
            vis[x] = true;
        }
    }
    return 0;
}
