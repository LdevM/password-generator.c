# password-generator.c
Projeto educacional feito na linguagem C para gerar senhas aleatórias de forma segura e personalizável. Este é um projeto simples que utiliza funções, ponteiros e manipulação de arquivos para demonstrar conceitos fundamentais da linguagem.

Funcionalidades do Projeto
O programa oferece as seguintes opções ao usuário:

  -Geração de Senha: Cria senhas aleatórias com base no tamanho e nível de dificuldade escolhidos pelo usuário.

  -Dificuldades:

    -Fácil: Senhas com apenas letras minúsculas.

    -Médio: Senhas com letras minúsculas e números.

    -Difícil: Senhas com todos os caracteres da tabela ASCII, exceto alguns caracteres especiais para evitar problemas.

  -Salvamento de Senha: Permite ao usuário salvar a senha gerada em um arquivo de texto.

  -Opções de Salvamento:

    -Salvar em um novo arquivo, com um nome de arquivo fornecido pelo usuário.

    -Adicionar a uma senha a um arquivo de texto já existente.

Como o Projeto Funciona
  O projeto segue um fluxo simples e validado a cada passo:

  1-O programa solicita o tamanho e o nível de dificuldade da senha desejada.

  2-Uma senha aleatória é gerada com base nas escolhas do usuário.

  3-O usuário é perguntado se deseja salvar a senha gerada.

  4-Se a resposta for sim, o programa oferece as opções de salvar em um novo arquivo ou adicionar a um arquivo existente.

  5-O nome de arquivo fornecido pelo usuário é validado para garantir que a extensão .txt seja utilizada.

  6-O arquivo é aberto e a senha é salva.


Próximos commits:
  -Adicionar o setlocale para imprimir corretamente os caracteres em portugês
  -Adicionar uma opção para ler um arquivo existente
