#include <utility>
#include <cstdio>
#include <cmath>
using namespace std;
int t,n,a,b;
inline double sqr(int x) { return (double)x*(double)x; }
inline pair<int,int> dfs(int sx,int sy,int ex,int ey,int l,int r,int num,int rot) {
	if (r-l+1 == 4) {
		if (rot%360 == 0) {
			if (num == l) return make_pair(sx,sy);
			if (num == l+1) return make_pair(sx,sy+1);
			if (num == r-1) return make_pair(ex,ey);
			if (num == r) return make_pair(ex,ey-1);
		}
		if (rot%360 == 90) {
			if (num == l) return make_pair(sx,sy);
			if (num == l+1) return make_pair(ex,ey-1);
			if (num == r-1) return make_pair(ex,ey);
			if (num == r) return make_pair(sx,sy+1);
		}
		if (rot%360 == 180) {
			if (num == l) return make_pair(ex,ey);
			if (num == l+1) return make_pair(ex,ey-1);
			if (num == r-1) return make_pair(sx,sy);
			if (num == r) return make_pair(sx,sy+1);
		}
		if (rot%360 == 270) {
			if (num == l) return make_pair(ex,ey);
			if (num == l+1) return make_pair(sx,sy+1);
			if (num == r-1) return make_pair(sx,sy);
			if (num == r) return make_pair(ex,ey-1);
		}
	}
	int mid = (l+r)/2,md1 = (l+mid)/2,md2 = (mid+r+1)/2;
	if (rot%360 == 0) {
		if (l <= num && num <= md1) return dfs(sx,sy,(sx+ex)/2,(sy+ey)/2,l,md1,num,rot+90);
		if (md1+1 <= num && num <= mid) return dfs(sx,(sy+ey)/2+1,(sx+ex)/2,ey,md1+1,mid,num,rot);
		if (mid+1 <= num && num <= md2) return dfs((sx+ex)/2+1,(sy+ey)/2+1,ex,ey,mid+1,md2,num,rot);
		if (md2+1 <= num && num <= r) return dfs((sx+ex)/2+1,sy,ex,(sy+ey)/2,md2+1,r,num,rot+270);
	}
	if (rot%360 == 90) {
		if (l <= num && num <= md1) return dfs(sx,sy,(sx+ex)/2,(sy+ey)/2,l,md1,num,rot+270);
		if (md1+1 <= num && num <= mid) return dfs((sx+ex)/2+1,sy,ex,(sy+ey)/2,md1+1,mid,num,rot);
		if (mid+1 <= num && num <= md2) return dfs((sx+ex)/2+1,(sy+ey)/2+1,ex,ey,mid+1,md2,num,rot);
		if (md2+1 <= num && num <= r) return dfs(sx,(sy+ey)/2+1,(sx+ex)/2,ey,md2+1,r,num,rot+90);
	}
	if (rot%360 == 180) {
		if (l <= num && num <= md1) return dfs((sx+ex)/2+1,(sy+ey)/2+1,ex,ey,l,md1,num,rot+90);
		if (md1+1 <= num && num <= mid) return dfs((sx+ex)/2+1,sy,ex,(sy+ey)/2,md1+1,mid,num,rot);
		if (mid+1 <= num && num <= md2) return dfs(sx,sy,(sx+ex)/2,(sy+ey)/2,mid+1,md2,num,rot);
		if (md2+1 <= num && num <= r) return dfs(sx,(sy+ey)/2+1,(sx+ex)/2,ey,md2+1,r,num,rot+270);
	}
	if (rot%360 == 270) {
		if (l <= num && num <= md1) return dfs((sx+ex)/2+1,(sy+ey)/2+1,ex,ey,l,md1,num,rot+270);
		if (md1+1 <= num && num <= mid) return dfs(sx,(sy+ey)/2+1,(sx+ex)/2,ey,md1+1,mid,num,rot);
		if (mid+1 <= num && num <= md2) return dfs(sx,sy,(sx+ex)/2,(sy+ey)/2,mid+1,md2,num,rot);
		if (md2+1 <= num && num <= r) return dfs((sx+ex)/2+1,sy,ex,(sy+ey)/2,md2+1,r,num,rot+90);
	}
	return make_pair(1,55);
}
int main() {
	freopen("read.in","r",stdin);
	freopen("bf.out","w",stdout);
	for (scanf("%d",&t);t--;) {
		scanf("%d%d%d",&n,&a,&b);
		pair<int,int> s = dfs(1,1,1<<n,1<<n,1,1<<(n<<1),a,0),t = dfs(1,1,1<<n,1<<n,1,1<<(n<<1),b,0);
		printf("%.0lf\n",(double)sqrt(sqr(s.first-t.first)+sqr(s.second-t.second))*10.);
	}
	return 0;
}
