//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

extern int weightArr[];

struct MinHeap {
    int data[512];
    int size;
    MinHeap(){ size=0; }
    int top(){ return data[0]; }
    void push(int x){ data[size]=x; upheap(size++); }
    void pop(){ data[0]=data[--size]; downheap(0); }
    void upheap(int i){
        while(i>0){
            int p=(i-1)/2;
            if(weightArr[data[i]]<weightArr[data[p]]){
                int t=data[i]; data[i]=data[p]; data[p]=t; i=p;
            } else break;
        }
    }
    void downheap(int i){
        while(true){
            int l=2*i+1,r=2*i+2,s=i;
            if(l<size && weightArr[data[l]]<weightArr[data[s]]) s=l;
            if(r<size && weightArr[data[r]]<weightArr[data[s]]) s=r;
            if(s!=i){ int t=data[i]; data[i]=data[s]; data[s]=t; i=s; }
            else break;
        }
    }
};

#endif
