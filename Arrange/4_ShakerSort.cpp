// Sắp xếp hỗn hợp (cocktail shaker sort):

// Lấy hình ảnh xóc bình cocktail, biến j có thể chạy 2 chiều, chiều xuôi thì đưa phần tử lớn nhất về cuối dãy,
// sau đó đảo lại để đưa phần tử bé nhất về đầu dãy.
void shakerSort (int a[], int n) {
  int left = 0, right = n - 1, k = left;
  while (left < right) {
    for (int i = left; i < right; i++)
      if (a[i] > a[i + 1]) { swap(a, i, i + 1); k = i; }
    right = k;
    for (int i = right; i > left; i--)
      if (a[i - 1] > a[i]) { swap(a, i - 1, i); k = i; }
    left = k;
  }
}
// Độ phức tạp: O(n^2).

// Đây là thuật toán cải tiến của sắp xếp nổi bọt nên nó cũng nhận diện được mảng đã sắp xếp.
// Thuật toán này có lợi thế hơn nổi bọt khi mảng có dải các phần tử đã được sắp xếp.