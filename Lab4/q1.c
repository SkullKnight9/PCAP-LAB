# include <stdio.h>
# include <mpi.h>
# include <string.h>
# include <stdlib.h>

void Error_Handler(int error_code){
	if(error_code != MPI_SUCCESS){
		char error_string[100];
		int length_of_error_string, error_class;
		MPI_Error_class(error_code, &error_class);
		MPI_Error_string(error_code,error_string,&length_of_error_string);
		printf("[ERROR %d]: %s\n",error_class,error_string);
	}
}


int main (int argc, char* argv[]){
	int rank,size,factsum,i,error_code;
	int fact = 1;

	MPI_Init(&argc,&argv);
	error_code = MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	error_code = MPI_Comm_size(MPI_COMM_WORLD,&size);
    Error_Handler(error_code);
	for(i=1;i<=rank+1;i++)
		fact = fact*i;

	error_code = MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    Error_Handler(error_code); 
	if(rank==size-1){
		printf("Sum of all the factorial = %d",factsum);
	}

	MPI_Finalize();
	exit(0);
}
