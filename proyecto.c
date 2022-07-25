#include <gtk/gtk.h>
#include <stdlib.h>

//En este proyecto desarrolamos un "gato", en cual  dos jugadores en simultaneo hacen parte de una partida.
// Este Juego cuenta con una interfaz grafica,ademas de un ocntador en caso de haber un ganador en la partida. Y un boton de reinicio

// function prototyping
int randomNumberLessThan(int n);
void initialising(GtkButton *buttonInit,int i,int j);
int hasAnyoneWon(int a[3][3]);
void setAllButtonsToBlank();
void computerMove();

// declaring global variables
static GtkButton *statusClick,*diffClick,*gameClick;
static GtkButton *button[3][3]={{NULL,NULL,NULL},{NULL,NULL,NULL},{NULL,NULL,NULL}};

// declaring global flags
static int flag=0, gameNotOver=1, initialise=0, statusFlag=0, pressed[3][3]={{0,0,0},{0,0,0},{0,0,0}};
static int moveCounter=0;

// declaring game parameters
static int arr[3][3]={{0,0,0},{0,0,0},{0,0,0}};#include <gtk/gtk.h>
#include <stdlib.h>

//En este proyecto desarrolamos un "gato", en cual  dos jugadores en simultaneo hacen parte de una partida.
// Este Juego cuenta con una interfaz grafica,ademas de un ocntador en caso de haber un ganador en la partida. Y un boton de reinicio

// function prototyping
int randomNumberLessThan(int n);
void initialising(GtkButton *buttonInit,int i,int j);
int hasAnyoneWon(int a[3][3]);
void setAllButtonsToBlank();
void computerMove();

// declaring global variables
static GtkButton *statusClick,*diffClick,*gameClick;
static GtkButton *button[3][3]={{NULL,NULL,NULL},{NULL,NULL,NULL},{NULL,NULL,NULL}};

// declaring global flags
static int flag=0, gameNotOver=1, initialise=0, statusFlag=0, pressed[3][3]={{0,0,0},{0,0,0},{0,0,0}};
static int moveCounter=0;

// declaring game parameters
static int arr[3][3]={{0,0,0},{0,0,0},{0,0,0}};
static int gameType=0, gameDifficulty=1;

// main method, start of execution
int main(int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

// initialising GTKbuilder with .glade file
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "mainUI.glade", NULL);

// initialising main window widget
    window = GTK_WIDGET (gtk_builder_get_object(builder, "mainWindow"));
    gtk_builder_connect_signals(builder, NULL);

// dereferencing builder pointer (for reuse later)
    g_object_unref(builder);

// showing main window widget
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

// called when quit is selected in settings menu
void on_gameExit_activate()
{
    gtk_main_quit();
    exit(0);
}

// runs the about dialog box
void on_aboutSelection_activate()
{
  GtkWidget   *about;
  GtkBuilder  *builder;

// initialising GTKbuilder with .glade file
  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "mainUI.glade", NULL);

// initialising about widget
  about = GTK_WIDGET(gtk_builder_get_object(builder, "aboutDialog"));
  gtk_builder_connect_signals(builder, NULL);

// dereferencing builder for later use
  g_object_unref(builder);
  gtk_dialog_run (GTK_DIALOG (about));

// when response signal is triggered
  gtk_widget_destroy (about);
}

// when gamemode button is pressed
void on_chooseGamemodeButton_clicked(GtkWidget *click_button, gpointer   user_data)
{
  gameClick = (GtkButton *) user_data;
  if(!statusFlag) return;
  //if(flag)
  //{
    //gtk_button_set_label(statusClick, "EMPEZAR DESDE SELECCIONAR JUEGO");
    //return;
  //}
  //flag=1;
  //enable flag at button press, not here. reset flag to 0 in restart
  //gtk_button_set_label(statusClick, "SELECCION DE MODO DE JUEGO");
  GtkBuilder  *builder;
  GtkWidget   *gameDialog;
// initialising GTKbuilder with .glade file
  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "mainUI.glade", NULL);
// initialising gamemode selection widget
  //gameDialog = GTK_WIDGET(gtk_builder_get_object(builder, "chooseGamemodeDialog"));
  gtk_builder_connect_signals(builder, NULL);
  g_object_unref(builder);
  gtk_dialog_run (GTK_DIALOG (gameDialog));
// when window is closed from the x button in toolbar
  gtk_widget_destroy(gameDialog);
}

// runs when PvP is selected in settings menu
//void on_pvpButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameType = 0;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(gameClick, "PvP");
}*/

// runs the choose difficulty pop up when PvC is selected in settings menu
//void on_pvcButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameType = 1;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(gameClick, "PvC");
}*/

// when difficulty button is pressed
//void on_chooseDifficultyButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
    diffClick = (GtkButton *) user_data;
    gtk_button_set_label(statusClick, "SELECCIONE DIFICULTAD");
    GtkBuilder  *builder;
    GtkWidget   *diffDialog;
  // initialising GTKbuilder with .glade file
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "mainUI.glade", NULL);
  // initialising difficulty selection widget
    diffDialog = GTK_WIDGET(gtk_builder_get_object(builder, "chooseDifficultyDialog"));
    gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);
    gtk_dialog_run (GTK_DIALOG (diffDialog));
  // when window is closed from the x button in toolbar
    gtk_widget_destroy(diffDialog);
}*/

// runs when easy is selected in difficulty selection dialog
//void on_easyButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameDifficulty = 0;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(diffClick, "FACIL ");
}*/

// runs when medium is selected in difficulty selection dialog
//void on_mediumButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameDifficulty = 1;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(diffClick, "MEDIO");
}*/

// runs when hard is selected in difficulty selection dialog
//void on_hardButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameDifficulty = 2;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(diffClick, "DIFICIL");
}*/

/* runs when restart is selected in settings menu. Destroys old window,
 reinitialises all global variables and runs main method */
void on_restartGame_activate(GtkWidget *click_button, gpointer   user_data)
{
  int i,j;
  if(!statusFlag) return;
  //gameDifficulty=0; gameType=0;flag=0;
   moveCounter=0; gameNotOver=1; initialise=0;
  for(i=0;i<3;i++)
  {
      for(j=0;j<3;j++)
      {
          button[i][j]=NULL;
          arr[i][j]=0;
          pressed[i][j]=0;
      }
  }
  setAllButtonsToBlank();
}
static int gameType=0, gameDifficulty=1;

// main method, start of execution
int main(int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

// initialising GTKbuilder with .glade file
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "mainUI.glade", NULL);

// initialising main window widget
    window = GTK_WIDGET (gtk_builder_get_object(builder, "mainWindow"));
    gtk_builder_connect_signals(builder, NULL);

// dereferencing builder pointer (for reuse later)
    g_object_unref(builder);

// showing main window widget
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

// called when quit is selected in settings menu
void on_gameExit_activate()
{
    gtk_main_quit();
    exit(0);
}

// runs the about dialog box
void on_aboutSelection_activate()
{
  GtkWidget   *about;
  GtkBuilder  *builder;

// initialising GTKbuilder with .glade file
  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "mainUI.glade", NULL);

// initialising about widget
  about = GTK_WIDGET(gtk_builder_get_object(builder, "aboutDialog"));
  gtk_builder_connect_signals(builder, NULL);

// dereferencing builder for later use
  g_object_unref(builder);
  gtk_dialog_run (GTK_DIALOG (about));

// when response signal is triggered
  gtk_widget_destroy (about);
}

// when gamemode button is pressed
void on_chooseGamemodeButton_clicked(GtkWidget *click_button, gpointer   user_data)
{
  gameClick = (GtkButton *) user_data;
  if(!statusFlag) return;
  //if(flag)
  //{
    //gtk_button_set_label(statusClick, "EMPEZAR DESDE SELECCIONAR JUEGO");
    //return;
  //}
  //flag=1;
  //enable flag at button press, not here. reset flag to 0 in restart
  //gtk_button_set_label(statusClick, "SELECCION DE MODO DE JUEGO");
  GtkBuilder  *builder;
  GtkWidget   *gameDialog;
// initialising GTKbuilder with .glade file
  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "mainUI.glade", NULL);
// initialising gamemode selection widget
  //gameDialog = GTK_WIDGET(gtk_builder_get_object(builder, "chooseGamemodeDialog"));
  gtk_builder_connect_signals(builder, NULL);
  g_object_unref(builder);
  gtk_dialog_run (GTK_DIALOG (gameDialog));
// when window is closed from the x button in toolbar
  gtk_widget_destroy(gameDialog);
}

// runs when PvP is selected in settings menu
//void on_pvpButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameType = 0;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(gameClick, "PvP");
}*/

// runs the choose difficulty pop up when PvC is selected in settings menu
//void on_pvcButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameType = 1;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(gameClick, "PvC");
}*/

// when difficulty button is pressed
//void on_chooseDifficultyButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
    diffClick = (GtkButton *) user_data;
    gtk_button_set_label(statusClick, "SELECCIONE DIFICULTAD");
    GtkBuilder  *builder;
    GtkWidget   *diffDialog;
  // initialising GTKbuilder with .glade file
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "mainUI.glade", NULL);
  // initialising difficulty selection widget
    diffDialog = GTK_WIDGET(gtk_builder_get_object(builder, "chooseDifficultyDialog"));
    gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);
    gtk_dialog_run (GTK_DIALOG (diffDialog));
  // when window is closed from the x button in toolbar
    gtk_widget_destroy(diffDialog);
}*/

// runs when easy is selected in difficulty selection dialog
//void on_easyButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameDifficulty = 0;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(diffClick, "FACIL ");
}*/

// runs when medium is selected in difficulty selection dialog
//void on_mediumButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameDifficulty = 1;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(diffClick, "MEDIO");
}*/

// runs when hard is selected in difficulty selection dialog
//void on_hardButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  gameDifficulty = 2;
  gtk_widget_destroy((GtkWidget *) user_data);
  gtk_button_set_label(diffClick, "DIFICIL");
}*/

/* runs when restart is selected in settings menu. Destroys old window,
 reinitialises all global variables and runs main method */
void on_restartGame_activate(GtkWidget *click_button, gpointer   user_data)
{
  int i,j;
  if(!statusFlag) return;
  //gameDifficulty=0; gameType=0;flag=0;
   moveCounter=0; gameNotOver=1; initialise=0;
  for(i=0;i<3;i++)
  {
      for(j=0;j<3;j++)
      {
          button[i][j]=NULL;
          arr[i][j]=0;
          pressed[i][j]=0;
      }
  }
  setAllButtonsToBlank();
}

// runs when status button is clicked, used to pass a reference of the status button
//void on_statusButton_clicked(GtkWidget *click_button, gpointer   user_data)
/*{
  statusClick = (GtkButton *) user_data;
  if(!flag)
    {
      gtk_button_set_label(statusClick, "SELECCIONE MODO DE JUEGO DESDE AJUSTES");
      statusFlag=1;
    }
}*/

/* initialising mode is used to get a reference to all the buttons in order to change
their labels in PvC mode. This is a downside of using Glade, as the computer
can not press the button when it's its move */

// runs when button 1,1 is clicked
int on_button11_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // runs if in initialising mode
  if(initialise!=0)
  {
    initialising(buttonTemp,0,0);
    return 0;
  }

  // runs if button has already been pressed either while Initialising or in-game
  if(pressed[0][0]) return 0;

  // runs when button is pressed in-game
  if(flag&&gameNotOver)
  {
    // runs when the button is pressed during an odd move
    if(++moveCounter%2)
    {
      arr[0][0]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[0][0]=1;
      switch(hasAnyoneWon(arr))
      {
        case 0: if(moveCounter==9)
                {
                  gtk_button_set_label(statusClick, "EMPATE");
                  gameNotOver=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 2");
      if(gameType==1) computerMove();
    }
    // runs when the button is pressed during an even move
    else
    {
      arr[0][0]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hasAnyoneWon(arr))
      {
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
    }
    pressed[0][0]=1;
  }
  return 0;
}

// runs when button 1,2 is clicked
int on_button12_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // runs if in initialising mode
  if(initialise!=0)
  {
    initialising(buttonTemp,0,1);
    return 0;
  }

  // runs if button has already been pressed either while Initialising or in-game
  if(pressed[0][1]) return 0;

  // runs when button is pressed in-game
  if(flag&&gameNotOver)
  {
    // runs when the button is pressed during an odd move
    if(++moveCounter%2)
    {
      arr[0][1]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[0][1]=1;
      switch(hasAnyoneWon(arr))
      {
        case 0: if(moveCounter==9)
                {
                  gtk_button_set_label(statusClick, "EMPATE");
                  gameNotOver=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 2 ");
      if(gameType==1) computerMove();
    }
    // runs when the button is pressed during an even move
    else
    {
      arr[0][1]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hasAnyoneWon(arr))
      {
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
    }
    pressed[0][1]=1;
  }
  return 0;
}

// runs when button 1,3 is clicked
int on_button13_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // runs if in initialising mode
  if(initialise!=0)
  {
    initialising(buttonTemp,0,2);
    return 0;
  }

  // runs if button has already been pressed either while Initialising or in-game
  if(pressed[0][2]) return 0;

  // runs when button is pressed in-game
  if(flag&&gameNotOver)
  {
    // runs when the button is pressed during an odd move
    if(++moveCounter%2)
    {
      arr[0][2]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[0][2]=1;
      switch(hasAnyoneWon(arr))
      {
        case 0: if(moveCounter==9)
                {
                  gtk_button_set_label(statusClick, "EMPATE");
                  gameNotOver=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 2 ");
      if(gameType==1) computerMove();
    }
    // runs when the button is pressed during an even move
    else
    {
      arr[0][2]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hasAnyoneWon(arr))
      {
        case 1: gtk_button_set_label(statusClick, "");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
    }
    pressed[0][2]=1;
  }
  return 0;
}

// runs when button 2,1 is clicked
int on_button21_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // runs if in initialising mode
  if(initialise!=0)
  {
    initialising(buttonTemp,1,0);
    return 0;
  }

  // runs if button has already been pressed either while Initialising or in-game
  if(pressed[1][0]) return 0;

  // runs when button is pressed in-game
  if(flag&&gameNotOver)
  {
    // runs when the button is pressed during an odd move
    if(++moveCounter%2)
    {
      arr[1][0]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[1][0]=1;
      switch(hasAnyoneWon(arr))
      {
        case 0: if(moveCounter==9)
                {
                  gtk_button_set_label(statusClick, "EMPATE");
                  gameNotOver=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 2 ");
      if(gameType==1) computerMove();
    }
    // runs when the button is pressed during an even move
    else
    {
      arr[1][0]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hasAnyoneWon(arr))
      {
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
    }
    pressed[1][0]=1;
  }
  return 0;
}

// runs when button 2,2 is clicked
int on_button22_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // runs if in initialising mode
  if(initialise!=0)
  {
    initialising(buttonTemp,1,1);
    return 0;
  }

  // runs if button has already been pressed either while Initialising or in-game
  if(pressed[1][1]) return 0;

  // runs when button is pressed in-game
  if(flag&&gameNotOver)
  {
    // runs when the button is pressed during an odd move
    if(++moveCounter%2)
    {
      arr[1][1]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[1][1]=1;
      switch(hasAnyoneWon(arr))
      {
        case 0: if(moveCounter==9)
                {
                  gtk_button_set_label(statusClick, "EMPATE");
                  gameNotOver=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 2 ");
      if(gameType==1) computerMove();
    }
    // runs when the button is pressed during an even move
    else
    {
      arr[1][1]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hasAnyoneWon(arr))
      {
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
    }
    pressed[1][1]=1;
  }
  return 0;
}

// runs when button 2,3 is clicked
int on_button23_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // runs if in initialising mode
  if(initialise!=0)
  {
    initialising(buttonTemp,1,2);
    return 0;
  }

  // runs if button has already been pressed either while Initialising or in-game
  if(pressed[1][2]) return 0;

  // runs when button is pressed in-game
  if(flag&&gameNotOver)
  {
    // runs when the button is pressed during an odd move
    if(++moveCounter%2)
    {
      arr[1][2]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[1][2]=1;
      switch(hasAnyoneWon(arr))
      {
        case 0: if(moveCounter==9)
                {
                  gtk_button_set_label(statusClick, "EMPATE");
                  gameNotOver=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 2 ");
      if(gameType==1) computerMove();
    }
    // runs when the button is pressed during an even move
    else
    {
      arr[1][2]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hasAnyoneWon(arr))
      {
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
    }
    pressed[1][2]=1;
  }
  return 0;
}

// runs when button 3,1 is clicked
int on_button31_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // runs if in initialising mode
  if(initialise!=0)
  {
    initialising(buttonTemp,2,0);
    return 0;
  }

  // runs if button has already been pressed either while Initialising or in-game
  if(pressed[2][0]) return 0;

  // runs when button is pressed in-game
  if(flag&&gameNotOver)
  {
    // runs when the button is pressed during an odd move
    if(++moveCounter%2)
    {
      arr[2][0]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[2][0]=1;
      switch(hasAnyoneWon(arr))
      {
        case 0: if(moveCounter==9)
                {
                  gtk_button_set_label(statusClick, "EMPATE");
                  gameNotOver=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 2 ");
      if(gameType==1) computerMove();
    }
    // runs when the button is pressed during an even move
    else
    {
      arr[2][0]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hasAnyoneWon(arr))
      {
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
    }
    pressed[2][0]=1;
  }
  return 0;
}

// runs when button 3,2 is clicked
int on_button32_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(buttonTemp,2,1);
      return 0;
  }

  // runs if button has already been pressed either while Initialising or in-game
  if(pressed[2][1]) return 0;

  // runs when button is pressed in-game
  if(flag&&gameNotOver)
  {
    // runs when the button is pressed during an odd move
    if(++moveCounter%2)
    {
      arr[2][1]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[2][1]=1;
      switch(hasAnyoneWon(arr))
      {
        case 0: if(moveCounter==9)
                {
                  gtk_button_set_label(statusClick, "EMPATE");
                  gameNotOver=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 2 ");
      if(gameType==1) computerMove();
    }
    // runs when the button is pressed during an even move
    else
    {
      arr[2][1]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hasAnyoneWon(arr))
      {
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
    }
    pressed[2][1]=1;
  }
  return 0;
}

// runs when button 3,3 is clicked
int on_button33_clicked(GtkWidget *click_button, gpointer   user_data)
{
  GtkButton *buttonTemp = (GtkButton *) user_data;

  // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(buttonTemp,2,2);
      return 0;
  }

  // runs if button has already been pressed either while Initialising or in-game
  if(pressed[2][2]) return 0;

  // runs when button is pressed in-game
  if(flag&&gameNotOver)
  {
    // runs when the button is pressed during an odd move
    if(++moveCounter%2)
    {
      arr[2][2]=1;
      gtk_button_set_label(buttonTemp, "X");
      pressed[2][2]=1;
      switch(hasAnyoneWon(arr))
      {
        case 0: if(moveCounter==9)
                {
                  gtk_button_set_label(statusClick, "EMPATE");
                  gameNotOver=0; return 0;
                } break;
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 2 ");
      if(gameType==1) computerMove();
    }
    // runs when the button is pressed during an even move
    else
    {
      arr[2][2]=2;
      gtk_button_set_label(buttonTemp, "O");
      switch(hasAnyoneWon(arr))
      {
        case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
                gameNotOver=0; return 0;
        case 2: gtk_button_set_label(statusClick, "JUGADOR 2 HA GANADO ");
                gameNotOver=0; return 0;
      }
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
    }
    pressed[2][2]=1;
  }
  return 0;
}

/* function for checking if whether any row, column or diagonal is completely
filled by either 0, 1, or 2 and returns either 0,1 or 2 */
int hasAnyoneWon(int a[3][3])
{
  int oneWon=0; int twoWon=0; int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(a[i][j]==1) oneWon++;
      if(a[i][j]==2) twoWon++;
    }
    if(oneWon==3) return 1;
    if(twoWon==3) return 2;
    oneWon=0; twoWon=0;
  }
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(a[j][i]==1) oneWon++;
      if(a[j][i]==2) twoWon++;
    }
    if(oneWon==3) return 1;
    if(twoWon==3) return 2;
    oneWon=0; twoWon=0;
  }
  for(i=0;i<3;i++)
  {
    if(a[i][i]==1) oneWon++;
    if(a[i][i]==2) twoWon++;
  }
  if(oneWon==3) return 1;
  if(twoWon==3) return 2;
  oneWon=0; twoWon=0;
  for(i=0,j=2;i<3;i++,j--)
  {
    if(a[i][j]==1) oneWon++;
    if(a[i][j]==2) twoWon++;
  }
  if(oneWon==3) return 1;
  if(twoWon==3) return 2;
  return 0;
}

// called after initialising mode is completed to reset buttons
void setAllButtonsToBlank()
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

/* called when it's the computers move. The logic works in such way as to rank
each playable button with a puntaje. If the button has already been pressed, scoring
that button is skipped. Scoring is done in two steps, the first step involves increasing
the puntaje of the button by 1 for each empty button in its row, column, and diagonal
(if it's either in the primary or secondary diagonal). the second step involves
checking whether Player 1 or Computer is about to win, and setting a higher puntaje
to those buttons which either block the winning move or play the winning move. playing
the winning move is puntajed higher than blocking TURNO DEL JUGADOR 1. Lastly, puntajes are
added to certain buttons to block Player 1 from reaching to the point where he/she
is assured a garuanteed win. The move to be played is randomised based on the
difficulty. Higher the difficulty, higher the chance that the ideal move is played. */

//void computerMove()
/*{
  int i,j,k,l,best=0,x,y;
  int tempGame[3][3];
  int puntaje[3][3]={{0,0,0},{0,0,0},{0,0,0}};
  moveCounter++;

  // coping game into a temporary array, to be used for checking if someone is about to win
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      tempGame[i][j]=arr[i][j];
    }
  }

  // running through all 9 buttons
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {

      // if a move has already been played in the button
      if(pressed[i][j]) continue;

      // adds puntaje for column and row
      for(k=0;k<3;k++)
      {
        if(arr[i][k]==0) puntaje[i][j]++;
        if(arr[k][j]==0) puntaje[i][j]++;
      }

      // adds puntaje for primary diagonal
      if((i==0&&j==0)||(i==2&&j==2)||(i==1&&j==1))
      {
        for(k=0;k<3;k++)
          if(arr[k][k]==0) puntaje[i][j]++;
      }

      // adds puntaje for secondary diagonal
      if((i==0&&j==2)||(i==2&&j==0)||(i==1&&j==1))
      {
        for(k=0,l=2;k<3;k++,l--)
          if(arr[k][l]==0) puntaje[i][j]++;
      }

      // checks if playing the button causes player 1 to win
      tempGame[i][j]=1;
      if(hasAnyoneWon(tempGame)==1) puntaje[i][j]+=100;

      // checks if playing the button causes computer to win
      tempGame[i][j]=2;
      if(hasAnyoneWon(tempGame)==2) puntaje[i][j]+=200;

      // resets the temporary game array
      tempGame[i][j]=0;
    }
  }

  // adjusting puntajes for certain edge cases to prevent player 1 from assured victory
  if(moveCounter==4)
  {
    if((arr[0][0]==1&&arr[2][2]==1)||(arr[0][2]==1&&arr[2][0]==1))
    puntaje[1][0]=300;
    if((arr[0][1]==1&&arr[1][0]==1)||(arr[1][0]==1&&arr[0][2]==1)||(arr[0][1]==1&&arr[2][0]==1))
    puntaje[0][0]=300;
    if((arr[0][1]==1&&arr[1][2]==1)||(arr[0][1]==1&&arr[2][2]==1)||(arr[1][2]==1&&arr[0][0]==1))
    puntaje[0][2]=300;
    if((arr[1][2]==1&&arr[2][1]==1)||(arr[1][2]==1&&arr[2][0]==1)||(arr[2][1]==1&&arr[0][2]==1))
    puntaje[2][2]=300;
    if((arr[2][1]==1&&arr[1][0]==1)||(arr[2][1]==1&&arr[0][0]==1)||(arr[1][0]==1&&arr[2][2]==1))
    puntaje[2][0]=300;
  }

  // finds the highest puntajed button
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(puntaje[i][j]>best)
      {
        best=puntaje[i][j]; x=i; y=j;
      }
    }
  }

    // alters the highest puntajed move to be played if a random number matches criteria, lower chance
    if(gameDifficulty==1)
    {
        if(randomNumberLessThan(10)<4)
	    {
		    do
		    {
		    	x=randomNumberLessThan(3); y=randomNumberLessThan(3);
		    }
		    while(pressed[x][y]);
	    }
    }

    // alters the highest puntajed move to be played if a random number matches criteria, higher chance
    if(gameDifficulty==0)
    {
		if(randomNumberLessThan(10)<7)
		{
			do
			{
				x=randomNumberLessThan(3); y=randomNumberLessThan(3);
			}
			while(pressed[x][y]);
		}
	}

  // plays the chosen button
  arr[x][y]=2;
  pressed[x][y]=1;
  gtk_button_set_label(button[x][y], "O");
  gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");

  // checks to see if anyone won
  switch(hasAnyoneWon(arr))
  {
    case 1: gtk_button_set_label(statusClick, "JUGADOR 1 HA GANADO ");
            gameNotOver=0;
            break;
    case 2: gtk_button_set_label(statusClick, "HA GANADO LA COMPUTADORA");
            gameNotOver=0;
            break;
  }
}*/

// runs for the first time each button is pressed
void initialising(GtkButton *buttonInit,int i,int j)
{
    if(button[i][j]!=NULL) return;
    button[i][j]=buttonInit;
    gtk_button_set_label(button[i][j], "OK");
    if(++initialise==10)
    {
      initialise=0;
      gtk_button_set_label(statusClick, "TURNO DEL JUGADOR 1");
      setAllButtonsToBlank();
    }
}

// random number generator, in the range of 0 < x < n
int randomNumberLessThan(int n)
{
    return (double)rand()*n/RAND_MAX;
}
// end of program
