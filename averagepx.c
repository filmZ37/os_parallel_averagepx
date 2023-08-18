#include<stdio.h>
#include<omp.h>

int main(int argc, char** argv){
    int n;
    int sum,total,avg;
    int* input;
    scanf("%d",&n);
    input = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",&input[i]);
    }

    #pragma omp parallel private(sum) shared(total)
    {
        sum = 0;
        total = 0;

        #pragma omp for 
        for(int i = 0; i < n; i++){
            sum += input[i];
        }

        #pragma omp critical
        {
            total += sum;
        }
    }

    avg = total/n;
    printf("%d",avg);

    free(input);
    return 0 ;
}