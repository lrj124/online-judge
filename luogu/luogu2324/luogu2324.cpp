/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.02.22:03
*Mail          :  1584634848@qq.com
*Problem       :  luogu2324
************************************************/
#include <algorithm>
#include <cstdio>
using std :: swap;
const char end[6][6] = { '0','0','0','0','0','0','0','1','1','1','1','1','0','0','1','1','1','1','0','0','0','*','1','1','0','0','0','0','0','1','0','0','0','0','0','0' };
const int dx[] = { 0,-2,-2,-1,-1,1,1,2,2 };
const int dy[] = { 0,-1,1,-2,2,-2,2,-1,1 };
char map[8][8];
int T,x,y,ans;
inline int diff() {
	int cnt = 0;
	for (int i = 1;i <= 5;i++)
		for (int j = 1;j <= 5;j++)
			if (end[i][j] ^ map[i][j]) cnt++;
	return cnt;
}
inline void dfs(int x,int y,int step,int dir) {
	if (step+diff() > 16 || step > ans) return;
	if (!diff()) {
		ans = step;
		return;
	}
	for (int i = 1;i <= 8;i++)
		if (x+dx[i] >= 1 && x+dx[i] <= 5 && y+dy[i] >= 1 && y+dy[i] <= 5 && dir+i ^ 9) {
			swap(map[y+dy[i]][x+dx[i]],map[y][x]);
			dfs(x+dx[i],y+dy[i],step+1,i);
			swap(map[y+dy[i]][x+dx[i]],map[y][x]);
		}
}
int main() {
	freopen("luogu2324.in","r",stdin);
	freopen("luogu2324.out","w",stdout);
	for (scanf("%d",&T);T--;) {
		for (int i = 1;i <= 5;i++) {
			scanf("%s",map[i]+1);
			for (int j = 1;j <= 5;j++)
				if (map[i][j] == '*') x = j,y = i;
		}
		ans = 233333;
		dfs(x,y,0,0);
		printf("%d\n",ans ^ 233333 ? ans : -1);
	}
	return 0;
}
