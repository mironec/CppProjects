#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	vector<string> slova;
	int pocetslov=0;
	int pocetznakov=0;
	vector<int> dlzky;
	string s;
	int dlzka;

	while(cin.good()){
		cin >> s;
		dlzka=s.length();
		dlzky.push_back(dlzka);
		slova.push_back(s);
		pocetslov++;
		pocetznakov+=dlzka;
	}
	int riadok = 0;
	int dlzkariadku = 0;
	//int beginRiadok = 0;
	int x = 0;
	while(x<pocetslov-1){
		s = slova[x];
		if(dlzkariadku+dlzky[x]+1<=60){
			if(dlzkariadku==0){
				dlzkariadku += dlzky[x];
				cout << s;
			}
			else{
				dlzkariadku += dlzky[x]+1;
				cout << " " << s;
			}
			x++;
		}
		else{
			cout << endl;
			riadok++;
			dlzkariadku=0;
		}
	}
}

