#include <iostream>
#include <fstream>

using namespace std;

class Palavra {
	friend class ABB;
	private:
		string Plv;
		int nPosicoes;
		int* posicoes;
	public:
		Palavra();
		Palavra(string umaPalavra, int pos);
		void inserindoPos(int pos);
};

Palavra::Palavra(){
	nPosicoes= 0;
	posicoes= 0;
}

Palavra::Palavra(string umaPalavra, int pos){
	Plv= umaPalavra;
	nPosicoes= 1;
	posicoes= new int[nPosicoes];
	posicoes[0]= pos;
}

void Palavra::inserindoPos(int pos){
	nPosicoes++;
	int* antigo= posicoes;
	int* novo= new int[nPosicoes];
	
	for (int i=0; i < nPosicoes-1; i++){
		novo[i]= antigo[i];
	}
	
	posicoes= novo;
	delete[] antigo;
	posicoes[nPosicoes-1]= pos;
}

class noh {
	friend class ABB;
	private:
		Palavra dado;
		noh* nEsq;
		noh* nDir;
	public:
		noh(const Palavra& umaPalavra);
};

noh::noh(const Palavra& umaPalavra){
	nEsq= NULL;
	nDir= NULL;
	dado= umaPalavra;
}

class ABB {
	private:
		noh* raiz;
		void destroir(noh* raiz);
		noh* insereAux(noh* umNoh, const Palavra& umaPalavra);
		noh* buscaAux(string umaPalavra);
	public:
		ABB();
		~ABB();
		void lendoArquivo();
		void inserir(const Palavra& umaPalavra);
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
		destroir(umNoh->nEsq);
		destroir(umNoh->nDir);
		delete umNoh;
	}
}

void ABB::lendoArquivo() {
	ifstream arquivo("entrada.txt");
	string lendoPalavra;
	noh* aux;
	int i=0;
	
	while (arquivo >> lendoPalavra){
		i++;
		aux= buscaAux(lendoPalavra);
		if (aux == NULL){
			Palavra novo(lendoPalavra, i);
			inserir(novo);
		} else {
			aux->dado.inserindoPos(i);
		}
	}
}

void ABB::inserir(const Palavra& umaPalavra){
	raiz= insereAux(raiz, umaPalavra);
}

noh* ABB::insereAux(noh* umNoh, const Palavra& umaPalavra){
	if (umNoh == NULL){
		noh* novo= new noh(umaPalavra);
		return novo;
	} else {
		if (umaPalavra.Plv < umNoh->dado.Plv){
			umNoh->nEsq= insereAux(umNoh->nEsq, umaPalavra);
		} else {
			umNoh->nDir= insereAux(umNoh->nDir, umaPalavra);
		}
	}
	return umNoh;
}

void ABB::busca(string umaPalavra){
	noh* nohComValor= buscaAux(umaPalavra);
	
	if (nohComValor == NULL){
		cout << "-1" << endl;
	} else {
		for (int i=0; i < nohComValor->dado.nPosicoes; i++){
			cout << nohComValor->dado.posicoes[i] <<" ";
		}
		cout << endl;
	}
}

noh* ABB::buscaAux(string umaPalavra){
	noh* atual= raiz;
	
	while (atual != NULL){
		if (atual->dado.Plv == umaPalavra){
			return atual;
		} else if (atual->dado.Plv > umaPalavra){
			atual= atual->nEsq;
		} else {
			atual= atual->nDir;
		}
	}
	return atual;
}

int main () {
	ABB arvore;
	string buscar;
	
	arvore.lendoArquivo();
	
	cin >> buscar;
	arvore.busca(buscar);
	
	return 0;
}
