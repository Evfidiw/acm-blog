//	review link:
//	https://www.luogu.com.cn/problem/P5093

/*	topic meaning��
	��������n������ÿ����Ϊ1~k.
	������ֻҪ��ǰ��˳����ڼ��ɡ�
	���ҳ�һ����̵������У�ʹ֮��������������֣�������̳��ȡ�
*/	
/*	think:
	ģ�⣬��һ�������е���������ﵽkʱ��len++��
	Ȼ�����+1��������Ĵ𰸣����ټ�һ���������ǲ����ڵ����С� 
*/ 

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
char getc(){
    static char buf[1<<14],*p1=buf,*p2=buf;
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
int read(){
   int s=0,w=1;  
   char ch=getchar();  
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}  
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();  
   return s*w;
}
const int N=100005;

int a[N], v[N];

int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
//	printf("%.3lf M\n",(double)sizeof(/*szm*/)/(1<<20));
//	clock_t start_time=clock();
	int n=read(), k=read(), cnt=0, len=1;
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=n; i++){
		if(v[a[i]]==0) v[a[i]] = ++cnt;
		if(cnt==k){
			cnt = 0;
			len++;
			memset(v,0,sizeof v);
		}
	}
	printf("%d\n",len);
	
	
//	clock_t end_time=clock();
//cout<<"Running time is:"<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
//	fclose(stdin);fclose(stdout);
	return 0;
}
