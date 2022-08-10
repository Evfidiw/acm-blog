## 前言

- 栈和队列在stl中都有得使用，可参考 [栈](https://oi-wiki.org/ds/stack/) [队列](https://oi-wiki.org/ds/queue/)
- 但我们还是要学习手写的方法，以便更进一步学习 单调栈 和 单调队列

## 【栈】

- 栈：先进后出

```c++
int stk[N], tt = 0;// tt表示栈顶

// 向栈顶插入一个数
stk[ ++ tt] = x;

// 从栈顶弹出一个数
tt -- ;

// 栈顶的值
stk[tt];

// 判断栈是否为空
if (tt > 0) {}
```

- 单调栈：O(N)

    - 应用：维护一个持续单调区间

    - 常见[模型](https://www.luogu.com.cn/problem/P5788)：找出每个数左边离它最近的比它小/大（注意下面的大于小于号）的数

        （第 i 个元素之后第一个大于 ai 的元素的下标-->变成右边？-->正序读入）

    - 两个tip：

        - 求左边的正序循环，求右边的倒序循环
        - 存单调递增，比较并出栈后的栈顶就是较小>；存单调递减就较大<（递增还是递减？看题意）

```c++
int top = 0;
while(n--){	//求左边最靠近自己的数而比自己小的数程序实现
    int x=read();
    while(top && stk[top]>=x) top--;	//此时stk[]单调递增
    if(top) printf("%d ",stk[top]);	//如果存在
    else ...	//如果不存在
        stk[++top] = x;
}

for(int i=n; i>=1; i--){ 	///求右边的最靠近的较大数的下标
    while(top && a[stk[top]]<=a[i]) top--;	//此时a[]单调递减.stk[]存的是下标
    if(top) pr[i]=stk[top];
    else pr[i]=0;
    stk[++top] = i; 
}
```

## 【队列】

- 队列：先进先出

```c++
int q[N], hh = 1, tt = 0;// hh 表示队头，tt表示队尾（下标从1开始）

// 向队尾插入一个数
q[ ++ tt] = x;

// 从队头弹出一个数
hh ++ ;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh <= tt) {}
```

- 循环队列

```c++
int q[N], hh = 1, tt = 0;// hh 表示队头，tt表示队尾的后一个位置

// 向队尾插入一个数
q[ ++ tt ] = x;
if (tt == N) tt = 0;

// 从队头弹出一个数
hh ++ ;
if (hh == N) hh = 0;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh != tt) {}
```

- 单调队列：得到**当前的某个范围内**的**最值**
    - 常见[模型](https://www.luogu.com.cn/problem/P1886)：找出滑动窗口中的最大值/最小值

```c++
int hh=1, tt=0;
q[1]=1;	//q[x]=i即储存x的下标为i
for(int i=1; i<=n; i++){
    if(hh<=tt && i-k+1>q[hh]) hh++;
    while(hh<=tt && a[q[tt]]>=a[i]) tt--;	// >=求最小值; 改成<=即为最大值
    q[++tt]=i;
    if(i>=k) printf("%d ",a[q[hh]]); //此时a[i]是以下标i开头的滑动窗口的最值
}
puts("");
```