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

		jogar = testa_jogada(comando);
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
	}

	if (cmd_aux == "MOEDAS") {

	}

	if (cmd_aux == "OPONETES") {

	}

	if (cmd_aux == "CASTELO") {

	}

	if (cmd_aux == "MKPERFIL") {

	}

	if (cmd_aux == "ADDPERFIL") {

	}

	if (cmd_aux == "SUBPERFIL") {

	}

	if (cmd_aux == "RMPERFIL") {

	}

	if (cmd_aux == "LOAD") {

	}

	if (cmd_aux == "INICIO") {

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

void Jogo::proximaInstancia(int n){
	for (int i = 0; i < n; i++) {
		//falta os movimentos dos seres

		instancia++;
	}
}
