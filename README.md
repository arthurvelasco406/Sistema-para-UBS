# Sistema - UBS

## Diário de Desenvolvimento

### Implementações
#### Arthur:
1. Funções de Pilha
2. Funções de Lista Encadeada
3. Imprimir Relatório

#### Gabriel:
1. Funções de Fila
2. Função de Intercalação

#### Leandra:
1. Função de Busca Binária
2. Função de Ordenação com Bubble Sort

### Questões

#### Qual foi a maior dificuldade? Como resolveram?
+ Gabriel - A maior dificuldade foi implementar uma lógica de tempo entre um atendimento e o outro, para gerar um relatório de atendimentos.
+ Leandra - Resolvemos utilizando a função GetTickCount() para contabilizar o tempo de inicio e final do atendimento.

#### Por que o algoritmo de busca/ordenação atribuído ao grupo é adequado (ou não) para o contexto escolhido? 
+ Leandra - O algoritmo de ordenação é adequado para ordenar o relatório final pois vem de acordo com a chamada dos pacientes.
+ Leandra - O algoritmo de busca é adequado pois é usado para a busca de cliente por senha em uma lista já ordenada.

#### Qual é o valor de inicio e final da fila após inserir [7] elementos e remover [2]? Mostre o estado do vetor. (N e M conforme tabela do grupo)
+ Gabriel - O início da fila passa a ser [2] e o final dela passa a ser [6]. <br> Estado do vetor = [-,-,3,4,5,6,7,-,-]

#### O algoritmo de ordenação do grupo é estável? Isso importa no contexto escolhido? Justifique.
+ Arthur - Sim, é estável. Acredito que isso seja importante para garantir que o relatório esteja consistente e seja entregue no mesmo formato.

#### Demonstre o estado da lista encadeada após as três primeiras inserções com dados reais do contexto.
+ No lista = {Cliente{senha=1; nome=arthur; prioritario=1; telefone=1111-1111}; *prox={Cliente{senha=2; nome=leandra; prioritario=0; telefone=2222-2222}; *prox={Cliente{senha=3; nome=gabriel; prioritario=0; telefone=3333-3333}; *prox=NULL}}
