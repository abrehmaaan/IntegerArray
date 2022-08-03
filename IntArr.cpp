#include<iostream>
using namespace std;
class IntArr{
    int capacity;
    int size;
    int* arr;
public:
    // default constructor
    IntArr(){
        capacity = 100;
        size = 0;
        arr = NULL;
    }
    // parameterized constructor
    IntArr(int s){
        size = 0;
        capacity = s;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++){
            arr[i] = 0;
        }
    }
    const int& operator[](int index)const{
        return arr[index];
    }
    // copy constructor
    IntArr(const IntArr& a){
        size = a.size;
        capacity = a.capacity;
        if (capacity != 0){
            arr = new int[capacity];
            for (int i = 0; i < capacity; i++){
                arr[i] = a.arr[i];
            }
        }
        else{
            arr = NULL;
        }
    }
    const IntArr& operator=(const IntArr& a){
        if (this != &a){
            if (a.size == 0 && size != 0){
                delete[]arr;
                size = 0;
                arr = NULL;
            }
            else{
                if (size != 0){
                    delete[]arr;
                }

                size = a.size;
                capacity = a.capacity;
                arr = new int[capacity];
                for (int i = 0; i < capacity; i++){
                    arr[i] = a.arr[i];
                }
            }
        }
        return *this;
    }
    ~IntArr(){
        if (size != 0){
            delete[]arr;
        }
    }
    void grow(){
        IntArr a(capacity*2);
        for(int i=0;i<size;i++){
            a.arr[i] = arr[i];
        }
        capacity = a.capacity;
        delete[]arr;
        arr = a.arr;
    }
    void push_back(int a){
        if(size<capacity){
            arr[size++] = a;
        }
        else{
            grow();
            arr[size++] = a;
        }
    }
    int pop_back(){
        return arr[size--];
    }
    int getSize() const{
        return size;
    }
};
int main() {
    cout << endl;
    IntArr a{5};
    for(int i=0; i<5; i++) { a.push_back((i+1)*5); }
    cout << "Array size: " << a.getSize() << endl;
    cout << "Array A: ";
    for(int i=0; i<a.getSize(); i++) { cout << a[i] << " "; }
    cout << endl << endl;
    a.push_back(30);
    a.push_back(35);
    cout << "Array size: " << a.getSize() << endl;
    IntArr b = a;
    cout << "Array A: ";
    for(int i=0; i<a.getSize(); i++) { cout << a[i] << " "; }
    cout << "\nPArray B: ";
    for(int i=0; i<b.getSize(); i++) { cout << b[i] << " "; }
    cout << endl << endl;
    a.pop_back();
    cout << "Array size: " << a.getSize() << endl;
    b = a;
    cout << "Array A: ";
    for(int i=0; i<a.getSize(); i++) { cout << a[i] << " "; }
    cout << "\nArray B: ";
    for(int i=0; i<b.getSize(); i++) { cout << b[i] << " "; }
    cout << endl << endl;
    cout << endl;
return 0;
}
