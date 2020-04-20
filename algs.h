#include <algorithm>
#include <vector>
using namespace std;

void bogo(vector<int> & V);
void bad(vector<int> & V);
void worse(vector<int> & V);
void worst(vector<int> & V);

int cota(int L);

template <typename T>
vector<vector<T>> permutaciones(vector<T> & V);

template <typename T>
void multinivel(vector<T> & V, int N);

///////////////////////////////

void bogo(vector<int> & V) {
	while (! is_sorted(V.begin(), V.end()))
		random_shuffle(V.begin(), V.end());
}

void bad(vector<int> & V) {
	do { 
		if(is_sorted(V.begin(), V.end()))
			return;
	} while(next_permutation(V.begin(), V.end()));
}

void worse(vector<int> & V) {
	vector<vector<int>> P = permutaciones(V);
	for(vector<int> X : P)
		if(is_sorted(X.begin(), X.end()))
			V = X;
}

void worst(vector<int> & V) {
	multinivel( V, cota(V.size()) );
}

///////////////////////////////

int cota(int L) {return 0;}

template <typename T>
vector<vector<T>> permutaciones(vector<T> & V) {
	vector<vector<T>> P;
	do { P.push_back(V);
	} while(next_permutation(V.begin(), V.end()));
	return P;
}

template <typename T>
void multinivel(vector<T> & V, int N) {
	if(N==0) sort(V.begin(), V.end());
	else {
		vector<vector<T>> P = permutaciones(V);
		multinivel(P, N-1);
		V = P[0];
	}
}
