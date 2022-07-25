#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

 GtkWidget *window;

 GtkWidget *upperLeftButton;
 GtkWidget *upperMidButton;
 GtkWidget *upperRightButton;
 GtkWidget *midLeftButton;
 GtkWidget *midMidButton;
 GtkWidget *midRightButton;
 GtkWidget *lowerLeftButton;
 GtkWidget *lowerMidButton;
 GtkWidget *lowerRightButton;

GtkWidget *col1;
GtkWidget *col2;
GtkWidget *col3;
GtkWidget *hbox;

int c = 0;
char ticTacToeBoard[3][3] =
{
    {'0','0','0'},{'0','0','0'},{'0','0','0'}
};
 void upperLeftButton(GtkWidget *widget, gpointer data)
{
        if(c%2 == 0)
        {
            upperLeftButton = gtk_button_new_with_label("X");
            gtk_box_pack_start(GTK_BOX(col1), upperLeftButton, TRUE, TRUE, 0);
            gtk_widget_show(upperLeftButton);
            c = c +1;
            ticTacToeBoard[0][0] = 'X';
                if(ticTacToeBoard[0][0] == ticTacToeBoard[0][1] && ticTacToeBoard[0][0] == ticTacToeBoard[0][2])
                    printf("Player 1 wins");

                else if(ticTacToeBoard[0][0] == ticTacToeBoard[1][0] && ticTacToeBoard[0][0] == ticTacToeBoard[2][0])
                    printf("Player 1 wins");

                else if(ticTacToeBoard[0][0] == ticTacToeBoard[1][1] && ticTacToeBoard[0][0] == ticTacToeBoard [2][2])
                    printf("Player 1 wins");
        }

         else if(c%2  == 1)
               { upperLeftButton = gtk_button_new_with_label("O");
                 gtk_box_pack_start(GTK_BOX(col1), upperLeftButton, TRUE, TRUE, 0);
                   gtk_widget_show(upperLeftButton);
       c = c +1;
                  ticTacToeBoard[0][0] = 'O';
         if(ticTacToeBoard[0][0] == ticTacToeBoard[0][1] && ticTacToeBoard[0][0] == ticTacToeBoard[0][2])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[0][0] == ticTacToeBoard[1][0] && ticTacToeBoard[0][0] == ticTacToeBoard[2][0])
         printf("Player 2 wins!");
        else if(ticTacToeBoard[0][0] == ticTacToeBoard[1][1] && ticTacToeBoard[0][0] == ticTacToeBoard[2][2])
        printf("Player 2 wins!");
      }
}

void upperMidButton(GtkWidget *widget, gpointer   data)
    {
        if(c%2 == 0)
        {
        upperMidButton = gtk_button_new_with_label("X");
        gtk_box_pack_start(GTK_BOX(col2), upperMidButton, TRUE, TRUE, 0);
        gtk_widget_show(upperMidButton);
            c = c +1;

        ticTacToeBoard[0][1] = 'X';
            if(ticTacToeBoard[0][0] == ticTacToeBoard[0][1] && ticTacToeBoard[0][0] == ticTacToeBoard[0][2])
                printf("Player 1 wins!");
            else if(ticTacToeBoard[0][1] == ticTacToeBoard[1][1] && ticTacToeBoard[0][1] == ticTacToeBoard[2][1])
                printf("Player 1 wins!");
        }

            else if(c%2  == 1)
            {
            upperMidButton = gtk_button_new_with_label("O");
            gtk_box_pack_start(GTK_BOX(col2), upperMidButton, TRUE, TRUE, 0);
            gtk_widget_show(upperMidButton);
                c = c +1;
                ticTacToeBoard[0][1] = 'O';
            if(ticTacToeBoard[0][0] == ticTacToeBoard[0][1] && ticTacToeBoard[0][0] == ticTacToeBoard[0][2])
                printf("Player 2 wins!");

            else if(ticTacToeBoard[0][1] == ticTacToeBoard[1][1] && ticTacToeBoard[0][1] == ticTacToeBoard[2][1])
                printf("Player 2 wins!");
            }

    }

         void toprightButton(GtkWidget *widget,
                      gpointer   data)
                           {

           if(c%2 == 0)
     { topRightButton = gtk_button_new_with_label("X");
       gtk_box_pack_start(GTK_BOX(col3), topRightButton, TRUE, TRUE, 0);
      gtk_widget_show(topRightButton);
                 c = c +1;
    ticTacToeBoard[0][2] = 'X';
      if(ticTacToeBoard[0][0] == ticTacToeBoard[0][1] && ticTacToeBoard[0][0] == ticTacToeBoard[0][2])
            printf("Player 1 wins!");
              else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][2] && ticTacToeBoard[0][2] == ticTacToeBoard[2][2])
                    printf("Player 1 wins!");
                 else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][1] && ticTacToeBoard[0][2] == ticTacToeBoard[2][0])
                    printf("Player 1 wins!");

          }
          else if(c%2  == 1)
               { topRightButton = gtk_button_new_with_label("O");
                gtk_box_pack_start(GTK_BOX(col3), topRightButton, TRUE, TRUE, 0);
                   gtk_widget_show(topRightButton);
       c = c +1;
                  ticTacToeBoard[0][2] = 'O';
         if(ticTacToeBoard[0][0] == ticTacToeBoard[0][1] && ticTacToeBoard[0][0] == ticTacToeBoard[0][2])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][2] && ticTacToeBoard[0][2] == ticTacToeBoard[2][2])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][1] && ticTacToeBoard[2][0] == ticTacToeBoard[0][2])
         printf("Player 2 wins!");
      }
        }

          void midleftButton(GtkWidget *widget,
                      gpointer   data)
                           {

           if(c%2 == 0)
     { midLeftButton = gtk_button_new_with_label("X");
       gtk_box_pack_start(GTK_BOX(col1), midLeftButton, TRUE, TRUE, 0);
      gtk_widget_show(midLeftButton);
                 c = c +1;
    ticTacToeBoard[1][0] = 'X';
      if(ticTacToeBoard[0][0] == ticTacToeBoard[1][0] && ticTacToeBoard[1][0] == ticTacToeBoard[2][0])
            printf("Player 1 wins!");
              else if(ticTacToeBoard[1][0] == ticTacToeBoard[1][1] && ticTacToeBoard[1][0] == ticTacToeBoard[1][2])
                    printf("Player 1 wins!");


          }
          else if(c%2  == 1)
               { midLeftButton = gtk_button_new_with_label("O");
                 gtk_box_pack_start(GTK_BOX(col1), midLeftButton, TRUE, TRUE, 0);
                   gtk_widget_show(midLeftButton);
       c = c +1;
                  ticTacToeBoard[1][0] = 'O';
         if(ticTacToeBoard[0][0] == ticTacToeBoard[1][0] && ticTacToeBoard[0][0] == ticTacToeBoard[2][0])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[1][0] == ticTacToeBoard[1][1] && ticTacToeBoard[1][0] == ticTacToeBoard[1][2])
         printf("Player 2 wins!");
  }

        }


          void midmidButton(GtkWidget *widget,
                      gpointer   data)
                           {

           if(c%2 == 0)
     { midMidButton = gtk_button_new_with_label("X");
       gtk_box_pack_start(GTK_BOX(col2), midMidButton, TRUE, TRUE, 0);
      gtk_widget_show(midMidButton);
                 c = c +1;
    ticTacToeBoard[1][1] = 'X';
      if(ticTacToeBoard[0][0] == ticTacToeBoard[1][1] && ticTacToeBoard[0][0] == ticTacToeBoard[2][2])
            printf("Player 1 wins!");
              else if(ticTacToeBoard[1][0] == ticTacToeBoard[1][1] && ticTacToeBoard[1][0] == ticTacToeBoard[1][2])
                    printf("Player 1 wins!");
                else if(ticTacToeBoard[0][1] == ticTacToeBoard[1][1] && ticTacToeBoard[0][1] == ticTacToeBoard[2][1])
                    printf("Player 1 wins!");
                 else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][1] && ticTacToeBoard[2][0] == ticTacToeBoard[1][1])
                    printf("Player 1 wins!");


          }
          else if(c%2  == 1)
               { midMidButton = gtk_button_new_with_label("O");
                 gtk_box_pack_start(GTK_BOX(col2), midMidButton, TRUE, TRUE, 0);
                   gtk_widget_show(midMidButton);
       c = c +1;
                  ticTacToeBoard[1][1] = 'O';
         if(ticTacToeBoard[0][0] == ticTacToeBoard[1][1] && ticTacToeBoard[0][0] == ticTacToeBoard[2][2])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[1][0] == ticTacToeBoard[1][1] && ticTacToeBoard[1][0] == ticTacToeBoard[1][2])
         printf("Player 2 wins!");
        else if(ticTacToeBoard[0][1] == ticTacToeBoard[1][1] && ticTacToeBoard[0][1] == ticTacToeBoard[2][1])
                    printf("Player 2 wins!");
        else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][1] && ticTacToeBoard[2][0] == ticTacToeBoard[1][1])
                    printf("Player 2 wins!");
      }
        }


     void midrightButton(GtkWidget *widget,
                      gpointer   data)
                           {

           if(c%2 == 0)
     { midRightButton = gtk_button_new_with_label("X");
       gtk_box_pack_start(GTK_BOX(col3), midRightButton, TRUE, TRUE, 0);
      gtk_widget_show(midRightButton);
                 c = c +1;
    ticTacToeBoard[1][2] = 'X';
      if(ticTacToeBoard[1][0] == ticTacToeBoard[1][1] && ticTacToeBoard[1][0] == ticTacToeBoard[1][2])
            printf("Player 1 wins!");
              else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][2] && ticTacToeBoard[0][2] == ticTacToeBoard[2][2])
                    printf("Player 1 wins!");



          }
          else if(c%2  == 1)
               { midRightButton = gtk_button_new_with_label("O");
                 gtk_box_pack_start(GTK_BOX(col3), midRightButton, TRUE, TRUE, 0);
                   gtk_widget_show(midRightButton);
       c = c +1;
                  ticTacToeBoard[1][2] = 'O';
         if(ticTacToeBoard[1][0] == ticTacToeBoard[1][1] && ticTacToeBoard[1][0] == ticTacToeBoard[1][2])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][2] && ticTacToeBoard[0][2] == ticTacToeBoard[2][2])
         printf("Player 2 wins!");
        }

        }

        void lowleftButton(GtkWidget *widget,
                    gpointer  data)
     {


       if(c%2 == 0)
               {   lowLeftButton = gtk_button_new_with_label("X");
                     gtk_box_pack_start(GTK_BOX(col1), lowLeftButton, TRUE, TRUE, 0);
                           gtk_widget_show(lowLeftButton);
              c = c +1;
                    ticTacToeBoard[2][0] = 'X';
                   if(ticTacToeBoard[2][0] == ticTacToeBoard[2][1] && ticTacToeBoard[2][0] == ticTacToeBoard[2][2])
                       printf("Player 1 wins!");
                   else if(ticTacToeBoard[2][0] == ticTacToeBoard[1][0] && ticTacToeBoard[0][0] == ticTacToeBoard[2][0])
                       printf("Player 1 wins!");
                   else if(ticTacToeBoard[2][0] == ticTacToeBoard[1][1] && ticTacToeBoard[0][2] == ticTacToeBoard [2][0])
                       printf("Player 1 wins!");

                   }
         else if(c%2  == 1)
               { lowLeftButton = gtk_button_new_with_label("O");
                 gtk_box_pack_start(GTK_BOX(col1), lowLeftButton, TRUE, TRUE, 0);
                   gtk_widget_show(lowLeftButton);
       c = c +1;
                  ticTacToeBoard[2][0] = 'O';
         if(ticTacToeBoard[2][0] == ticTacToeBoard[2][1] && ticTacToeBoard[2][0] == ticTacToeBoard[2][2])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[0][0] == ticTacToeBoard[1][0] && ticTacToeBoard[0][0] == ticTacToeBoard[2][0])
         printf("Player 2 wins!");
        else if(ticTacToeBoard[2][0] == ticTacToeBoard[1][1] && ticTacToeBoard[2][0] == ticTacToeBoard[0][2])
        printf("Player 2 wins!");
      }
        }


         void lowmidButton(GtkWidget *widget,
                      gpointer   data)
                           {

           if(c%2 == 0)
     { lowMidButton = gtk_button_new_with_label("X");
       gtk_box_pack_start(GTK_BOX(col2), lowMidButton, TRUE, TRUE, 0);
      gtk_widget_show(lowMidButton);
                 c = c +1;
    ticTacToeBoard[2][1] = 'X';
      if(ticTacToeBoard[2][0] == ticTacToeBoard[2][1] && ticTacToeBoard[2][0] == ticTacToeBoard[2][2])
            printf("Player 1 wins!");
              else if(ticTacToeBoard[0][1] == ticTacToeBoard[1][1] && ticTacToeBoard[0][1] == ticTacToeBoard[2][1])
                    printf("Player 1 wins!");


          }
          else if(c%2  == 1)
               { lowMidButton = gtk_button_new_with_label("O");
                 gtk_box_pack_start(GTK_BOX(col2), lowMidButton, TRUE, TRUE, 0);
                   gtk_widget_show(lowMidButton);
       c = c +1;
                  ticTacToeBoard[2][1] = 'O';
         if(ticTacToeBoard[2][0] == ticTacToeBoard[2][1] && ticTacToeBoard[2][0] == ticTacToeBoard[2][2])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[0][1] == ticTacToeBoard[1][1] && ticTacToeBoard[0][1] == ticTacToeBoard[2][1])
         printf("Player 2 wins!");

      }
        }

         void lowrightButton(GtkWidget *widget,
                      gpointer   data)
                           {

           if(c%2 == 0)
     { lowRightButton = gtk_button_new_with_label("X");
       gtk_box_pack_start(GTK_BOX(col3), lowRightButton, TRUE, TRUE, 0);
      gtk_widget_show(lowRightButton);
                 c = c +1;
    ticTacToeBoard[2][2] = 'X';
      if(ticTacToeBoard[2][0] == ticTacToeBoard[2][1] && ticTacToeBoard[2][0] == ticTacToeBoard[2][2])
            printf("Player 1 wins!");
              else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][2] && ticTacToeBoard[0][2] == ticTacToeBoard[2][2])
                    printf("Player 1 wins!");
                 else if(ticTacToeBoard[2][2] == ticTacToeBoard[1][1] && ticTacToeBoard[0][0] == ticTacToeBoard[2][2])
                    printf("Player 1 wins!");

          }
          else if(c%2  == 1)
               { lowRightButton = gtk_button_new_with_label("O");
                 gtk_box_pack_start(GTK_BOX(col3), lowRightButton, TRUE, TRUE, 0);
                   gtk_widget_show(lowRightButton);
       c = c +1;
                  ticTacToeBoard[2][2] = 'O';
         if(ticTacToeBoard[2][0] == ticTacToeBoard[2][1] && ticTacToeBoard[2][0] == ticTacToeBoard[2][2])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[0][2] == ticTacToeBoard[1][2] && ticTacToeBoard[0][2] == ticTacToeBoard[2][2])
         printf("Player 2 wins!");
         else if(ticTacToeBoard[2][2] == ticTacToeBoard[1][1] && ticTacToeBoard[2][2] == ticTacToeBoard[0][0])
         printf("Player 2 wins!");
      }
        }

   int main(int argc, char** argv)
   {
gtk_init(&argc, &argv);
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_container_set_border_width(GTK_CONTAINER (window), 10);
g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  col1 = gtk_vbox_new(FALSE, 0);
  col2 = gtk_vbox_new(FALSE, 0);
  col3 = gtk_vbox_new(FALSE, 0);
hbox = gtk_hbox_new(FALSE, 0);


 gtk_container_add(GTK_CONTAINER(window), hbox);
 gtk_container_add(GTK_CONTAINER(hbox), col1);
   gtk_container_add(GTK_CONTAINER(hbox), col2);
 gtk_container_add(GTK_CONTAINER(hbox), col3);

   gtk_widget_show(col1);
     gtk_widget_show(col2);
     gtk_widget_show(col3);
    gtk_widget_show(hbox);

  GtkWidget *label1 = gtk_label_new("Tic Tac Toe");
    gtk_box_pack_start(GTK_BOX(hbox), label1, FALSE, FALSE, 0);
      gtk_widget_show(label1);


 upperLeftButton = gtk_button_new_with_label(" ");
   gtk_box_pack_start(GTK_BOX(col1), upperLeftButton, TRUE, TRUE, 0);
     gtk_widget_show(upperLeftButton);

upperMidButton = gtk_button_new_with_label(" ");
   gtk_box_pack_start(GTK_BOX(col2), upperMidButton, TRUE, TRUE, 0);
        gtk_widget_show(upperMidButton);

topRightButton = gtk_button_new_with_label(" ");
   gtk_box_pack_start(GTK_BOX(col3), topRightButton, TRUE, TRUE, 0);
           gtk_widget_show(topRightButton);

     midLeftButton = gtk_button_new_with_label(" ");
        gtk_box_pack_start(GTK_BOX(col1), midLeftButton, TRUE, TRUE, 0);
                gtk_widget_show(midLeftButton);

    midMidButton = gtk_button_new_with_label(" ");
       gtk_box_pack_start(GTK_BOX(col2), midMidButton, TRUE, TRUE, 0);
               gtk_widget_show(midMidButton);

midRightButton = gtk_button_new_with_label(" ");
   gtk_box_pack_start(GTK_BOX(col3), midRightButton, TRUE, TRUE, 0);
           gtk_widget_show(midRightButton);

 lowLeftButton = gtk_button_new_with_label(" ");
    gtk_box_pack_start(GTK_BOX(col1), lowLeftButton, TRUE, TRUE, 0);
            gtk_widget_show(lowLeftButton);

lowMidButton = gtk_button_new_with_label(" ");
   gtk_box_pack_start(GTK_BOX(col2), lowMidButton, TRUE, TRUE, 0);
           gtk_widget_show(lowMidButton);

 lowRightButton = gtk_button_new_with_label(" ");
    gtk_box_pack_start(GTK_BOX(col3), lowRightButton, TRUE, TRUE, 0);
            gtk_widget_show(lowRightButton);



g_signal_connect(upperLeftButton, "clicked", G_CALLBACK(upperLeftButton), NULL);
g_signal_connect(upperMidButton, "clicked", G_CALLBACK(upperMidButton), NULL);
g_signal_connect(topRightButton, "clicked", G_CALLBACK(toprightButton), NULL);
g_signal_connect(midLeftButton, "clicked", G_CALLBACK(midleftButton), NULL);
g_signal_connect(midMidButton, "clicked", G_CALLBACK(midmidButton), NULL);
g_signal_connect(midRightButton, "clicked", G_CALLBACK(midrightButton), NULL);
g_signal_connect(lowLeftButton, "clicked", G_CALLBACK(lowleftButton), NULL);
g_signal_connect(lowMidButton, "clicked", G_CALLBACK(lowmidButton), NULL);
g_signal_connect(lowRightButton, "clicked", G_CALLBACK(lowrightButton), NULL);


gtk_widget_show(window);

g_print("main: calling gtk_main\n");
gtk_main();

return EXIT_SUCCESS;
}
