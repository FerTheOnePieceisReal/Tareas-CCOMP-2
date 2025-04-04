#include<iostream>
void swap(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void merge(int *p, int*q){
    //Final del array
    int *final=p+(q-p)*2;
    //Numero de elementos del array
    int num_elem=(final-p);
    int mitad=num_elem/2;
    int m=mitad;
    if(p<final && q<final){
        for(int i=0;i<m;i++){
            for(int k=0;k<mitad;k++){
                if(*(p+k)>*(q+k))
                    swap(*(p+k),*(q+k));
            }
            num_elem-=2;
            mitad=num_elem/2;
            p=p+1;
        }
    }
}    

int main(){
    int arr[6]={2,6,30,3,11,21};
    int *p=arr;
    int*q=arr+3;
    merge(p,q);
    for(int i=0;i<6;i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}