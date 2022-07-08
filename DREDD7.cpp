#include <iostream>
#include <fstream>

using namespace std;

class noh {
	friend class ABB;
	private:
		noh* d;
		noh* esq;
		noh* dir;
		string nome;
		int numPosicoes;
		int* posicoes;
	public:
		noh(noh* umaPalavra);
		noh(string Nome, int pos);
		void inserePos(int pos);
};

noh::noh(string Nome, int pos){
	nome= Nome;
	numPosicoes= 1;
	posicoes= new int[numPosicoes];
	posicoes[0]= pos;
}

noh::noh(noh* umaPalavra){
	esq= NULL;
	dir= NULL;
	d= umaPalavra;
	numPosicoes= 0;
	posicoes= 0;
}

void noh::inserePos(int pos){
	cout <<"entro"<<endl;
	numPosicoes++;
	int* antigo= posicoes;
	int* novo= new int[numPosicoes];
	
	for (int i=0; i < numPosicoes-1; i++){
		novo[i]= antigo[i];
	}
	
	posicoes= novo;
	delete[] antigo;
	posicoes[numPosicoes-1]= pos;
}

class ABB {
	private:
		noh* raiz;
		void destroir(noh* raiz);
		noh* insereAux(noh* umNoh, noh umaPalavra);
		noh* buscaAux(string umaPalavra);
	public:
		ABB();
		~ABB();
		void lerArquivo();
		void inserir(noh umaPalavra);
		void busca(string umaPalavra);
};

ABB::ABB(){
	raiz= NULL;
}

ABB::~ABB(){
	destroir(raiz);
}

void ABB::destroir(noh* umNoh){
	if (umNoh != NULL) {
		destroir(umNoh->esq);
		destroir(umNoh->dir);
		delete umNoh;
	}
}

void ABB::lerArquivo() {
	ifstream arquivo("entrada.txt");
	string Palavras;
	noh* aux;
	int pos= 0;
	
	while (arquivo >> Palavras){
		pos++;
		aux= buscaAux(Palavras);
		if (aux == NULL){
			noh novo(Palavras, pos);
			inserir(novo);
		} else {
			aux->d->inserePos(pos);
		}
	}
}

void ABB::inserir(noh umaPalavra){
	raiz= insereAux(raiz, umaPalavra);
}

noh* ABB::insereAux(noh* umNoh, noh umaPalavra){
	if (umNoh == NULL){
		noh* novo= new noh(umaPalavra);
		return novo;
	} else {
		if (umaPalavra.nome < umNoh->d->nome){
			umNoh->esq= insereAux(umNoh->esq, umaPalavra);
		} else {
			umNoh->dir= insereAux(umNoh->dir, umaPalavra);
		}
	}
	return umNoh;
}

noh* ABB::buscaAux(string umaPalavra){
	noh* atual= raiz;
	while (atual != NULL){
		if (atual->d->nome == umaPalavra){
			return atual;
		} else if (atual->d->nome > umaPalavra){
			atual= atual->esq;
		} else {
			atual= atual->dir;
		}
	}
	return atual;
}

void ABB::busca(string umaPalavra){
	noh* nohComValor= buscaAux(umaPalavra);
	
	if (nohComValor == NULL){
		cout << "-1" << endl;
	} else {
		for (int i=0; i < nohComValor->d->numPosicoes; i++){
			cout << nohComValor->d->posicoes[i] <<" ";
		}
		cout << endl;
	}
}

int main () {
	ABB arvore;
	string buscar;
	
	arvore.lerArquivo();
	
	cin >> buscar;
	arvore.busca(buscar);
	return 0;
}
