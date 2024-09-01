#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int x_len = 10; // 가로
const int y_len = 10; // 세로
const int size = x_len * y_len;

bool mine_map[x_len * y_len];
bool displayed_map[x_len * y_len];

int to_x(int loc);
int to_y(int loc);
int to_loc(int row, int col);

void addRandomMines(int num);
bool* get_neibor_squares(int loc);
int get_mine_num(int loc);
void set_displayed_map(int loc);
void print_map();


int main(int argc, char const *argv[])
{
    
    return 0;
}

int to_x(int loc) { return loc % x_len; }
int to_y(int loc) { return loc / x_len; }
int to_loc(int x, int y) { return y * x_len + x; }

void addRandomMines(int num)
{
    for (int i = num; i > 0; i--)
    {
        int mine_loc = rand()% size;
        if (mine_map[mine_loc]) i++;
        mine_map[mine_loc] = 1;
    }
}

bool* get_neibor_squares(int loc)
{
    int x_loc = to_x(loc);
    if (x_loc == 0) // 왼쪽 벽에 닿으면
    {
        
    } 
    else if (x_loc == x_len-1) // 오른쪽 벽에 닿으면
    {
        
    }
    int y_loc = to_y(loc);
    if (y_loc == 0) // 위쪽 벽에 닿으면
    {
        /* code */
    }
    else if (y_loc == y_len-1) // 아래쪽 벽에 닿으면
    {
        /* code */
    }
    
}

int get_mine_num(int loc)
{
    int answer = 0;
    bool* neibor_squares = get_neibor_squares(loc);

    for(; *neibor_squares != NULL ; neibor_squares++)
    {
        if(*neibor_squares) answer++;
    }

    return answer;
}

void set_displayed_map(int loc)
{
    if (get_mine_num(loc) == 0)
    {
        bool* neibor_squares = get_neibor_squares(loc);
        for (; *neibor_squares != NULL ; neibor_squares++)
        {
            set_displayed_map( *neibor_squares );
        }
        
    }
    displayed_map[loc] = true;
}

void print_map()
{
    for (int i = 0; i < y_len; i++)
    {
        for (int j = 0; j < x_len; j++)
        {
            if (displayed_map[i*j]) printf("%d", get_mine_num(to_loc(j, i)));
            else printf("?");
        }
        printf("\n");
    }
}