/************************************************
*Author        :  lrj124
*Created Time  :  2020.08.14.09:44
*Mail          :  1584634848@qq.com
*Problem       :  luogu1512
************************************************/
#include <cstdio>
int sg[2002][13][32];
inline void get_sg() {
}
int main() {
	freopen("luogu1512.in","r",stdin);
	freopen("luogu1512.out","w",stdout);
	int T,y,m,d;
	get_sg();
	for (scanf("%d",&T);T--;puts(sg[y][m][d] ? "YES" : "NO")) scanf("%d%d%d",&y,&m,&d);
	return 0;
}
