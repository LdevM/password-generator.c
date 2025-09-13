# password-generator.c
Projeto educacional feito na linguagem C para gerar senhas aleatórias de forma segura e personalizável. Este é um projeto simples que utiliza funções, ponteiros e manipulação de arquivos para demonstrar conceitos fundamentais da linguagem.

## Funcionalidades do Projeto
O programa oferece as seguintes opções ao usuário:

* **Geração de Senha**: Cria senhas aleatórias com base no tamanho e nível de dificuldade escolhidos pelo usuário.
* **Dificuldades**:
    * Fácil: Senhas com apenas letras minúsculas.
    * Médio: Senhas com letras minúsculas e números.
    * Difícil: Senhas com todos os caracteres da tabela ASCII, exceto alguns caracteres especiais para evitar problemas.
* **Salvamento de Senha**: Permite ao usuário salvar a senha gerada em um arquivo de texto.
* **Opções de Salvamento**:
    * Salvar em um novo arquivo, com um nome de arquivo fornecido pelo usuário.
    * Adicionar a uma senha a um arquivo de texto já existente.
* **Leitura de Arquivo**: Permite ao usuário ler o conteúdo de um arquivo de texto existente, exibindo as senhas salvas.
* **Renomear Arquivo**: Permite ao usuário alterar o nome de um arquivo de texto existente.

## Como o Projeto Funciona
O projeto segue um fluxo simples e validado a cada passo:

1.  O programa solicita o tamanho e o nível de dificuldade da senha desejada.
2.  Uma senha aleatória é gerada com base nas escolhas do usuário.
3.  O usuário é perguntado se deseja salvar a senha gerada.
4.  Se a resposta for sim, o programa oferece as opções de salvar em um novo arquivo ou adicionar a um arquivo existente.
5.  O nome de arquivo fornecido pelo usuário é validado para garantir que a extensão `.txt` seja utilizada.
6.  O arquivo é aberto e a senha é salva.
7.  Após salvar, o usuário pode ler o conteúdo do arquivo, renomeá-lo ou gerar uma nova senha.

## Próximos passos
* [ ] Adicionar uma opção para ler um arquivo existente. (Já feito e atualizado)
* [ ] Adicionar uma opção para renomear um arquivo. (Já feito e atualizado)
* [ ] Refatorar o código para melhorar a organização e legibilidade. (Já feito e atualizado
* [ ] Alterar lógica de salvar em arquivos para salvar em banco de dados.

## Alterações do terceiro Commit
* Modularização dos menus
* Divisão das funções em headers e arquivos .c, para melhorar a legibilidade do código
