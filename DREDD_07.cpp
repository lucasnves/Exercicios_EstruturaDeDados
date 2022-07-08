#include <iostream>

using namespace std;

class no{
	friend class fila;
	private:
		string Valor;
		no* Proximo;
	public:
		no(string valor);
};

no::no(string valor){
	Valor= valor;
	Proximo= NULL;
}

class fila{
	private:
		no* Inicio;
		no* Fim;
		unsigned Tamanho;
	public:
		fila();
		~fila();
		bool vazia();
		void enfileira (string valor);
		string desenfileira();
};

fila::fila (){
	Inicio= NULL;
	Fim= NULL;
	Tamanho= 0;
}

fila::~fila (){
	while (Tamanho > 0){
		desenfileira();
	}
	delete Inicio;
	delete Fim;
}

bool fila::vazia(){
	return (Tamanho==0);
}

void fila::enfileira(string valor){
	no* novo= new no(valor);
	if (Tamanho==0){
		Inicio= novo;
	} else {
		Fim->Proximo= novo;
	}
	Fim= novo;
	Tamanho++;
}

string fila::desenfileira(){
	string valor= Inicio->Valor;
	no* aux= Inicio;
	Inicio= Inicio->Proximo;
	delete aux;
	Tamanho--;
	if (Tamanho==0){
		Fim= NULL;
	}
	return valor;
}

int main (){
	fila f1, f2;
	
	string opcao, nome;
	int i=0;
	
	do {
		cin >> opcao;
		if (opcao == "normal"){
			cin >> nome;
			f1.enfileira(nome);
		} else if (opcao == "prioridade"){
			cin >> nome;
			f2.enfileira(nome);
		} else if (opcao == "atender"){
			if (f1.vazia() and f2.vazia()){
				cout << "AGUARDE" <<endl;
			} else if ((i==3 or f2.vazia()) and not f1.vazia()){
				cout << f1.desenfileira() <<endl;
				i=0;
			} else if ((i < 3 or f1.vazia()) and not f2.vazia()){
				cout << f2.desenfileira() <<endl;
				i++;
			}
		}
	} while (opcao != "fim");
	
	return 0;
}
