#include "Algoritthm.h"

// 1
//Sắp xếp đổi chỗ (interchange sort):
// Xuất phát từ đầu dãy, lần lượt so sánh phần tử đầu dãy với các phần tử còn lại, 
// nếu thấy lớn hơn thì đổi chỗ cho nhau, mục đích là để sau khi quét một lượt, phần tử bé nhất sẽ về đầu dãy.
void interchangeSort (int a[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a, i, j);
            }
        }
    }
}
void swap (int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
//Độ phức tạp: O(n^2).


// 2
// Sắp xếp chọn (selection sort):
// Tìm phần tử nhỏ nhất trước, rồi mới đổi chỗ nó cho phần tử đầu tiên, xong lặp lại với phần còn lại.
void selectionSort (int a[], int n) {
    int min;
    int iMin;
    for (int i = 0; i < n - 1; i++) {
        min = a[i];
        iMin = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[iMin]) 
            {
                min = a[j];
                iMin = j;
            }
        }
        swap(a, iMin, i);
    }
}
// Độ phức tạp: O(n^2).
// Số phép so sánh tương đương với sắp xếp đổi chỗ, nhưng số lần hoán vị được giảm đi nhiều.


// 3
// Sắp xếp nổi bọt (bubble sort):
// Lần lượt đổi chỗ các cặp đôi phần tử cạnh nhau nếu chúng ngược thứ tự,
// mục đích cũng là sau một lượt, phần tử bé nhất sẽ về đầu dãy.
void bubbleSort (int a[], int n) {
    for (int i = 0; i < n - 1; i++){
        for (int j = n - 1; j > i; j--){
            if (a[j] < a[j - 1])
            {
                swap(a, j, j - 1);
            }
        }
    }
}
// Độ phức tạp: O(n^2).
// Số phép so sánh và hoán vị tương đương sắp xếp đổi chỗ.
// Thuật toán này có lợi thế là phát hiện được mảng đã được sắp xếp hay chưa
// bằng cách kiểm tra xem có phải swap lần nào ko.


// 4
// Sắp xếp hỗn hợp (cocktail shaker sort):
// Lấy hình ảnh xóc bình cocktail, biến j có thể chạy 2 chiều, chiều xuôi thì đưa phần tử lớn nhất về cuối dãy,
// sau đó đảo lại để đưa phần tử bé nhất về đầu dãy.
void   shakerSort (int a[], int n) {
    int left = 0;
    int right = n - 1;
    int k = left;
    while (left < right) {
        for (int i = left; i < right; i++)
        {
            if (a[i] > a[i + 1]) 
            {
                swap(a, i, i + 1);
                k = i;
            }
        }
        right = k;
        for (int i = right; i > left; i--)
        {
            if (a[i - 1] > a[i])
            {
                swap(a, i - 1, i);
                k = i;
            }
        }
        left = k;
    }
}
// Độ phức tạp: O(n^2).
// Đây là thuật toán cải tiến của sắp xếp nổi bọt nên nó cũng nhận diện được mảng đã sắp xếp.
// Thuật toán này có lợi thế hơn nổi bọt khi mảng có dải các phần tử đã được sắp xếp.


// 5
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


// 6
// Chèn nhị phân (binary insertion sort):
// Là cải tiến một chút của insertion sort, thay vì tìm vị trí để chèn một cách tuần tự,
// ta áp dụng ý tưởng như thuật toán tìm kiếm nhị phân, cứ chia đôi rồi chia đôi.
void binaryInsertionSort (int a[], int n) {
    int left, right, mid, x;
    for (int i = 1; i < n; i++) {
        x = a[i]; left = 0; right = i - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (x < a[mid]) right = mid - 1;
            else left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--)
        {
            a[j + 1] = a[j];
        }
        a[left] = x;
    }
}


// 7
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


// 8
// Sắp xếp nhanh (quick sort):
// Chọn phần tử x ở giữa mảng. Tìm ở bên trái của x phần tử nào lớn hơn x, ở bên phải có phần tử nào nhỏ hơn x,
// rồi đổi chỗ 2 phần tử đó.Quét hết lượt thì lặp lại thuật toán với từng nửa. Đến khi nào độ dài các đoạn để quét là 1 thì dừng.
void   quickSort (int a[], int left, int right) {
    int i, j, x;
    x = a[(left + right) / 2];
    i = left; j = right;
    do
    {
        while (a[i] < x)
        {
            i++;
        }
        while (a[j] > x)
        {
            j--;
        }
        if (i <= j) 
        {
            swap(a, i, j);
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
    {
        quickSort(a, left, j);
    }
    if(i < right)
    {
        quickSort(a, i, right);
    }
}
// Độ phức tạp trung bình: O( n log(n) ).


// 9
// Sắp xếp trộn (merge sort):
// Chia đôi dãy thành 2 dãy con bằng hàm mergeSort(). Giả sử rằng mỗi dãy con đã được sắp xếp theo thứ tự, 
// thì giờ chỉ cần trộn hai dãy con với nhau thành một dãy duy nhất bằng hàm merge(). 
// Nếu dãy con chưa được sắp xếp thì lại áp dụng hàm mergeSort() lên dãy con đó, 
// cứ chia đôi như vậy cho đến khi ko cần phải chia nữa.
//trộn 2 dãy con lại với nhau
void merge (int a[], int left, int mid, int right) {
    int tmp[right - left + 1];
    int i = left, j = mid + 1, pos = 0;
    while (i <= mid || j <= right)
    {
        if ((i <= mid && j <= right && a[i] < a[j]) || j > right)
        {
            tmp[pos++] = a[i++];
        }
        else
        {
            tmp[pos++] = a[j++];
        }
    }
    for (i = 0; i < right - left + 1; i++)
    {
        a[left + i] = tmp[i];
    }
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


// 10
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
    while (j <= r)
    {
        if( j < r && a[j] < a[j + 1])
        {
            j++; //2 đứa con của cùng 1 bố, đứa nào to hơn thì trỏ j về đứa đó
        }
        if (a[j] <= x)
        {
            return;
        }
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
        if (r > 0)
        {
            shift(a, 0, r);
        }
    }
}
// Độ phức tạp trung bình: O( n log(n) ).




// -----------------------------------------------------------------------------------------------------





// 1
// Tìm kiếm tuyến tính:
// Là kiểm tra tuần tự từng phần tử của mảng, đến khi nào giống thì thôi.
int linearSearch (int a[], int k, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == k)
        {
            return i; //trả về vị trí tìm thấy
        }
    }
    return -1; //trả về -1 nếu ko tìm thấy
}


// 2
// Tìm kiếm nhị phân:
// Điều kiện của thuật toán này là mảng đã được sắp xếp tăng dần.
// So sánh x với giá trị của phần tử nằm ở giữa mảng (mid=(left+right)/2).
// Nếu x nhỏ hơn a[mid] thì nó chỉ có thể nằm ở nửa bên trái, ngược lại x lớn hơn a[mid] thì x nằm ở nửa bên phải.
// Xác định x nằm ở nửa nào thì ta lặp lại thuật toán với nửa đó.
// Như vậy số lần kiểm tra giảm đi nhiều do ko phải mất công kiểm tra những phần tử thuộc nửa còn lại.
int binarySearch (int a[], int n, int x) {
    int left = 0, right = n - 1, mid;
    do {
        mid = (left + right) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] <= x)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    } while (left <= right);
    return -1;
}


// 3
// Tìm kiếm nội suy:
// Là cải tiến của thuật toán tìm kiếm nhị phân. Thay vì chia đôi, thuật toán này chia theo phép tính 
// \mathrm{mid} = \mathrm{left} + \dfrac{\mathrm{right}-\mathrm{left}} {a[\mathrm{right}]-a[\mathrm{left}]} (x-a[\mathrm{left}])

// https://maitroisang.wordpress.com/2017/10/18/cac-thuat-toan-sap-xep-va-tim-kiem/

// giúp thu gọn khoảng tìm kiếm hơn. Chỉ cần thay biểu thức tính mid này vào code mẫu của thuật toán tìm kiếm nhị phân là được.
int interpolationSearch (int a[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int mid;
    do {
        mid = left + (right - left) / (a[right] - a[left]) * (x - a[left]);
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] <= x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    } while (left <= right);
    return -1;
}


// 4
// Thuật Toán Tìm Kiếm Nhảy:
int   JumpSearch(int a[], int k, int n)
{
	int d = 3; //bước nhảy
	int i = 0;
	int j = i + d;
	while (j < n && a[j] < k) // khi tăng j mà j vẫn còn nằm trong mảng và tại a[i] vẫn chưa bằng số k thì tiếp tục tăng i và j
	{
		j = j + d;
		i = i + d;
	}
	if (j >= n);// khi mà j vượt khỏi mảng thì ta đặt j=n;
	{
		j = n-1 ;
	}
	while (a[i] < k)
	{
		i = i + 1;
		if (i >= n || i > j)
			return -1;
	}
	if (a[i] == k)
		return i;
	else
    return -1;
}


// 5
//Thuật Toán Tìm Kiếm Nhị Phân (Binary Search):
int   binSearch(int a[], int k, int n){
    int left=0; 
    int right = n-1;
    while (left <= right){
        int mid = (left+right)/2; // Lay phan nguyen
        if (a[mid]==k)
            return mid;
        else if (a[mid]<k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}