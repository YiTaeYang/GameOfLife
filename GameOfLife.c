#include <stdio.h>
#include <stdlib.h>

const int x_size = 50;
const int y_size = 50;
char cell_map[x_size][y_size];
char live_cell = '*';
char empty_space = '-';

void setting();
void apply_next_gene();

void show_field();

int main(int argc, char const *argv[])
{
    printf("setting: \n");
    setting();
    int answer = 1;
    while (answer)
    {
        printf("continue? (0 / !0): ");
        int answer;
        scanf("%d", &answer);

        apply_next_gene();
        show_field();
    }
    
    return 0;
}

void setting()
{
    int loc[2];
    while (1)
    {
        printf("stop? (0 (x_loc) (y_loc) /!0 any any ): ");
        int answer;
        scanf("%d %d %d", &answer, &loc[0], &loc[1]);
        if (answer) break;

        cell_map[loc[0]][loc[1]] = 1;
        show_field();
    }
    
}

void apply_next_gene() {

    //get next cell states
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            //get near cells
            char nears[9] = {cell_map[i-1][j-1], cell_map[i][j-1],cell_map[i+1][j-1],
             cell_map[i-1][j],cell_map[i+1][j],
             cell_map[i-1][j+1],cell_map[i][j+1],cell_map[i+1][j+1]};

            //get num(near.state: 1)
            int near_count = 0;
            for (int k = 0; k< 8; k++)
                if ((nears[k] & 0x01) == 1) near_count++;

            //calc next cell state
            cell_map[i][j] = cell_map[i][j] & 0xfd;
            if ( (cell_map[i][j] & 0x01) == 0)
            {
                if(near_count == 3) cell_map[i][j] = cell_map[i][j] | 0x02;
            }
            else
            {
                if (near_count == 3) cell_map[i][j] = cell_map[i][j] | 0x02;
                if (near_count == 2) cell_map[i][j] = cell_map[i][j] | 0x02;
            }   
        }
    }

    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            cell_map[i][j] = cell_map[i][j]>>1;
        }
    }
    
}

void show_field()
{
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            printf("%c", (cell_map[i][j] & 0x01) == 1 ? live_cell: empty_space);
        }
        printf("\n");
    }
    
}