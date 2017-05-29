// 第7章 排序

// 直接插入排序
// 1. 从R[i-1]起向前进行顺序查找，监视哨设置在R[0]；
R[0] = R[i];									// 设置哨兵
for (int j = i - 1; R[0].key < R[j].key; j--)	// 从后往前找
	return j + 1;								// 返回R[i]的插入位置为j+1
// 2. 对于在查找过程中找到的那些关键字不小于R[i].key的记录，可以在查找的同时实现向后移动；

// i= 2, 3, ..., n, 实现整个序列的排序。

void InsertionSort(int R[], int n)
{
	for (int i = 2; i <= n; i++)
	{
		R[0] = R[i];
		for (int j = i - 1; R[0].key < R[j].key; --j)
			R[j + 1] = R[j];
		R[j + 1] = R[0];
	}
}


// 交换类排序

void QuickSort(Elem R[], int n)
{
    QSort(R, 1, n);
}

void QSort(Elem R[], int low, int high)
{
    if (low < high)
    {
        pivotloc = Partition(R, low, high);
        QSort(R, low, pivotloc - 1);
        QSort(R, pivotloc + 1, high);
    }
}



int Partition(Elem R[], int low, int high)
{
    pivotkey = R[low].key;
    while(low < high)
    {
        while(low < high && R[high].key >= pivotkey)
            high--;
        R[low]<-->R[high];

        while(low < high && R[high].key <= pivotkey)
            low++;
        R[low]<-->R[high];
    }

    return low;
}









// 选择排序
// 堆排序


void HeapSort(HeapType &h)
{
    for(i = h.length/2; i > 0; i--)
        HeapAdjust(h, i, h.length);
    for(i = h.length; i > 1; i--)
    {
        h.r[1] <-->h.r[i];
        HeapAdjust(h, 1, i - 1);
    }
}





void HeapAdjust(HeapType &h, int s, int m)
{
    rc = h.r[s];
    for(j = 2*s; j <= m; j *= 2)
    {
        if(j < m && h.r[j].key < h.r[j+1].key)
            j++;
        if(!(rc.key < h.r[j].key))
            break;
        h.r[s] = h.r[j];
        s = j;
    }
    h.r[s] = rc;
}

