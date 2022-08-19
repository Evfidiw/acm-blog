//	link
//	https://www.luogu.com.cn/problem/UVA11235

//	mean:
//	max cnt in segment
	
/*	think��
	�����ǵݼ������䣬��֪ͬһ������������һ���һ�Σ�
		�� num[i]��ʾ��i�������ǵڼ��Σ�����l��r�ǵڼ��ε���˵���Ҷ˵�
	��������������ֵ�ֳ����Σ�һ���������ģ����������Ҷ˲������ģ� 
	Ϊmax(r[L]-left+1, rmq(r[L],l[R]), right-l[R]+1) 
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int read(){
   int s=0,w=1;  
   char ch=getchar();  
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}  
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();  
   return s*w;  
} 
#define ll long long
#define inf 0x3f3f3f3f
const int N = 200005;

int f[N][21], l[N], r[N], num[N];

int query(int l,int r)
{
    int k = log(r-l+1)/log(2);
    return max(f[l][k], f[r-(1<<k)+1][k]);
}

int main()
{
    int n, q, t=inf, cnt=0;
    while(1){
	    cin >> n;
	    if(!n) break;
	    cin >> q;
	    for(int i=1; i<=n; i++){
	    	int x=read();
	    	if(x!=t) t=x, r[cnt]=i-1, l[++cnt]=i;
	    	num[i] = cnt;
		}
	    for(int i=1; i<=cnt; i++){
	    	f[i][0] = r[i]-l[i]+1;
		}
		for(int j=1; j<=21; j++){
	        for(int i=1; i+(1<<j)-1<=n; i++){
	            f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
	        }
	    }
	    for(int i=1; i<=q; i++){
	    	int ans=0, x=read(), y=read();
	    	if(num[x]==num[y]) printf("%d\n",y-x+1);
	    	else{
	    		if(num[x]+1 <= num[y]-1) ans = query(num[x]+1, num[y]-1);
	    		ans = max(ans, max(r[num[x]]-x+1, y-l[num[y]]+1));
	    		printf("%d\n",ans);
			}
		}
	}
    return 0;
} 
