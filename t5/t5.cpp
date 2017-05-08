#include <iostream>
#include <vector>
#include <string>

#include <sstream>
#include <fstream>

#include <algorithm>

using namespace std;

class Jogador {

	private:

		string nome;
		int ponto;

	public:

		Jogador(string n, int p) {
			this->nome = n;
			this->ponto = p;
		}

		string getNome() {
			return this->nome;
		}

		int getPonto() {
			return this->ponto;
		}

		void addPonto(int ponto) {
			this->ponto += ponto;
		}

		string toString() {
			return "Nome: " + this->getNome() + 
					" -> Pontos: " + to_string(this->getPonto());
		}
};

bool compByPonto(Jogador* a, Jogador* b) {
    return a->getPonto() > b->getPonto();
}

class Atividade {

	private:

		string descricao;
		vector<Jogador*> jogadores;

	public:

		Atividade(string d) {
			this->descricao = d;
		}

		Atividade(string d, vector<Jogador*> j) {
			this->descricao = d;
			this->jogadores = j;
		}

		string getDescricao() {
			return this->descricao;
		}

		Jogador* getJogador(Jogador* n) {
			for(Jogador* j: this->jogadores) {
				if(j->getNome() == n->getNome())
					return j;
			}

			return nullptr;
		}

		Jogador* addJogador(Jogador* j) {
			if(!this->getJogador(j))
				this->jogadores.push_back(j);

			return this->getJogador(j);
		}

		string toString() {
			string infos;

			infos = "Atividade: " + this->getDescricao() + '\n';
			for(Jogador* j: this->jogadores) {
				infos += j->toString() + '\n';
			}

			return infos;
		}

		void ordenaPontosAtividade() {
			sort(this->jogadores.begin(), this->jogadores.end(), compByPonto);
		}
};

class Jogo {

	private:

		vector<Atividade*> atividades;
		vector<Jogador*> jogadoresTotal; //Armazena o Total de Pontos de todos os jogadores que participaram de ao menos uma atividade

	public:

		Jogo() { }

		Jogo(vector<Atividade*> a) {
			this->atividades = a;
		}

		Atividade* getAtividade(Atividade* a) {
			for(Atividade* at: this->atividades) {
				if(at->getDescricao() == a->getDescricao())
					return at;
			}

			return nullptr;
		}

		Jogador* getJogadorTotal(Jogador* jt) {
			for(Jogador* j : this->jogadoresTotal) {
				if(j->getNome() == jt->getNome())
					return j;
			}

			return nullptr;
		}

		Atividade* addAtividade(Atividade* a) {
			if(!this->getAtividade(a))
				this->atividades.push_back(a);

			return this->getAtividade(a); 
		}

		void addJogador(Atividade* a, Jogador* j) {
			Jogador* jAdd = this->getJogadorTotal(a->addJogador(j));
			if(!jAdd)
				this->jogadoresTotal.push_back(new Jogador(j->getNome(), j->getPonto()));
			else
				jAdd->addPonto(j->getPonto());
		}

		void ordenaPontos() {
			for(Atividade* at: this->atividades)
				at->ordenaPontosAtividade();

			sort(this->jogadoresTotal.begin(), this->jogadoresTotal.end(), compByPonto);
		}

		string toStringTotal() {
			string infos;

			infos = "Total de Pontos\n";
			for(Jogador* j: this->jogadoresTotal) {
				infos += j->toString() + '\n';
			}

			return infos;
		}

		string toStringAtividades() {
			string infos;

			for(Atividade* a: this->atividades) {
				infos += a->toString() + '\n';
			}

			return infos;
		}

};

int main() {

	ifstream arquivo("pontos.csv");

	string linha;
	string infos[3];

	Jogo j = Jogo();

	while(getline(arquivo, linha)) {
		stringstream linestream(linha);
		getline(linestream, infos[0], ',');
		getline(linestream, infos[1], ',');
		getline(linestream, infos[2], '\n');

		j.addJogador(j.addAtividade(new Atividade(infos[1])), new Jogador(infos[0], stoi(infos[2])));
	}

	j.ordenaPontos();

	cout << j.toStringAtividades() << endl;

	cout << j.toStringTotal() << endl;
	
	

	return 0;
}