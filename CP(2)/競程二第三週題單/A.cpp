#include <iostream>
#include <cstdio>
#define N 200010 
using namespace std;
int bit[N] , n , bef[N] , kase=1 ;
int lower_bit(int x) {
	return x & (-x) ;
}
void update(int x,int v) {
	for( ; x<=n ; x+=lower_bit(x))
		bit[x] += v ;
}
int sum(int x) {
	int ans=0 ;
	for( ; x ; x-=lower_bit(x))
		ans += bit[x] ;
	return ans ;
}
int main () {
	while(scanf("%d",&n)==1 && n) {
		int i , v , x ;
		char c[5] ;
		for(i=0 ; i<=n ; i++)
			bit[i] = 0 ;
		for(i=1 ; i<=n ; i++) {
			scanf("%d",&v) ;
			update(i,v) ;
			bef[i] = v ;
		}
		if(kase!=1) puts("") ;
		printf("Case %d:\n",kase++) ;
		while(scanf("%s",c)==1 && c[0]!='E') {
			if(c[0]=='S') {
				scanf("%d%d",&x,&v) ;
				update(x,v-bef[x]) ;
				bef[x] = v ;
			} else {
				scanf("%d%d",&x,&v) ;
				printf("%d\n",sum(v)-sum(x-1)) ;
			}
		}
	}
}
