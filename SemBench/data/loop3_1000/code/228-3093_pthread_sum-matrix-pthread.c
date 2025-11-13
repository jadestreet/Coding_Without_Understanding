#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
int ** A; 
int sum = 0; 
int number_of_threads; 
int matrix_size; 
pthread_mutex_t mut; 
typedef struct matrix_data_struct {
    int id;
    int number_of_threads;
    int matrix_size;
    int ** A;
} Matrix_Data;
struct timespec initial_time, end_time;
void sumMatrices (int matrix_id, int matrix_size, int number_of_threads, int ** mat_A);
void * function_pthread (void * arg);
void createThreads (pthread_t * threads, int number_of_threads, int matrix_size, int ** mat_A);
void joinThreads (pthread_t * p_threads);
int ** allocateMatrix (int matrix_size);
void generateMatrix(int ** mat, int matrix_size);
void printMatrix (int ** mat, int matrix_size, char * matrix_name);
int main (int argc, char ** argv)
{
	if (argc != 3) 
	{
		printf("Use: %s <N> <T>,  onde 'N' é a dimensão da matriz unitária e 'T' é o número de threads.\n", argv[0]);
		return 1;
	}
	matrix_size = atoi(argv[1]);
	number_of_threads = atoi(argv[2]);
	A = allocateMatrix(matrix_size);
	generateMatrix(A, matrix_size);
	if (matrix_size < 20)
		printMatrix(A, matrix_size, "A");
	pthread_t * p_threads;
	p_threads = (pthread_t *) malloc(number_of_threads * sizeof(pthread_t));
  	pthread_mutex_init(&mut, NULL);
	clock_gettime(CLOCK_MONOTONIC, &initial_time);
	createThreads(p_threads, number_of_threads, matrix_size, A);
	joinThreads(p_threads);
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	printf("A soma de todos os termos é: %d\n", sum);
	double elapsed = end_time.tv_sec - initial_time.tv_sec;
	elapsed += (end_time.tv_nsec - initial_time.tv_nsec) / 1000000000.0;
 	printf ("O tempo de processamento foi de: %f segundos\n", elapsed);   
  	pthread_mutex_destroy(&mut);  
	return 0;
}
void sumMatrices (int matrix_id, int matrix_size, int number_of_threads, int ** mat_A)
{
	int i, j;
	int start_row, end_row;
	start_row = matrix_id * (matrix_size / number_of_threads);
	if (matrix_id == number_of_threads - 1)
	{
		end_row = (matrix_id + 1) * (matrix_size/number_of_threads) + matrix_size % number_of_threads;
	}
	else
	{
		end_row = (matrix_id + 1) * (matrix_size/number_of_threads);
	}
	for (i = start_row; i < end_row; i++)
	{
		for (j = 0; j < matrix_size; j++) 
		{
			pthread_mutex_lock(&mut); 
			sum += A[i][j];
			pthread_mutex_unlock(&mut); 
		}
	}
}
void * function_pthread (void * arg)
{
	Matrix_Data * m_data = (Matrix_Data *) arg;
	sumMatrices(m_data->id, m_data->matrix_size, m_data->number_of_threads, m_data->A);
	return (void *)NULL;
}
void joinThreads (pthread_t * p_threads)
{
	int i;
	for (i = 0; i < number_of_threads; i++)
		pthread_join(p_threads[i], NULL);
}
void createThreads (pthread_t * threads, int number_of_threads, int matrix_size, int ** mat_A) 
{
	int i;
	Matrix_Data * m_data;
	for (i = 0; i < number_of_threads; i++) 
	{
		m_data = (Matrix_Data *) malloc(sizeof(Matrix_Data));
		m_data->id = i;
		m_data->number_of_threads = number_of_threads;
		m_data->matrix_size = matrix_size;
		m_data->A = mat_A;
    	pthread_create(&threads[i], NULL, function_pthread, (void *)(m_data));
  	}
}
int ** allocateMatrix (int matrix_size) 
{
	int i;
	int * values, ** temp;
  	values = malloc (matrix_size * matrix_size * sizeof(int));
 	temp = malloc (matrix_size * sizeof(int *));
	for (i = 0; i < matrix_size; i++)
  		temp[i] = &(values[i * matrix_size]);
 	return temp;
}
void generateMatrix(int ** mat, int matrix_size) 
{
	int i, j;
	for (i = 0; i < matrix_size; i++)
    	for (j = 0; j < matrix_size; j++) 
      		mat[i][j] = 1;
}
void printMatrix (int ** mat, int matrix_size, char * matrix_name)
{
	int i,j;
	printf ("A matriz %s %d X %d é:\n", matrix_name, matrix_size, matrix_size);
	for (i = 0; i < matrix_size; i++)
	{
		for (j = 0; j < matrix_size; j++)
	  		printf ("%d ", mat[i][j]);
		printf ("\n");
	}
	printf("\n");
}