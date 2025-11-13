#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void initial_condition(double *u, int n_points, double delta_x);
void copy(double *u_to_copy, double *u_new, int n_x);
void update_u(double *u_present, double *u_past, double n_x, double r);
void print_u(double *u, double n_x, double delta_x);
int main(){
	double x_f = 2.0;
	int n_x = 1000;
	double delta_x = x_f/n_x;
	double delta_t = 1E-3;
	int n_t = 800.0;
	double c = 1.0;
	double r = c* delta_t / delta_x;
	double *u_past = malloc(n_x*sizeof(double));
	double *u_present = malloc(n_x*sizeof(double));
	initial_condition(u_past, n_x, delta_x);
	int i;
	for(i=0;i<n_t;i++){
		update_u(u_present, u_past, n_x, r);
		copy(u_present, u_past, n_x);
	}
	print_u(u_present, n_x, delta_x);
}
void initial_condition(double *u, int n_points, double delta_x){
	int i;
	for(i=0; i<n_points; i++){
		double x = i*delta_x;
		if(x<1.25 && x > 0.75){
			u[i] = 2.0;
		}else{
			u[i] = 0.0;
		}
	}
}
void copy(double *u_to_copy, double *u_new, int n_x){
	int i;
	for(i=0;i<n_x;i++){
		u_new[i] = u_to_copy[i];
	}
}
void update_u(double *u_present, double *u_past, double n_x, double r){
	int i;
	for(i=1;i<n_x-1;i++){
		u_present[i] = u_past[i] - r*(u_past[i]-u_past[i-1]);
	}
}
void print_u(double *u, double n_x, double delta_x){
	int i;
	for(i=0;i<n_x;i++){
		printf("%f %f\n", i*delta_x, u[i]);
	}
}