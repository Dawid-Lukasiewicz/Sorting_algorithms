#ifndef HEAP_SRT
#define HEAP_SRT

#include<iostream>

using namespace std;

template<class T>
void heap_largest(T *tab, int size, int root)
{
    int largest=root;
    int child_left=2*root+1;
    int child_right=2*root+2;

    if (child_left<size && tab[child_left]>tab[largest])
    {
        largest=child_left;
    }

    if (child_right<size && tab[child_right]>tab[largest])
    {
        largest=child_right;
    }

    if (largest!=root)
    {
        T tmp=tab[largest];
        tab[largest]=tab[root];
        tab[root]=tmp;
        heap_largest(tab,size,largest);
    }
}

template<class T>
void heap_srt(T *tab, int original_size, float percent)
{
    if(percent>100)
        return;
    else
    {
        int size=original_size*percent/100;
        
        for (int i=size/2-1; i>=0; i--)
        {
            heap_largest(tab, size-1, i);
        }
        
        for (int i=size-1; i>0; i--)
        {
            T tmp=tab[0];
            tab[0]=tab[i];
            tab[i]=tmp;
            heap_largest(tab, i, 0);
        }
    }
}

#endif