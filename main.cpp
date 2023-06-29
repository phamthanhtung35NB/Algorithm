#include <iostream>
#include "Algoritthm.h"
int main(){
    int arr[20]={1,1321,231,3,5,12,345,32,78,121,132,32,23,78,34,56,78,90,322,13};
    for (int i = 0; i < 20; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    binaryInsertionSort(arr,20);
    for (int i = 0; i < 20; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n"<<linearSearch(arr,56,20);
    
    
}