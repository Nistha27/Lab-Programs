#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sortItems(int n, int weight[], int values[],double ratio[]){
    int i ,j ;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(ratio[j]<ratio[j+1]){
                swap(&weight[j],&weight[j+1]);
                swap(&values[j],&values[j+1]);
                double temp=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=temp; 
            }
        }
    }
}

void knapsackDiscrete(int W, int weight[],int values[],int n){
    double ratio[n];
    int i;
    for(i=0;i<n;i++){
        ratio[i]=(double) values[i]/weight[i];
    }
    sortItems(n,weight,values,ratio);
    int currentWeight=0;
    int finalValue=0;
    for(i=0;i<n;i++){
        if(currentWeight+weight[i]<=W){
            currentWeight+=weight[i];
            finalValue+=values[i];
            printf("Items Selected %d (weight:%d,value:%d)\n",i+1,weight[i],values[i]);
        }
    }
    printf("Maximum Value:%d",finalValue);
}

int main(){
    int weight []={2,3,5,7,1,4,4};
    int values []={10,5,15,7,6,18,3};
    int W=15;
    int n= sizeof(values)/sizeof(values[0]);
    knapsackDiscrete(W, weight, values,n);
    return 0;
}
