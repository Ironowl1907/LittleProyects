#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &left, vector<int> &right, vector<int> &array) {
    int leftS = left.size();
    int rightS = right.size();

    int i = 0, r = 0, l = 0;

    while (l < leftS && r < rightS) {
        if (left[l] < right[r]) {
            array[i] = left[l];
            i++;
            l++;
        } else {
            array[i] = right[r];
            i++;
            r++;
        }
    }

    while (l < leftS) {
        array[i] = left[l];
        i++;
        l++;
    }

    while (r < rightS) {
        array[i] = right[r];
        r++;
        i++;
    }
}

void mergeSort(vector<int> &arr) {
    int length = arr.size();
    if (length <= 1) return;

    int middle = length / 2;
    vector<int> left(arr.begin(), arr.begin() + middle);
    vector<int> right(arr.begin() + middle, arr.end());

    mergeSort(left);
    mergeSort(right);
    merge(left, right, arr);
}

int main() {
    vector<int> arr = {8, 2, 5, 3, 4, 7, 6, 1};
    mergeSort(arr);
    for (int a : arr) {
        cout << a << endl;
    }
    return 0;
}
