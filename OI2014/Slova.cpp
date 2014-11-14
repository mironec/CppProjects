#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float calcSkaredost(vector<string> riadok, int dlzka, string slovoToAdd, int slovaToAdd, int last){
	if(last==0) return 0;
	if(slovaToAdd==-1){
		return (riadok.size()-1)*pow((60.0f-dlzka+riadok[riadok.size()-1].length())/(riadok.size()-2.0)-1,2);
	}
	else if(slovaToAdd==0){
		return riadok.size()*pow((60.0f-dlzka)/(riadok.size()-1.0)-1,2);
	}
	else if(slovaToAdd==1){
		return (riadok.size()+1)*pow((60.0f-dlzka-slovoToAdd.length())/riadok.size()-1,2);
	}
	return -154546;
}

int main(int argc, char **argv) {
	vector<string> slova;
	vector<vector<string> > riadky;
	vector<int> dlzkyRiadkov;
	int pocetslov=0;
	int pocetznakov=0;
	vector<int> dlzky;
	string s = "a";
	int dlzka;

	while(cin.good()){
		getline(cin,s);
		if(s=="") break;
		string ss = "";
		for(unsigned int i = 0;i<s.length();i++){
			if(s.at(i)==' '){
				dlzka=ss.length();
				dlzky.push_back(dlzka);
				slova.push_back(ss);
				pocetslov++;
				pocetznakov+=dlzka;
				ss="";
			}
			else{
				ss+=s.at(i);
			}
		}
		dlzka=ss.length();
		dlzky.push_back(dlzka);
		slova.push_back(ss);
		pocetslov++;
		pocetznakov+=dlzka;
	}
	riadky.resize((pocetznakov+pocetslov+40)/30);
	dlzkyRiadkov.resize(riadky.size(),0);
	int riadok = 0;
	int dlzkariadku = 0;
	//int beginRiadok = 0;
	int x = 0;
	while(x<pocetslov){
		s = slova[x];
		if(dlzkariadku+dlzky[x]+1<=60){
			if(dlzkariadku==0){
				dlzkariadku += dlzky[x];
				riadky[riadok].push_back(s);
				dlzkyRiadkov[riadok] += dlzky[x];
				//cout << s;
			}
			else{
				dlzkariadku += dlzky[x]+1;
				riadky[riadok].push_back(s);
				dlzkyRiadkov[riadok] += dlzky[x]+1;
				//cout << " " << s;
			}
			x++;
		}
		else{
			//cout << endl;
			riadok++;
			dlzkariadku=0;
		}
	}

	bool zasek = false;
	while(!zasek){
		zasek=true;
	for(int i=riadok-1;i>=0;i--){
		float skaredRemove = calcSkaredost(riadky[i],dlzkyRiadkov[i],"",-1,riadok-i);
		float skaredAdd = calcSkaredost(riadky[i+1],dlzkyRiadkov[i+1],riadky[i][riadky[i].size()-1],1,riadok-i-1);
		float skared1 = calcSkaredost(riadky[i],dlzkyRiadkov[i],"",0,riadok-i);
		float skared2 = calcSkaredost(riadky[i+1],dlzkyRiadkov[i+1],"",0,riadok-i-1);
		string slovo = riadky[i][riadky[i].size()-1];
		if((skaredRemove+skaredAdd<skared1+skared2)&&(dlzkyRiadkov[i+1]+slovo.length()+1<61)){
			riadky[i+1].insert(riadky[i+1].begin(),slovo);
			dlzkyRiadkov[i+1]+=slovo.length()+1;
			dlzkyRiadkov[i]-=slovo.length()+1;
			riadky[i].pop_back();
			i--;
			zasek=false;
		}
	}

	for(int i=0;i<riadok;i++) {
		float skaredRemove = calcSkaredost(riadky[i],dlzkyRiadkov[i],"",-1,riadok-i);
		float skaredAdd = calcSkaredost(riadky[i+1],dlzkyRiadkov[i+1],riadky[i][riadky[i].size()-1],1,riadok-i-1);
		float skared1 = calcSkaredost(riadky[i],dlzkyRiadkov[i],"",0,riadok-i);
		float skared2 = calcSkaredost(riadky[i+1],dlzkyRiadkov[i+1],"",0,riadok-i-1);
		string slovo = riadky[i][riadky[i].size()-1];
		if((skaredRemove+skaredAdd<skared1+skared2)&&(dlzkyRiadkov[i+1]+slovo.length()+1<61)){
			riadky[i+1].insert(riadky[i+1].begin(),slovo);
			dlzkyRiadkov[i+1]+=slovo.length()+1;
			dlzkyRiadkov[i]-=slovo.length()+1;
			riadky[i].pop_back();
			i--;
			zasek=false;
		}
	}
	}

	for(int i=0;i<riadok+1;i++){
		for(unsigned int x=0;x<riadky[i].size();x++){
			cout << riadky[i][x];
			if(x!=riadky[i].size()-1) cout << " ";
		}
		cout << endl;
	}
}

