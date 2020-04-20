#include <iostream> // cout
#include <algorithm>// random_shuffle
#include <vector>	// vector
#include <numeric>	// iota
#include <chrono>
using namespace std;
using namespace std::chrono;

#include "algs.h"

int main() {
	vector<int> V(5);
	iota(V.begin(), V.end(), 1);
	random_shuffle(V.begin(), V.end());
	
	vector<int> X(V), Y(V), Z(V);
	
	auto start = high_resolution_clock::now();   
	bogo(X);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Bogo: "
         << duration.count() << " ms" << endl; 
  
	start = high_resolution_clock::now();   
	bad(Y);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<milliseconds>(stop - start); 
    cout << "Bad: "
         << duration.count() << " ms" << endl; 
  
	start = high_resolution_clock::now();   
	worse(Z);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<milliseconds>(stop - start); 
    cout << "Worse: "
         << duration.count() << " ms" << endl; 
  
	start = high_resolution_clock::now();   
	worst(V);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<milliseconds>(stop - start); 
    cout << "Worst: "
         << duration.count() << " ms" << endl; 
         
    return 0;
}
