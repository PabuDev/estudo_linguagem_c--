#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>


using namespace std;

struct Turma{
    string nome, turma, status;
    char sexo;
    int idade, matricula;
    float nota1, nota2, media;
};

//Funções pre declaradas
void cadastrarAluno(vector<Turma> &turme);
void exibirBoletim(const vector<Turma> &turma);
void mediaAluno(vector<Turma> &turma);
void exibirAlunoMedia(const vector<Turma> &turma);
void alunoMaiorMedia(vector<Turma> &turma);
void consultarAluno(vector<Turma> &turma);
void alterarNota(vector<Turma> &turma); 
void ordenarBoletim(vector<Turma> &turma);

int main(){
    const int quantidadeAluno = 3;
    char continuar;

    /*
    cout << "Digite a quantidade de aluno da turma: ";

    cin >> quantidadeAluno;
    */

    vector<Turma> turma(quantidadeAluno);

    //Chamando a função para cadastrar os alunos
    cadastrarAluno(turma);
    mediaAluno(turma); //chama a função para calcular a média dos alunos
    ordenarBoletim(turma);
    
    //Chamando a função para exibir o Boletim dos alunos
    exibirBoletim(turma);
    //Chamando a função para exibit os Alunos acima da Média
    exibirAlunoMedia(turma);
    //Chamando a função para exibir o(a) aluno(a) com a maior média
    alunoMaiorMedia(turma);
    
    do{
        consultarAluno(turma);
    
        cout << "Deseja buscar outro aluno? (s/n): ";
        cin >> continuar;
    }while(continuar == 's' || continuar == 'S');
    exibirBoletim(turma);

    return 0;

}

//Função para Cadastrar os Alunos na Turma
void cadastrarAluno(vector<Turma> &turma){
    cout << " ----------------------------------------- " << endl;
    cout << " ------- CADASTRAR ALUNO NA TURMA ------- " << endl;
    cout << " ----------------------------------------- " << endl;
    for(size_t i = 0;  i < turma.size(); i++){
       
        cout << "Digite os dados do(a) alundo(a) " << 1 + i << endl;
        
        cout << "Digite a matricula do(a) aluno(a): ";
        cin >> turma[i].matricula;

        cout << "Nome do(a) aluno(a): ";
        cin >> turma[i].nome;

        cout << "Digite a idade do(a) aluno(a) " << turma[i].nome << ": ";
        cin >> turma[i].idade;

        cout << "Digite o sexo do(a) aluno(a) " << turma[i].nome << ": ";
        cin >> turma[i].sexo;

        cout << "Digite a turma: ";
        cin >> turma[i].turma;
        
        cout << "Digite a primeira nota: ";
        cin >> turma[i].nota1;

        cout << "Digite a segunda nota: ";
        cin >> turma[i].nota2;

        cout << " ---------------------------------- " << endl;
    }
}

//Função para Exibir os dados dos Aluno em tabela
void exibirBoletim(const vector<Turma> &turma){
    cout << " ----- BOLETIM DOS ALUNOS -------" << endl;
    cout << left << setw(15) << "Nome" << 
    setw (8) << "Idade" << 
    setw(8) << "Sexo" << 
    setw(8) << "Turma" << 
    setw(8) << "Nota 1" <<
    setw(8) << "Nota 2" <<
    setw(8) << "Media" <<
    setw(15) << "Status" << endl;

    for(size_t i = 0; i < turma.size(); i++){
        cout << left << setw (15) <<turma[i].nome <<
        setw(8) << turma[i].idade <<
        setw(8) << turma[i].sexo <<
        setw(8) << turma[i].turma << 
        setw(8) << turma[i].nota1 <<
        setw(8) << turma[i].nota2 <<
        setw(8) << turma[i].media <<
        setw(15) << turma[i].status << endl;
    }
    
}

//Função para calcular a média do aluno
void mediaAluno(vector<Turma> &turma){
    for(size_t i = 0; i < turma.size(); i++){
        turma[i].media = (turma[i].nota1 + turma[i].nota2) / 2;
        if(turma[i].media >= 7){
               turma[i].status = "Aprovado";
        }else{
            turma[i].status = "Reprovado";
        }
    }
}

//Função para calcular e exibir o(a) aluno(a) com a maior média
void alunoMaiorMedia(vector<Turma> &turma){
    float maiorMedia = 0;
    for(size_t i = 0; i < turma.size(); i++){
        if(turma[i].media > maiorMedia){
            maiorMedia = turma[i].media;
        }
    }
    cout << " ----- ALUNO(A) COM MAIOR MEDIA------" << endl;
    cout << "====================================" << endl;
    cout << left << setw(15) << "Nome" << 
    setw (8) << "Idade" << 
    setw(8) << "Sexo" << 
    setw(8) << "Turma" << 
    setw(8) << "Media" << endl;

    for(size_t i = 0; i < turma.size(); i++){
        if(turma[i].media == maiorMedia){
            cout << left << setw (15) <<turma[i].nome <<
            setw(8) << turma[i].idade <<
            setw(8) << turma[i].sexo <<
            setw(8) << turma[i].turma << 
            setw(8) << turma[i].media << endl;
        }
    }
}

//Função para exibir somente os dados dos alunos acima da média
void exibirAlunoMedia(const vector<Turma> &turma){
    cout << " ----- ALUNOS ACIMA DA MEDIA ------" << endl;
    cout << "====================================" << endl;
    cout << left << setw(15) << "Nome" << 
    setw (8) << "Idade" << 
    setw(8) << "Sexo" << 
    setw(8) << "Turma" << 
    setw(8) << "Nota 1" <<
    setw(8) << "Nota 2" <<
    setw(8) << "Media" <<
    setw(15) << "Status" << endl;
    for(size_t i = 0; i < turma.size(); i++){
        if(turma[i].media > 7){
            cout << left << setw (15) <<turma[i].nome <<
            setw(8) << turma[i].idade <<
            setw(8) << turma[i].sexo <<
            setw(8) << turma[i].turma << 
            setw(8) << turma[i].nota1 <<
            setw(8) << turma[i].nota2 <<
            setw(8) << turma[i].media <<
            setw(15) << turma[i].status << endl;
        }
    }
}

void consultarAluno(vector<Turma> &turma){
    int consultaMatricula;
    bool encontrado = false;
    char alterar;
    int op;

    cout << "Digite o numero da matricula: ";
    cin >> consultaMatricula;
    
    for(size_t i = 0; i < turma.size(); i++){
        if(consultaMatricula == turma[i].matricula){
            cout << left << 
            setw (15) << turma[i].nome <<
            setw(8) << turma[i].idade <<
            setw(8) << turma[i].sexo <<
            setw(8) << turma[i].turma <<
            setw(8) << turma[i].media << endl;

            cout << "Deseja alterar nota? (s/n): ";
            cin >> alterar;
        
            if(alterar == 's' || alterar == 'S'){
                cout << "Qual nota deseja alterar? 1 - Nota 1" << endl <<"2 - Nota 2" << endl << "Opcao: ";
                cin >> op;
                if(op == 1){
                    cout << "Digite a nova nota da Nota 1: ";
                    cin >> turma[i].nota1;
                    mediaAluno(turma);
                }else if(op == 2){
                    cout << "Digite a nova nota da Nota 2: ";
                    cin >> turma[i].nota2;
                    mediaAluno(turma);
                }
                else{
                    break;
                }
            }

            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        cout << "[ERRO]: Nenhum aluno encontrado com a matricula: " << consultaMatricula << endl;
    }
}
//Função para ordenar os dados em descrescente a parte da média
void ordenarBoletim(vector<Turma> &turma){
    sort(turma.begin(), turma.end(), [](const Turma &a, const Turma &b){
        return a.media > b.media;
    });
}