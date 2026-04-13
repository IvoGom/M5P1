// main.cpp
// Versão inicial: definição das structs

#include <string>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Morada {
    string rua;
    string cidade;
    string codigo_postal; // formato livre, ex., "1234-567"
    string pais;
};

enum Sexo {
    MASCULINO,
    FEMININO,
    OUTRO
};

enum EstadoSocio {
    INATIVO = 0,
    ATIVO = 1
};

struct Socio {
    int id;                     // identificador único do sócio
    string nome;
    Sexo sexo;
    Data data_nascimento;
    Morada morada;
    string telefone;
    string email;
    Data data_inscricao;
    EstadoSocio estado;         // Indica se o Sócio está ativo
    int mensalidade_centimos;   // valor da mensalidade em cêntimos
};

