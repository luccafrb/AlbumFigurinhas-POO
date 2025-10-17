# Álbum de Figurinhas Virtual
## Equipe
- Vinícius Sandrin Lemes  
- Lucca
- Marcelle 
Este é um projeto de simulação de um aplicativo de álbum de figurinhas virtual, desenvolvido como trabalho prático para a disciplina de **Algoritmos e Programação: Orientação a Objetos** na Escola Politécnica da UNISINOS.

---

## Objetivo do Projeto
O objetivo principal é criar um programa que simule as funcionalidades de um aplicativo de álbum de figurinhas, como o apresentado na **Figura 1**, utilizando o conceito de Orientação a Objetos.  
A persistência dos dados (usuários, figurinhas e trocas) é implementada por meio de arquivos de texto tabulados no formato **CSV**.

---

## Funcionalidades Implementadas

O programa possui um menu inicial com as seguintes opções:

- **Novo Álbum**: Permite a criação de um novo usuário, com nome e senha.
- **Acessar Álbum**: Permite que um usuário existente acesse sua coleção após fornecer seu nome de usuário e senha.
- **Sair do Aplicativo**: Encerra o programa, garantindo que todas as alterações nos álbuns dos usuários sejam salvas nos arquivos CSV.

### Após acessar o álbum, o usuário pode:
- **Ver Álbum**: Permite folhear o álbum página por página. Ele mostra as figurinhas coladas, as que estão na coleção (**COLAR**) ou as que ainda faltam.
- **Gerenciar a Coleção**: Dá acesso às figurinhas que não foram coladas no álbum, permitindo ao usuário gerenciar sua coleção.
- **Abrir Pacote de Figurinhas**: Adiciona três novas figurinhas aleatórias à coleção do usuário.
- **Voltar ao Menu Anterior**

### Dentro do menu de gerenciamento da coleção, é possível:
- **Colar Figurinha**: Permite colar uma figurinha da coleção no álbum.
- **Disponibilizar para troca**: Altera o status de uma figurinha para que ela fique disponível para ser trocada.
- **Propor troca de figurinhas**: Permite propor uma troca de figurinhas com outros usuários.
- **Revisar solicitações de troca**: Permite que o usuário aceite ou recuse solicitações de troca que foram feitas para ele.
- **Voltar ao Menu Anterior**

---

## Estrutura de Classes

A estrutura do sistema é baseada em um conjunto de classes, conforme proposto no trabalho:

- **Usuario**: Gerencia os dados do usuário e seu respectivo álbum.
- **Album**: Representa o álbum do usuário, contendo páginas, figurinhas e requisições de troca.
- **Pagina**: Representa uma página do álbum.
- **Figurinha**: Contém as informações de cada figurinha (número, nome, status, etc.).
- **Troca**: Armazena os detalhes de uma solicitação de troca (proponente, figurinhas, status, etc.).
