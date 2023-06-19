#include <iostream>
#include <vector>
using namespace std;


#if 0
// one form 
void maxHeapify(vector<int> &v, int i, int size)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int largest = i;
    if (l < size && v[l] > v[i])
    largest = l;
    if (r < size && v[r] > v[largest])
    largest = r;
    if (largest != i)
    {
        swap(v[i], v[largest]);
        maxHeapify(v, largest, size);
    }
}
#endif

void maxHeapify(vector<int> &v, int i, int size)
{
    while (1)
    {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int largest = i;
        if (l < size && v[l] > v[i])
        largest = l;
        if (r < size && v[r] > v[largest])
        largest = r;
        if (largest == i) break;
        swap(v[i], v[largest]);
        i = largest;
    }
}

/* sink the biggest among (p, l, r), down to the tail*/
void minHeapify(int v[], int i, int size)
{
    while (1)
    {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int smallest = i;
        if (l < size && v[l] < v[i])
        smallest = l;
        if (r < size && v[r] < v[smallest])
        smallest = r;
        if (smallest == i) break;
        swap(v[i], v[smallest]);
        i = smallest;
    }
}

// from first half
void buildMaxHeap(vector<int> &v)
{
    for(int i = v.size() / 2 ; i >= 0; --i)
        maxHeapify(v, i, v.size());
}

// from first half
void buildMinHeap(int v[], int size)
{
    for(int i = size / 2 ; i >= 0; --i)
        minHeapify(v, i, size);
}

void heapSort(vector<int> &v)
{
    buildMaxHeap(v);
    int i = v.size();
    while (--i > 0)
    {
        // 把最大值放到最后，把最小值插入堆中，堆的size减一
        swap(v[i], v[0]);
        maxHeapify(v, 0, i);
    }
}

void maxheapIncreaseKey(vector<int> &v, int i, int key)
{
    if( key < v[i])
    return ;
    v[i] = key;
    while (i > 0 && v[(i-1) / 2] < v[i])
    {
        int tmp = v[i];
        v[i] = v[(i - 1) / 2] ;
        v[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}

/* Raise the smaller to the root*/
void minheapIncreaseKey(int v[], int i, int key)
{
    if( key > v[i])
    return ;
    v[i] = key;
    while (i > 0 && v[(i-1) / 2] > v[i])
    {
        int tmp = v[i];
        v[i] = v[(i - 1) / 2] ;
        v[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}

int minHeapExtractMin(int v[], int &size)
{
    int min = v[0];
    v[0] = v[--size];
    minHeapify(v, 0, size);
    return min;
}

void maxHeapInsert(vector<int> &v, int key)
{
    int i = 0x80000000;
    v.push_back(i);
    maxheapIncreaseKey(v, v.size() - 1, key);
}

void minHeapInsert(int v[], int &size,int key)
{
    v[size] = 0x7FFFFFFF;
    minheapIncreaseKey(v, size, key);
    ++size;
}

void dump(vector<int> &v)
{
    for (auto &i : v)
    cout << i << ' ';
    cout << endl;

}
void dump(int v[], int size)
{
    for (int i = 0;i < size; ++i)
    cout << v[i] << ' ';
    cout << endl;
}

void test1()
{
    vector<int> v{16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    dump(v);

    maxHeapify(v, 1, v.size());
    dump(v);

}

void test2()
{
    vector<int> v{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    dump(v);
    buildMaxHeap(v);
    dump(v);

    maxHeapInsert(v, 5);
    maxHeapInsert(v, 12);
    maxHeapInsert(v, 20);
    maxHeapInsert(v, 0);
    dump(v);


}

void test3()
{
    vector<int> v{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    for (auto &i : v)
    cout << i << ' ';
    cout << endl;

    heapSort(v);
    for (auto &i : v)
    cout << i << ' ';
    cout << endl;
}

void test4(){
    
#define minHeapSize 100
int v[minHeapSize] = {0};
int size = 0;
for (auto a: {4, 1, 3, 2, 16, 9, 10, 14, 8, 7})
{
    v[size++] =a;
}
dump(v, size);
    
    buildMinHeap(v, size);
    dump(v, size);

    minHeapInsert(v, size,5);
    minHeapInsert(v,  size,12);
    minHeapInsert(v, size, 20);
    minHeapInsert(v, size, 0);
    dump(v ,size);
    while(size > 0)   printf("%d\n", minHeapExtractMin(v,size));


}
int main()
{
    test1();
    cout<< "-------------" <<endl;
    test2();
    cout<< "-------------" <<endl;
    test4();

    return 0;
}
