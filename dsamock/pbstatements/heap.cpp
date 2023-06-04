#include <iostream>
#include <vector>
using namespace std;

// Heapify a subtree rooted at index i in the given heap
void heapify(vector<int>& heap, int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < heapSize && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, heapSize, largest);
    }
}

// Build a max-heap from the given array of marks
void buildMaxHeap(vector<int>& marks) {
    int n = marks.size();

    // Start from the last non-leaf node and heapify all subtrees
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(marks, n, i);
    }
}

// Find the minimum and maximum marks using a heap data structure
void findMinMaxMarks(const vector<int>& marks, int& minMark, int& maxMark) {
    vector<int> maxHeap = marks;
    vector<int> minHeap = marks;

    buildMaxHeap(maxHeap);

    minMark = minHeap[0];
    maxMark = maxHeap[0];
}

// Perform heapsort to sort the marks in descending order
void heapSort(vector<int>& marks) {
    int n = marks.size();

    // Build a max-heap from the given marks
    buildMaxHeap(marks);

    // Perform heapsort
    for (int i = n - 1; i > 0; i--) {
        swap(marks[0], marks[i]);
        heapify(marks, i, 0);
    }
}

int main() {
    vector<int> marks = { 90, 85, 92, 78, 95, 88 };

    int minMark, maxMark;
    findMinMaxMarks(marks, minMark, maxMark);

    cout << "Minimum mark: " << minMark << endl;
    cout << "Maximum mark: " << maxMark << endl;

    cout << "Marks before sorting: ";
    for (int mark : marks) {
        cout << mark << " ";
    }
    cout << endl;

    heapSort(marks);

    cout << "Marks after sorting (descending order): ";
    for (int mark : marks) {
        cout << mark << " ";
    }
    cout << endl;

    return 0;
}
