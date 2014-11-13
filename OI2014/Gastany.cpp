#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
	int n,m;

	cin >> n >> m;

	int belongsTo[n+1];
	int gastanEdges[n+1];
	int usefulHeads[n+1];
	int usefulTails[n+1];
	vector<int> gastanyByUsefulNeighbors[n+1];

	for(int i=0;i<n+1;i++){
		belongsTo[i]=i;
		gastanEdges[i]=0;
		usefulHeads[i]=-1;
		usefulTails[i]=-1;
	}

	int beginx,endx;
	int u=0;
	for(int i=0;i<m;i++){
		cin >> beginx >> endx;
		if(belongsTo[beginx]!=belongsTo[endx]){
			gastanEdges[beginx]++;
			gastanEdges[endx]++;
			belongsTo[endx]=belongsTo[beginx];
			if(gastanEdges[beginx]>gastanEdges[endx]){
				usefulHeads[endx]=beginx;
				usefulTails[beginx]=endx;
			}
			else{
				usefulHeads[beginx]=endx;
				usefulTails[endx]=beginx;
			}
			u++;
		}
	}

	for(int i=0;i<n+1;i++){
		gastanyByUsefulNeighbors[gastanEdges[i]].push_back(i);
	}
	int done=0;
	int x = 1;
	while(done<n){
		if(gastanEdges[x]==1){
			gastanEdges[x]--;
			gastanEdges[usefulHeads[x]]--;
			done++;
			cout << x << " ";
		}
		x++;
		if(x>n){x=1;}
	}

}

