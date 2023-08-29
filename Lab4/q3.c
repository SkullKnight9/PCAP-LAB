# include <stdio.h>
# include <mpi.h>
# include <string.h>
# include <stdlib.h>


int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int matrix[3][3];
    int searchElement;
    int localCount = 0;

    if (rank == 0) {
        printf("Enter a 3x3 matrix:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        printf("Enter the element to search: ");
        scanf("%d", &searchElement);
    }

    MPI_Bcast(&searchElement, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int localRowCount = 3 / size;
    int localMatrix[localRowCount][3];
    MPI_Scatter(matrix, localRowCount * 3, MPI_INT, localMatrix, localRowCount * 3, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < localRowCount; i++) {
        for (int j = 0; j < 3; j++) {
            if (localMatrix[i][j] == searchElement) {
                localCount++;
            }
        }
    }


    int globalCount;
    MPI_Reduce(&localCount, &globalCount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Total occurrences of %d in the matrix: %d\n", searchElement, globalCount);
    }

    MPI_Finalize();
    return 0;
}
