// Shell sort:
// Là cải tiến của insertion sort, chia nhỏ thành nhiều dãy con có độ dài h,
// sau đó so sánh từng vị trí tương ứng giữa các đoạn con rồi đổi chỗ cho đúng,
// giảm dần độ dài h lại đến khi bằng 1 thì dừng.
void shellSort (int a[], int n, int h[], int k) {
  int i, j, step, x, len;
  for (step = 0; step < k; step++) {
    len = h[step];
    for (i = len; i < n; i++) {
      x = a[i];
      j = i - len;
      while (x < a[j] && j >= 0) {
        a[j + len] = a[j];
        j -= len;
      }
      a[j + len] = x;
    }
  }
}
// Mảng h[] thường chứa một dãy số đặc biệt, ví dụ như dãy (3n+1), hay dãy các số lẻ (2n+1),
// ít ai để dãy h giảm dần từng đơn vị một, nhằm làm giảm số bước k phải thực hiện, tăng tốc độ sắp xếp lên.
// Do đó rất khó xác định độ phức tạp của thuật toán, nó phụ thuộc vào mảng ban đầu và cách chọn các số h.