#include <iostream>

#include <curses.h>

using namespace std;

int main()
{
    int limiteEnX, limiteEnY;
    initscr();
    getmaxyx(stdscr, limiteEnY, limiteEnX);

    if (!has_colors())
    {
        endwin();
        return 1;
    }


    WINDOW *ventana = newwin(limiteEnY, limiteEnX, 0, 0);


    refresh();
    cbreak();
    noecho();
    nonl();
    intrflush(ventana, FALSE);
    keypad(ventana, TRUE);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLUE);
    wbkgd(ventana, COLOR_PAIR(1));


    mvwprintw(ventana, 0, 1, "YaST @ g185");
    mvwprintw(ventana, 0, limiteEnX - 18, "Press F1 for Help");


    int tituloDelTitulo = ((limiteEnX - 2) / 2) - 10;
    WINDOW *titulo = derwin(ventana, 3, limiteEnX - 2, 1, 1);
    mvwprintw(titulo, 1, tituloDelTitulo, "YaST2 Control Center");
    box(titulo, ACS_VLINE, ACS_HLINE);


    int longitud = (limiteEnX - 2) / 3;


    WINDOW *ventana1Tercio = derwin(ventana, 10, longitud, 6, 1);
    box(ventana1Tercio, ACS_VLINE, ACS_HLINE);


    WINDOW *ventana2Tercios = derwin(ventana, 10, longitud * 2, 6, longitud + 1);
    box(ventana2Tercios, ACS_VLINE, ACS_HLINE);


    
    touchwin(ventana);
    wrefresh(ventana);
    getchar();
    endwin();
    return 0;
}