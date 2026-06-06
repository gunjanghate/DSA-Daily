class Solution {
public:
    int count = 0; // Store the number of reverse pairs

    // Merge function to merge two sorted halves of the array
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // Temporary array
        int left = low;   // Starting index of the left half of arr
        int right = mid + 1; // Starting index of the right half of arr

        // Storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Transferring all elements from temporary to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Count reverse pairs where arr[i] > 2 * arr[j]
    void countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) { // Use 2LL to avoid overflow
                right++;
            }
            count += (right - (mid + 1));
        }
    }

    // Merge Sort function
    void mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return; // Base case: single element

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);     // Left half
        mergeSort(arr, mid + 1, high); // Right half
        countPairs(arr, low, mid, high); // Count reverse pairs
        merge(arr, low, mid, high);   // Merge sorted halves
    }

    // Function to return the number of reverse pairs
    int reversePairs(vector<int> &nums) {
        count = 0; // Reset count
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};