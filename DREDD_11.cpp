#include <iostream>

using namespace std;

struct processos{
		int codigo;
		int prioridade;
};

class Heap{
	private:
		processos* heap;
		int capacidade;
		int tamanho;
		void arruma();
		void ArrumaDescendo(int i);
		void ArrumaSubindo(int i);
		inline int Pai(int i);
		inline int Esquerdo(int i);
		inline int Direito(int i);
	public:
		Heap(int cap);
		~Heap();
		void Inserir(processos& proc);
		processos Retirar();

};

Heap::Heap(int cap){
	capacidade= cap;
	heap= new processos[cap];
	tamanho= 0;
}

Heap::~Heap(){
	delete[] heap;
}

void Heap::arruma(){
	for (int i=(tamanho/2-1); i >= 0; i--){
		ArrumaDescendo(i);
	}
}

void Heap::ArrumaDescendo(int i){
	int esq= Esquerdo(i);
	int dir= Direito(i);
	int maior= i;
	
	if (esq < tamanho and (heap[esq].prioridade > heap[maior].prioridade)){
		maior= esq;
	}
	if (dir < tamanho and (heap[dir].prioridade > heap[maior].prioridade)){
		maior= dir;
	}
	if (maior != i){
		swap(heap[i], heap[maior]);
		ArrumaDescendo(maior);
	}
}

void Heap::ArrumaSubindo(int i){
	int p= Pai(i);
	if (heap[i].prioridade > heap[p].prioridade){
		swap(heap[i], heap[p]);
		ArrumaSubindo(p);
	}
}

int Heap::Pai(int i){
	return (i-1)/2;
}

int Heap::Esquerdo(int i){
	return 2*i+1;
}

int Heap::Direito(int i){
	return 2*i+2;
}

processos Heap::Retirar(){
	if (tamanho==0){
		return processos();
	}
	processos aux= heap[0];
	swap(heap[0], heap[tamanho-1]);
	tamanho--;
	ArrumaDescendo(0);
	return aux;
}

void Heap::Inserir(processos& proc){
	if (tamanho==capacidade){
		return;
	}
	heap[tamanho]= proc;
	ArrumaSubindo(tamanho);
	tamanho++;
}

int main(){
	unsigned capacidade;
	cin >> capacidade;
	
	Heap heap(capacidade);
	processos proc;
	
	char comando;
	
	do {
		cin >> comando;
		switch (comando) {
			case 'i':
				cin >> proc.codigo >> proc.prioridade;
				heap.Inserir(proc);
				break;
			case 'o':
			proc= heap.Retirar();
			if (proc.codigo != 0 and proc.prioridade != 0){
				cout << proc.codigo << ' ' << proc.prioridade <<endl;
			} else {
				cout << "Nao encontrado" <<endl;
			}
				break;
			case 's':
				break;
		}
	} while (comando != 's');
	
	return 0;
}
