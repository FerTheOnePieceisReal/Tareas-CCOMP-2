#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void merge(int* p, int* q, int*final) {
    int* current = p;
    int c=0;
    while (current <q) {
        int* left = current;
        int* right = q;
        
        while (right < final-c) {
            if (*left > *right) {
                swap(*left, *right);
            }
            left++;
            right++;
        }
        current++;
        c++;
    }
}

int main() {
    int arr[] = {2, 4, 30, 3, 11, 21};
    
    int* p = arr;
    int* q = arr+3;
    int*final=p+(q-p)*2;
    merge(p,q, final);
    for(int*a=p;a<p+6;a++){
        std::cout << *a << " ";
    }
    
    return 0;
}
