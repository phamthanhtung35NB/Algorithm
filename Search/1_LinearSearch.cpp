// Tìm kiếm tuyến tính:
// Là kiểm tra tuần tự từng phần tử của mảng, đến khi nào giống thì thôi.
int linearSearch (int a[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (a[i] == x) return i; //trả về vị trí tìm thấy
    else return -1; //trả về -1 nếu ko tìm thấy
  }
}
