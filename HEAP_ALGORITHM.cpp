// comple with "-std=c++11"

#include <iostream>
#include <random>
#include <vector>
#include <math.h>
#include "Eigen/SVD"
#include <algorithm>
#include <functional>
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

vector<double> Create_Random_Normarized_Vector(){
	vector<double> Normarized_Vector;
	uniform_real_distribution<double> lambda(-1.0,1.0);
	random_device rd;
	std::mt19937 mt(rd());
	double theta=asin(lambda(mt));
	uniform_real_distribution<double> _phi(0,2*M_PI);
	double phi=_phi(mt);
	Normarized_Vector.push_back(cos(theta)*cos(phi));
	Normarized_Vector.push_back(cos(theta)*sin(phi));
	Normarized_Vector.push_back(sin(theta));
	for(int i=0; i<3;i++)	cout<<Normarized_Vector[i];
	cout <<endl;
	return Normarized_Vector;
}

void Normarize_Vector(vector<double> v){
	double norm;
	for(int i=0; i<v.size(); i++)	norm+=v[i]*v[i];
	for(int i=0; i<v.size(); i++)	v[i]/=pow(norm,0.5);
	return;
}

double Inner_Product(vector<double> u,vector<double> v){
	double product=0;
	for(int i=0; i<u.size(); i++) product+=u[i]*v[i];
	return product;
}

vector<vector<double>> Create_Random_Rotation_Matrix(){
	vector<vector<double>> vectors;
	double innerproduct;
	for(int i=0; i<3; i++)		vectors.push_back(Create_Random_Normarized_Vector());
	for(int i=0; i<3; i++){
		for(int j=0; j<i; j++){
			innerproduct=Inner_Product(vectors[i],vectors[j]);
			for(int k=0; k<vectors[i].size(); k++) vectors[i][k]-=vectors[j][k]*innerproduct;	
		}
		Normarize_Vector(vectors[i]);
	}	
	return vectors;
}

int main(){

	vector<double*> A,B;
	int n_a, n_b; //The number of the vectors of A, B

	B=Init_Vectors_inB(5);
	for(int i=0; i<5;i++)		cout<<B[i][0]<<","<<B[i][1]<<","<<B[i][2]<<endl;
	//Create_Random_Normarized_Vector();
	vector<vector<double>> vectors=Create_Random_Rotation_Matrix();
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<vectors[i][j];
		}
		cout<<endl;
	}
	
	Close_Vectors_inB(B);
}
