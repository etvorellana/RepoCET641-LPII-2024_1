#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_ARQUIVO "tarefas.txt"
#define TAM_MAX_TAREFA 256
#define MAX_TAREFAS 100

GtkWidget *lista_tarefas;

void adicionarTarefa(GtkWidget *widget, gpointer entrada);
void listarTarefas();
void removerTarefa(GtkWidget *widget, gpointer entrada);
void marcarTarefa(GtkWidget *widget, gpointer entrada);


int main(int argc, char *argv[]) {

    GtkWidget *janela;
    GtkWidget *grade;
    GtkWidget *botao_adicionar;
    GtkWidget *entrada_tarefa;
    
    gtk_init(&argc, &argv);

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(janela), "Lista de Tarefas");
    gtk_window_set_default_size(GTK_WINDOW(janela), 300, 500);
    g_signal_connect(janela, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grade = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(janela), grade);

    entrada_tarefa = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grade), entrada_tarefa, 0, 0, 2, 1);

    botao_adicionar = gtk_button_new_with_label("Adicionar Tarefa");
    g_signal_connect(botao_adicionar, "clicked", G_CALLBACK(adicionarTarefa), entrada_tarefa);
    gtk_grid_attach(GTK_GRID(grade), botao_adicionar, 0, 1, 2, 1);

    lista_tarefas = gtk_list_box_new();
    gtk_list_box_set_selection_mode(GTK_LIST_BOX(lista_tarefas), GTK_SELECTION_SINGLE);
    
    GtkWidget *janela_rolagem = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_hexpand(janela_rolagem, TRUE);
    gtk_widget_set_vexpand(janela_rolagem, TRUE);
    gtk_container_add(GTK_CONTAINER(janela_rolagem), lista_tarefas);
    gtk_grid_attach(GTK_GRID(grade), janela_rolagem, 0, 2, 2, 1);

    listarTarefas();

    gtk_widget_show_all(janela);
    gtk_main();

    return 0;
}

void adicionarTarefa(GtkWidget *widget, gpointer entrada) {
    const char *descricao_tarefa = gtk_entry_get_text(GTK_ENTRY(entrada));
    if (strlen(descricao_tarefa) == 0) return;

    FILE *arquivo = fopen(NOME_ARQUIVO, "a");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "[ ] %s\n", descricao_tarefa);
    fclose(arquivo);

    gtk_entry_set_text(GTK_ENTRY(entrada), "");
    listarTarefas();
}

void listarTarefas() {
    FILE *arquivo = fopen(NOME_ARQUIVO, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    gtk_container_foreach(GTK_CONTAINER(lista_tarefas), (GtkCallback) gtk_widget_destroy, NULL);

    char linha[TAM_MAX_TAREFA + 4];
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = 0;

        GtkWidget *caixa_horizontal = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
        GtkWidget *botao_check = gtk_check_button_new();
        if (linha[1] == 'X') {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(botao_check), TRUE);
        }
        GtkWidget *rotulo = gtk_label_new(linha + 4);
        GtkWidget *botao_excluir = gtk_button_new_with_label("Excluir");

        g_signal_connect(botao_excluir, "clicked", G_CALLBACK(removerTarefa), rotulo);
        g_signal_connect(botao_check, "toggled", G_CALLBACK(marcarTarefa), rotulo);

        gtk_box_pack_start(GTK_BOX(caixa_horizontal), botao_check, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(caixa_horizontal), rotulo, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(caixa_horizontal), botao_excluir, FALSE, FALSE, 0);

        GtkWidget *linha_caixa = gtk_list_box_row_new();
        gtk_container_add(GTK_CONTAINER(linha_caixa), caixa_horizontal);
        gtk_container_add(GTK_CONTAINER(lista_tarefas), linha_caixa);

        gtk_widget_show_all(linha_caixa);
    }

    fclose(arquivo);
}

void removerTarefa(GtkWidget *widget, gpointer entrada) {
    GtkListBoxRow *linha_caixa = GTK_LIST_BOX_ROW(gtk_widget_get_parent(gtk_widget_get_parent(GTK_WIDGET(widget))));
    GtkWidget *rotulo = GTK_WIDGET(entrada);
    const char *descricao_tarefa = gtk_label_get_text(GTK_LABEL(rotulo));

    FILE *arquivo = fopen(NOME_ARQUIVO, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linhas[MAX_TAREFAS][TAM_MAX_TAREFA + 4];
    int cont = 0;

    while (fgets(linhas[cont], sizeof(linhas[cont]), arquivo)) {
        linhas[cont][strcspn(linhas[cont], "\n")] = '\0';
        cont++;
    }

    fclose(arquivo);

    arquivo = fopen(NOME_ARQUIVO, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    for (int i = 0; i < cont; i++) {
        if (strstr(linhas[i], descricao_tarefa) == NULL) {
            fprintf(arquivo, "%s\n", linhas[i]);
        }
    }

    fclose(arquivo);
    gtk_widget_destroy(GTK_WIDGET(linha_caixa));
}

void marcarTarefa(GtkWidget *widget, gpointer entrada) {
    GtkWidget *rotulo = GTK_WIDGET(entrada);
    const char *descricao_tarefa = gtk_label_get_text(GTK_LABEL(rotulo));
    gboolean completada = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));

    FILE *arquivo = fopen(NOME_ARQUIVO, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linhas[MAX_TAREFAS][TAM_MAX_TAREFA + 4];
    int cont = 0;

    while (fgets(linhas[cont], sizeof(linhas[cont]), arquivo)) {
        linhas[cont][strcspn(linhas[cont], "\n")] = '\0';
        cont++;
    }

    fclose(arquivo);

    arquivo = fopen(NOME_ARQUIVO, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    for (int i = 0; i < cont; i++) {
        if (strstr(linhas[i], descricao_tarefa) != NULL) {
            if (completada) {
                linhas[i][1] = 'X';
            } else {
                linhas[i][1] = ' ';
            }
        }
        fprintf(arquivo, "%s\n", linhas[i]);
    }

    fclose(arquivo);
}