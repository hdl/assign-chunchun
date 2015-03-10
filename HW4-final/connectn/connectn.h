void print_board(char *board, int num_rows, int num_columns);
int play_game(char tile, char *board, int num_rows, int num_columns, int col_to_play);
char * create_board(int num_rows, int num_columns);
int tie_game(char *board, int num_rows, int num_columns);
int row_win(char tile, char *board, int num_rows, int num_columns, int number_of_win);
int col_win(char tile, char *board, int num_rows, int num_columns, int number_of_win);
int left_diag_win(char tile, char *board, int num_rows, int num_columns, int number_of_win);
int right_diag_win(char tile, char *board, int num_rows, int num_columns, int number_of_win);
int check_win(char *board, int num_rows, int num_columns, int number_of_win);
