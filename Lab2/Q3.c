#include "mpi.h"
#include<stdio.h>
#include<stdlib.h>

int main (int argc, char *argv[]){

	int rank,size;
    int i,n,x;
	MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int arr[size-1];
    MPI_Status status;

        int buffer_size = MPI_BSEND_OVERHEAD + sizeof(int )*size-1;
        int *buffer = (int*)malloc(buffer_size);
        MPI_Buffer_attach(buffer,buffer_size);

    if(rank == 0){
        printf("Enter elements of Array \n");
        for(i=0;i<size-1;i++){
            scanf("%d",&arr[i]);
        }

        
        for(i=1;i<size;i++){
            MPI_Bsend(&arr[i],1,MPI_INT,i,i,MPI_COMM_WORLD);
        }
        
    }

    else{
        MPI_Recv(&x,1,MPI_INT,0,rank,MPI_COMM_WORLD,&status);
        if(rank % 2 == 0){
            arr[rank] = arr[rank] * arr[rank];
            printf(" Process %d : %d\n",rank,arr[rank]);
        }
        else{
             arr[rank] = arr[rank] * arr[rank] * arr[rank];
             printf("Process % d : %d\n",rank,arr[rank]);
        }  
    }

    
    MPI_Buffer_detach(&buffer, &buffer_size);
    MPI_Finalize();
}

