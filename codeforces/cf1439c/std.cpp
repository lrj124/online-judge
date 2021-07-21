#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

template <typename T>

void read(T &a)
{
	T x = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	a = x * f;
}

template <typename T,typename... Args> void read(T &t,Args &... args) {read(t); read(args...); }

int n,a[N],m;

struct Segment_Tree
{
	int sum[N << 2],lazy[N << 2],mini[N << 2];
	void pushup(int now)
	{
		sum[now] = sum[now << 1] + sum[now << 1 | 1];
		mini[now] = min(mini[now << 1],mini[now << 1 | 1]);
	}
	void pushdown(int now,int l,int r)
	{
		if (lazy[now] == -1) return ;
		int mid = (l + r) >> 1;
		sum[now << 1] = (mid - l + 1) * lazy[now];
		mini[now << 1] = lazy[now];
		lazy[now << 1] = lazy[now];
		sum[now << 1 | 1] = (r - mid) * lazy[now];
		mini[now << 1 | 1] = lazy[now];
		lazy[now << 1 | 1] = lazy[now];
		lazy[now] = -1;
	}
	void build(int now,int l,int r)
	{
		lazy[now] = -1;
		if (l == r)
		{
			sum[now] = a[l];
			mini[now] = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(now << 1,l,mid);
		build(now << 1 | 1,mid + 1,r);
		pushup(now);
	}
	void update(int now,int l,int r,int ll,int rr,int k)
	{
		if (ll <= l && rr >= r)
		{
			sum[now] = (r - l + 1) * k;
			lazy[now] = k;
			return ;
		}
		pushdown(now,l,r);
		int mid = (l + r) >> 1;
		if (ll <= mid) update(now << 1,l,mid,ll,rr,k);
		if (rr > mid) update(now << 1 | 1,mid + 1,r,ll,rr,k);
		pushup(now);
	}
	int query(int now,int l,int r,int ll,int rr)
	{
		if (ll <= l && rr >= r)
		{
			return sum[now];
		}
		pushdown(now,l,r);
		int mid = (l + r) >> 1,ans = 0;
		if (ll <= mid) ans += query(now << 1,l,mid,ll,rr);
		if (rr > mid) ans += query(now << 1 | 1,mid + 1,r,ll,rr);
		return ans;
	}
	int query(int now,int l,int r,int &val)
	{
		if (val >= sum[now])
		{
			val -= sum[now];
			return r - l + 1;
		}
		if (l == r) return 0;
		pushdown(now,l,r);
		int mid = (l + r) >> 1,ans = 0;
		if (mini[now << 1] <= val) ans += query(now << 1,l,mid,val);
		if (mini[now << 1 | 1] <= val) ans += query(now << 1 | 1,mid + 1,r,val);
		return ans;
	}
}T;

signed main()
{
	freopen("in.in","r",stdin);
	freopen("ans.ans","w",stdout);
	read(n,m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	T.build(1,1,n);
	while (m--)
	{
		int opt;
		read(opt);
		if (opt == 1)
		{
			int l = 1,r,x,ans = -1,y;
			read(r,y);
			x = r;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (T.query(1,1,n,mid,mid) < y) r = mid - 1,ans = mid;
				else l = mid + 1;
			}
			if (ans == -1) continue;
			T.update(1,1,n,ans,x,y);
		}
		if (opt == 2)
		{
			int x,w;
			read(x,w);
			if (x > 1) w += T.query(1,1,n,1,x - 1);
			int res = T.query(1,1,n,w);
			printf("%lld\n",res - (x - 1));
		}
	}
	return 0;
}
