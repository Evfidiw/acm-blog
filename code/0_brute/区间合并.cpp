//	����: �����д��ڽ���������ϲ�

 
//	sort����a[i].l���� 
void solve()
{
	vector<pii> res;
	int l=a[1].l, r=a[1].l;
	for(int i=1; i<=n; i++){
	    if(r < a[i].l){
	    	res.push_back({l,r});
	        l=a[i].l; r=a[i].r;
	    }
	    else r = max(r, a[i].r);
	}
	res.push_back({l,r});
}

for(vector<int>::iterator it=a.begin();it!=a.end();it++) 
	printf("%d %d\n",*it.l,*it.r);
