#include <iostream>
#include <string>

using namespace std;

/*
 * Código desenvolvido para atividade de TADs;
 * Parte de implementação;
 * NOME: LUCAS NEVES SABER GABRIEL
 * 
 * Decisão sobre o projeto:
 *  Usei os valores de modo aleatório para as definições
 * de esporte, atleta e patrocinador. E com essas entidades fiz com que
 * esporte fosse class e atleta e patrocinador como struct.
 */

struct atleta{
	string nome;
	float altura;
	float peso;
	string nacionalidade;
	char nascimento [10];
};

struct patrocinador{
	string nome;
	string setor;
	string paisede;
	float investido;
	float iContrato;
	float fContrato;
};

class esporte{
	private:
		string nomeEsporte;
		string atv;
		char data [10];
		char hora [10];
		esporte *lEsportes;
		atleta *lAtletas;
		patrocinador *lPatrocinadores;
		int totalE, totalA, totalP;
	public:
		esporte(int q=0);
		~esporte();
		void cadastrarEsporte();
		void cadastrarAtleta(int q);
		void cadastrarPatrocinador(int q);
		void buscar();
};

esporte::esporte(int q){
	totalE= q;
	lEsportes= new esporte[totalE];
}

esporte::~esporte(){
	delete[] lEsportes;
	delete[] lAtletas;
	delete[] lPatrocinadores;
	
	totalE= 0, totalA= 0, totalP= 0;
}

void esporte::cadastrarEsporte(){
	for (int i=0; i < totalE; i++){
		cout << "ESPORTE" <<endl;
		cout << "Nome do Esporte: ";
		cin.ignore();
		getline(cin, lEsportes[i].nomeEsporte);
		cout << "Atv específica: ";
		cin >> lEsportes[i].atv;
		cout << "Data(DD.MM): ";
		cin >> lEsportes[i].data;
		cout << "Hora(HH:MM): ";
		cin >> lEsportes[i].hora;
		cout <<endl;
		
		cout << "Quantos atletas nesse esporte? ";
		cin >> totalA;
		lEsportes[i].cadastrarAtleta(totalA);

		cout << "Quantos patrocinadores nesse esporte? ";
		cin >> totalP;
		lEsportes[i].cadastrarPatrocinador(totalP);
	}
}

void esporte::cadastrarAtleta(int q){
	lAtletas= new atleta[q];
	
	for (int j=0; j < q; j++){
		cout << "ATLETA" <<endl;
		cout << "Nome: ";
		cin.ignore();
		getline(cin, lAtletas[j].nome);
		cout << "Altura: ";
		cin >> lAtletas[j].altura;
		cout << "Peso: ";
		cin >> lAtletas[j].peso;
		cout << "Nacionalidade: ";
		cin >> lAtletas[j].nacionalidade;
		cout << "Data de nascimento(DD.MM.AAAA): ";
		cin >> lAtletas[j].nascimento;
		cout <<endl;
	}
}

void esporte::cadastrarPatrocinador(int q){
	lPatrocinadores= new patrocinador[q];
	
	for (int k=0; k < q; k++){
		cout << "PATROCINADOR" <<endl;
		cout << "Nome: ";
		cin.ignore();
		getline(cin, lPatrocinadores[k].nome);
		cout << "Setor: ";
		cin >> lPatrocinadores[k].setor;
		cout << "País sede: ";
		cin >> lPatrocinadores[k].paisede;
		cout << "Valor investido: ";
		cin >> lPatrocinadores[k].investido;
		cout << "Início do contrato: ";
		cin >> lPatrocinadores[k].iContrato;
		cout << "Final do contrato: ";
		cin >> lPatrocinadores[k].fContrato;
		cout <<endl;
	}
}

void esporte::buscar(){
	string busca, repetir, procurar;
	int p;
	do{
	cout << "Deseja buscar 'Esporte','Atleta' ou 'Patrocinador'? ";
	cin >> busca;
	
	if (busca=="Esporte"){
		cout <<"Buscar qual Esporte? ";
		cin.ignore();
		getline(cin, procurar);
		
		p=-1;
		for (int i=0; i < totalE; i++){
			if (procurar == lEsportes[i].nomeEsporte){
				cout <<endl;
				cout << "ESPORTE" <<endl<<endl;
				cout << "Nome do Esporte: " << lEsportes[i].nomeEsporte <<endl;
				cout << "Atv específica: " << lEsportes[i].atv <<endl;
				cout << "Data e hora: " << lEsportes[i].data << " - "<< lEsportes[i].hora << "h"<<endl;
				cout <<endl;
				
				cout << "Atletas desse esporte: "<<endl;
				for (int j=0; j < totalA; j++){
					cout << lEsportes[i].lAtletas[j].nome <<endl;
				}
				cout <<endl;
				cout << "Patrocinadores desse esporte: "<<endl;
				for (int k=0; k < totalP; k++){
					cout << lEsportes[i].lPatrocinadores[k].nome <<endl;
				}
				cout <<endl;
				p=1;
			}
		}
		if (p==-1){
			cout << "Não econtrado!" <<endl;
		}
		
	} else if(busca=="Atleta"){
		cout << "Buscar qual Atleta? ";
		cin.ignore();
		getline(cin, procurar);
		
		p=-1;
		for (int i=0; i < totalE; i++){
			for (int j=0; j < totalA; j++){
				if(procurar == lEsportes[i].lAtletas[j].nome){
					cout <<endl;
					cout << "ATLETA: "<<endl;
					cout << "Nome: " << lEsportes[i].lAtletas[j].nome <<endl;
					cout << "Altura: " << lEsportes[i].lAtletas[j].altura <<endl;
					cout << "Peso: " << lEsportes[i].lAtletas[j].peso <<endl;
					cout << "Nacionalidade: " << lEsportes[i].lAtletas[j].nacionalidade <<endl;
					cout << "Data de nascimento: " << lEsportes[i].lAtletas[j].nascimento <<endl;
					cout << "Esporte: " << lEsportes[i].nomeEsporte <<endl;
					cout <<endl;
					p=1;
				}
			}
		}
		if (p==-1){
			cout << "Não econtrado!" <<endl;
		}
		
	} else if(busca=="Patrocinador"){
		cout << "Buscar qual Patrocinador? ";
		cin.ignore();
		getline(cin, procurar);
		
		p=-1;
		for (int i=0; i < totalE; i++){
			for (int k=0; k < totalP; k++){
				if (procurar == lEsportes[i].lPatrocinadores[k].nome){
					cout << endl;
					cout << "PATROCINADOR: "<<endl;
					cout << "Nome: " << lEsportes[i].lPatrocinadores[k].nome <<endl;
					cout << "Setor: " << lEsportes[i].lPatrocinadores[k].setor <<endl;
					cout << "País sede: " << lEsportes[i].lPatrocinadores[k].paisede <<endl;
					cout << "Valor investido: " << lEsportes[i].lPatrocinadores[k].investido <<endl;
					cout << "Início do contrato: " << lEsportes[i].lPatrocinadores[k].iContrato <<endl;
					cout << "Final do contrato: " << lEsportes[i].lPatrocinadores[k].fContrato <<endl;
					cout << "Esporte: " << lEsportes[i].nomeEsporte <<endl;
					cout <<endl;
				}
			}
		}
		if (p==-1){
			cout << "Não econtrado!" <<endl;
		}
		
	} else{
		cout << "Opção não encontrada!" <<endl;
	}
	
	cout << "Deseja procurar outra opção? [S] ou [N]: ";
	cin >> repetir;
	cout <<endl;
	}while(repetir == "S");
	
}
int main (){
	int qEsporte;
	
	cout << "Quantidade de Esportes: ";
	cin >> qEsporte;
	
	esporte *temp = new esporte(qEsporte);
	
	temp->cadastrarEsporte();
	temp->buscar();
	
	delete temp;
	temp= NULL;
	
	return 0;
}
