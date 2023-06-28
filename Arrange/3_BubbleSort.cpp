// Sắp xếp nổi bọt (bubble sort):
// Lần lượt đổi chỗ các cặp đôi phần tử cạnh nhau nếu chúng ngược thứ tự,
// mục đích cũng là sau một lượt, phần tử bé nhất sẽ về đầu dãy.
void bubbleSort (int a[], int n) {
  for (i = 0; i < n - 1; i++)
    for (j = n - 1; j > i; j--)
      if (a[j] < a[j - 1]) swap(a, j, j - 1);
}
// Độ phức tạp: O(n^2).
// Số phép so sánh và hoán vị tương đương sắp xếp đổi chỗ.
// Thuật toán này có lợi thế là phát hiện được mảng đã được sắp xếp hay chưa
// bằng cách kiểm tra xem có phải swap lần nào ko.