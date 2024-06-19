#include "editor.h"

int main(int argc, char **argv) {
	gtk_init(&argc, &argv); // inicializar o GTK
	ed_abrirJanelaPrincipal(); // abrir a janela
	gtk_main(); // main loop

	return 0;
}
