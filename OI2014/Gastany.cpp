#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int* belongsTo;
int* gastanEdges;
int* usefulEdges;

void turnBelong(int begin, int oldBelong, int newBelong){
	for(int i=1;i<n+1;i++){
		if(belongsTo[i]==oldBelong) belongsTo[i]=newBelong;
	}
}

int main(int argc, char **argv) {

	cin >> n >> m;

	belongsTo = new int[n+1];
	gastanEdges = new int[n+1];
	usefulEdges = new int[n+1];

	for(int i=0;i<n+1;i++){
		belongsTo[i]=i;
		gastanEdges[i]=0;
		usefulEdges[i]=0;
	}

	int beginx,endx;
	int u=0;
	for(int i=0;i<m;i++){
		cin >> beginx >> endx;
		if(belongsTo[beginx]!=belongsTo[endx]){
			gastanEdges[beginx]++;
			gastanEdges[endx]++;

			usefulEdges[beginx]+=endx;
			usefulEdges[endx]+=beginx;
			if(gastanEdges[beginx]>gastanEdges[endx]){
				int oldB = belongsTo[endx];
				belongsTo[endx]=belongsTo[beginx];
				if(gastanEdges[endx]>1)
					turnBelong(endx,oldB,belongsTo[endx]);
			}
			else{
				int oldB = belongsTo[beginx];
				belongsTo[beginx]=belongsTo[endx];
				if(gastanEdges[beginx]>1)
					turnBelong(beginx,oldB,belongsTo[beginx]);
			}
			u++;
		}
	}

	int done=0;
	int x = 1;
	int zasek = 0;
	while(done<n){
		if(gastanEdges[x]==1){
			gastanEdges[x]--;
			gastanEdges[usefulEdges[x]]--;
			usefulEdges[usefulEdges[x]]-=x;
			done++;
			cout << x << " ";
			if(done == n-1){
				cout << usefulEdges[x];
				done++;
			}
			zasek=0;
		}
		x++;
		if(x>n){x=1; zasek++;}
		if(zasek==3){
			cout << "oh boy";
			done = n;
		}
	}

}

