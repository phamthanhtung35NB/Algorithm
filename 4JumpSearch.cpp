//Thuật Toán Tìm Kiếm Nhảy
int JumpSearch(int a[], int k, int n)
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
