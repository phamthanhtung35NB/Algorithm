// Chèn nhị phân (binary insertion sort):

// Là cải tiến một chút của insertion sort, thay vì tìm vị trí để chèn một cách tuần tự,
// ta áp dụng ý tưởng như thuật toán tìm kiếm nhị phân, cứ chia đôi rồi chia đôi.
void binaryInsertionSort (int a[], int n) {
  int left, right, mid, x;
  for (int i = 1; i < n; i++) {
    x = a[i]; left = 0; right = i - 1;
    while (left <= right) {
      mid = (left + right) / 2;
      if (x < a[mid]) right = mid - 1;
      else left = mid + 1;
    }
    for (int j = i - 1; j >= left; j--) a[j + 1] = a[j];
    a[left] = x;
  }
}