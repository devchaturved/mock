#include <iostream>
#include <vector>
using namespace std;

// Heapify a subtree rooted at index i in the given heap
void heapify(vector<int>& heap, int heapSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < heapSize && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, heapSize, smallest);
    }
}

// Build a min-heap from the given array of marks
void buildMinHeap(vector<int>& marks) {
    int n = marks.size();

    // Start from the last non-leaf node and heapify all subtrees
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(marks, n, i);
    }
}

// Find the minimum and maximum marks using a heap data structure
void findMinMaxMarks(const vector<int>& marks, int& minMark, int& maxMark) {
    vector<int> minHeap = marks;

    buildMinHeap(minHeap);

    minMark = minHeap[0];
    maxMark = marks[0];
}

// Perform heapsort to sort the marks in descending order
void heapSort(vector<int>& marks) {
    int n = marks.size();

    // Build a max-heap from the given marks
    buildMinHeap(marks);

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
