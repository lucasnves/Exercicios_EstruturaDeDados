#include <iostream>

using namespace std;

class noh{
	friend class Hash;
	private:
		int chave;
		int valor;
		int colidiu;
	public:
		noh();
};

noh::noh(){
	chave= 0;
	valor= 0;
	colidiu= 0;
}
class Hash{
	private:
		noh* elemento;
		int capacidade;
	public:
		Hash(int cap);
		~Hash();
		int calculaHash(int valor);
		void inserir(int valor);
		void remover(int valor);
		int pertinencia(int valor);
		void percorre();
};

Hash::Hash(int cap){
	elemento= new noh[cap];
	capacidade= cap;
	for (int i=0; i < cap; i++){
		elemento[i].chave= -1;
		elemento[i].valor= -1;
		elemento[i].colidiu= -1;
	}
}

Hash::~Hash(){
	for (int i=0; i < capacidade; i++){
		if (elemento[i].chave != -1){
			elemento[i].chave= -1;
			elemento[i].valor= -1;
			elemento[i].colidiu= -1;
		}
	}
	delete[] elemento;
}

int Hash::calculaHash(int valor){
	return valor%capacidade;
}

void Hash::inserir(int valor){
	int posicao= calculaHash(valor);
	int o=0;
	if (pertinencia(valor)==-1){
		if (elemento[posicao].chave== -1){
			elemento[posicao].chave= posicao;
			elemento[posicao].valor= valor;
		} else {
			while (posicao < capacidade and o==0){
				if (elemento[posicao].chave== -1){
					elemento[posicao].valor= valor;
					elemento[posicao].chave= posicao;
					elemento[posicao].colidiu= calculaHash(valor);
					o=1;
				}
				posicao++;
			}
		}
	}
}

void Hash::remover(int valor){
	int posicao= calculaHash(valor);
	while (elemento[posicao].chave != -1){
		if (elemento[posicao].valor == valor){
			elemento[posicao].chave= -1;
			elemento[posicao].valor= -1;
		}
		posicao++;
	}
	for (int i=0; i < capacidade; i++){
		if (elemento[i].chave != -1 and elemento[i].colidiu != -1){
			int p= elemento[i].colidiu;
			if (elemento[p].chave == -1){
				elemento[p].valor= elemento[i].valor;
				elemento[p].chave= p;
				elemento[p].colidiu= -1;
				
				elemento[i].valor= -1;
				elemento[i].chave= -1;
				elemento[i].colidiu= -1;
			} else {
				while (p < elemento[i].chave){
					if (elemento[p].chave == -1){
						elemento[p].valor= elemento[i].valor;
						elemento[p].chave= p;
						elemento[p].colidiu= -1;
						
						elemento[i].valor= -1;
						elemento[i].chave= -1;
						elemento[i].colidiu= -1;
					}
					p++;
				}
			}
		}
	}
}

int Hash::pertinencia(int valor){
	int posicao= calculaHash(valor);
	while (elemento[posicao].chave != -1){
		if (elemento[posicao].valor == valor){
			return 1;
		}
		posicao++;
	}
	return -1;
}

void Hash::percorre(){
	for (int i= 0; i < capacidade; i++){
		if (elemento[i].chave != -1){
			cout << elemento[i].valor <<" ";
		}
	}
	cout <<endl; 
}
int main (){
	Hash th(101);
	int p;
	for (int i=0; i < 10; i++){
		cin >> p;
		th.inserir(p);
	}
	for (int i=0; i < 3; i++){
		cin >> p;
		th.remover(p);
	}
	for (int i=0; i < 2; i++){
		cin >> p;
		cout << th.pertinencia(p) <<endl;
	}
	th.percorre();
	for (int i=0; i < 3; i++){
		cin >> p;
		th.inserir(p);
	}
	th.percorre();
	return 0;
}
