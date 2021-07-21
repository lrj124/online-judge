#include<cstdio>
#include<algorithm>
#include<cctype>
#define maxn 200007
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
const int inf=0x7fffffff;
int n,m,num,head[maxn],a[maxn],size[maxn],d[maxn],top[maxn];
int cnt,sum[maxn<<2],lazy[maxn<<2],maxx[maxn<<2],minn[maxn<<2];
int fa[maxn],id[maxn],zrj[maxn],son[maxn];
char s1[8];
inline int qread() {
  char c=getchar();int num=0,f=1;
  for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
  for(;isdigit(c);c=getchar()) num=num*10+c-'0';
  return num*f;
}
struct node {
  int v,w,nxt;
}e[maxn<<1];
inline void ct(int u, int v, int w) {
  e[++num].v=v;
  e[num].w=w;
  e[num].nxt=head[u];
  head[u]=num;
}
void dfs1(int u) {
  size[u]=1;
  for(int i=head[u];i;i=e[i].nxt) {
    int v=e[i].v;
    if(v!=fa[u]) {
      d[v]=d[u]+1;
      fa[v]=u;
      zrj[v]=e[i].w;
      dfs1(v);
      size[u]+=size[v];
      if(size[v]>size[son[u]]) son[u]=v;
    }
  }
}
void dfs2(int u, int t) {
  id[u]=++cnt;
  top[u]=t;
  a[cnt]=zrj[u];
  if(son[u]) dfs2(son[u],t);
  for(int i=head[u];i;i=e[i].nxt) {
    int v=e[i].v;
    if(v!=fa[u]&&v!=son[u]) dfs2(v,v);
  }
}
inline void pushup(int rt) {
  sum[rt]=sum[ls]+sum[rs];
  maxx[rt]=max(maxx[ls],maxx[rs]);
  minn[rt]=min(minn[ls],minn[rs]);
}
inline void pushdown(int rt) {
  if(lazy[rt]) {
    sum[ls]=-sum[ls],lazy[ls]^=1;
    sum[rs]=-sum[rs],lazy[rs]^=1;
    int t1=maxx[ls],t2=maxx[rs],s1=minn[ls],s2=minn[rs];
    maxx[ls]=-s1,maxx[rs]=-s2,minn[ls]=-t1,minn[rs]=-t2;
    lazy[rt]=0;
  }
}
void build(int rt, int l, int r) {
  if(l==r) {
    sum[rt]=maxx[rt]=minn[rt]=a[l];
    return;
  }
  int mid=(l+r)>>1;
  build(ls,l,mid);
  build(rs,mid+1,r);
  pushup(rt);
}
void add(int rt, int l, int r, int L, int val) {
  if(l==r) {
    sum[rt]=maxx[rt]=minn[rt]=val;
    return;
  }
  pushdown(rt);
  int mid=(l+r)>>1;
  if(L<=mid) add(ls,l,mid,L,val);
  else add(rs,mid+1,r,L,val);
  pushup(rt);
}
void modify(int rt, int l, int r, int L, int R) {
  if(L>r||R<l) return;
  if(L<=l&&r<=R) {
    sum[rt]=-sum[rt],lazy[rt]^=1;
    int t=maxx[rt],s=minn[rt];
    maxx[rt]=-s,minn[rt]=-t;
    return;
  } 
  int mid=(l+r)>>1;
  pushdown(rt);
  modify(ls,l,mid,L,R),modify(rs,mid+1,r,L,R);
  pushup(rt);
}
int csum(int rt, int l, int r, int L, int R) {
  if(L>r||R<l) return 0;
  if(L<=l&&r<=R) return sum[rt];
  int mid=(l+r)>>1;
  pushdown(rt);
  return csum(ls,l,mid,L,R)+csum(rs,mid+1,r,L,R);
}
int cmax(int rt, int l, int r, int L, int R) {
  if(L>r||R<l) return -inf;
  if(L<=l&&r<=R) return maxx[rt];
  int mid=(l+r)>>1,ans=-inf;
  pushdown(rt);
  if(L<=mid) ans=max(ans,cmax(ls,l,mid,L,R));
  if(R>mid) ans=max(ans,cmax(rs,mid+1,r,L,R));
  return ans;
}
int cmin(int rt, int l, int r, int L, int R) {
  if(L>r||R<l) return inf;
  if(L<=l&&r<=R) return minn[rt];
  int mid=(l+r)>>1,ans=inf;
  pushdown(rt);
  if(L<=mid) ans=min(ans,cmin(ls,l,mid,L,R));
  if(R>mid) ans=min(ans,cmin(rs,mid+1,r,L,R));
  return ans;
}
void cal(int x, int y) {
  int fx=top[x],fy=top[y];
  while(fx!=fy) {
    if(d[fx]<d[fy]) swap(x,y),swap(fx,fy);
    modify(1,1,cnt,id[fx],id[x]);
    x=fa[fx],fx=top[x];
  }
  if(id[x]>id[y]) swap(x,y);
  modify(1,1,cnt,id[x]+1,id[y]);
}
int query_max(int x, int y) {
  int fx=top[x],fy=top[y],ans=-inf;
  while(fx!=fy) {
    if(d[fx]<d[fy]) swap(x,y),swap(fx,fy);
    ans=max(ans,cmax(1,1,cnt,id[fx],id[x]));
    x=fa[fx],fx=top[x];
  }
  if(id[x]>id[y]) swap(x,y);
  ans=max(ans,cmax(1,1,cnt,id[x]+1,id[y]));
  return ans;
}
int query_min(int x, int y) {
  int fx=top[x],fy=top[y],ans=inf;
  while(fx!=fy) {
    if(d[fx]<d[fy]) swap(x,y),swap(fx,fy);
    ans=min(ans,cmin(1,1,cnt,id[fx],id[x]));
    x=fa[fx],fx=top[x];
  }
  if(id[x]>id[y]) swap(x,y);
  ans=min(ans,cmin(1,1,cnt,id[x]+1,id[y]));
  return ans;
}
int query_sum(int x, int y) {
  int fx=top[x],fy=top[y],ans=0;
  while(fx!=fy) {
    if(d[fx]<d[fy]) swap(x,y),swap(fx,fy);
    ans+=csum(1,1,cnt,id[fx],id[x]);
    x=fa[fx],fx=top[x];
  }
  if(id[x]>id[y]) swap(x,y);
  ans+=csum(1,1,cnt,id[x]+1,id[y]);
  return ans;
}
int main() {
  freopen("luogu1505.in","r",stdin);
  freopen("std.out","w",stdout);
  n=qread();
  for(int i=1,u,v,w;i<n;++i) {
    u=qread()+1,v=qread()+1,w=qread();
    ct(u,v,w);ct(v,u,w);
  }
  dfs1(1);dfs2(1,1);build(1,1,n);
  m=qread();
  for(int i=1,x,y;i<=m;++i) {
    scanf("%s",s1);x=qread()+1,y=qread()+1;
    if(s1[0]=='C') add(1,1,n,id[x],y-1);
    if(s1[0]=='N') cal(x,y);
    if(s1[0]=='S') printf("%d\n",query_sum(x,y));
    if(s1[1]=='I') printf("%d\n",query_min(x,y));
    if(s1[1]=='A') printf("%d\n",query_max(x,y));
  }
  return 0;
}
