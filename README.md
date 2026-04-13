Gestor de Sócios do Ginásio
Descrição

Projeto em C++ para gerir socios de um ginásio: registo, consulta, alteração e remoção.
Esta versão inicial trabalha apenas em memória (structs e arrays). Não usa ficheiros.
Porquê este projeto

Praticar structs, arrays e organização de dados em C++.
Aprender a trabalhar com controlo de versões (Git) e a manter um historial de commits claro.
Entregar código simples, legível e funcional como base para futuras melhorias.
Ficheiros iniciais

main.cpp — contém apenas as definições das structs (commit obrigatório).
README.md — este ficheiro.
.gitignore — recomendado para ignorar binários e ficheiros temporários.
Requisito obrigatório (atenção)

O repositório deve ser público no GitHub.
Deve existir um commit com a mensagem exatamente: "Versão inicial: definição das structs" Esse commit só pode conter o ficheiro main.cpp com as structs — sem menus, funções ou lógica.
Sugestão de workflow

Criar o repositório no GitHub e clonar localmente.
Adicionar o main.cpp com apenas as structs.
Fazer o commit obrigatório: git add main.cpp git commit -m "Versão inicial: definição das structs"
Criar branches para desenvolver features (ex.: feature/menu, feature/crud).
Fazer commits pequenos e frequentes; usar PRs para integrar na main.
Plano de desenvolvimento sugerido (exemplo prático)

Versão inicial: definição das structs
Esqueleto do menu principal (sem lógica)
Implementar registo de sócios (adicionar ao array)
Implementar listagem e pesquisa (por id ou nome)
Implementar edição de dados do sócio
Implementar remoção (marcar como inativo)
Adicionar validações de entrada e limites do array
Refatorar em módulos (.cpp) e limpar código
Documentação final e exemplos de uso
Boas práticas


Mensagens de commit claras e descritivas.
Funções com responsabilidade única.
Código legível com comentários onde ajudem.
Não usar persistência externa nesta versão base (apenas memória).


Data

13 de abril de 2026.