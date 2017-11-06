#include<iostream>
#include<algorithm>
using namespace std;

void HeapAdjust(int *A,int i,int size)
{
    if(i<=size/2)
    {
        int temp=i;
        int lchild=2*i;
        int rchild=2*i+1;

        if(lchild<=size&&A[lchild]>A[temp])
            temp=lchild;
        if(rchild<=size&&A[rchild]>A[temp])
            temp=rchild;
        if(temp!=i)
        {
            swap(A[temp],A[i]);
            HeapAdjust(A,temp,size);
        }
    }
    return ;
}

void InitHeap(int *A,int size)
{
    for(int i=size/2;i>0;i--)
        HeapAdjust(A,i,size);
    return ;
}

void HeapSort(int *A,int size)
{
    InitHeap(A,size);
    cout<<endl;
    for(int i=size;0<i;i--)
    {
        swap(A[i],A[1]);
        HeapAdjust(A,1,i-1);
    }
}

int main()
{
    int A[100]={};
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    HeapSort(A,n);
    for(int i=1;i<=n;i++)
    cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
