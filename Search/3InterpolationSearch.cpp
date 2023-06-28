// Tìm kiếm nội suy:
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
