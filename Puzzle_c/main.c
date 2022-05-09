#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

typedef struct s_data	t_data;
typedef struct s_square	t_square;

struct s_data
{
	int		width; // width of the building.
	int		height; // height of the building.
	int		turns; // maximum number of turns before game over.
	int		current_x; // current x position
	int		current_y; // current y position
	int		last_x; // last x position
	int		last_y; // last y position
	char	bomb_dir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
};

struct	s_square
{
	int	x_top_left; // x top left
	int	y_top_left; // y top left
	int	x_top_right; // x top right
	int	y_top_right; // y top right
	int	x_bot_left; // x bot left
	int	y_bot_left; // y bot left
	int	x_bot_right; // x bot right
	int	y_bot_right; // y bot right
	int	x_middle; //middle between xtl and xtr
	int	y_middle; //middle between ytl and ybl
};

void	define_square(t_square *square, int xtl, int ytl, int xbr, int ybr)
{
	square->x_top_left = xtl;
	square->y_top_left = ytl;

	square->x_bot_right = xbr;
	square->y_bot_right = ybr;
	
	square->x_top_right = xbr;
	square->y_top_right = ytl;
	
	square->x_bot_left = xtl;
	square->y_bot_left = ybr;

	if (xtl > 0 && xtl != xbr)
		square->x_middle = xbr - (xtl / 2);
	else
		square->x_middle = xbr / 2;
	if (ytl > 0 && ytl != ybr)
		square->y_middle = ybr - (ytl / 2);
	else
		square->y_middle = ybr / 2;
}

int main(void)
{
	t_data		data;
	t_square	square;
	int			dest_x = 0;
	int			dest_y = 0;

	scanf("%d%d", &data.width, &data.height);
	scanf("%d", &data.turns);
	scanf("%d%d", &data.current_x, &data.current_y);
	define_square(&square, 0, 0, data.width, data.height);
	data.last_x = data.current_x;
	data.last_y = data.current_y;
	while (42)
	{
		scanf("%s", data.bomb_dir);
		if (!strcmp(data.bomb_dir, "U\n"))
			define_square(&square, data.current_x, 0, data.current_x, data.current_y);
		else if (!strcmp(data.bomb_dir, "UR\n"))
			define_square(&square);
		else if (!strcmp(data.bomb_dir, "R\n"))
			define_square(&square);
		else if (!strcmp(data.bomb_dir, "DR\n"))
			define_square(&square);
		else if (!strcmp(data.bomb_dir, "D\n"))
			define_square(&square);
		else if (!strcmp(data.bomb_dir, "DL\n"))
			define_square(&square);
		else if (!strcmp(data.bomb_dir, "L\n"))
			define_square(&square);
		else if (!strcmp(data.bomb_dir, "UL\n"))
			define_square(&square);
		dest_x = square.x_middle;
		dest_y = square.y_middle;
		data.last_x = data.current_x;
		data.last_y = data.current_y;
		data.current_x = dest_x;
		data.current_y = dest_y;
		printf("%d %d\n", dest_x, dest_y);
	}
	return (0);
}