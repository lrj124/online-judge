#include <string>
#include <cstdio>
using ll = long long;
const ll mod = (ll)1e9+7;
ll f[1<<21][21],ans,n;
std :: string s;
int main(){
	scanf("%lld%s",&n,&s[0]);
	for (int i = 0;i < 1<<n;i++) f[i][0] = (s[i] == '1');
	for (int j = 0;j < n;j++)
		for (int i = 0;i < 1<<n;i++) f[i][j+1] = (f[i][j]*2ll+f[i^(1<<j)][j])%mod;
	for (int i = 0;i < 1<<n;i++) ans = (ans+f[i][n]*3ll*(s[i] == '1'))%mod;
	printf("%lld",ans);
	return 0;
}
