#ifndef QUICK_HH
#define QUICK_HH

#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

template<class T>
void quick_srt(T *Tab, int L, int R)
{
    if(L>=R)
        return;

    int middle=Tab[(L+R)/2];
    int l=L-1, r=R+1; 
 
    while(true)
    {
        while(middle<Tab[--r]){}
        
        while(middle>Tab[++l]){}

        if(l<=r)
        {
            T tmp=Tab[r];
            Tab[r]=Tab[l];
            Tab[l]=tmp;
        }
        else
            break;
    }
    if(L<r)
        quick_srt(Tab, L, r);
    if(R>l)
        quick_srt(Tab, l, R);
        
}

template<class T>
void quick_srt(T *Tab, int L, int R, float Percent)
{
    if(Percent>100)
    {
        cout<<"Parametr 'Percent' nie może być większy od 100"<<endl;
        return;
    }
    else
    {
        R=R*Percent/100;
        if(L>=R)
            return;

        int middle=Tab[(L+R)/2];
        int l=L-1, r=R+1; 
    
        while(true)
        {
            while(middle<Tab[--r]){}
            
            while(middle>Tab[++l]){}

            if(l<=r)
            {
                T tmp=Tab[r];
                Tab[r]=Tab[l];
                Tab[l]=tmp;
            }
            else
                break;
        }
        if(L<r)
            quick_srt(Tab, L, r);
        if(R>l)
            quick_srt(Tab, l, R);
    }   
}

#endif