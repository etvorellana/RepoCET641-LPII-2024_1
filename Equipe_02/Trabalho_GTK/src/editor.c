#include "editor.h"

static ed_Editor ed;

static void ed_callbackAbrirArquivo(GtkWidget *widget, gpointer data);
static void ed_callbackSalvarArquivo(GtkWidget *widget, gpointer data);

void ed_abrirJanelaPrincipal(void) {
	// cria e prepara a janela
	ed.window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // "toplevel" = janela normal
	gtk_window_set_title(GTK_WINDOW(ed.window), "Editor de Texto");
	gtk_window_set_default_size(GTK_WINDOW(ed.window), 800, 600);
	g_signal_connect(ed.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	// criar uma caixa (box) para colocar a interface dentro
	GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_container_add(GTK_CONTAINER(ed.window), vbox);

	// criar a barra de menu
	GtkWidget *menu_bar = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(vbox), menu_bar, FALSE, FALSE, 0);

	// criar o item de opções
	GtkWidget *options_item = gtk_menu_item_new_with_label("Opções");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), options_item);

	// criar o submenu de opções nesse item
	GtkWidget *options_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(options_item), options_menu);

	GtkWidget *open_item = gtk_menu_item_new_with_label("Abrir...");
	g_signal_connect(open_item, "activate", G_CALLBACK(ed_callbackAbrirArquivo), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(options_menu), open_item);

	GtkWidget *save_item = gtk_menu_item_new_with_label("Salvar como...");
	g_signal_connect(save_item, "activate", G_CALLBACK(ed_callbackSalvarArquivo), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(options_menu), save_item);

	GtkWidget *exit_item = gtk_menu_item_new_with_label("Sair");
	g_signal_connect(exit_item, "activate", G_CALLBACK(gtk_main_quit), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(options_menu), exit_item);

	// criar caixa de texto e adicionar ela à box
	// a scrolled window é usada para adicionar uma barra de rolagem à caixa de
	// texto
	ed.text_view = gtk_text_view_new();
	GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER(scrolled_window), ed.text_view);
	gtk_box_pack_start(GTK_BOX(vbox), scrolled_window, TRUE, TRUE, 0);

	// armazenar também uma referência ao buffer de texto
	ed.text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(ed.text_view));

	// mostrar a janela
	gtk_widget_show_all(ed.window);
}

static void ed_callbackAbrirArquivo(GtkWidget *widget, gpointer data) {
	// abrir o dialog de arquivo
	GtkWidget *dialog = gtk_file_chooser_dialog_new("Abrir arquivo",
		GTK_WINDOW(ed.window),
		GTK_FILE_CHOOSER_ACTION_OPEN,
		"Cancelar", GTK_RESPONSE_CANCEL,
		"Abrir", GTK_RESPONSE_ACCEPT,
		NULL);

	// aguardar o resultado do dialog
	if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
		// se deu certo, carregar o arquivo
		char *nomeArquivo = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

		char *conteudo = ed_lerArquivo(nomeArquivo);
		if (conteudo != NULL) {
			gtk_text_buffer_set_text(ed.text_buffer, conteudo, strlen(conteudo));
			free(conteudo);
		} else {
			const char *msg = "Falha ao abrir o arquivo!";
			gtk_text_buffer_set_text(ed.text_buffer, msg, strlen(msg));
		}

		free(nomeArquivo);
	}

	// equivalente a free()
	gtk_widget_destroy(dialog);
}

static void ed_callbackSalvarArquivo(GtkWidget *widget, gpointer data) {
	// lógica parecida com o código para abrir o arquivo
	GtkWidget *dialog = gtk_file_chooser_dialog_new("Salvar arquivo",
		GTK_WINDOW(ed.window),
		GTK_FILE_CHOOSER_ACTION_SAVE,
		"Cancelar", GTK_RESPONSE_CANCEL,
		"Salvar", GTK_RESPONSE_ACCEPT,
		NULL);

	if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
		// pegar nome do arquivo
		char *nomeArquivo = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

		// pegar conteúdo do buffer
		GtkTextIter start, end;
		gtk_text_buffer_get_start_iter(ed.text_buffer, &start);
		gtk_text_buffer_get_end_iter(ed.text_buffer, &end);
		char *conteudo = gtk_text_buffer_get_text(ed.text_buffer, &start, &end, FALSE);

		// salvar no arquivo
		ed_escreverArquivo(nomeArquivo, conteudo);

		free(conteudo);
		free(nomeArquivo);
	}

	gtk_widget_destroy(dialog);
}

char* ed_lerArquivo(const char *path) {
	FILE *fd = fopen(path, "r");
	if (!fd) return NULL;

	// `mem` é o conteúdo inteiro que queremos ler
	char *mem = NULL;
	int tam_atual = 0;

	// ler o arquivo em pedaços de MAX bytes
	const int MAX = 512;
	char temp[MAX];
	while (1) {
		int lido = fread(temp, 1, MAX, fd);

		// calcular o novo tamanho e realocar para isso
		// Note que inicialmente, mem=NULL, e o realloc vai alocar memória ao
		// invés de "realocar". Conveniente!
		int novo_tamanho = tam_atual + lido;
		mem = realloc(mem, novo_tamanho);

		// copiar os dados que pegamos do arquivo p/ a memória alocada
		for (int i = 0; i < lido; i++) {
			mem[tam_atual+i] = temp[i];
		}

		// atualizar o tamanho para o novo
		tam_atual = novo_tamanho;

		// Se não foram lidos MAX bytes, quer dizer que ou deu erro ou o arquivo
		// terminou. Vamos parar.
		if (lido < MAX) break;
	}

	// adicionar um '\0' no final
	mem = realloc(mem, tam_atual+1);
	mem[tam_atual] = '\0';

	fclose(fd);

	return mem;
}

void ed_escreverArquivo(const char *path, const char *texto) {
	FILE *fd = fopen(path, "w");
	if (!fd) return;

	int nbytes = strlen(texto);
	fwrite(texto, 1, nbytes, fd);

	fclose(fd);
}
