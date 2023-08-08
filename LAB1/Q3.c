#include <mpi.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int rank, size;

	int a = 5;
	int b = 15;

	//printf("The Numbers are %d , %d",a,b);

	MPI_Init (&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 1){
		printf("Addition: %d \n",a+b);
	}

	else if(rank == 2){
		printf("Subtraction: %d \n ",b-a);
	}

	else if(rank == 3){
		printf("Multiplication: %d \n ",a*b);
	}

	else if(rank == 4){
		printf("Division: %d \n",b/a);
	}

	MPI_Finalize();
	

	return 0;

}