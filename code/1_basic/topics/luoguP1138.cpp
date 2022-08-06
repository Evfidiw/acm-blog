//	link��
//	https://www.luogu.com.cn/problem/P1138

//	����k������ģ��
//	�ڿ���˼���У�ÿ��ѡȡ��׼ֵ����һ��ĵݹ飬ʱ�临�ӶȽӽ�O(n) 

//	model��
int quick_sort(int l, int r){
    int i=l, j=r, base=a[l];//ѡ��˵�Ϊ��׼�� 
    while(i<j){
        while(i<j && a[j]>base) j--;
        if(i<j) swap(a[i],a[j]);
        while(i<j && a[i]<=base) i++;//�������ң��ҵ���һ�����ڻ�׼������ 
        if(i<j) swap(a[i],a[j]);
    }
    a[i]=base;
    if(i==k) return a[k];
	else if(i>k) return quick_sort(l, i-1);
	else return quick_sort(i+1, r);
}
