// Sắp xếp vun đống (heap sort):

// Sở dĩ gọi là vun đống vì mô hình thuật toán có dạng hình như quả núi.
// Để dễ gọi hơn, mình gọi là cây phả hệ, mỗi một nốt là bố, mỗi bố có 2 nốt con (ở đây chọn mô hình phân hoạch nhị phân cho dễ), tương tự với các đời con sau.

// Bước 1: hiệu chỉnh thành dạng vun đống.

// Bước 2: so sánh bố với con. Giả sử bài toán là sắp xếp mảng tăng dần, vậy ta hoán đổi vị trí sao cho thằng lớn hơn lên làm bố.
// Bắt đầu từ thế hệ cháu chắt chút chít trước, sau đó đẩy dần lên thế hệ ông cụ kị,
// đến cuối cùng ta sẽ được thằng to nhất lên chức cụ tổ. Khi cụ tổ đã ở đúng vị trí của nó trên bàn thờ rồi, 
// ta chỉ việc lặp lại thuật toán với đám con cháu còn lại,cũng hiệu chỉnh thành đống rồi so sánh bố con. 
// Chương trình kết thúc khi đám con cháu hoá ra chỉ còn 1 đứa.

//tìm kiếm và hoán đổi trong khoảng l đến r
void shift (int a[], int l, int r) {
  int x, i, j;
  i = l; j = 2 * i + 1; //i trỏ vào bố, j trỏ vào con đầu tiên của bố i
  x = a[i];
  while (j <= r) {
    if( j < r && a[j] < a[j + 1]) j++; //2 đứa con của cùng 1 bố, đứa nào to hơn thì trỏ j về đứa đó
    if (a[j] <= x) return;
    else { //nếu thấy con lớn hơn bố, hoán đổi bố con và tăng biến trỏ i, j xuống thế hệ dưới
      a[i] = a[j];
      a[j] = x;
      i = j; j = 2 * i + 1;
      x = a[i];
    }
  }
}
//hàm hiệu chỉnh mảng a thành dạng heap
void createHeap (int a[], int n) {
  int l = n / 2 - 1;
  while (l >= 0) {
    shift(a, l, n - 1);
    l--;
  }
}
 
void heapSort (int a[], int n) {
  createHeap(a, n);
  int r = n - 1;
  while (r > 0) {
    swap(a, 0, r); //đưa cụ về cuối dãy
    r--;
    if (r > 0) shift(a, 0, r);
  }
}
// Độ phức tạp trung bình: O( n log(n) ).