#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

PLL calc(LL n, LL m)	//计算 n 级图，第m点的坐标
{
	if(0 == n)			//如果是0 级图，坐标只能是 (0, 0)
	{
		return make_pair(0, 0);
	}
	LL len = 1ll << (n - 1);	
	LL cnt = 1ll << (2 * n - 2);
	PLL pos = calc(n - 1, m % cnt);
	LL x = pos.first, y = pos.second;
	LL z = m / cnt;
	if(0 == z)	//左上
	{
		return make_pair(y, x);
	}
	if(1 == z)	//右上
	{
		return make_pair(x, y + len);
	}
	if(2 == z)	//右下
	{
		return make_pair(x + len, y + len);
	}
	//左下
	return make_pair(2 * len - y - 1, len - x - 1);
}

int main()
{
	freopen("read.in","r",stdin);
	freopen("std.out","w",stdout);
	int Test;
	scanf("%d", &Test);
	while(Test--)
	{
		LL N, A, B;
		scanf("%lld%lld%lld", &N, &A, &B);
		PLL ac = calc(N, A - 1);
		PLL bc = calc(N, B - 1);
		double x = ac.first - bc.first, y = ac.second - bc.second;
		printf("%.0f\n", sqrt(x * x + y * y) * 10);	//这里用 %lf 输出，poj 会 wa
	}
	return 0;
}
