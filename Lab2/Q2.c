#include "mpi.h"
#include<stdio.h>

int main (int argc, char *argv[]){

	int rank,size;
    int i,x;
    x = 5;
	MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;

    if(rank == 0){

        printf("Enter value to send to slaves \n");
        scanf("%d",&x);
        MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);
        MPI_Send(&x,1,MPI_INT,2,2,MPI_COMM_WORLD);

    }

    if(rank == 1){
        MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        printf("Slave Process %d has received and processed data : %d \n",rank,x);

    }
    if(rank == 2){
        MPI_Recv(&x,1,MPI_INT,0,2,MPI_COMM_WORLD,&status);
        printf("Slave Process %d has received and processed data : %d \n",rank,x);
    }
    MPI_Finalize();
}