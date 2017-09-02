#include<bits/stdc++.h>
using namespace std;

void one_dimension_thermal_conductivity(){
	double alpha;
	double lambda, cee, rho;
	double T_n[10000], T_n1[10000];
	double b, delta_x, total_time, delta_t;
	int num_i, num_n;
	char line[100];
	FILE *in_file, *out_file;
	in_file = fopen("input.dat", "r");
	out_file = fopen("output.dat", "w");

	fgets(line, sizeof(line), in_file);
	fgets(line, sizeof(line), in_file);
	sscanf(line, "%lf %lf %lf", &lambda, &cee, &rho);
	alpha = lambda / (cee * rho);
	fgets(line, sizeof(line), in_file);
	fgets(line, sizeof(line), in_file);
	sscanf(line, "%lf %lf %lf %lf", &b, &delta_x, &total_time, &delta_t);
	num_i = b / delta_x;
	num_n = total_time / delta_t;

	for(int i = 0; i <= num_i; i++){
		if(i == 0){
			T_n[i] = 0.0;
			fputs("0.0 ", out_file);
		}
		else if(i == num_i){
			T_n[i] = 0.0;
			fputs("0.0\n", out_file);
		}else{
			T_n[i] = 20.0;
			fputs("20.0 ", out_file);
		}
	}
	double hoge = alpha * delta_t / (delta_x * delta_x);
	for(int i = 2; i <= num_n; i++){
		for(int j = 0; j <= num_i; j++){
			if(j == 0){
				T_n1[j] = 0.0;
				fputs("0.0 ", out_file);
			}else if(j == num_i){
				T_n1[j] = 0.0;
				fputs("0.0\n", out_file);
			}else{
				T_n1[j] = hoge * (T_n[j - 1] + T_n[j + 1]) + (1 - 2 * hoge) * T_n[j];
				fprintf(out_file, "%.5lf ", T_n1[j]);
			}
		}
		for(int j = 0; j <= num_i; j++){
			T_n[j] = T_n1[j];
		}
	}
	fclose(in_file);
	fclose(out_file);
}

int main(){
	one_dimension_thermal_conductivity();
	return 0;
}
