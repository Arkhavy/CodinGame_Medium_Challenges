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

void	define_square(t_square *square, int xtl, int ytl, int xbr, int ybr, int len)
{
	dprintf(2, "xtl %d ytl %d xbr %d ybr %d\n", xtl, ytl, xbr, ybr);
	if (len == 1)
	{
		if (xtl == xbr)
		{
			if (ytl > square->y_top_left)
				square->y_middle = ytl / 2;
			else
				square->y_middle = square->y_top_left / 2;
		}
		else if (ytl == ybr)
		{
			if (xtl > square->x_top_left)
				square->x_middle = xtl / 2;
			else
				square->x_middle = square->x_top_left / 2;
		}
	}
	else
	{
		// if (xtl > 0 && xtl != xbr)
		// 	square->x_middle = xbr - (xtl / 2);
		// else
			square->x_middle = xbr / 2 + xtl;
		// if (ytl > 0 && ytl != ybr)
		// 	square->y_middle = ybr - (ytl / 2);
		// else
			square->y_middle = ybr / 2 + ytl;
	}
	square->x_top_left = xtl;
	square->y_top_left = ytl;

	square->x_bot_right = xbr;
	square->y_bot_right = ybr;
	
	square->x_top_right = xbr;
	square->y_top_right = ytl;
	
	square->x_bot_left = xtl;
	square->y_bot_left = ybr;

	dprintf(2, "x_mid %d y_mid %d\n", square->x_middle, square->y_middle);
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
	define_square(&square, 0, 0, data.width, data.height, 0);
	data.last_x = -1;
	data.last_y = -1;
	while (42)
	{
		scanf("%s", data.bomb_dir);
		dprintf(2, "\n%s\n\n", data.bomb_dir);
		if (!strncmp(data.bomb_dir, "U", 4))
			define_square(&square, data.current_x, square.y_top_left, data.current_x, data.current_y, strlen(data.bomb_dir));
		else if (!strncmp(data.bomb_dir, "UR", 4))
			define_square(&square, data.current_x, square.y_top_left, square.x_bot_right, data.current_y, strlen(data.bomb_dir));
		else if (!strncmp(data.bomb_dir, "R", 4))
			define_square(&square, data.current_x, data.current_y, square.x_bot_right, data.current_y, strlen(data.bomb_dir));
		else if (!strncmp(data.bomb_dir, "DR", 4))
			define_square(&square, data.current_x, data.current_y, square.x_bot_right, square.y_bot_right, strlen(data.bomb_dir));
		else if (!strncmp(data.bomb_dir, "D", 4))
			define_square(&square, data.current_x, data.current_y, data.current_x, square.y_bot_right, strlen(data.bomb_dir));
		else if (!strncmp(data.bomb_dir, "DL", 4))
			define_square(&square, square.x_top_left, data.current_y, data.current_x, square.y_bot_right, strlen(data.bomb_dir));
		else if (!strncmp(data.bomb_dir, "L", 4))
			define_square(&square, square.x_top_left, data.current_y, data.current_x, data.current_y, strlen(data.bomb_dir));
		else if (!strncmp(data.bomb_dir, "UL", 4))
			define_square(&square, square.x_top_left, square.y_top_left, data.current_x, data.current_y, strlen(data.bomb_dir));
		dest_x = square.x_middle;
		dest_y = square.y_middle;
		data.current_x = dest_x;
		data.current_y = dest_y;
		printf("%d %d\n", dest_x, dest_y);
	}
	return (0);
}
