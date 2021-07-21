#include <cstdio>
#define Abs(x) (x > 0 ? x : -(x))
int t,n,x,y,k,cas;
double s;
inline int gcd(int a,int b) { return b ? gcd(b,a%b) : a; }
int main() {
	for (scanf("%d",&t);t--;s = k = 0) {
		scanf("%d",&n);
		for (int i = 1,a,b;i <= n;i++) {
			scanf("%d%d",&a,&b);
			s += 1.*(x*(y+b)-(x+a)*y)/2.0;
			x += a; y += b;
			k += gcd(Abs(a),Abs(b));
		}
		printf("Scenario #%d:\n%d %d %.1f\n\n",++cas,(int)(s+1.-1.*k/2.),k,s);
	}
	return 0;
}
