NAME= fractol
CFLAGS= -Wall -Wextra -Werror
SRCS= main.c error.c mandelbrot.c julia.c utils.c
OBJS=$(SRCS:.c=.o)
MINILIBX_DIR := ./minilibx_opengl_20191021
MINILIBX := $(MINILIBX_DIR)/libmlx.a
INCLUDES := -I$(MINILIBX_DIR)
LDFLAGS := -L$(MINILIBX_DIR)
LIBS=-lm -lmlx

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX)
	@$(MAKE) -C ./libft
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS)  ./libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

$(MINILIBX):
	$(MAKE) -j4 -C $(MINILIBX_DIR)

all:$(NAME)

clean:
		rm -f $(OBJS)

fclean:clean
		rm -f $(NAME)

re: fclean all