//Thuật Toán Tìm Kiếm Nhị Phân (Binary Search)
int binSearch(int a[], int k, int n){
    int left=0; 
    int right = n-1;
    while (left <= right){
        int mid = (left+right)/2; // Lay phan nguyen
        if (a[mid]==k)
            return mid;
        else if (a[mid]<k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}