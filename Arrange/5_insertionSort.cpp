// Sắp xếp chèn (insertion sort):
// Chúng ta coi phần bên trái của biến chạy i là phần đã được sắp xếp theo đúng thứ tự 
// (sẽ chuyển dần các phần tử từ mớ hỗn độn ở phần bên phải sang). 
// Tìm vị trí thích hợp trong nửa trái đó để chèn phần tử a[i] vào cho đúng thứ tự, 
// sau đó dịch chuyển dần các phần tử bên phải kể từ vị trí vừa tìm ra để nong lấy một lỗ trống,
// rồi mới chèn x (mang giá trị của a[i]) vào.
void insertionSort (int a[], int n) {
  int pos, x;
  for (int i = 1; i < n; i++) {
    x = a[i]; pos = i - 1;
    while (pos >= 0 && a[pos] > x) {
      a[pos + 1] = a[pos];
      pos--;
    }
    a[pos + 1] = x;
  }
}
// Độ phức tạp: O(n^2).
// Thuật toán này chỉ thích hợp với mảng đã được sắp xếp một phần,
// còn với mảng ngẫu nhiên thì thuật toán này phế hơn cả sắp xếp nổi bọt do hoán vị quá nhiều.