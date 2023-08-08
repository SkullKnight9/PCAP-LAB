#include <mpi.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int rank, size;

	//int x;
	//int i = 0;

	MPI_Init (&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	
		if(rank % 2!= 0){
			printf("World, process: %d \n",rank);
		}

		else{
			printf("Hello, process: %d \n",rank);
		}

    MPI_Finalize();
	

	return 0;

}