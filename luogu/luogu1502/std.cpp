#include<bits/stdc++.h>
#define maxn 10007
using namespace std;
int t,n,w,h,cnt,lim,root;
struct node{
    int x,l,r,w,d;
}a[maxn<<3];//扫描线 
struct tree{
    int le,ri,w,tag;
}tr[5000007];//动态开点的不同，le和ri记录的是左端点和右端点的p值 
//tr记住稍微大一点 （别 MLE 了 ），反正不会错 
template<typename type_of_scan>
inline void scan(type_of_scan &x){
    type_of_scan f=1;x=0;char s=getchar();
    while(s<'0'||s>'9') f=s=='-'?-1:1,s=getchar();
    while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+s-'0',s=getchar();
    x*=f;
}

bool operator <(node x,node y){
    return x.x==y.x?x.d>y.d:x.x<y.x;
}//sort的细节*** 

inline void push_down(int p,int k){
    if(!tr[p].le) tr[p].le=++cnt;//没点开点 
    if(!tr[p].ri) tr[p].ri=++cnt;
    tr[tr[p].le].w+=k,tr[tr[p].ri].w+=k;
    tr[tr[p].le].tag+=k,tr[tr[p].ri].tag+=k;
}

void add(int nl,int nr,int l,int r,int &p,int k){
    if(!p) p=++cnt;//没点开点 
    if(nl<=l&&nr>=r){
        tr[p].w+=k,tr[p].tag+=k;
        return ;
    }
    if(tr[p].tag) push_down(p,tr[p].tag);tr[p].tag=0;
    int mid=(l+r)>>1;
    if(nl<=mid) add(nl,nr,l,mid,tr[p].le,k);
    if(nr>mid) add(nl,nr,mid+1,r,tr[p].ri,k);
    tr[p].w=max(tr[tr[p].le].w,tr[tr[p].ri].w);
}//与线段树相同 

inline void work(){
    int ans=0;memset(tr,0,sizeof tr);
    scan(n);scan(w),scan(h);
    for(int i=1,x,y,v;i<=n;i++)
        scan(x),scan(y),scan(v),lim=max(x+w+1,lim),//lim是线段树范围 
        a[(i<<1)-1]=(node){x,y,y+h-1,v,1},//强行转换格式，-1的细节** 
        a[i<<1]=(node){x+w-1,y,y+h-1,v,-1};//细节** 
    sort(a+1,a+1+2*n);//细节** 

    for(int i=1;i<=2*n;i++){
        add(a[i].l,a[i].r,1,lim,root,a[i].w*a[i].d);
        ans=max(ans,tr[root].w);//直接用整棵树更新就好啦 
    }
    printf("%d\n",ans);
}

int main(){
	freopen("luogu1502.in","r",stdin);
	freopen("std.out","w",stdout);
    scan(t);
    while(t--) work();
    return 0;
}
