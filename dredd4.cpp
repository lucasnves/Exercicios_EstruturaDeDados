#include <iostream>
using namespace std;
struct funcionario {
	int identificador;
	float horas_trabalhadas;
	float valor_hora;
	float salario;
};
int particiona(funcionario dados[], int A, int B){
	int i=A+1, j=B;
	float pivo = dados[A].salario;
	while (i <= j){
		if (dados[i].salario <= pivo){
			i++;
		} else if (pivo <= dados[j].salario){
			j--;
		} else {
			swap (dados[i], dados[j]);
			i++;
			j--;
		}
	}
	swap (dados[A], dados[j]);
	return j;
}
void quicksort(funcionario dados[], int pos_pivo, int B){
	if (pos_pivo < B){
		int novo_pivo= particiona(dados, pos_pivo, B);
		quicksort(dados, pos_pivo, novo_pivo-1);
		quicksort(dados, novo_pivo+1, B);
	}
}
void leitura (funcionario v[], int n) {
	for (int i=0; i<n; i++) {
		cin >> v[i].identificador >> v[i].horas_trabalhadas >> v[i].valor_hora;
		v[i].salario = v[i].horas_trabalhadas * v[i].valor_hora;
	}
}
void saida (funcionario v[], int limite){
	for (int i=0; i<limite; i++){
		cout << v[i].identificador << " " << v[i].salario << endl;
	}
}
int main () {
	int qtd_funcionario;
	cin >> qtd_funcionario;
	funcionario vetor[qtd_funcionario];
	leitura (vetor, qtd_funcionario);
	quicksort(vetor, 0, qtd_funcionario - 1);
	saida(vetor, qtd_funcionario);
	return 0;
}
