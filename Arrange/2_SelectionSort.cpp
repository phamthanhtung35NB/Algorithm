// Sắp xếp chọn (selection sort):
// Tìm phần tử nhỏ nhất trước, rồi mới đổi chỗ nó cho phần tử đầu tiên, xong lặp lại với phần còn lại.
void selectionSort (int a[], int n) {
  int min;
  int iMin;
  for (i = 0; i < n - 1; i++) {
    min = a[i];
    iMin = i;
    for (j = i + 1; j < n; j++)
      if (a[j] < a[iMin]) { min = a[j]; iMin = j; }
    swap(a, iMin, i);
  }
}
// Độ phức tạp: O(n^2).
// Số phép so sánh tương đương với sắp xếp đổi chỗ, nhưng số lần hoán vị được giảm đi nhiều.