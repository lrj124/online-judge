/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.17.22:04
*Mail          :  1584634848@qq.com
*Problem       :  b
************************************************/
#include <bits/stdc++.h>
using namespace std;
int T,n,a[200001],b[200001],c[200001],d[200001];
int main() {
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++) scanf("%d",&b[i]);
	int ct = 0,l = a[1],r =  b[1];
	for (int i = 2;i <= n;i++) {
		if (r < a[i] || l > b[i]) {
			c[++ct] = l;
			d[ct] = r;
			l = a[i];
			r = b[i];
		}else{
			l=max(l,a[i]);
			r=min(r,b[i]);
		}
	}
	c[++ct] = l;
	d[ct] = r;
	int pos = c[1];
	if (ct == 1) {
		printf("0\n");
		return 0;
	}
	if (d[1] < c[2]) pos = d[1];
	long long ans = 0;
	for (int i = 2;i <= ct;i++)
		if (pos>d[i]) {
			if ((pos-d[i])%2 == 1 && d[i]-c[i] > 0 && i <  ct && d[i+1] < c[i]) {
				ans  += (pos-d[i]+1)/2;
				pos = d[i]-1;
			}else {
				ans += (pos-d[i]+1)/2;
				pos = d[i];
			}
		}  else {
			if ((c[i]-pos)%2 == 1 && d[i]-c[i] > 0 && i < ct && c[i+1] > d[i]) {
				ans += (c[i]-pos+1)/2;
				pos = c[i]+1;
			}
			else {
				ans += (c[i]-pos+1)/2;
				pos = c[i];
			}
		}
	printf("%lld",ans);
	return 0;
}
