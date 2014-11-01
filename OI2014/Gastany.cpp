#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
	int n,m;
	vector<int> begin;
	vector<int> end;
	vector<int> g;

	cin >> n >> m;

	int beginx,endx;
	begin.resize(m);
	end.resize(m);
	g.resize(n);

	for(int i=0;i<m;i++){
		cin >> beginx >> endx;
		begin.push_back(beginx);
		end.push_back(endx);
		g[beginx]++;
		g[endx]++;
	}
	sort(g.begin(),g.end());
}

