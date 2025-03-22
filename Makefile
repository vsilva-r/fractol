CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE
LFLAGS = -Llibft -lft -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

NAME := fractol

SRCS = main.c \
	fractol_colorfade.c \
	fractol_parse.c \
	fractol_init.c \
	fractol_render.c \
	fractol_events.c \
	fractol_math.c

OBJS = $(SRCS:%.c=objs/%.o)

MLIBX = ./minilibx-linux/libmlx.a
LIBFT = ./libft/libft.a

RM = rm -f

$(OBJS): $(SRCS) fractol.h
	mkdir -p objs
	${CC} ${CFLAGS} ${SRCS} -c
	mv *.o objs
	
${NAME}: minilibx ${LIBFT} ${OBJS}
	${CC} ${OBJS} ${LFLAGS} ${CFLAGS} -o ${NAME}.out

${MLIBX}: 
	make -C minilibx_linus

${LIBFT}:
	make -C libft


all: ${NAME}

clean:
	${RM} -r objs

fclean: clean
	${RM} ${NAME}

re: fclean all
	
.PHONY: all clean fclean re minilibx
.DEFAULT_GOAL := all
