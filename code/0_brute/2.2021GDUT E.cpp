//	link:
//	https://ac.nowcoder.com/acm/contest/13504/E

/*	mean:
	n���������飬q��ѯ�ʱ��Ϊ����[l��r]�������У�x�ı����м���
*/
/*	think:
	��vectorԤ���������i���ֵ�λ�ã�
	��_bound ���Եõ�λ��l,r�ǵڼ������� 
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int l, r, x;
int a, ans;
vector<int> vt[1000005];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        vt[a].push_back(i);
    }
    while(m--)
    {
        scanf("%d%d%d", &l, &r, &x);
        ans = 0;
        for(int i = x; i <= 100000; i += x) 
			ans += upper_bound(vt[i].begin(), vt[i].end(), r) - lower_bound(vt[i].begin(), vt[i].end(), l);
        printf("%d\n", ans);
    }
    return 0;
}
