#include <mpi.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int rank, size;
	char str[5] = "HELLO";

	MPI_Init (&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	str[rank] ^= 32;

	printf("%s\n",str );

	MPI_Finalize();

	return 0;
}