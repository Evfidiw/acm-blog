//	link
//	https://ac.nowcoder.com/acm/contest/13504/B

/*	mean： 
	计算：max{ R-L | 1<=L<=R<=n, a[L]==a[R] }, 
	对于所有i (L<=i<=R), 满足 a[i]>=a[L].
	也就是找到两个坐标,这两个坐标的值相等,并且他们之间的值都大于等于这两个坐标上的值.
	问这两个坐标相减最大值是多少
*/ 

/*	think：
	法一：
		其实就是单调栈。如参考代码，求左边较小的数，然后特判相等的情况。 
	法二：
		用RMQ 存区间最小值，然后离散化存某个数上一次出现的位置。
		扫描一遍，如果该数已出现过，就检测两个数的区间内最小值是否为这个数。
		可以用线段树维护区间最值，也可以用ST表。 
	思路三：
		这是我最开始的思路，用双指针维护，
		思路其实同法一，但是双指针维护的 l 和 r 的关系，
		应该维护的是一个单调栈而不是单调队列，故想法错误。
		
*/

for(int i=1; i<=n; i++){
    a[i]=read();
    while(top && a[stk[top]]>a[i]) top--;    //此时存的是单调递增
    if(!top) stk[++top]=i;
    else{
        if(a[stk[top]]==a[i]) ans = max(ans, i-stk[top]);
        else stk[++top]=i;
    }
}
