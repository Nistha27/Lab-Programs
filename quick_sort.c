#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int a[],int low,int high){
    int pivot=low;
    int i=low;
    int j=high+1;
    while(i<=j){
        do{
            i++;
        }while(pivot>=a[i] && i<=high);
        do{
            j--;
        }while(pivot<a[j]);
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void qs(int a[],int low, int high){
    int mid;
    if(low<high){
        mid=partition(a,low,high);
        qs(a,low,mid-1);
        qs(a,mid+1,high);
    }
}


void generateAndWriteToFile(const char *filename,int n){
    FILE *fp;
    int i;
    fp=fopen(filename,"w");
    if(fp==NULL){
        printf("Error opening the file\n");
        exit(1);
    }
    srand(time(NULL));
    for(i=0;i<n;i++){
        fscanf(fp,"%d\n",rand()%10000);
    }
    fclose(fp);
}

void readFromFile(const char *filename,int n, int a[]){
    int i;
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("Error opening the file\n");
        exit(1);
    }
    for(i=0;i<n;i++){
        if(fscanf(fp,"%d",&a[i])!=1){
            printf("Error reading from file \n");
            fclose(fp);
            exit(1);
        }
    }
    fclose(fp);
}

int main(){
    const char *filename="input.txt";
    const char *output_filename="sorting.csv";
    clock_t start,end;
    int i,n,a[10000];
    double cpu_time_used;
    FILE *output_fp;
    output_fp=fopen(output_filename,"w");
    if(output_fp==NULL){
        printf("Error opening the file\n");
        return 1;
    }
    fprintf(output_fp,"n,Time Taken(seconds)\n");
    for(n=5000;n<=10000;n+=1000){
        a[n];
        generateAndWriteToFile(filename,n);
        readFromFile(filename,n,a);
        start=clock();
        qs(a,0,n-1);
        end=clock();
        cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;
        printf("Time Taken to sort %d elements %f seconds\n",n,cpu_time_used);
        fprintf(output_fp,"%d,%f\n",n,cpu_time_used);
    }
    for(i=0;i<5000;i++)
    printf("%d\t",a[i]);
    fclose(output_fp);
    printf("Data Written to %s\n", output_filename);
    return 0;
}