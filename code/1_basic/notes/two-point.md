## 双指针

- 又名“尺取法”，“2 point”

- 原理：对一段连续的区间有特定要求的时候，不满足要求时优化遍历，将朴素的O(n^2)优化到接近O(n)

- 快慢指针：先固定一个指针，然后另一个指针去连续的判断一段区间，并且**返回第一个指针而不是从头开始**
    
- 模板参考：

    ``````c++
    for(int l=1,r=1; r<=n; r++){
        while(l<r && check(l,r)) l++, ...;
    }
    // 循环后得回到1的位置开始删掉数字？双指针就可以就直接从l的下一位开始删除了
    
    // eg:一串数字中,求 最长连续不重复子序列
    for(int l=1,r=1; r<=n; r++){
    	cnt[a[r]]++;
        while(l<r && cnt[a[r]]>1) cnt[a[l++]]-- ;
        res = max(res, r-l+1);
    }
    ``````

- eg:

    [eg1](http://poj.org/problem?id=3320)  [eg2](https://github.com/Evfidiw/acm-blog/blob/main/code/1_basic/topics/poj3061.cpp)