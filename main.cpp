#include <iostream>

#include <curses.h>

using namespace std;

int main()
{
    int limiteEnX = 0, limiteEnY = 0;
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

    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    init_pair(3, COLOR_YELLOW, COLOR_BLUE);

    attron(COLOR_PAIR(1));


    WINDOW *primeraLineaColor = subwin(ventana, 1, limiteEnX, 0, 0);
    wbkgd(primeraLineaColor, COLOR_PAIR(2));
    mvwprintw(primeraLineaColor, 0, 1, "YaST @ g185");
    mvwprintw(primeraLineaColor, 0, limiteEnX - 18, "Press F1 for Help");
    wrefresh(primeraLineaColor);

    mvwprintw(ventana, limiteEnY - 2, 1, "[Help]");
    mvwprintw(ventana, limiteEnY - 2, limiteEnX - 8, "[Quit]");



    int tituloDelTitulo = ((limiteEnX - 3) / 2) - 10;
    WINDOW *tituloBorde = derwin(ventana, 3, limiteEnX - 2, 1, 1);
    box(tituloBorde, ACS_VLINE, ACS_HLINE);

    attron(COLOR_PAIR(3));
    mvwprintw(tituloBorde, 1, tituloDelTitulo, "YaST2 Control Center");
    // attroff(COLOR_PAIR(3));

    wrefresh(tituloBorde);

    int longitud = (limiteEnX - 2) / 3;
    int largo = limiteEnY - 10;

    WINDOW *ventana1Tercio = derwin(ventana, largo, longitud, 6, 1);
    box(ventana1Tercio, ACS_VLINE, ACS_HLINE);

    attron(COLOR_PAIR(3));
    mvwprintw(ventana1Tercio, 1, 1, "Software");
    // attroff(COLOR_PAIR(3));
    
    mvwprintw(ventana1Tercio, 2, 1, "Hardware");
    mvwprintw(ventana1Tercio, 3, 1, "System");
    mvwprintw(ventana1Tercio, 4, 1, "Network Devices");
    mvwprintw(ventana1Tercio, 5, 1, "Network services");
    mvwprintw(ventana1Tercio, 6, 1, "Security And Users");
    mvwprintw(ventana1Tercio, 7, 1, "Misc");

    wrefresh(ventana1Tercio);

    WINDOW *ventana2Tercios = derwin(ventana, largo, limiteEnX - longitud - 2, 6, longitud + 1);
    box(ventana2Tercios, ACS_VLINE, ACS_HLINE);

    attron(COLOR_PAIR(3));
    mvwprintw(ventana2Tercios, 1, 1, "Patch CD Update");
    // attroff(COLOR_PAIR(3));
    
    mvwprintw(ventana2Tercios, 2, 1, "Installation into Directory");
    mvwprintw(ventana2Tercios, 3, 1, "Online Update");
    mvwprintw(ventana2Tercios, 4, 1, "Install and Remove Software");
    mvwprintw(ventana2Tercios, 5, 1, "Chaange source of installation");
    mvwprintw(ventana2Tercios, 6, 1, "System update");

    wrefresh(ventana2Tercios);

    refresh();
    touchwin(ventana);
    wrefresh(ventana);
    attroff(COLOR_PAIR(1));
    getchar();
    endwin();
    return 0;
}