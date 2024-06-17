#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[],int low,int mid, int high){
    int i,j,k,m;
    int b[10000];
    i=low;
    k=low;
    j=mid+1;
    while((i<=mid)&&(j<=high)){
        if(a[i]<a[j]){
            b[k]=a[i];
            k++;
            i++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        for(m=j;m<=high;m++){
            b[k]=a[m];
            k++;
        }
    }
    else{
        for(m=i;m<=mid;m++){
            b[k]=a[m];
            k++;
        }
    }
    for(k=low;k<=high;k++){
        a[k]=b[k];
    }
}

void merge_sort(int a[], int low, int high){
    int mid =(low+high)/2;
    if(low<high){
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void generateAndWriteToFile(const char *filename,int n){
    FILE *fp;
    int i;
    fp=fopen(filename,"w");
    if(fp==NULL){
        printf("Error opening");
        exit(1);
    }
    srand(time(NULL));
    for(i=0;i<n;i++){
        fprintf(fp,"%d\n",rand()%10000);
    }
    fclose(fp);
}

void readFromFile(const char *filename,int a[], int n){
    FILE *fp;
    int i;
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("Error opening file\n");
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
    int n,i,a[10000];
    double cpu_time_used;
    clock_t start,end;
    FILE *output_fp;
    output_fp=fopen(output_filename,"w");
    if(output_fp==NULL){
        printf("Error opening file \n");
        return 1;
    }
    fprintf(output_fp,"n , Time Taken (seconds)\n");
    for(n=5000;n<=10000;n+=1000){
        a[n];
        generateAndWriteToFile(filename,n);
        readFromFile(filename,a,n);
        start=clock();
        merge_sort(a,0,n-1);
        end=clock();
        cpu_time_used=((double) (end-start))/CLOCKS_PER_SEC;
        printf("Time Taken to sort %d elements %f seconds\n",n,cpu_time_used);
        fprintf(output_fp,"%d,%f\n",n,cpu_time_used);
    }
    for(i=0;i<5000;i++)
        printf("%d\t",a[i]);
    fclose(output_fp);
    printf("Data Written to %s\n",output_filename);
    return 0;
}