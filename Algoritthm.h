#ifndef ALGORITTHM_H
#define ALGORITTHM_H

// class Algoritthm
// {
    
// public:
    // 1 Sắp xếp đổi chỗ (interchange sort):
        void interchangeSort (int a[], int n);
        void swap (int a[], int i, int j);
    // 2 Sắp xếp chọn (selection sort):
        void selectionSort (int a[], int n);
    // 3 Sắp xếp nổi bọt (bubble sort):
        void bubbleSort (int a[], int n);
    // 4 Sắp xếp hỗn hợp (cocktail shaker sort):
        void shakerSort (int a[], int n);
    // 5 Sắp xếp chèn (insertion sort):
        void insertionSort (int a[], int n);
    // 6 Chèn nhị phân (binary insertion sort):
        void binaryInsertionSort (int a[], int n);
    // 7 Shell sort: (Là cải tiến của insertion sort)
        void shellSort (int a[], int n, int h[], int k);
    // 8 Sắp xếp nhanh (quick sort):
        void quickSort (int a[], int left, int right);
    // 9 Sắp xếp trộn (merge sort):
        void merge (int a[], int left, int mid, int right);
        //phân hoạch
        void mergeSort (int a[], int left, int right);
    // 10 Sắp xếp vun đống (heap sort):
        void heapSort (int a[], int n);
        void shift (int a[], int l, int r);
        void createHeap (int a[], int n);

    // 1 Tìm kiếm tuyến tính:
        int linearSearch (int a[], int k, int n);
    // 2 Tìm kiếm nhị phân:
        int binarySearch (int a[], int k, int n);
    // 3 Tìm kiếm nội suy:
        int interpolationSearch (int a[], int k, int n);
    // 4 Thuật Toán Tìm Kiếm Nhảy:
        int JumpSearch(int a[], int k, int n);
    // 5 Thuật Toán Tìm Kiếm Nhị Phân (Binary Search):
        int binSearch(int a[], int k, int n);

//     Algoritthm();
//     ~Algoritthm();
// };

#endif