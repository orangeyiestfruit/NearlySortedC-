// Insertion Sort.cpp : Defines the entry point for the console application.
//Nearly sorted - when there are elements that are switched from an originally sorted array

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;
const int zzz = 10000000; //size of the generated k-sorted array
const int hi = 2; //Used in delcaring vector for storing both the generated array and the removed values
const int wi = zzz + 1; // used in declaring aforementioned vector
vector<vector<int>> scana(vector<int> arry) {
	vector<vector<int>> al;
	arry.resize(zzz);
	al.resize(hi);
	int ri;
	int car = 0;
	int m;
	int c = 1;
	for (m = 0; m < zzz - 1; m++) {
		if (arry[m] > arry[m + 1]) {
			if (c == 0) {
				al[0].push_back(arry[m-1]);
				al[0].push_back(arry[m]);
				al[0].push_back(arry[m+1]);
				al[1].push_back(m - 1);
				al[1].push_back(m);
				al[1].push_back(m + 1);
				c = 1;
			}
			else if (c == 2) {
				al[0].push_back(arry[m + 1]);
				al[1].push_back(m + 1);
				c = 0;
			}
			else if (c == 1) {
				al[0].push_back(arry[m]);
				al[0].push_back(arry[m + 1]);
				al[1].push_back(m);
				al[1].push_back(m + 1);
				c = 2;
			}
		}
		else {
			if (c > 0) {
				c -= 1;
			}
		}
	}
	return al;
}
vector<int> sorta(vector<vector<int>> comb) {
	int case1 = comb[0].size();
	if (case1 >30) {
		sort(comb[0].begin(), comb[0].end());
	}
	else {
		int irt, kirt, jirt;
		for (irt = 1; irt < case1; irt++) {
			kirt = comb[0][irt];
			jirt = irt - 1;
			while(jirt>=0 && comb[0][jirt]>kirt) {
				comb[0][jirt + 1] = comb[0][jirt];
				jirt = jirt - 1;
			}
			comb[0][jirt + 1] = kirt;
		}
	}
	return comb[0];
}
vector<int> prepa(vector<vector<int>> comb2, vector<int> sorts, vector<int> arry) {
	vector<int> result(zzz);
	size_t r;
	size_t comp;
	for (r = 0, comp = comb2[1].size(); r < comp; r++) {
		arry[comb2[1][r]] = sorts[r];
	}
	return arry;
}
int main()
{
	int i;
	int l;
	const int size = zzz;
	vector<int> ar;
	vector<int> ar2;
	int p = 100; //misplaces 3 elements every sixty
	for (l = 1; l < size; l++) {
		ar[l].push_back(l);
		ar[2].push_back(l);
	}
	int ca;
	int ca2;
	for (i = 4; i < size; i++) {
		if (i%p == 0) {
			ca2 = ar2[i];
			ca = ar[i];
			ar[i] = ar[i-4];
			ar2[i] = ar2[i - 4];
			ar[i-4] = ca;
			ar2[i - 4] = ca2;
		}
		//cout << ar[i-2] <<"\n";
	}
	clock_t doi = clock();
	vector<vector<int>> res = scana(ar);
	vector<int> res2 = sorta(res);
	vector<int> fin=prepa(res, res2,ar);
	doi = clock() - doi;
	int blas = 0;
	cout << "Optimized intro/inser sort finished in " << doi << "clocks!\n";
	clock_t espero = clock();
	sort(ar2.begin(), ar2.end());
	espero = clock() - espero;
	cout << "std::sort finished in " << espero << "clocks! " << espero - doi << " clocks slower than the first one!\n";
    return 0;
}
