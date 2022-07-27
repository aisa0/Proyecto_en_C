/* Proyecto en C para el curso IE-0117 Programación Bajo Plataformas Abiertas
Elaborado por:
Ariel Mora
Isabel Sabater
Jose Acevedo
Este proyecto consiste en la creación de un juego de Gato (3 en línea o Tic Tac Toe)
El juego cuenta con una interfaz gráfica desarrollada en GTK, su modo de juego consiste
en inicializarlo mediante el botón de Iniciar juego, y crea un tablero para dos
jugadores, uno asociado a la letra X y el otro asociado a la letra O.
El objetivo es conseguir que tres de las letras coincidan en una fila vertical,
horizontal o diagonal, gana el primero que lo consiga.
*/

#include <gtk/gtk.h>
#include <stdlib.h>

// Inicialización del programa.
void init(GtkButton *buttonInit,int i,int j);
int hayGanador(int a[3][3]);
void todosBotonesBlanco();

// Se define el botón de estado que sirve para definir ganadores.
static GtkButton *statusClick;
static GtkButton *button[3][3]={{NULL,NULL,NULL},{NULL,NULL,NULL},{NULL,NULL,NULL}};

// Declaración de variables globales.
static int flag=0, juegoNoTerminado=1, iniciado=0, playingFlag=0, pressed[3][3]={{0,0,0},{0,0,0},{0,0,0}};
static int moverContador=0;

// Declaración de los parámetros deljuego.
static int arr[3][3]={{0,0,0},{0,0,0},{0,0,0}};

// Inicio de ejecución del main.
int main(int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

// Inicialización de GTK.
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "mainUI.glade", NULL);

// Inicialización de la ventana principal.
    window = GTK_WIDGET (gtk_builder_get_object(builder, "mainWindow"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

// Programación del botón de salir.
void on_gameExit_activate()
{
    gtk_main_quit();
    exit(0);
}

// Código para el botón de Acerca de...
void on_aboutSelection_activate()
{
  GtkWidget   *about;
  GtkBuilder  *builder;

// Llamamiento del archivo Glade.
  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "mainUI.glade", NULL);

// Inicialización del widget de Acerca de...
  about = GTK_WIDGET(gtk_builder_get_object(builder, "aboutDialog"));
  gtk_builder_connect_signals(builder, NULL);

  g_object_unref(builder);
  gtk_dialog_run (GTK_DIALOG (about));
  gtk_widget_destroy (about);
}

// ESTA SECCION SE ENCARGA DEL BOTON PARA INICIAR EL JUEGO Y STATUS DEL JUEGO
void on_statusButton_clicked(GtkWidget *click_button, gpointer   user_data)
{
  statusClick = (GtkButton *) user_data;

  if(!flag)
    {
      gtk_button_set_label(statusClick, "Jugando");
      playingFlag=1;
      flag = 1;
    }
}


// ESTA SECCION SE ENCARGA DE LA LÓGICA EN EL TABLERO
// Los enteros on_buttonxx_clicked estan asociados a los handlers dentro de Glade
int on_button11_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // Inicializar un modo.
  if(iniciado!=0)
  {
    init(buttonTemp,0,0);
    return 0;
  }

  // Protección en caso de que el botón sea presionado antes de que se active.
  if(pressed[0][0]) return 0;

  // Para cuando el bot+on es presionado in-game
  if(flag&&juegoNoTerminado)
  {

  // Esta parte del código corre cuando se hace movida en turno impar y par respectivamente.
  // Este en específico activa la casilla 1,1 que esla esquina superior izquierda.
  // Se va a replicar para todas las casillas del tablero.
    if(++moverContador%2)
    {
      arr[0][0]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[0][0]=1;
      switch(hayGanador(arr))
      {
        case 0: if(moverContador==9)
                {
                  gtk_button_set_label(statusClick, "¡Empate!");
                  juegoNoTerminado=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 2...");
    }

    else
    {
      arr[0][0]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hayGanador(arr))
      {
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 1...");
    }
    pressed[0][0]=1;
  }
  return 0;
}

// Pära la casilla 1,2
int on_button12_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  if(iniciado!=0)
  {
    init(buttonTemp,0,1);
    return 0;
  }

  if(pressed[0][1]) return 0;

  if(flag&&juegoNoTerminado)
  {
    if(++moverContador%2)
    {
      arr[0][1]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[0][1]=1;
      switch(hayGanador(arr))
      {
        case 0: if(moverContador==9)
                {
                  gtk_button_set_label(statusClick, "¡Empate!");
                  juegoNoTerminado=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 2...");
    }

    else
    {
      arr[0][1]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hayGanador(arr))
      {
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 1...");
    }
    pressed[0][1]=1;
  }
  return 0;
}

// Para el botón 1,3
int on_button13_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  if(iniciado!=0)
  {
    init(buttonTemp,0,2);
    return 0;
  }

  if(pressed[0][2]) return 0;

  if(flag&&juegoNoTerminado)
  {
    if(++moverContador%2)
    {
      arr[0][2]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[0][2]=1;
      switch(hayGanador(arr))
      {
        case 0: if(moverContador==9)
                {
                  gtk_button_set_label(statusClick, "¡Empate!");
                  juegoNoTerminado=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 2...");
    }

    else
    {
      arr[0][2]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hayGanador(arr))
      {
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 1...");
    }
    pressed[0][2]=1;
  }
  return 0;
}

// Para el botón 2,1
int on_button21_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  if(iniciado!=0)
  {
    init(buttonTemp,1,0);
    return 0;
  }

  if(pressed[1][0]) return 0;

  if(flag&&juegoNoTerminado)
  {
    if(++moverContador%2)
    {
      arr[1][0]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[1][0]=1;
      switch(hayGanador(arr))
      {
        case 0: if(moverContador==9)
                {
                  gtk_button_set_label(statusClick, "¡Empate!");
                  juegoNoTerminado=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 2...");
    }

    else
    {
      arr[1][0]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hayGanador(arr))
      {
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 1...");
    }
    pressed[1][0]=1;
  }
  return 0;
}

// Para el botón 2,2
int on_button22_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  if(iniciado!=0)
  {
    init(buttonTemp,1,1);
    return 0;
  }

  if(pressed[1][1]) return 0;

  if(flag&&juegoNoTerminado)
  {
    if(++moverContador%2)
    {
      arr[1][1]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[1][1]=1;
      switch(hayGanador(arr))
      {
        case 0: if(moverContador==9)
                {
                  gtk_button_set_label(statusClick, "¡Empate!");
                  juegoNoTerminado=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 2...");
    }

    else
    {
      arr[1][1]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hayGanador(arr))
      {
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 1...");
    }
    pressed[1][1]=1;
  }
  return 0;
}

// Para el botón 2,3
int on_button23_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  if(iniciado!=0)
  {
    init(buttonTemp,1,2);
    return 0;
  }

  if(pressed[1][2]) return 0;

  if(flag&&juegoNoTerminado)
  {
    if(++moverContador%2)
    {
      arr[1][2]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[1][2]=1;
      switch(hayGanador(arr))
      {
        case 0: if(moverContador==9)
                {
                  gtk_button_set_label(statusClick, "¡Empate!");
                  juegoNoTerminado=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 2...");
    }

    else
    {
      arr[1][2]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hayGanador(arr))
      {
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 1...");
    }
    pressed[1][2]=1;
  }
  return 0;
}

// Para el botón 3,1
int on_button31_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  if(iniciado!=0)
  {
    init(buttonTemp,2,0);
    return 0;
  }

  if(pressed[2][0]) return 0;

  if(flag&&juegoNoTerminado)
  {
    if(++moverContador%2)
    {
      arr[2][0]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[2][0]=1;
      switch(hayGanador(arr))
      {
        case 0: if(moverContador==9)
                {
                  gtk_button_set_label(statusClick, "¡Empate!");
                  juegoNoTerminado=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 2...");
    }

    else
    {
      arr[2][0]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hayGanador(arr))
      {
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 1...");
    }
    pressed[2][0]=1;
  }
  return 0;
}

// Para el botón 3,2
int on_button32_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  if(iniciado!=0)
  {
      init(buttonTemp,2,1);
      return 0;
  }

  if(pressed[2][1]) return 0;

  if(flag&&juegoNoTerminado)
  {
    if(++moverContador%2)
    {
      arr[2][1]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[2][1]=1;
      switch(hayGanador(arr))
      {
        case 0: if(moverContador==9)
                {
                  gtk_button_set_label(statusClick, "¡Empate!");
                  juegoNoTerminado=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 2...");
    }

    else
    {
      arr[2][1]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hayGanador(arr))
      {
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 1...");
    }
    pressed[2][1]=1;
  }
  return 0;
}

// Para el botón 3,3
int on_button33_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  if(iniciado!=0)
  {
      init(buttonTemp,2,2);
      return 0;
  }

  if(pressed[2][2]) return 0;

  if(flag&&juegoNoTerminado)
  {
    if(++moverContador%2)
    {
      arr[2][2]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[2][2]=1;
      switch(hayGanador(arr))
      {
        case 0: if(moverContador==9)
                {
                  gtk_button_set_label(statusClick, "¡Empate!");
                  juegoNoTerminado=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 2...");
    }

    else
    {
      arr[2][2]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hayGanador(arr))
      {
        case 1: gtk_button_set_label(statusClick, "¡Jugador 1 gana!");
                juegoNoTerminado=0; return 0;
        case 2: gtk_button_set_label(statusClick, "¡Jugador 2 gana!");
                juegoNoTerminado=0; return 0;
      }
      gtk_button_set_label(statusClick, "Turno del jugador 1...");
    }
    pressed[2][2]=1;
  }
  return 0;
}

// ESTA SECCION REVISA SI HAY TRES X U O EN LINEA
// Es la sección encargada de dictar las condiciones de gane del juego.
int hayGanador(int a[3][3])
{
  int unoGana=0; int dosGana=0; int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(a[i][j]==1) unoGana++;
      if(a[i][j]==2) dosGana++;
    }
    if(unoGana==3) return 1;
    if(dosGana==3) return 2;
    unoGana=0; dosGana=0;
  }
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(a[j][i]==1) unoGana++;
      if(a[j][i]==2) dosGana++;
    }
    if(unoGana==3) return 1;
    if(dosGana==3) return 2;
    unoGana=0; dosGana=0;
  }
  for(i=0;i<3;i++)
  {
    if(a[i][i]==1) unoGana++;
    if(a[i][i]==2) dosGana++;
  }
  if(unoGana==3) return 1;
  if(dosGana==3) return 2;
  unoGana=0; dosGana=0;
  for(i=0,j=2;i<3;i++,j--)
  {
    if(a[i][j]==1) unoGana++;
    if(a[i][j]==2) dosGana++;
  }
  if(unoGana==3) return 1;
  if(dosGana==3) return 2;
  return 0;
}

// ESTA SECCION VUELVE A COLOCAR TODOS LOS BOTONES EN " "
// Hace que todos los botones inicien en blanco para empezar el juego.
void todosBotonesBlanco()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            gtk_button_set_label(button[i][j], " ");
        }
    }
}


// Éste es el botón de inicialización.
void init(GtkButton *buttonInit,int i,int j)
{
    if(button[i][j]!=NULL) return;
    button[i][j]=buttonInit;
    gtk_button_set_label(button[i][j], "Probando");
    if(++iniciado==10)
    {
      iniciado=0;
      gtk_button_set_label(statusClick, "Turno jugador 1");
      todosBotonesBlanco();
    }
}

// Última línea de código, este es el final del programa.
