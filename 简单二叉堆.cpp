#include<iostream>
#include<algorithm>
#define maxn 1000
using namespace std;

class Heap
{
    friend ostream &operator<<(ostream &,const Heap &);
    friend istream &operator>>(istream &,Heap &);
public:
    void HeapInit()
    {
        for(int i=size/2; i>0; i--)
            HeapAdjust(i,size);
        return ;
    }
    void HeapAdjust(int i,int size)
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
                HeapAdjust(temp,size);
            }
        }
        return ;
    }
    void HeapSort()
    {
        for(int i=size; 0<i; i--)
        {
            swap(A[i],A[1]);
            HeapAdjust(1,i-1);
        }
    }
    int insertHeap(int e)
    {
        A[++size]=e;
        int i,j;
        for(i=size,j=size/2; A[i]>A[j]&&i>1&&j>0; i=j,j=j/2)
            swap(A[i],A[j]);
        return i? i:1;
    }
    int popHeap()
    {
        A[0]=A[1];
        A[1]=A[size--];
        HeapAdjust(1,size);
        return A[0];
    }
private:
    int  A[maxn];
    int size;
};

ostream &operator<<(ostream &output,const Heap & H)
{
    output<<"The Heap has"<<H.size<<"element(s):\n";
    for(int i=1; i<=H.size; i++)
        output<<H.A[i]<<" ";
    output<<"\n";
    return output;
}

istream &operator>>(istream &input,Heap &H)
{
    cout<<"size?\n";
    input>>H.size;
    cout<<"data?\n";
    for(int i=1; i<=H.size; i++)
        input>>H.A[i];
    return input;
}


int main()
{
    Heap H1;
    cin>>H1;
    H1.HeapInit();
    cout<<H1;
    int k;
    cin>>k;
    H1.insertHeap(k);
    cout<<H1;
    H1.popHeap();
    cout<<H1;
    H1.HeapSort();
    cout<<H1;
    return 0;
}
