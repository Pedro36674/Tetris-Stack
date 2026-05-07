# Gerenciador de Peças com Fila e Pilha

## Descrição

Projeto em C que implementa um gerenciador de peças utilizando duas estruturas de dados fundamentais:
- **Fila Circular**: com capacidade para 5 peças
- **Pilha**: com capacidade para 3 peças reservadas

O sistema permite operações estratégicas como jogar peças, reservar, trocar e realizar trocas em bloco entre as estruturas.

## Requisitos Funcionais

✅ **Inicialização**
- Fila circular com 5 peças geradas aleatoriamente
- Pilha de reserva com capacidade para 3 peças
- Cada peça possui tipo ('I', 'O', 'T', 'L') e ID único

✅ **Operações Disponíveis**
1. **Jogar Peça**: remove a peça da frente da fila (dequeue)
2. **Reservar Peça**: move a peça da frente da fila para o topo da pilha
3. **Usar Peça Reservada**: remove a peça do topo da pilha
4. **Trocar Peça Única**: substitui a frente da fila pelo topo da pilha
5. **Trocar Múltipla**: alterna os 3 primeiros da fila com as 3 da pilha
6. **Exibir Estado**: mostra o estado da fila e pilha

✅ **Características Adicionais**
- Geração automática de novas peças para manter a fila sempre cheia
- Validação de operações (fila/pilha cheias ou vazias)
- Peças removidas não retornam ao jogo

## Estrutura do Projeto

```
tetris/
├── tetris.c           # Código-fonte principal
├── tetris.exe         # Executável compilado
├── tetris.ilk         # Arquivo de informações de ligação
└── README.md          # Este arquivo
```

## Estruturas de Dados

### Struct Peca
```c
typedef struct {
    char tipo;  // 'I', 'O', 'T' ou 'L'
    int id;     // Número único sequencial
} Peca;
```

### Struct Fila (Circular)
```c
typedef struct {
    Peca itens[FILA_CAPACIDADE];    // Array de peças
    int inicio;                      // Índice do primeiro elemento
    int fim;                         // Índice do próximo espaço livre
    int total;                       // Número de peças na fila
} Fila;
```

### Struct Pilha
```c
typedef struct {
    Peca itens[PILHA_CAPACIDADE];   // Array de peças
    int topo;                        // Índice do topo (-1 = vazia)
} Pilha;
```

## Como Compilar

### Windows (Visual C++)
```bash
cd tetris
cl.exe /Zi /EHsc /nologo tetris.c /Fe:tetris.exe
```

### Linux/Mac (GCC)
```bash
cd tetris
gcc -o tetris tetris.c
```

## Como Executar

### Windows
```bash
tetris.exe
```

### Linux/Mac
```bash
./tetris
```

## Exemplo de Uso

```
=== Estado atual ===
Fila de peças: [I 0] [L 1] [T 2] [O 3] [I 4]
Pilha de reserva: (Topo -> Base) [vazia]
====================

Opções de ação:
1 - Jogar peça da frente da fila
2 - Enviar peça da fila para a pilha de reserva
3 - Usar peça da pilha de reserva
4 - Trocar peça da frente da fila com o topo da pilha
5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
0 - Sair
Escolha uma opção: 2
Peça reservada: [I 0]

=== Estado atual ===
Fila de peças: [L 1] [T 2] [O 3] [I 4] [L 5]
Pilha de reserva: (Topo -> Base): [I 0]
====================
```

## Funções Principais

| Função | Descrição |
|--------|-----------|
| `void inicializarFila(Fila *fila)` | Inicializa a fila vazia |
| `void inicializarPilha(Pilha *pilha)` | Inicializa a pilha vazia |
| `void enfileirar(Fila *fila, Peca peca)` | Adiciona peça ao final da fila |
| `int desenfileirar(Fila *fila, Peca *peca)` | Remove peça do início da fila |
| `int empilhar(Pilha *pilha, Peca peca)` | Adiciona peça ao topo da pilha |
| `int desempilhar(Pilha *pilha, Peca *peca)` | Remove peça do topo da pilha |
| `int trocarFrenteFilaPilha(Fila *fila, Pilha *pilha)` | Troca única entre fila e pilha |
| `int trocarTresPrimeiros(Fila *fila, Pilha *pilha)` | Troca múltipla de 3 peças |
| `void mostrarFila(const Fila *fila)` | Exibe conteúdo da fila |
| `void mostrarPilha(const Pilha *pilha)` | Exibe conteúdo da pilha |

## Conceitos Trabalhados

- **Fila Circular**: manipulação eficiente com reaproveitamento de espaço
- **Pilha Linear**: armazenamento LIFO (último a entrar, primeiro a sair)
- **Structs e Arrays**: tipos personalizados para representar dados complexos
- **Ponteiros**: passagem por referência para modificar estruturas
- **Modularização**: funções especializadas para cada operação
- **Validação**: controle de fluxo e restrições

## Requisitos Não-Funcionais

✅ **Usabilidade**: interface clara com separação visual entre fila e pilha
✅ **Legibilidade**: código bem organizado com nomes descritivos
✅ **Documentação**: comentários explicando a lógica de cada função

## Notas Importantes

- Peças são geradas aleatoriamente com tipos: I, O, T, L
- A fila é sempre mantida com 5 elementos (quando possível)
- A pilha tem capacidade máxima de 3 peças
- Operações de troca preservam a ordem relativa das peças
- Números de ID são sequenciais e únicos

## Autor

Projeto acadêmico focado no aprendizado de estruturas de dados.

---

**Última atualização**: 7 de maio de 2026
