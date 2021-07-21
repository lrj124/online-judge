#include <bits/stdc++.h>
#define maxn 101000
#define maxm 303000
using namespace std;

template<class T>
inline void read(T &a){
    T s = 0, w = 1;
    char c = getchar();
    while(c < '0' || c  > '9') {if(c == '-') w = -1; c = getchar();}
    while(c >= '0' && c <= '9') {s = (s << 1) + (s << 3) + (c ^ 48); c = getchar();}
    a = s*w;
}

static int n,q;
static int head[maxn], net[maxm], to[maxm],tot;

inline void add(int x, int y){
    net[++tot] = head[x], head[x] = tot, to[tot] = y;
}

static int dfn[maxn],tid[maxn], fat[maxn], size[maxn], son[maxn], deep[maxn];
static int top[maxn], cnt;

set<int> Ans[maxn];

void dfs1(int x, int fa){
    size[x] = 1;
    son[x] = 0; size[0] = 0;
    fat[x] = fa;
//  printf("%d\n", x);
    for (int i = head[x]; i; i = net[i]){
        int v = to[i];
        if(v == fa) continue;
        deep[v] = deep[x] + 1;
        dfs1(v, x);
        size[x] += size[v];
        if(size[v] > size[son[x]]) son[x] = v;
    }
}
void dfs2(int x, int fa, int t){
    dfn[++cnt] = x;
    //printf("%d %d %d\n", cnt, x, t);
    tid[x] = cnt;
    top[x] = t;
    if(!son[x]) return;
    dfs2(son[x], x, t);
    for (int i = head[x]; i; i = net[i]){
        int v = to[i];
        if(v == fa || v == son[x]) continue;
        dfs2(v, x, v);
    }
}

int col[maxn];
int main(){
        freopen("luogu4416.in","r", stdin);
        freopen("std.out","w", stdout);
    read(n); read(q);
//  printf("%d\n", n); return 0;
    for (int i = 1; i < n; i++){
        int x, y;
        read(x); read(y);
        add(x, y); add(y, x);
    }
    dfs1(1, 0);
    dfs2(1, 0, 1); 
    for (int i = 1; i <= q; i++){
        int opt, x;
        read(opt); read(x);
        if(opt == 0){
            col[x] ^= 1;
            if(col[x] == 1) Ans[top[x]].insert(tid[x]);
             else Ans[top[x]].erase(tid[x]);
        }
        else{
            int ans = 0x3f3f3f3f;
            while(x){
                int k = *Ans[top[x]].begin();
                if(Ans[top[x]].size())
                    if(deep[dfn[k]] <= deep[x]) ans = dfn[k];
                x = fat[top[x]];
            }
            printf("%d\n", ans == 0x3f3f3f3f ? -1: ans);
        }
    }
    return 0;
}
