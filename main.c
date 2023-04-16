#include <stdio.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include <time.h>


int contador = 0; // variável global
char texto[128];

void incrementaContador() {
    contador++;
}

int randX(){
    int x;
    srand(time(NULL)); // inicializa a semente randômica com o tempo atual

    x = rand() % 1921; // gera um número aleatório entre 0 e 1920
    return x;
}

int randY(){
    int y;
    srand(time(NULL)); // inicializa a semente randômica com o tempo atual

    y = rand() % 1921; // gera um número aleatório entre 0 e 1920
    return y;
}

static void create_window()
{   
    GtkWidget *window;
    GtkWidget *label;

    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hidra");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);
    gtk_container_set_border_width(GTK_CONTAINER(window), 100);
    gtk_window_move(GTK_WINDOW(window), randX(), randY());
    

    incrementaContador();
    printf("Cabeças: %d", contador);

    sprintf(texto, "Cabeça da Hidra: %d", contador);
    label = gtk_label_new(texto);
    gtk_container_add(GTK_CONTAINER(window), label);
    
    gtk_widget_show_all(window);

    g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(create_window), NULL);
    

}


int main(int argc, char *argv[]) {
     printf("O código que está rodando é para estudos\n");
   
    
    GtkWidget *window;
    GtkWidget *label;


    gtk_init(&argc, &argv);


    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hidra iniciada");
    label = gtk_label_new("Corte-me a cabeça se for capaz");
    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);


    g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(create_window), NULL);


    gtk_widget_show_all(window);


    gtk_main();

    return 0;


}

//compilar com:
//gcc -o resultado main.c `pkg-config --cflags --libs gtk+-3.0`

//rodar com:
// ./resultado 