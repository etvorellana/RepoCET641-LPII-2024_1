//----------------------------------------------------------------------------//
// Bibliotecas//

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------------------------------------------------------------------//
// Defines//

#define ARQUIVO_CSV "contatos.csv"

//----------------------------------------------------------------------------//
// Structs//

typedef struct
{
    char nome[100];
    char numero[20];
    char email[100];
} Contato;

typedef struct
{
    Contato *contatos;
    int contador;
} ContatosLista;

//----------------------------------------------------------------------------//
// Functions//

ContatosLista lista_contatos = {NULL, 0};

GtkWidget *main_window;
GtkWidget *contact_list_box;


void ler_do_arquivo();                                                           // stella
void ao_adicionar_contato(GtkWidget *widget, gpointer data);                     // antonio
void adicionar_contato(const char *nome, const char *numero, const char *email); // antonio
void mostrar_alerta(GtkWindow *parente, const char *mensagem);                   // antonio
void display_contatos();                                                         // ariel 
void ao_deletar_contato(GtkWidget *widget, gpointer data);                       // ariel
void ao_fechar_janela();                                                         // stella
void salvar_no_arquivo();                                                        // stella

//----------------------------------------------------------------------------//
// Main//

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "Agenda de Contatos");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 800, 600);

    g_signal_connect(main_window, "destroy", G_CALLBACK(ao_fechar_janela), NULL);

    GtkWidget *VBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *ButtonAdd = gtk_button_new_with_label("Adicionar Contato");
    contact_list_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    g_signal_connect(ButtonAdd, "clicked", G_CALLBACK(ao_adicionar_contato), NULL);

    gtk_box_pack_start(GTK_BOX(VBox), ButtonAdd, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(VBox), contact_list_box, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(main_window), VBox);

    ler_do_arquivo();
    display_contatos();

    gtk_widget_show_all(main_window);
    gtk_main();

    free(lista_contatos.contatos);
    return 0;
}

//----------------------------------------------------------------------------//
// Declared Functions//

void ler_do_arquivo()
{
    FILE *fp = fopen(ARQUIVO_CSV, "r");
    if (!fp)
    {
        perror("Não foi possivel abrir o arquivo");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), fp))
    {
        lista_contatos.contatos = realloc(lista_contatos.contatos, sizeof(Contato) * (lista_contatos.contador + 1));
        sscanf(line, "%99[^,],%19[^,],%99[^\n]", lista_contatos.contatos[lista_contatos.contador].nome, lista_contatos.contatos[lista_contatos.contador].numero, lista_contatos.contatos[lista_contatos.contador].email);
        lista_contatos.contador++;
    }
    fclose(fp);
}

void ao_adicionar_contato(GtkWidget *widget, gpointer data)
{
    GtkWidget *Dialogo = gtk_dialog_new_with_buttons("Adicionar Contato", GTK_WINDOW(main_window), GTK_DIALOG_MODAL, "Adicionar", GTK_RESPONSE_ACCEPT, "Cancelar", GTK_RESPONSE_REJECT, NULL);
    GtkWidget *ContentArea = gtk_dialog_get_content_area(GTK_DIALOG(Dialogo));

    GtkWidget *EntradaNome = gtk_entry_new();
    GtkWidget *EntradaNumero = gtk_entry_new();
    GtkWidget *EntradaEmail = gtk_entry_new();

    gtk_entry_set_placeholder_text(GTK_ENTRY(EntradaNome), "Nome");
    gtk_entry_set_placeholder_text(GTK_ENTRY(EntradaNumero), "Número");
    gtk_entry_set_placeholder_text(GTK_ENTRY(EntradaEmail), "Email");

    gtk_box_pack_start(GTK_BOX(ContentArea), EntradaNome, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(ContentArea), EntradaNumero, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(ContentArea), EntradaEmail, FALSE, FALSE, 0);

    gtk_widget_show_all(Dialogo);

    if (gtk_dialog_run(GTK_DIALOG(Dialogo)) == GTK_RESPONSE_ACCEPT)
    {
        const char *nome = gtk_entry_get_text(GTK_ENTRY(EntradaNome));
        const char *numero = gtk_entry_get_text(GTK_ENTRY(EntradaNumero));
        const char *email = gtk_entry_get_text(GTK_ENTRY(EntradaEmail));
        if (strlen(nome) != 0 && (strlen(numero) != 0 || strlen(email) != 0))
        {

            if (strchr(email, '@') == NULL || strchr(email, '.') == NULL)
            {
                if (strlen(email) == 0)
                {
                    email = "vazio";
                }
                else
                {
                    mostrar_alerta(GTK_WINDOW(main_window), "formato de e-mail inválido.\nExemplo: seuemail@gmail.com");
                }
            }

            if (strlen(numero) < 11)
            {
                if (strlen(numero) == 0)
                {
                    numero = "vazio";
                }
                else
                {
                    mostrar_alerta(GTK_WINDOW(main_window), "Número de telefone inválido.\nmínimo de 11 dígitos.");
                }
            }
            if ((strlen(numero) >= 11 || numero == "vazio") && ((strchr(email, '.') != NULL && strchr(email, '@') != NULL) || email == "vazio"))
            {
                adicionar_contato(nome, numero, email);
                display_contatos();
            }
        }
    }

    gtk_widget_destroy(Dialogo);
}

void adicionar_contato(const char *nome, const char *numero, const char *email)
{
    lista_contatos.contatos = realloc(lista_contatos.contatos, sizeof(Contato) * (lista_contatos.contador + 1));
    strncpy(lista_contatos.contatos[lista_contatos.contador].nome, nome, sizeof(lista_contatos.contatos[lista_contatos.contador].nome));
    strncpy(lista_contatos.contatos[lista_contatos.contador].numero, numero, sizeof(lista_contatos.contatos[lista_contatos.contador].numero));
    strncpy(lista_contatos.contatos[lista_contatos.contador].email, email, sizeof(lista_contatos.contatos[lista_contatos.contador].email));
    lista_contatos.contador++;
}

void mostrar_alerta(GtkWindow *parente, const char *mensagem)
{
    GtkWidget *Dialogo = gtk_message_dialog_new(parente, GTK_DIALOG_MODAL, GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, "%s", mensagem);
    gtk_dialog_run(GTK_DIALOG(Dialogo));
    gtk_widget_destroy(Dialogo);
}

void display_contatos()
{
    gtk_container_foreach(GTK_CONTAINER(contact_list_box), (GtkCallback)gtk_widget_destroy, NULL);
    for (int i = 0; i < lista_contatos.contador; i++)
    {
        GtkWidget *HBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
        GtkWidget *Label = gtk_label_new(lista_contatos.contatos[i].nome);
        GtkWidget *Numero = gtk_label_new(lista_contatos.contatos[i].numero);
        GtkWidget *Email = gtk_label_new(lista_contatos.contatos[i].email);
        GtkWidget *ButtonDelete = gtk_button_new_with_label("Deletar");

        gtk_box_pack_start(GTK_BOX(HBox), Label, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox), Numero, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox), Email, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox), ButtonDelete, FALSE, FALSE, 0);

        g_signal_connect(ButtonDelete, "clicked", G_CALLBACK(ao_deletar_contato), GINT_TO_POINTER(i));

        gtk_box_pack_start(GTK_BOX(contact_list_box), HBox, FALSE, FALSE, 0);
    }
    gtk_widget_show_all(main_window);
}

void ao_deletar_contato(GtkWidget *widget, gpointer data)
{
    int index = GPOINTER_TO_INT(data);
    for (int i = index; i < lista_contatos.contador - 1; i++)
    {
        lista_contatos.contatos[i] = lista_contatos.contatos[i + 1];
    }
    lista_contatos.contador--;
    lista_contatos.contatos = realloc(lista_contatos.contatos, sizeof(Contato) * lista_contatos.contador);
    gtk_widget_destroy(gtk_widget_get_parent(widget));
}

void ao_fechar_janela()
{
    salvar_no_arquivo();
    gtk_main_quit();
}

void salvar_no_arquivo()
{
    FILE *fp = fopen(ARQUIVO_CSV, "w");
    if (!fp)
    {
        perror("Não foi possivel abrir o arquivo");
        return;
    }
    for (int i = 0; i < lista_contatos.contador; i++)
    {
        fprintf(fp, "%s,%s,%s\n", lista_contatos.contatos[i].nome, lista_contatos.contatos[i].numero, lista_contatos.contatos[i].email);
    }
    fclose(fp);
}