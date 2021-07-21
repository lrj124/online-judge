//I am hunting for the golden stag.
#include <cstdio>
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
int 
int main() {
	freopen("cf545e.in","r",stdin);
	freopen("cf545e.out","w",stdout);
	
	return 0;
}
