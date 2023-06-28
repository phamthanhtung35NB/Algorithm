// Sắp xếp trộn (merge sort):

// Chia đôi dãy thành 2 dãy con bằng hàm mergeSort(). Giả sử rằng mỗi dãy con đã được sắp xếp theo thứ tự, 
// thì giờ chỉ cần trộn hai dãy con với nhau thành một dãy duy nhất bằng hàm merge(). 
// Nếu dãy con chưa được sắp xếp thì lại áp dụng hàm mergeSort() lên dãy con đó, 
// cứ chia đôi như vậy cho đến khi ko cần phải chia nữa.
//trộn 2 dãy con lại với nhau
void merge (int a[], int left, int mid, int right) {
  int tmp[right - left + 1];
  int i = left, j = mid + 1, pos = 0;
  while (i <= mid || j <= right) {
    if ((i <= mid && j <= right && a[i] < a[j]) || j > right)
      tmp[pos++] = a[i++];
    else
      tmp[pos++] = a[j++];
  }
  for (i = 0; i < right - left + 1; i++) a[left + i] = tmp[i];
}
//phân hoạch
void mergeSort (int a[], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
  }
}
// Thuật toán này có nhược điểm lớn là vừa tốn bộ nhớ do đệ quy, vừa tốn bộ nhớ do khởi tạo thêm mảng tạm thời làm mảng trộn.