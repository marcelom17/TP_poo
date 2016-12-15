#pragma once

#include "Util.h"
#include "Consola.h"
#include "Planicie.h"
#include "Posicao.h"

class Jogo {
	Consola c;
	int instancia=0;
	int linha_f, coluna_f;
	vector <Planicie> vec_mapa;  // ?? nao sei por causa da planicie

public:
	void Inicia_jogo();
	int avanca_instancia(int n);
	void desenha_tabuleiro();
	bool comandos_configurar(string comando);
	bool comandos_jogo(string comando);
	void limpa_consola(Consola & consola, int cor, bool flag);
	string upper(string palavra);
	void proximaInstancia(int n);
	void msgErro(string msg);

	void criar_mapa(int linhas, int colunas);
	void imprimeZona(int x, int y, int px, int py, int col);
	bool verifica_dim(int x);

// comandos de configuracao
	void dimensao(vector<string>comandos);
	void moedas(vector<string>comandos);
	void oponentes(vector<string>comandos);
	void castelo(vector<string>comandos);
	void mkperfil(vector<string>comandos);
	void addperfil(vector<string>comandos);
	void subperfil(vector<string>comandos);
	void rmperfil(vector<string>comandos);
	void load(vector<string>comandos);
	void inicio();
};