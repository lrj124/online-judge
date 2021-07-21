/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.18.20:11
*Mail          :  1584634848@qq.com
*Problem       :  c
************************************************/
#include <bits/stdc++.h>
using namespace std;
priority_queue<double,vector<double>,greater<double> > Q;
int n;
int main() {
	scanf("%d",&n);
	for (int i = 1,x;i <= n;i++) scanf("%d",&x),Q.push(x);
	for (int i = 1;i < n;i++) {
		double a,b; a = Q.top(); Q.pop(); b = Q.top(); Q.pop();
		Q.push((a+b)/2.);
	}
	printf("%.5f",Q.top());
	return 0;
}
