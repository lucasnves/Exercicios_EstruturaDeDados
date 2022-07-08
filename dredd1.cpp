#include <iostream>

using namespace std;

struct corredores{
	int cod, idade, peso;
	string nome, sexo;
};

struct treinamento{
	int dia, cod, tempo;
	float distancia;
};

void procurar(corredores dados[], treinamento infos[], int qnt, int k){
	int menoridade= dados[0].idade;
	int j=0;
	int total[qnt];
	
	for (int i=0; i < qnt; i++){
		total[i]=0;
		if (dados[i].sexo == "M"){
			if (menoridade < dados[i].idade){
				menoridade= dados[i].idade;
				j= i;
			}
		}
	}
	
	float soma=0;
	float somatorio[k];
	int d=0;
	int maistreino= total[0];
	for (int i=0; i < k; i++){
			somatorio[i]= 0;
			
		if (infos[i].cod == dados[j].cod){
			soma+= infos[i].distancia;
		}
		for (int l=0; l < qnt; l++){
			if (dados[l].cod == infos[i].cod){
				total[l]+= 1;
			}
			if (maistreino < total[l]){
				maistreino= total[l];
				d= l;
			}
			if (infos[i].cod == dados[l].cod){
				somatorio[l]+= infos[i].tempo;
			}
		}
	}
	if (j==0){
		cout << -1 <<endl;
	} else {
		cout << dados[j].nome <<" "<< soma <<endl;
	}
	cout << dados[d].nome <<" "<< dados[d].idade <<endl;
	for (int i=0; i < qnt; i++){
		cout << dados[i].nome<<" "<< (somatorio[i])/(total[i]) <<endl;
	}
}

int main (){
	int qnt;
	cin >> qnt;
	corredores dados[qnt];
	treinamento infos[100];
	
	for (int i=0; i < qnt; i++){
		cin >> dados[i].cod;
		cin >> dados[i].nome;
		cin >> dados[i].idade;
		cin >> dados[i].peso;
		cin >> dados[i].sexo;
	}
	int k=0;
	for (int j=0; j < 100; j++){
		cin >> infos[j].dia;
		if (infos[j].dia == -1){
			break;
		}
		cin >> infos[j].cod;
		cin >> infos[j].distancia;
		cin >> infos[j].tempo;
		k++;
	}
	procurar (dados, infos, qnt, k);
	
	return 0;
}
