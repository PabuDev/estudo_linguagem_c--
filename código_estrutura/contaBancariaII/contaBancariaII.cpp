/*
Simulação de uma conta bancária

Criar uma struct Conta com número, titular e saldo. Implementar funções 
depositar() e sacar(), recebendo a conta por referência quando necessário.

*/
#include <iostream>
#include <string>

using namespace std;

//Estrutura Conta
struct Conta{
    int numero;
    string titular;
    float saldo = 50000.00;
};

//Inicialização das funções do código
void menu();
void sacar(Conta &cp1);
void dpositar(Conta &p1);

//Bloco pŕincipal do código
int main(){
    Conta p1; //Variável do tipo Conta
    int opcao;

    cout << " ----- Conta ------ " << endl;
    cout << "Saldo: " << p1.saldo << endl;
    
    //Loop para interagir com as funções
    do{
        menu();
        cin >> opcao;

        switch(opcao){
            case 1:
                sacar(p1);
                break;
            case 2:
                depositar(p1);
                break;
            case 3:
                cout << "Saindo da conta bancaria..." << endl;
                break;
            default:
                cout << "Opcao invalida..." << endl;
        
        }
    }while(opcao != 3); //Ficará no loop até que digite o número 3


    return 0;
}

void menu(){
    cout << " ----- MENU ------ " << endl;
    cout << "1 - Sacar" << endl << 
            "2 - Depositar" << endl << 
            "3 - Sair" << endl << 
            "Esolha um das opções: ";
}


//Função para Sacar
void sacar(Conta &p1){
    int valorSaque;

    cout << endl << "Digite o valor de saque: " << endl;
    cin >> valorSaque;

    if(valorSaque > p1.saldo){
        cout << "[ERRO]: Valor maior que saldo em conta..." << endl;
    } else if(valorSaque <= 0){
        cout << "[ERRO]: valor invalido para saque..." << endl;
    } else {
        p1.saldo -= valorSaque;
        cout << "Saque realizado com sucesso!" << endl;
        cout << "O novo saldo em conta e: R$ " << p1.saldo << endl;
    }
    
}

//Função para Depositar
void depositar(Conta &p1){
    int valorDeposito;

    cout << endl << "Digite o valor para depositar: " << endl;
    cin >> valorDeposito;

    if(valorDeposito <= 0){
        cout << "[ERRO]: Valor invalido para deposito..." << endl;
    } else {
        p1.saldo += valorDeposito;
        cout << "Deposito realizado com sucesso!" << endl;
        cout << "Saldo em conta e: R$ " << p1.saldo << endl;
    }
}