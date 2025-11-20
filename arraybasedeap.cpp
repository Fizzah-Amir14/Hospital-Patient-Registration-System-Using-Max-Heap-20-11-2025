#include<iostream>
using namespace std;

struct Patient {
    string name;
    int age;
    int priority;
};

int heapsize = 0;
Patient arr[50];

int parent(int i) { return i/2; }
int leftchild(int i) { return 2*i; }
int rightchild(int i) { return 2*i + 1; }

void swapVal(Patient &a, Patient &b) {
    Patient temp = a;
    a = b;
    b = temp;
}

void shiftUp(int i) {
    while(i > 1 && arr[parent(i)].priority < arr[i].priority) {
        swapVal(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void insert(Patient p) {
    heapsize++;
    arr[heapsize] = p;
    shiftUp(heapsize);
}

void shiftDown(int i) {
    int maxindex = i;
    int left = leftchild(i);
    if(left <= heapsize && arr[left].priority > arr[maxindex].priority)
        maxindex = left;

    int right = rightchild(i);
    if(right <= heapsize && arr[right].priority > arr[maxindex].priority)
        maxindex = right;

    if(i != maxindex) {
        swapVal(arr[i], arr[maxindex]);
        shiftDown(maxindex);
    }
}

Patient remove() {
    if(heapsize == 0) return {"", 0, -1};
    Patient top = arr[1];
    arr[1] = arr[heapsize];
    heapsize--;
    shiftDown(1);
    return top;
}

int main() {
    insert({"Alice", 30, 2});
    insert({"Bob", 40, 5});
    insert({"Charlie", 20, 3});
    insert({"Daisy", 25, 1});

    cout << "Heap elements: ";
    for(int i = 1; i <= heapsize; i++)
        cout << arr[i].name << "(" << arr[i].priority << ") ";
    cout << endl;

    Patient treated = remove();
    cout << "Treated patient: " << treated.name << endl;

    cout << "Heap elements after removal: ";
    for(int i = 1; i <= heapsize; i++)
        cout << arr[i].name << "(" << arr[i].priority << ") ";
    cout << endl;

    return 0;
}
