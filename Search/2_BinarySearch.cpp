// Tìm kiếm nhị phân:
// Điều kiện của thuật toán này là mảng đã được sắp xếp tăng dần.
// So sánh x với giá trị của phần tử nằm ở giữa mảng (mid=(left+right)/2).
// Nếu x nhỏ hơn a[mid] thì nó chỉ có thể nằm ở nửa bên trái, ngược lại x lớn hơn a[mid] thì x nằm ở nửa bên phải.
// Xác định x nằm ở nửa nào thì ta lặp lại thuật toán với nửa đó.
// Như vậy số lần kiểm tra giảm đi nhiều do ko phải mất công kiểm tra những phần tử thuộc nửa còn lại.
int binarySearch (int a[], int n, int x) {
  int left = 0, right = n - 1, mid;
  do {
    mid = (left + right) / 2;
    if (a[mid] == x) return mid;
    else if (a[mid] <= x) left = mid + 1;
    else right = mid - 1;
  } while (left <= right);
  return -1;
}
