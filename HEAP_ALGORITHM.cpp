#include <iostream>
#include <random>
#include <vector>
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

int main(){

	vector<double*> A,B;
	B=Init_Vectors_inB(5);
	for(int i=0; i<5;i++){
		cout<<B[i][0]<<","<<B[i][1]<<","<<B[i][2]<<endl;
	}
	Close_Vectors_inB(B);
}
