#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Agenda{ 
	string nome;
	string telefone;
	string empresa;
}; // Estrutura que compões a agenda

Agenda *vetAgenda = new Agenda[10]; // Estanciamento da Struct dentro de um ponteiro vetor de 10 posições
static int pos = 0;  // Variavel global

/*Prototipos das funções e procedimentos*/
void menu(Agenda *vetAgenda);
Agenda cadastrar(Agenda *vetAgenda);
void imprime(Agenda *vetAgenda);
void consultar(Agenda *vetAgenda);
void alterar(Agenda *vetAgenda);
void deletar(Agenda *vetAgenda);

/*Função principal do programa*/
int main(){		
	menu(vetAgenda);
}

/*Realiza o cadastro na agenda / Atribui valores as variáveis da Struct Agenda*/
Agenda cadastrar(Agenda *vetAgenda){
	int quant;
	
	cout << "Quanto contatos voce quer cadastrar: " << endl;
	cin >> quant;
	
	system("cls");
	if(pos < 10){
		for(int i = pos; i < quant; i++){
			cout << "Digite o seu nome: ";
			cin >> vetAgenda[i].nome;
			cout << "Digite o seu telefone: ";
			cin >> vetAgenda[i].telefone;
			cout << "Digite a sua empresa: ";
			cin >> vetAgenda[i].empresa;
			cout << endl;
			pos = i;
			cout << "Cadastro de " + vetAgenda[pos].nome + " realizado com sucesso na posicao " << pos << " da agenda!" << endl;
			cout << endl;
			system("pause");
			system("cls");	
		}	
	}else{
		cout << "\nNão há mais espaço. Agenda Lotada!" << endl;
	}
	return(*vetAgenda);
}

/*Imprimir na tela os dados da agenda*/
void imprime(Agenda *vetAgenda){
	system("cls");
	cout << "**AGENDA COMPLETA**" << endl;
	cout << endl;

	for(int i = 0; i <= pos; i++){		
		cout << "Posicao do contato: " << i << endl;
		cout << "Nome: " << vetAgenda[i].nome << endl;
		cout << "Telefone: " << vetAgenda[i].telefone << endl;
		cout << "Empresa: " << vetAgenda[i].empresa << endl;
		cout << endl;
	}	
}

/*Realiza consulta na agenda*/
void consultar(Agenda *vetAgenda){
	bool procura = false;
	string nomeConsultado;
	int posicao;

	system("cls");
	cout << "Nome do contato a ser consultado: ";  
	cin >> nomeConsultado;

  	for(int i = 0; i < 10; i++){
		if(nomeConsultado == vetAgenda[i].nome){
			procura = true;
			posicao = i;			
		}
	}
	if(procura){
		cout << "\nNome encontrado na posicao: " << posicao << endl;
		cout << endl;
		cout << ">>Dados do contato<<" << endl;
		cout << "NOME: " << vetAgenda[posicao].nome << endl;
		cout << "TELEFONE: " << vetAgenda[posicao].telefone << endl;
		cout << "EMPRESA: " << vetAgenda[posicao].empresa << endl;
		cout << endl;
	}else{
		cout << "\nContato nao encontrado!" << endl;
	}
	system("pause");
}

/*Procedimento que realiza alteração nos dados da agenda*/
void alterar(Agenda *vetAgenda){
	bool procura = false;
	string procuraN, novoN, novoT, novaE;
  	int posicao;
	char dado;

	cout << "Qual o nome do contato que sera alterado: ";
	cin >> procuraN;

	for(int i = 0; i <= 9; i++){
		if(procuraN == vetAgenda[i].nome){
			procura = true;
			posicao = i;
		}else{
		cout << "\nNome nao localizado!" << endl;
		}
	}

	if(procura){
		system("cls");
		cout << "Qual o dado que deseja alterar?" << endl;
		cout << "Digite 'n' para Nome / 't' para Telefone / 'e' para empresa" << endl;
		cin >> dado;
	}
	
	if(dado == 'n'){
		cout << "\nDigite o novo nome: ";
		cin >> novoN;
		vetAgenda[posicao].nome = novoN;
		cout << "\nNovo nome cadastrado foi " << novoN << "na posicao ";
		cout << posicao << " da Agenda." << endl;
	}else
		if(dado == 't'){
			cout << "\nDigite o novo telefone: ";
			cin >> novoT;
			vetAgenda[posicao].telefone = novoT;
			cout << "\nNovo telefone cadastrado foi " << novoT << "na posicao ";
			cout << posicao << " da Agenda." << endl;
		}else
			if(dado == 'e'){
				cout << "\nDigite a nova empresa: ";
				cin >> novaE;
				vetAgenda[posicao].empresa = novaE;
				cout << "\nNovo telefone cadastrado foi " << novaE << "na posicao ";
				cout << posicao << " da Agenda." << endl;
			}
	system("pause");
}

/*Procedimento que deleta um registro da agenda*/
void deletar(Agenda *vetAgenda){
	bool procura = false;
	int posRemove;
	string procurarNome;

	cout << "Qual o nome do contato a ser deletado?" << endl;
	cin >> procurarNome;

	for(int i = 0; i < 10; i++){
		if(procurarNome == vetAgenda[i].nome){
		procura = true;
		posRemove = i;
		}
	}

	if(procura){
		for(int i = posRemove; i < pos-1; i++){
			vetAgenda[posRemove].nome = vetAgenda[posRemove+1].nome;
			vetAgenda[posRemove].telefone = vetAgenda[posRemove+1].telefone;
			vetAgenda[posRemove].empresa = vetAgenda[posRemove+1].empresa;
		}
		cout << "\nO contato " << procurarNome << " foi deletado!" << endl;
	}else{
		cout << "\nContato nao localizado!" << endl;
	}	
	pos--;
	system("pause");
}

/*Procedimento que monta um menu de opções no console*/
void menu(Agenda *vetAgenda){	
	int opcao;
	
	do {
	  do{
	      	system("cls");
	      	cout << "\t+--------------------------------+\n";
	      	cout << "\t|          MENU PRINCIPAL        |\n";
	      	cout << "\t+--------------------------------+\n";
	     	cout << "1- Cadastrar" << endl;
	      	cout << "2- Consultar" << endl;
	      	cout << "3- Alterar" << endl;
	      	cout << "4- Deletar" << endl;
			cout << "5- Exibir Agenda" << endl;
	      	cout << "0- Sair" << endl;
	      
		   	cout << "\nInforme a opcao desejada: ";
		   	cin >> opcao;
		   	
			}while(opcao < 0 || opcao > 5);
		
		  	if(opcao == 1){
		  		system("cls");
		  		cadastrar(vetAgenda);
				system("pause");
			  	}
				else
				if(opcao == 2){
					system("cls");
					consultar(vetAgenda);
					}					
					else
					if(opcao == 3){
						system("cls");
						alterar(vetAgenda);
						}						
						else
						if(opcao == 4){
							system("cls");
							deletar(vetAgenda); 
							}
							else
							if(opcao == 5){
								system("cls");
								imprime(vetAgenda);
								system("pause");
								}
 	}while(opcao != 0);
}
