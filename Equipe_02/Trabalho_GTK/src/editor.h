#ifndef _EDITOR_H
#define _EDITOR_H

#include <gtk/gtk.h>

typedef struct ed_Editor {
	// a janela
	GtkWidget *window;

	// o widget de texto
	GtkWidget *text_view;

	// o buffer com o conteúdo do widget de texto
	GtkTextBuffer *text_buffer;
} ed_Editor;

/**
 * Lê o conteúdo do arquivo em `path` e o retorna em uma string.
 *
 * A string deve ser apropriadamente liberada com free().
 */
char* ed_lerArquivo(const char *path);

/**
 * Escreve o conteúdo de `texto` no arquivo em `path`.
 */
void ed_escreverArquivo(const char *path, const char *texto);

/**
 * Inicializa o editor e abre a janela principal.
 */
void ed_abrirJanelaPrincipal(void);

#endif
