#include <stdio.h>
#include <stdbool.h>
#include <gtk/gtk.h>

// Função que cria a janela
static void create_window()
{
    GtkWidget *window;
    GtkWidget *label;

    // Cria a janela
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Nova janela");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Cria um label com o texto "Hello World"
    label = gtk_label_new("Hello World");
    gtk_container_add(GTK_CONTAINER(window), label);

    // Exibe a janela
    gtk_widget_show_all(window);

    // Conecta o sinal "delete-event" à função que cria uma nova janela
    g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(create_window), NULL);
}

int main(int argc, char *argv[])
{
    GtkWidget *window;

    // Inicializa o GTK
    gtk_init(&argc, &argv);

    // Cria a primeira janela
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Minha janela");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Conecta o sinal "delete-event" à função que cria uma nova janela
    g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(create_window), NULL);

    // Exibe a primeira janela
    gtk_widget_show_all(window);

    // Inicia o loop principal do GTK
    gtk_main();

    return 0;
}
