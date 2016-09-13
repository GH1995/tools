// 第6章 查找


// （2）折半查找





// 非递归算法
int BinSearch1(SSTable ST, KeyType key)
{
    int low = 1;
    int high = ST.length;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(key == ST.elem[mid].key)
            return mid;
        else if(key < ST.elem[mid].key)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return 0;
}



















// 递归算法
int BinSearch2(SSTable, int low, int high, KeyType key)
{
    if(low > high)
        return 0;
    else
    {
        mid = (low + high)/2;
        switch
        {
            case ST.elem[mid].key < key:
                return BinSearch2(ST, mid + 1, high, key);
                break;

            case ST.elem[mid].key == key:
                return mid;
                break;

            case ST.elem[mid].key > key:
                return BinSearch2(ST, low, mid - 1, key);
                break;

            default:; 
        }
    }
}