// comple with "-std=c++11"

#include <iostream>
#include <random>
#include <vector>
#include <math.h>
#include "Eigen/SVD"
static const int dimention = 3;
using namespace std;

vector<double*> Init_Vectors_inB(int n_b){
	vector<double*> B;
	uniform_real_distribution<double> x(0,1.0);
	random_device rd;
	std::mt19937 mt(rd());
	for (int i=0; i<n_b; i++){
		B.push_back(new double [dimention]);
		for(int j=0; j<dimention; j++){
			B.back()[j]=x(mt);
		}
	}
	return B;
}

void Close_Vectors_inB(vector<double*> B){
	while(B.size()>0){
		delete[] B.back();
		B.pop_back();
	}
	return;
}

double* Create_Random_Normarized_Vector(){
	double Normarized_Vector[3];
	uniform_real_distribution<double> lambda(-1.0,1.0);
	random_device rd;
	std::mt19937 mt(rd());
	double theta=asin(lambda(mt));
	uniform_real_distribution<double> _phi(0,2*M_PI);
	double phi=_phi(mt);
	Normarized_Vector[0] = cos(theta)*cos(phi);
	Normarized_Vector[1] = cos(theta)*sin(phi);
	Normarized_Vector[2] = sin(theta);
	for(int i=0; i<3;i++){
		cout<<Normarized_Vector[i]<<endl;
	}
	return Normarized_Vector;
}


int main(){

	vector<double*> A,B;
	int n_a, n_b; //The number of the vectors of A, B

	B=Init_Vectors_inB(5);
	for(int i=0; i<5;i++){
		cout<<B[i][0]<<","<<B[i][1]<<","<<B[i][2]<<endl;
	}
	Create_Random_Normarized_Vector();
	Close_Vectors_inB(B);
}
