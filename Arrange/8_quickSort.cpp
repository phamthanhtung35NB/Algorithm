// Sắp xếp nhanh (quick sort):

// Chọn phần tử x ở giữa mảng. Tìm ở bên trái của x phần tử nào lớn hơn x, ở bên phải có phần tử nào nhỏ hơn x,
// rồi đổi chỗ 2 phần tử đó.Quét hết lượt thì lặp lại thuật toán với từng nửa. Đến khi nào độ dài các đoạn để quét là 1 thì dừng.
void quickSort (int a[], int left, int right) {
  int i, j, x;
  x = a[(left + right) / 2];
  i = left; j = right;
  do {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) { swap(a, i, j); i++; j--; }
  } while (i <= j);
  if (left < j) quickSort(a, left, j);
  if(i < right) quickSort(a, i, right);
}
// Độ phức tạp trung bình: O( n log(n) ).