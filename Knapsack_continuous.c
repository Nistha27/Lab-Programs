#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sortItems(int n,int weight[],int values[] ,double ratio[]){
    int i,j;
    for (i=0;i<n-1;i++){
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

void knapsackContinuous(int W , int weight[],int values[],int n){
    int i;
    double ratio[n];
    for(i=0;i<n;i++){
        ratio[i]=(double) values[i]/weight[i];
    }
    sortItems(n,weight,values,ratio);
    int currentWeight=0;
    double finalValue=0;
    for(i=0;i<n;i++){
        if(currentWeight+weight[i]<=W){
            currentWeight+=weight[i];
            finalValue+=values[i];
            printf("Item:%d(weight:%d values:%d)\n",i+1,weight[i],values[i]);
        }
        else{
            int remain=W-currentWeight;
            finalValue+= values[i]*((double) remain/weight[i]);
            printf("Items:%d (weight:%d,values:%0.02f)(fractional)\n",i+1,weight[i],values[i]*((double) remain/weight[i]));
            break;
        }
        
    }
    printf("Maximum Value:%0.2f",finalValue);
}

int main(){
    int values[]={10,5,15,7,6,18,3};
    int weight[]={2,3,5,7,1,4,4};
    int W=15;
    int n= sizeof(values)/sizeof(values[0]);
    knapsackContinuous(W,weight,values,n);
}