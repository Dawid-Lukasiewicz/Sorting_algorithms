#ifndef MERGE_HH
#define MERGE_HH

#include<iostream>
#include<cstdlib>


using namespace std;

template<class T>
void merge(T *tab, int l, int r, int m)
{
        int size_L=m-l+1, size_R=r-m;
        T *tab_L=new T[size_L];
        T *tab_R=new T[size_R];
        
        for (int i=0; i<size_L; i++)
            tab_L[i]=tab[l+i];
        for (int i=0; i<size_R; i++)
            tab_R[i]=tab[m+1+i];

        int indx_curr=l;
        int indx_L=0, indx_R=0;
        for (indx_curr; indx_L<size_L && indx_R<size_R; indx_curr++)
        {
            if(tab_L[indx_L]>=tab_R[indx_R])
                tab[indx_curr]=tab_R[indx_R++];
            else
                tab[indx_curr]=tab_L[indx_L++];
        }
        while (indx_L<size_L)
            tab[indx_curr++]=tab_L[indx_L++];
        
        while (indx_R<size_R)
            tab[indx_curr++]=tab_R[indx_R++];

        delete[] tab_L;
        delete[] tab_R;
}

template<class T>
void merge_sort(T *tab, int l, int r)
{
    if(l<r)
    {    
        int m=(l+r)/2;
        merge_sort(tab, l, m);
        merge_sort(tab, m+1, r);
        merge(tab, l, r, m);
    }
}

template<class T>
void merge_sort(T *tab, int l, int r, float Percent)
{
    if(Percent>100)
    {
        cout<<"Parametr 'Percent' nie może być większy od 100"<<endl;
        return;
    }
    else
    {
        r=r*Percent/100-1;
        if(l<r)
        {
            
            int m=(l+r)/2;
            merge_sort(tab, l, m);
            merge_sort(tab, m+1, r);
            merge(tab, l, r, m);
        }
    }
}

#endif