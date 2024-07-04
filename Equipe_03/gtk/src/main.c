#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

GtkBuilder   *builder;//chama o glade
GtkWidget    *window;//abre a janela
GtkStack     *stack;//interaçção entre janelas
GtkListStore *modelo;//dados da tabela

typedef struct produto {
    int id;
    char produto[50];
    int quantidade;
    struct produto *proximo;//aponta para o proximo produto
} prod;

int id = 0;
prod *cabecalho_prod = NULL;
prod *proximo_prod = NULL;

void on_main_window_destroy(GtkWidget *Widget, gpointer data) {
    prod *temp;
    while (cabecalho_prod != NULL) {
        temp = cabecalho_prod;
        cabecalho_prod = cabecalho_prod->proximo;
        free(temp);
    }
    gtk_main_quit();
}

void on_botao_entrar_clicked(GtkWidget *Widget, gpointer data) {
    gtk_stack_set_visible_child_name(stack, "tela-cadastro");
}

void carregar_produtos_salvos() {
    FILE *file;
    file = fopen("lista-de-compras.txt", "r");

    prod *temp;
    while (cabecalho_prod != NULL) {
        temp = cabecalho_prod;
        cabecalho_prod = cabecalho_prod->proximo;
        free(temp);
    }
    proximo_prod = NULL;
    id = 0;

    while (!feof(file)) {
        prod *novo_prod = (prod*)malloc(sizeof(prod));
        if (fscanf(file, "%d %s %d", &novo_prod->id, novo_prod->produto, &novo_prod->quantidade) == 3) {
            novo_prod->proximo = NULL;
            if (cabecalho_prod == NULL) {
                cabecalho_prod = novo_prod;
                proximo_prod = cabecalho_prod;
            } else {
                proximo_prod->proximo = novo_prod;
                proximo_prod = proximo_prod->proximo;
            }
            id = novo_prod->id; 
        } else {
            free(novo_prod);
        }
    }
    fclose(file);
}

void on_cadastrar_produto_clicked(GtkWidget *Widget, gpointer data) {
    GtkEntry *entry_produto = GTK_ENTRY(gtk_builder_get_object(builder, "produto"));
    const char *produto = gtk_entry_get_text(entry_produto);
    GtkEntry *entry_quantidade = GTK_ENTRY(gtk_builder_get_object(builder, "quantidade"));
    const char *quantidade_str = gtk_entry_get_text(entry_quantidade);
    int quantidade = atoi(quantidade_str);

    prod *novo_prod = (prod*)malloc(sizeof(prod));
    novo_prod->id = ++id;
    strcpy(novo_prod->produto, produto);
    novo_prod->quantidade = quantidade;
    novo_prod->proximo = NULL;

    if (cabecalho_prod == NULL) {
        cabecalho_prod = novo_prod;
        proximo_prod = cabecalho_prod;
    } else {
        proximo_prod->proximo = novo_prod;
        proximo_prod = proximo_prod->proximo;
    }

    gtk_entry_set_text(entry_produto, "");
    gtk_entry_set_text(entry_quantidade, "");
    gtk_list_store_clear(modelo);
    GtkTreeIter iter;
    prod *iterprod = cabecalho_prod;
    while (iterprod != NULL) {
        gtk_list_store_append(modelo, &iter);
        gtk_list_store_set(modelo, &iter, 
            0, iterprod->id,
            1, iterprod->produto,
            2, iterprod->quantidade,
            -1);
        iterprod = iterprod->proximo;
    }

   
    FILE *file;
    file = fopen("lista-de-compras.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d %s %d\n", novo_prod->id, novo_prod->produto, novo_prod->quantidade);
        fclose(file);
    }
}

void on_delete_item_clicked(GtkWidget *Widget, gpointer data) {
}

void on_delet_all_clicked(GtkWidget *Widget, gpointer data) {

    prod *temp;
    while (cabecalho_prod != NULL) {
        temp = cabecalho_prod;
        cabecalho_prod = cabecalho_prod->proximo;
        free(temp);
    }
    cabecalho_prod = NULL;
    proximo_prod = NULL;
    id = 0;

    gtk_list_store_clear(modelo);

    FILE *file = fopen("lista-de-compras.txt", "w");
    if (file != NULL) {
        fclose(file);
    }

    g_print("Apagado\n");
}


void on_voltar_tela_inicial_clicked(GtkWidget *Widget, gpointer data) {
    gtk_stack_set_visible_child_name(stack, "tela-inicial");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    builder = gtk_builder_new_from_file("C:/Users/Ricão/Documents/Faculdade/Segundo semestre/LP/Projeto_LP_lista_de_compras/glade/lista_de_compras.glade");
    gtk_builder_add_callback_symbols(
        builder,
        "on_botao_entrar_clicked",        G_CALLBACK(on_botao_entrar_clicked),
        "on_main_window_destroy",         G_CALLBACK(on_main_window_destroy),
        "on_cadastrar_produto_clicked",   G_CALLBACK(on_cadastrar_produto_clicked),
        "on_delete_item_clicked",         G_CALLBACK(on_delete_item_clicked),
        "on_delet_all_clicked",          G_CALLBACK(on_delet_all_clicked),
        "on_voltar_tela_inicial_clicked", G_CALLBACK(on_voltar_tela_inicial_clicked),
        NULL);
    gtk_builder_connect_signals(builder, NULL);
    stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    modelo = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore1"));
    
    carregar_produtos_salvos();
    
    gtk_widget_show_all(window);
    gtk_main();
    

    prod *temp;
    while (cabecalho_prod != NULL) {
        temp = cabecalho_prod;
        cabecalho_prod = cabecalho_prod->proximo;
        free(temp);
    }
    
    return 0;
}
