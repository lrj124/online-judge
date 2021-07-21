/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.24.20:58
*Mail          :  1584634848@qq.com
*Problem       :  luogu5091
************************************************/
#include <cstdio>
#include <cctype>
char b[20000010];
int cnt,a,m,ans(1);
inline int power(int x,int y) {
	int ans = 1;
	for (;y;y >>= 1,x = 1ll*x*x%m) if (y&1) ans = 1ll*ans*x%m;
	return ans;
}
int main() {
	freopen("luogu5091.in","r",stdin);
	freopen("luogu5091.out","w",stdout);
	scanf("%d%d",&a,&m); getchar();
	for (char ch = getchar();isalnum(ch);b[++cnt] = ch,ch = getchar());
	for (int i = cnt;i;i--,a = power(a,10)) ans = 1ll*ans*power(a,b[i]-'0')%m;
	printf("%d",ans);
	return 0;
}
