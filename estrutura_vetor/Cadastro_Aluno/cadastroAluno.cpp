#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;

struct Turma{
    string nome, turma, status;
    char sexo;
    int idade;
    float nota1, nota2, media;
};

//Funções pre declaradas
void cadastrarAluno(vector<Turma> &turme);
void exibirBoletim(const vector<Turma> &turma);
void mediaAluno(vector<Turma> &turma);
void exibirAlunoMedia(const vector<Turma> &turma);
void alunoMaiorMedia(vector<Turma> &turma);

int main(){
    const int quantidadeAluno = 3;

    /*
    cout << "Digite a quantidade de aluno da turma: ";

    cin >> quantidadeAluno;
    */

    vector<Turma> turma(quantidadeAluno);

    //Chamando a função para cadastrar os alunos
    cadastrarAluno(turma);
    
    //Chamando a função para exibir o Boletim dos alunos
    exibirBoletim(turma);

    //Chamando a função para exibit os Alunos acima da Média
    exibirAlunoMedia(turma);

    //Chamando a função para exibir o(a) aluno(a) com a maior média
    alunoMaiorMedia(turma);


    return 0;

}

//Função para Cadastrar os Alunos na Turma
void cadastrarAluno(vector<Turma> &turma){
    cout << " ------- CADASTRAR ALUNO NA TURMA ------- " << endl;
    for(size_t i = 0;  i < turma.size(); i++){
        cout << "Nome do aluno: ";
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
        mediaAluno(turma); //chama a função para calcular a média dos alunos
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