#include <iostream>

using namespace std;

class no{
	friend class pilha;
	private:
		int nValor;
		no* nProximo;
	public:
		no(int valor);
};

no::no(int valor){
	nValor= valor;
	nProximo= NULL;
}

class pilha{
	private:
		no* pTopo;
		int pTamanho;
		no* pTopoaux;
	public:
		pilha();
		~pilha();
		void empilha(int valor);
		void ordenar();
		int desempilha();
		bool vazia();
};

pilha::pilha (){
	pTopo= NULL;
	pTopoaux= NULL;
	pTamanho= 0;
}

pilha::~pilha (){
	while (pTamanho > 0){
		desempilha();
	}
}

bool pilha::vazia(){
	return (pTamanho==0);
}

void pilha::empilha(int valor){
	while (pTopo != NULL and valor > pTopo->nValor){
		ordenar();
	}
	no* novo= new no(valor);
	novo->nProximo= pTopo;
	pTopo= novo;
	pTamanho++;
	
	while (pTopoaux != NULL){
		no* auxx= pTopo;
		pTopo= pTopoaux;
		pTopoaux= pTopoaux->nProximo;
		pTopo->nProximo= auxx;
	}
}

void pilha::ordenar(){
	no* aux= pTopoaux;
	pTopoaux= pTopo;
	pTopo= pTopo->nProximo;
	pTopoaux->nProximo= aux;
}

int pilha::desempilha(){
	int valor= pTopo->nValor;
	no* aux= pTopo;
	pTopo= pTopo->nProximo;
	delete aux;
	pTamanho--;
	return valor;
}

int main (){
	pilha p1;
	
	int tam, num;
	cin >> tam;
	
	for (int i=0; i < tam; i++){
		cin >> num;
		p1.empilha(num);
	}
	
	while (not p1.vazia()){
		cout << p1.desempilha() << " ";
	}
	cout <<endl;
	
	return 0;
}
