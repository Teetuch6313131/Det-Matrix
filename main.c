#include<stdio.h>
#include<stdlib.h>

void matGen(double **mat, int N);
void printArrayNN0(double **mat, int N);
double detFunc(double **mat,int N);

int main()
{
    int size, minsize = 2, maxsize = 6; // size starts from 2x2 to maxsize x maxsize
    // static 2-dim array are created
    double m[6][6] = { {0} };
    // static array of pointer are created
    double* ap[6] = {&m[0][0],&m[1][0],&m[2][0],&m[3][0],&m[4][0],&m[5][0]};
    double** mat = ap;
    //int loop, Sing;

    // Q1_3 determinant
    printf("===================== determinant =====================\n\n");
    printf("input N: ");
    scanf("%d",&size);
    //
    printf("input %d numbers for mat: ", size*size);
    matGen(mat, size);
    printf("Determinant = %.2lf\n",detFunc(mat, size));
    printArrayNN0(mat, size);
    printf("===============================================================\n\n");
    // Q1_3 determinant

    return 0;
}

double detFunc(double **mat,int N){
    if (N == 1)
        return (mat[0][0]);

    else if (N == 2)
        return (mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1]);

    else {
        double m[6][6] = { {0} };
        double* ap[6] = {&m[0][0],&m[1][0],&m[2][0],&m[3][0],&m[4][0],&m[5][0]};
        double** minor = ap;
        int row_minor, column_minor;
        int firstrow_columnindex;
        int sum = 0;

        register int row,column;

        // exclude first row and current column
        for(firstrow_columnindex = 0; firstrow_columnindex < N;
                firstrow_columnindex++) {

            row_minor = 0;

            for(row = 1; row < N; row++) {

                column_minor = 0;

                for(column = 0; column < N; column++) {
                    if (column == firstrow_columnindex)
                        continue;
                    else
                        minor[row_minor][column_minor] = mat[row][column];

                    column_minor++;
                }

                row_minor++;
            }

            //m = row_minor;
            //n = column_minor;

            if (firstrow_columnindex % 2 == 0)
                sum += mat[0][firstrow_columnindex] * detFunc(minor,N-1);
            else
                sum -= mat[0][firstrow_columnindex] * detFunc(minor,N-1);

        }

        return sum;

    }
    }


void matGen(double **mat, int N) {
    int i,j;
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            scanf("%lf",&mat[i][j]);
        }
    }
}

void printArrayNN0(double **mat, int N) {
    int i,j;
    for(i=0;i<N;i++) {
//        printf("| ");
        for(j=0;j<N;j++) {
            printf("% 8.0lf ",mat[i][j]); // no floating point
        }
        printf("\n");
//        printf(" |\n");
    }
    printf("\n");
}

/*
int det() {
    

    if (row_size != column_size) {
        printf("DimensionError: Operation Not Permitted \n");
        exit(1);
    }

    else if (row_size == 1)
        return (B[0][0]);

    else if (row_size == 2)
        return (B[0][0]*B[1][1] - B[1][0]*B[0][1]);

    else {
        int minor[row_size-1][column_size-1];
        int row_minor, column_minor;
        int firstrow_columnindex;
        int sum = 0;

        register int row,column;

        // exclude first row and current column
        for(firstrow_columnindex = 0; firstrow_columnindex < row_size;
                firstrow_columnindex++) {

            row_minor = 0;

            for(row = 1; row < row_size; row++) {

                column_minor = 0;

                for(column = 0; column < column_size; column++) {
                    if (column == firstrow_columnindex)
                        continue;
                    else
                        minor[row_minor][column_minor] = B[row][column];

                    column_minor++;
                }

                row_minor++;
            }

            m = row_minor;
            n = column_minor;

            if (firstrow_columnindex % 2 == 0)
                sum += B[0][firstrow_columnindex] * det(minor);
            else
                sum -= B[0][firstrow_columnindex] * det(minor);

        }

        return sum;

    }
}
*/