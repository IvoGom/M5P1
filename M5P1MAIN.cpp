// main.cpp
// Gestor de Sócios do Ginásio — versão simples em memória (structs e arrays)

#include <iostream>
#include <string>

using namespace std;

struct Data { int dia, mes, ano; };
struct Morada { string rua, cidade, codigo_postal, pais; };
enum Sexo { MASCULINO, FEMININO, OUTRO };
enum EstadoSocio { INATIVO = 0, ATIVO = 1 };

struct Socio {
    int id;
    string nome;
    Sexo sexo;
    Data data_nascimento;
    Morada morada;
    string telefone;
    string email;
    Data data_inscricao;
    EstadoSocio estado;
    int mensalidade_centavos;
};

const int MAX_SOCIOS = 100;
Socio socios[MAX_SOCIOS];
int n_socios = 0;
int proximo_id() { int m=0; for(int i=0;i<n_socios;i++) if(socios[i].id>m) m=socios[i].id; return m+1; }

void limpar_input(){ cin.clear(); cin.ignore(10000,'\n'); }
int ler_int(const string &p){ int v; while(!(cout<<p, cin>>v)){ limpar_input(); cout<<"Entrada inválida\n"; } limpar_input(); return v; }
string ler_linha(const string &p){ string s; cout<<p; getline(cin,s); return s; }

void registar(){
    if(n_socios>=MAX_SOCIOS){ cout<<"Capacidade atingida\n"; return; }
    Socio s; s.id = proximo_id();
    limpar_input();
    s.nome = ler_linha("Nome: ");
    cout<<"Sexo (1=Masculino 2=Feminino 3=Outro): "; int x; cin>>x; limpar_input(); s.sexo = (x==1?MASCULINO:(x==2?FEMININO:OUTRO));
    cout<<"Data Nascimento (dd mm aaaa): "; cin>>s.data_nascimento.dia>>s.data_nascimento.mes>>s.data_nascimento.ano; limpar_input();
    cout<<"Morada - Rua: "; getline(cin,s.morada.rua);
    cout<<"Morada - Cidade: "; getline(cin,s.morada.cidade);
    cout<<"Código Postal: "; getline(cin,s.morada.codigo_postal);
    cout<<"País: "; getline(cin,s.morada.pais);
    cout<<"Telefone: "; getline(cin,s.telefone);
    cout<<"Email: "; getline(cin,s.email);
    cout<<"Data Inscrição (dd mm aaaa): "; cin>>s.data_inscricao.dia>>s.data_inscricao.mes>>s.data_inscricao.ano; limpar_input();
    s.estado = ATIVO;
    int euros = ler_int("Mensalidade - Euros: "); int cent = ler_int("Cêntimos: ");
    s.mensalidade_centavos = euros*100 + cent;
    socios[n_socios++] = s;
    cout<<"Sócio registado ID="<<s.id<<"\n";
}

void listar(){
    if(n_socios==0){ cout<<"Sem sócios\n"; return; }
    for(int i=0;i<n_socios;i++){
        cout<<"ID:"<<socios[i].id<<" Nome:"<<socios[i].nome<<" Estado:"<<(socios[i].estado==ATIVO?"Ativo":"Inativo")<<"\n";
    }
}

int achar_indice_por_id(int id){
    for(int i=0;i<n_socios;i++) if(socios[i].id==id) return i;
    return -1;
}

void consultar(){
    if(n_socios==0){ cout<<"Sem sócios\n"; return; }
    int id = ler_int("ID: ");
    int i = achar_indice_por_id(id);
    if(i<0){ cout<<"Não encontrado\n"; return; }
    Socio &s = socios[i];
    cout<<"ID:"<<s.id<<"\nNome:"<<s.nome<<"\nEmail:"<<s.email<<"\nTelefone:"<<s.telefone<<"\nEstado:"<<(s.estado==ATIVO?"Ativo":"Inativo")<<"\n";
}

void alterar(){
    if(n_socios==0){ cout<<"Sem sócios\n"; return; }
    int id = ler_int("ID do sócio a alterar: ");
    int i = achar_indice_por_id(id);
    if(i<0){ cout<<"Não encontrado\n"; return; }
    limpar_input();
    string novo = ler_linha("Novo nome (deixe vazio para manter): ");
    if(!novo.empty()) socios[i].nome = novo;
    cout<<"Alterar mensalidade? (s/n): "; char c; cin>>c; limpar_input();
    if(c=='s' || c=='S'){ int e=ler_int("Euros: "); int ce=ler_int("Cêntimos: "); socios[i].mensalidade_centavos = e*100+ce; }
    cout<<"Alterado.\n";
}

void remover(){
    if(n_socios==0){ cout<<"Sem sócios\n"; return; }
    int id = ler_int("ID do sócio a remover (marca inativo): ");
    int i = achar_indice_por_id(id);
    if(i<0){ cout<<"Não encontrado\n"; return; }
    socios[i].estado = INATIVO;
    cout<<"Sócio marcado como inativo.\n";
}

int main(){
    while(true){
        cout<<"\n1.Listar 2.Registar 3.Consultar 4.Alterar 5.Remover 6.Sair\n";
        int op = ler_int("Opção: ");
        if(op==1) listar();
        else if(op==2) registar();
        else if(op==3) consultar();
        else if(op==4) alterar();
        else if(op==5) remover();
        else if(op==6) break;
        else cout<<"Opção inválida\n";
    }
    return 0;
}