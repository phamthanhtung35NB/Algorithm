void BubbleSort(int arr[], int n){
    for(int i=n-1;i>0;i--){
        bool check =1;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int tam=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tam;
                check=0;
            }
        }
        if(check==1){
            break;
        }
    }
}
void quickSort(std::vector<int>& nums, int low, int high) {
    if (low < high) {
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (nums[j] <= pivot) {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[i + 1], nums[high]);

        quickSort(nums, low, i);
        quickSort(nums, i + 1, high);
    }
}
void SelectionSort(int arr[], int n){
    for(int i=0;i<n;i++){
        int minData =i;
        for(int j=i+1;j<n;j++){
            if(arr[minData]>arr[j]){
                minData=j;
            }
        }
        if(i!=minData){
            int tem=arr[i];
            arr[i]=arr[minData];
            arr[minData]=tem;
        }
    }
}
void InsertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}
