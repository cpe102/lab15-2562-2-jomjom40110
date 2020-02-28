#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

void randData(double *dPtr,int N ,int M){
	for(int i=0;i<N*M;i++){
			*(dPtr+i)=(rand()%100)*0.01;
		}
}
void findRowSum(const double *dPtr,double *result,int N,int M){
	int a = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			*(result+i) += *(dPtr+a);
			a++;
		}
	}
}
void showData(double *dPtr,int N,int M){
	int a=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout  << setw(5) << fixed << setprecision(2) << *(dPtr+a) <<" ";
			a++;
		}
		cout << endl;
	}
}