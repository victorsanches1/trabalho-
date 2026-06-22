#include <stdio.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int inicio;
    int fim;
} Fila;


void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}


int filaVazia(Fila *f) {
    return f->inicio > f->fim;
}


void enfileirar(Fila *f, int valor) {
    f->itens[++f->fim] = valor;
}


int desenfileirar(Fila *f) {
    return f->itens[f->inicio++];
}

void bfs(int grafo[MAX][MAX], int vertices, int inicio) {
    int visitado[MAX] = {0};

    Fila fila;
    inicializarFila(&fila);

    visitado[inicio] = 1;
    enfileirar(&fila, inicio);

    printf("Ordem da BFS: ");

    while (!filaVazia(&fila)) {
        int atual = desenfileirar(&fila);

        printf("%d ", atual);

        for (int i = 0; i < vertices; i++) {
            if (grafo[atual][i] == 1 && !visitado[i]) {
                visitado[i] = 1;
                enfileirar(&fila, i);
            }
        }
    }

    printf("\n");
}

int main() {
    int vertices = 6;

    int grafo[MAX][MAX] = {0};

    // Criando as arestas
    grafo[0][1] = 1;
    grafo[1][0] = 1;

    grafo[0][2] = 1;
    grafo[2][0] = 1;

    grafo[1][3] = 1;
    grafo[3][1] = 1;

    grafo[1][4] = 1;
    grafo[4][1] = 1;

    grafo[2][5] = 1;
    grafo[5][2] = 1;

    bfs(grafo, vertices, 0);

    return 0;
}
