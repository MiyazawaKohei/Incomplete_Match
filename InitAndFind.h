// comple with "-std=c++11"

#include <iostream>
#include <random>
#include <vector>
#include <math.h>
#include "Eigen/SVD"
#include <algorithm>
#include <functional>
#include "heap.h"
using namespace std;

vector<double*> Init_Vectors_inB(int n_b);
void Close_Vectors(vector<double*> B);
vector<double> Create_Random_Normarized_Vector();
double L2_Norm(vector<double> v);
vector<double> Normarize_Vector(vector<double> v);
double Inner_Product(vector<double> u,vector<double> v);
vector<vector<double>> Create_Random_Rotation_Matrix();
int MyRandom_Int(int i);
vector<int> Create_Random_Permutaiton(int n_b);
vector<double*> Init_Vectors_inA(vector<double*> B,vector<vector<double>> rotation, vector<int> permutation,int n_a, double SDofnoise);
void Fix_Gravity_Point_to_Origin(vector<double*> vectors);
Eigen::Matrix<double,3,3> Compute_BAt(const vector<double*> A,const vector<double*> B);
double Maximize_trRBAt(const vector<double*> A,const vector<double*> B);
double Minimize_RMSD(const vector<double*> A,const vector<double*> B, const vector<int> sigma_i);
data* New_Data_for_HEAP(vector<int> taple,double key);
HEAP* BUILD_HEAP_FOR_PAIRS(const vector<double*> A, const vector<double*> B);
vector<int> Complement_of_Vector(vector<int> oneset, int allsetsize);
void View_Contents_ofH(HEAP *H);
void Find_Minimizing_Permutation(const vector<double*> A, const vector<double*> B);
