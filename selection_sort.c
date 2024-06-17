#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int a[], int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[j+1]){
                min=j;
            }
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}

void generateAndWriteToFile(const char*filename,int n){
    int i;
    FILE *fp;
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

void readFromFile(const char *filename,int a[],int n){
    int i;
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("Error reading the file\n");
        exit(1);
    }
    for(i=0;i<n;i++){
        if(fscanf(fp,"%d",&a[i])!=1){
            printf("Error reading from file\n");
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
    double cpu_time_used;
    int n,i,a[10000];
    FILE *output_fp;
    output_fp=fopen(output_filename,"w");
    if(output_fp==NULL){
        printf("Error reading the file\n");
        return 1;
    }
    fprintf(output_fp,"n,Time Taken(seconds)\n");
    for(i=5000;i<=10000;n+=1000){
        a[n];

        generateAndWriteToFile(filename,n);
        readFromFile(filename,a,n);
        start=clock();
        selection_sort(a,n);
        end=clock();

        cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;
        printf("Time Taken to sort %d element %f sec\n",n,cpu_time_used);
        fprintf(output_fp,"%d,%f\n,cpu_time_used");
    }
    for(i=0;i<5000;i++)
    printf("%d\t",a[i]);
    fclose(output_fp);
    printf("Data written to %s \n",output_filename);
    return 0;
}