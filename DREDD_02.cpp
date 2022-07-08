#include <iostream>

using namespace std;

class noh {
	friend class deque;
	private:
		noh* nProximo;
		noh* nAnterior;
		string nLinha;
	public:
		noh(string linha);
};

noh::noh(string linha){
	nProximo= NULL;
	nAnterior= NULL;
	nLinha= linha;
}

class deque{
	private:
		noh* dPrimeiro;
		noh* dUltimo;
		int dTamanho;
	public:
		deque();
		~deque();
		void Inserir(string linha);
		void RemoverFinal();
		void RemoverInicio();
};

deque::deque(){
	dPrimeiro= NULL;
	dUltimo= NULL;
	dTamanho= 0;
}

deque::~deque() {
	noh* aux= dPrimeiro;
	while (aux != NULL){
		noh* aux2= aux;
		aux= aux->nProximo;
		delete aux2;
	}
	dPrimeiro= NULL;
	dUltimo= NULL;
	dTamanho= 0;
}

void deque::Inserir (string linha){
	noh* novo= new noh(linha);
	if(dPrimeiro == NULL){
		dPrimeiro= novo;
		dUltimo= novo;
	} else {
		novo->nAnterior= dUltimo;
		dUltimo->nProximo= novo;
		dUltimo= novo;
	}
	dTamanho++;
}

void deque::RemoverFinal(){
	noh* aux= dUltimo;
	
	if (dTamanho > 0){
		cout << "desfazer: "<< dUltimo->nLinha <<endl;
		if(aux == dPrimeiro) {
			dPrimeiro = NULL;
			dUltimo = NULL;
		} else {
			dUltimo = aux->nAnterior;
			dUltimo->nProximo = NULL;
		}
		delete aux;
		dTamanho--;
	} else {
		cout << "ERRO" <<endl;
	}
}

void deque::RemoverInicio(){
	noh* aux= dPrimeiro;
	
	cout << "esqueci: "<< dPrimeiro->nLinha <<endl;
	if(aux == dUltimo) {
		dPrimeiro = NULL;
		dUltimo = NULL;
	} else {
		dPrimeiro = aux->nProximo;
		dPrimeiro->nAnterior = NULL;
	}
	delete aux;
	dTamanho--;
}

int main() {
	deque lista;
	
	int quantidade;
	cin >> quantidade;
	
	int i=0;
	
	string linha;
	getline(cin, linha);
	
	do {
		getline(cin, linha);
		if (linha == "undo"){
			lista.RemoverFinal();
			i--;
			if (i<0){
				i=0;
			}
		} else if (linha != "sair"){
			if (i == quantidade){
				lista.RemoverInicio();
				i--;
			}
			lista.Inserir(linha);
			i++;
		}
	} while (linha != "sair");
	
	return 0;
}
