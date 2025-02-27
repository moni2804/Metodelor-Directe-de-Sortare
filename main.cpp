/*
    pe cazul average :
        -cele mai buna metode de sortare sunt select sort si insertion sort
        -selection sort are cele mai putine atribuiri
        -insertion sort are cele mai putine comparari
    pe cazul best:
        -cele mai buna metode de sortare sunt bubble sort si insertion sort
        -selection sort si bubble sort au cele mai putine atribuiri (0)
        -bubble sort si insertion sort au cele mai putine comparari
    pe cazul worst:
        -cea mai buna metoda de sortare este selection sort
        -selection sort are cele mai putine atribuiri (0)
        -selection sort si insertion sort au cele mai putine comparari

*/
#include <iostream>
#include "../lab4/Profiler.h"
using namespace std;

Profiler profiler;

void selectionSort(int a[],int n){
    Operation comp_sel=profiler.createOperation("selectionSort_comp",n);
    Operation atr_sel=profiler.createOperation("selectionSort_atr",n);
    for(int i=0;i<n-1;i++){
        int aux=i;
        for(int j=i+1;j<n;j++){
            comp_sel.count();
            if(a[aux]>a[j]){
                aux=j;
            }
        }
        if(aux!=i){
            swap(a[i],a[aux]);
            atr_sel.count(3);
        }
    }
}

void bubbleSort(int a[],int n){
    int ok=1;
    Operation comp_b=profiler.createOperation("bubbleSort_comp",n);
    Operation atr_b=profiler.createOperation("bubbleSort_atr",n);
    do{
        ok=1;
        for(int i=0;i<n-1;i++) {
            comp_b.count();
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                ok = 0;
                atr_b.count(3);
            }
        }
    }   while(ok==0);
}

void insertionSort(int a[],int n){
    Operation comp_i=profiler.createOperation("insertionSort_comp",n);
    Operation atr_i=profiler.createOperation("insertionSort_atr",n);
    for(int i=1;i<n;i++){
        int j=i-1;
        int aux=a[i];
        atr_i.count();
        while(a[j]>aux && j>=0){
            comp_i.count();
            a[j+1]=a[j];
            j--;
            atr_i.count();
        }
        atr_i.count();
        a[j+1]=aux;
        if(j>0){comp_i.count();}
    }
}
void duplicateA(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}
void test(){
    int b[]={9,7,8,5,4,6};

    insertionSort(b,6);

    for(int i=0;i<6;i++)
        cout<<b[i]<<" ";
}

void perf(int order){
    int a[10000],b[10000];
    int n;
    for(int i=0;i<5;i++) {
        for (int i = 100; i < 10000; i += 100) {
            FillRandomArray(a, i, -5000, 5000, false, order);
            duplicateA(a,b,i);
            selectionSort(b, i);

            duplicateA(a,b,i);
            bubbleSort(b,i);

            duplicateA(a,b,i);
            insertionSort(b,i);
        }
    }

    profiler.divideValues("selectionSort_comp",5);
    profiler.divideValues("selectionSort_atr",5);
    profiler.addSeries("selectionSortTotal","selectionSort_comp","selectionSort_atr");

    profiler.divideValues("bubbleSort_comp",5);
    profiler.divideValues("bubbleSort_atr",5);
    profiler.addSeries("bubbleSortTotal","bubbleSort_comp","bubbleSort_atr");

    profiler.divideValues("insertionSort_comp",5);
    profiler.divideValues("insertionSort_atr",5);
    profiler.addSeries("insertionSortTotal","insertionSort_comp","insertionSort_atr");

    profiler.createGroup("Total","selectionSortTotal","bubbleSortTotal","insertionSortTotal");
    profiler.createGroup("Atr","selectionSort_atr","bubbleSort_atr","insertionSort_atr");
    profiler.createGroup("Comp","selectionSort_comp","bubbleSort_comp","insertionSort_comp");


}
void worst(){
    int a[10000],b[10000];
    int n;
    for(int i=0;i<5;i++) {
        for (int i = 100; i < 10000; i += 100) {
            FillRandomArray(a, i, -5000, 5000, false, ASCENDING);
            swap(a[0],a[i-1]);
            duplicateA(a,b,i);
            selectionSort(b, i);

            FillRandomArray(a, i, -5000, 5000, false, DESCENDING);
            duplicateA(a,b,i);
            bubbleSort(b,i);

            duplicateA(a,b,i);
            insertionSort(b,i);
        }
    }

    profiler.divideValues("selectionSort_comp",5);
    profiler.divideValues("selectionSort_atr",5);
    profiler.addSeries("selectionSortTotal","selectionSort_comp","selectionSort_atr");

    profiler.divideValues("bubbleSort_comp",5);
    profiler.divideValues("bubbleSort_atr",5);
    profiler.addSeries("bubbleSortTotal","bubbleSort_comp","bubbleSort_atr");

    profiler.divideValues("insertionSort_comp",5);
    profiler.divideValues("insertionSort_atr",5);
    profiler.addSeries("insertionSortTotal","insertionSort_comp","insertionSort_atr");

    profiler.createGroup("Total","selectionSortTotal","bubbleSortTotal","insertionSortTotal");
    profiler.createGroup("Atr","selectionSort_atr","bubbleSort_atr","insertionSort_atr");
    profiler.createGroup("Comp","selectionSort_comp","bubbleSort_comp","insertionSort_comp");


}
void perf_all(){
    perf(UNSORTED);
    profiler.reset("best");
    perf(ASCENDING);
    profiler.reset("worst");
    worst();
    profiler.showReport();

}
int main() {

    //test;
    perf_all();
    return 0;
}
