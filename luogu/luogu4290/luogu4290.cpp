/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.22.17:09
*Mail          :  1584634848@qq.com
*Problem       :  luogu4290
************************************************/
#include <cstring>
#include <cstdio>
const int maxn = 200 + 10;
const char ans[] = { 'W','I','N','G' };
int n[4],bec[maxn][3],tot;
bool f[maxn][maxn][4];
inline int num(char ch) {
	if (ch == 'W') return 0;
	if (ch == 'I') return 1;
	if (ch == 'N') return 2;
	if (ch == 'G') return 3;
	return 233;
}
int main() {
	//freopen("luogu4290.in","r",stdin);
	//freopen("luogu4290.out","w",stdout);
	for (int i = 0;i < 4;i++) scanf("%d",&n[i]);
	for (int i = 0;i < 4;i++)
		for (int j = 1;j <= n[i];j++) {
			char str[3]; scanf("%s",str);
			bec[++tot][0] = i;
			bec[tot][1] = num(str[0]);
			bec[tot][2] = num(str[1]);
		}
	char str[maxn]; scanf("%s",str);
	int len = strlen(str);
	for (int i = 1;i <= len;i++) f[i][i][num(str[i-1])] = true;
	for (int i = len;i;i--)
		for (int j = i+1;j <= len;j++)
			for (int k = i;k < j;k++)
				for (int t = 1;t <= tot;t++) f[i][j][bec[t][0]] |= f[i][k][bec[t][1]]&f[k+1][j][bec[t][2]];
	for (int i = 0;i < 4;i++)
		if (f[1][len][i]) printf("%c",ans[i]),f[0][0][0] = true;
	if (!f[0][0][0]) printf("The name is wrong!");
	return 0;
}
