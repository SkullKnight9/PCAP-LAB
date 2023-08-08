#include <stdio.h>
#include <mpi.h>
#include <math.h>
int main(int argc,char **argv){

    int x=3;
    double result;
    int rank;
    int size;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    result = pow(x,rank);

    printf("Proccess %d, pow(%d, %d) = %f\n", rank,x,rank, result);

    MPI_Finalize();


    return 0;
}