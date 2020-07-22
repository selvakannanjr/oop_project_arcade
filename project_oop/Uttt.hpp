#ifndef UTTT_HPP_INCLUDED
#define UTTT_HPP_INCLUDED



class Ultimate
{

    static int master[9];     //{1} for P_1 , {2} for P_1 ,{3} for draw

    static int win;

    int big_pos;

    int draw;

    int p_number;       //player number

    char a[3][3][9];

    struct game //Ultimate TTT
    {
        char b[3][3][9];
        int p_number;
        int shell;
        int draw_g;
        int master_rec[9];
    };


public:
    Ultimate();
    void put_struc_in_file();
    void get_struc_from_file();
    int winner();
    void checkforwin(int x);
    void display();
    void put();
    void check_for_draw(int box_no);
    int game_input(int box_number);
    int big_box_input(int player_number);
    int menu();
    void control(); //main
};
#endif // UTTT_HPP_INCLUDED
