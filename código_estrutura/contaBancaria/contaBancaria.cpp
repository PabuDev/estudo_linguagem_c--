/*
Simulando um Reajuste Salarial

Criar uma struct Funcionário com matrícula, nome, cargo e salário. Faça uma 
função que receba o funcionário por referência e aplique um percentual de 
reajuste.
*/

#include <iostream>
#include <string>

using namespace std;

struct Funcionario{
    string nome, cargo;
    float salario, reajusteSalario;
    int matricula;
};

void dadosFuncionario(Funcionario &f1);
void reajusteSalarioMais(Funcionario &f1);
void reajusteSalarioMenos(Funcionario &f1);
void exibirDadosFuncionario(Funcionario &f1); 
void menu();

int main(){
    Funcionario f1;
    int opcao;

    do{
        menu();
        cin >> opcao;
        switch(opcao){
            case 1:
                dadosFuncionario(f1);
                reajusteSalarioMais(f1);
                break;
            case 2:
                dadosFuncionario(f1);
                reajusteSalarioMenos(f1);
                break;
            case 3:
                exibirDadosFuncionario(f1);
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida..." << endl;
        }
    }while(opcao != 3);

    return 0;
}

//Funções

void menu(){
    cout << " ----------- Reajuste Salarial ----------- " << endl;
    cout << "1 - Aumento" << endl 
    << "2 - Diminuir" << endl 
    << "3 - Sair" << endl 
    << "Qual vai ser o reajuste? " << endl;
}

void dadosFuncionario(Funcionario &f1){
    cout << "Nome do Funcionario: ";
    cin >> f1.nome;
    cout << "Matricula: ";
    cin >> f1.matricula;
    cout << "Cargo: ";
    cin >> f1.cargo;
    cout << "Salario: ";
    cin >> f1.salario;

}

void exibirDadosFuncionario(Funcionario &f1){
    cout << " ------ DADOS FUNCIONARIO ------" << endl;
    cout << "Nome: " << f1.nome << endl;
    cout << "Matricula: " << f1.matricula << endl;
    cout << "Cargo: " << f1.cargo << endl;
    cout << "Salario antigo: " << f1.salario << endl;
    cout << "Salario pos Reajuste: " << f1.reajusteSalario << endl;
}

//Função para reajuste Salarial
void reajusteSalarioMais(Funcionario &f1){
    float reajuste = f1.salario * 0.02;
    f1.reajusteSalario = reajuste + f1.salario;
    cout << "Reajuste salario e R$ " << f1.salario << endl;
}

void reajusteSalarioMenos(Funcionario &f1){
    float reajuste = f1.salario * 0.02;
    f1.reajusteSalario = reajuste - f1.salario;
    cout << "Reajuste salario e R$ " << f1.salario << endl;
}