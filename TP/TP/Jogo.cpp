#include "Jogo.h"


void Jogo::Inicia_jogo(){
	//limpar o ecra

	//usar consola para mostrar as coisas

}

int Jogo::avanca_instancia(int n){
	//avançar a instancia, podemos fazer tudo de uma vez, ou tem de ser um ciclo, para avançar uma a uma por causa do cpu fazer jogada uma a uma ?
	instancia += n;
	return instancia;
	//ou em ciclo

}

void Jogo::desenha_tabuleiro(){
	string comando;
	bool jogar = true;
	
	while (jogar) {
		c.gotoxy(0,44);
		c.setBackgroundColor(c.PRETO);
		c.gotoxy(0, 45);
		c.setBackgroundColor(c.BRANCO);
		c.setTextColor(c.PRETO);
		cout << "Comando: ";
		for (unsigned int i = 1; i < 110; i++)
			cout << " ";
		//Sleep(1500);
		limpa_consola(c, 0, 0);
		c.setTextColor(c.BRANCO_CLARO);
		c.gotoxy(16, 45);
		getline(cin, comando);


		if (comando == "")
			comando = "NEXT";

		jogar = comandos_configurar(comando);
	}


}

void Jogo::limpa_consola(Consola & consola, int cor, bool flag){
	if (!flag)	// Pinta a área da prompt com a cor de fundo da consola
	{
		consola.gotoxy(8, 50);
		cout << "                                                                           ";
		consola.gotoxy(0, 51);
		cout << "                                                                                ";
		consola.gotoxy(0, 52);
		cout << "                                                                                ";

	}
	else			// Pinta a área da prompt com a cor da fação que está a jogar
	{
		consola.setBackgroundColor(cor);
		consola.gotoxy(8, 36);
	}
}

bool Jogo::comandos_configurar(string comando)
{
	string buffer;
	stringstream cmd(comando);	// insere o comando numa stream
	vector <string> comandos;	// cria um vetor onde serao armazenados as palavras isuladas

	while (cmd >> buffer)		// Enquanto houver comandos para ler vai armazenando no vetor ( FAZ O PARSE DO COMANDO)
		comandos.push_back(buffer);

	string cmd_aux = upper(comandos[0]);

	if (cmd_aux == "SAIR") {
		exit(0);
	}
//por no comandos_jogo
/*	if (cmd_aux == "NEXT") {
		if (comandos.size() == 2)
			proximaInstancia(atoi(comandos[1].c_str()));
		else
			proximaInstancia(1);
		return true;
	}
	*/
	if (cmd_aux == "DIM") {
		dimensao(comandos);
		return true;
	}

	if (cmd_aux == "MOEDAS") {
		moedas(comandos);
		return true;
	}

	if (cmd_aux == "OPONETES") {
		oponentes(comandos);
		return true;
	}

	if (cmd_aux == "CASTELO") {
		castelo(comandos);
		return true;
	}

	if (cmd_aux == "MKPERFIL") {
		mkperfil(comandos);
		return true;
	}

	if (cmd_aux == "ADDPERFIL") {
		addperfil(comandos);
		return true;
	}

	if (cmd_aux == "SUBPERFIL") {
		subperfil(comandos);
		return true;
	}

	if (cmd_aux == "RMPERFIL") {
		rmperfil(comandos);
		return true;
	}

	if (cmd_aux == "LOAD") {
		load(comandos);
		return true;
	}

	if (cmd_aux == "INICIO") {
		inicio();
		return true;
	}

	return false;
}

string Jogo::upper(string palavra)
{
	for (unsigned int i = 0; i < palavra.size(); i++)
	{
		if (palavra.at(i) >= 'a' && palavra.at(i) <= 'z')
			palavra.at(i) -= 32;
	}
	return palavra;
}

void Jogo::proximaInstancia(int n){  //e para o next
	for (int i = 0; i < n; i++) {
		//falta os movimentos dos seres

		instancia++;
	}
}

void Jogo::criar_mapa(int linhas, int colunas){
	int x = 10, y = 5;
	int i = 0, j = 0, k = 0 ,size = 0;
	string num;	
	c.gotoxy(x, y);
	c.setBackgroundColor(c.AMARELO_CLARO);
	c.setTextColor(c.PRETO);
//rebordo
	for (k = 0; k < colunas; k++) {
		num = to_string(k);
		size = num.size();

		switch (size){	
		case 1:
			cout << " " << k << " ";
			break;
		case 2:
			cout << " " << k;
			break;
		case 3:
			cout << k;
			break;
		}
	}
	y++;

	for (i = 0; i < linhas; i++)
	{
		x = x - 3;
		c.gotoxy(x, y);
		c.setBackgroundColor(c.AMARELO_CLARO);
		c.setTextColor(c.PRETO);
		cout << "   ";
		y++;
		c.gotoxy(x, y);

		cout << i;
		if (i < 100) {
			if (i < 10)
				cout << "  ";
			else
				cout << " ";
		}

		y++;
		c.gotoxy(x, y);
		cout << "   ";
		y = y - 2;
		x = x + 3;
		c.gotoxy(x, y);

		for (j = 0; j < colunas; j++)
		{
			if (i % 2 == 0) {

				if (j % 2 == 0)

					c.setBackgroundColor(c.VERMELHO);

				else
					c.setBackgroundColor(c.BRANCO);

			}
			else
			{
				if (j % 2 != 0)
					c.setBackgroundColor(c.VERMELHO);
				else
					c.setBackgroundColor(c.BRANCO);
			}


			imprimeZona(x, y, i, j, colunas);

			x = x + 3;
			c.gotoxy(x, y);
		}
		x = 10;
		y = y + 3;
		c.gotoxy(x, y);

	}
}

void Jogo::imprimeZona(int x, int y, int px, int py, int col){
	c.gotoxy(x, y);
	int pos = col*px + py;
	vec_mapa[pos].imprime(x, y);
}

bool Jogo::verifica_dim(int x) {
	if (x > 9 && x < 1000)
		return true;
	else
		return false;

}

//funcoes de configuracao

void Jogo::dimensao(vector<string> comandos){
	if (comandos.size() != 3) {
		msgErro("numero de Argumentos errado (dim lin col)");
	}
	else {
		if (vec_mapa.size() == 0) {
			int l = atoi(comandos[1].c_str());
			int c = atoi(comandos[2].c_str());
			if (verifica_dim(c) && verifica_dim(l))//se DIMENSOES ESTAO NO LIMITE
			{
				this->coluna_f = c;
				this->linha_f = l;
				for (int i = 0; i < l; i++)
				{
					for (int j = 0; j < c; j++)
					{
						vec_mapa.push_back(Planicie(Posicao(i, j, transformaBiToUni(j, i))));
					}
				}
				criar_mapa(l, c);
			}
			else
			{
				string msg = "Dimensoes fora do limite [9,1000]";
				msgErro(msg);
			}
		}
		else {
			msgErro("Jogo ja criado");
		}
	}

}

void Jogo::moedas(vector<string> comandos){

}

void Jogo::oponentes(vector<string> comandos){

}

void Jogo::castelo(vector<string> comandos){

}

void Jogo::mkperfil(vector<string> comandos){

}

void Jogo::addperfil(vector<string> comandos){

}

void Jogo::subperfil(vector<string> comandos){

}

void Jogo::rmperfil(vector<string> comandos){

}

void Jogo::load(vector<string> comandos){

}

void Jogo::inicio(){

}
