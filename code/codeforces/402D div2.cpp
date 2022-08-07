//	link:
//	https://codeforces.com/contest/779/problem/D

/*	mean:
	����t����p��,��t�а�����˳��ȥ���ַ�,
	�����ȥ�����ٸ�,ʹ��p����Ϊt��������
*/

/*	think��
	����ȥ��x��ʱp��t�������У���ȥ��1~x��ʱpҲ��t��������
	����ʵ����һ�֡���������������ö��ִ�
	Ȼ����Ǳ���д��check������
*/ 

//	link
//	

#include <iostream>
#include <cstring>
using namespace std; 

#define ll long long
const int N = 2e5+5;

string p, t;
int n;
int a[N];
bool vis[N];

bool check(int x)
{
	memset(vis, 0, sizeof vis);
	for(int i=0; i<x; i++) vis[a[i]-1]=1;
	
	int cntt=0, cntp=0; 
	while(cntp<p.length() && cntt<t.length()){
		if(vis[cntt]==0 && p[cntp]==t[cntt]) cntp++;
		cntt++;
		
	}
	if(cntp >= p.length()) return true;
	return false;
}

int bsearch_2(int l, int r){
    while(l < r){
        int mid = l+r+1 >> 1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    return l;
}

int main()
{
	cin >> t >> p;
	n = t.length();
	for(int i=0; i<n; i++) cin >> a[i];
	cout << bsearch_2(0,n-1);
	
	return 0;
}
