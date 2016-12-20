#include "Jogo.h"


Jogo::Jogo(){
	blin = 0;
	bcol = 0;
	system("chcp 1252 >NUL:");
	c.setScreenSize(50, 90);						// Tamanho 'lógico' da consola em linhas x colunas de carateres: o tamanho em pixels depende do tamanho das fontes

	cor_fundo = c.VERDE;		// Cor de fundo da consola
	cor_texto = c.PRETO;	// Cor por omissão do texto e elementos gráficos

	c.setBackgroundColor(cor_fundo);// Define a cor de fundo
	c.setTextColor(cor_texto);		// Define a cor dos carateres

	c.clrscr();
}

void Jogo::Inicia_jogo(){
	//limpar o ecra
	desenha_tabuleiro();
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
		c.gotoxy(0, 45);
		c.setBackgroundColor(c.BRANCO);
		c.setTextColor(c.PRETO);
		cout << "Comando: ";
		for (unsigned int i = 1; i < 117; i++)
			cout << " ";
		limpa_consola(c, 0, 0);
		c.setTextColor(c.PRETO);
		c.gotoxy(9, 45);
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

	if (cmd_aux == "OPONENTES") {
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

void Jogo::msgErro(string msg){
	cout << "erro";
}

void Jogo::criar_mapa(int linhas, int colunas){
	for (int i = 0; i < linhas; i++) {
		//vector<Celula *>col;
			mapa.push_back();
		for (int j = 0; j < colunas; j++) {
			col.at(j)->setColor(c.PRETO);
		}
	}

}

void Jogo::imprimeFoco(int anchorL, int anchorC){
	c.clrscr();
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 40; j++) {
			c.gotoxy(anchorL + i, anchorC + j);
			cout << "L";
		}
	}
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
		//if (mapa.size() == 0) {
			int l = atoi(comandos[1].c_str());
			int c = atoi(comandos[2].c_str());
			if (verifica_dim(c) && verifica_dim(l))//se DIMENSOES ESTAO NO LIMITE
			{
				this->coluna_f = c;
				this->linha_f = l;
				//criar_mapa(l, c);
			}
			else
			{
				string msg = "Dimensoes fora do limite [9,1000]";
				msgErro(msg);
			}
		}

//	}

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
	criar_mapa(linha_f,coluna_f);
	cout << "criou";
	imprimeFoco(10, 10);
}
