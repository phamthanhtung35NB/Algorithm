// Tìm kiếm nội suy:
// Là cải tiến của thuật toán tìm kiếm nhị phân. Thay vì chia đôi, thuật toán này chia theo phép tính 
// \mathrm{mid} = \mathrm{left} + \dfrac{\mathrm{right}-\mathrm{left}} {a[\mathrm{right}]-a[\mathrm{left}]} (x-a[\mathrm{left}])

// https://maitroisang.wordpress.com/2017/10/18/cac-thuat-toan-sap-xep-va-tim-kiem/

// giúp thu gọn khoảng tìm kiếm hơn. Chỉ cần thay biểu thức tính mid này vào code mẫu của thuật toán tìm kiếm nhị phân là được.
int interpolationSearch (int a[], int n, int x) {
  int left = 0, right = n - 1, mid;
  do {
    mid = left + (right - left) / (a[right] - a[left]) * (x - a[left]);
    if (a[mid] == x) return mid;
    else if (a[mid] <= x) left = mid + 1;
    else right = mid - 1;
  } while (left <= right);
  return -1;
}
