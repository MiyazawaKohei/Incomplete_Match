// comple with "-std=c++11"

#include <iostream>
#include <random>
#include <vector>
#include <math.h>
#include "Eigen/SVD"
#include <algorithm>
#include <functional>
#include "InitAndFind.h"
using namespace std;

int main(){

	vector<double*> A,B;
	int n_a, n_b; //The number of the vectors of A, B
	n_a=5;
	n_b=100;
	double SDofnoise=0.0001;
	B=Init_Vectors_inB(n_b);
	cout<<"B:"<<endl;
	for(int i=0; i<n_b;i++)		cout<<B[i][0]<<","<<B[i][1]<<","<<B[i][2]<<endl;
	vector<vector<double>> rotation=Create_Random_Rotation_Matrix();
	vector<int> permutation=Create_Random_Permutaiton(n_b);
	
	A=Init_Vectors_inA(B,rotation,permutation,n_a,SDofnoise);
	vector<int> permutationcut(n_a,0);
	for(int i=0; i<n_a; i++) permutationcut[i]=permutation[i];
	cout<<"Minimized_RMSD:"<<Minimize_RMSD(A,B,permutationcut)<<endl;
	Find_Minimizing_Permutation(A,B);
	Close_Vectors(A);
	Close_Vectors(B);
}
