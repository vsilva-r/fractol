CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

NAME := fractol

SRCS = main.c \
	fractol_init.c \
	fractol_render.c \
	fractol_events.c \
	fractol_math.c

OBJS = $(SRCS:%.c=objs/%.o)

MLIBX = ./minilibx-linux

RM = rm -f

$(OBJS): $(SRCS) fractol.h
	mkdir -p objs
	${CC} ${CFLAGS} ${SRCS} -c
	mv *.o objs
	
${NAME}: ${OBJS} minilibx
	${CC} ${OBJS} ${LFLAGS} ${CFLAGS} -o ${NAME}.out

minilibx: 
	make -C ${MLIBX}


all: ${NAME}
	./${NAME}.out
clean:
	${RM} -r objs

fclean: clean
	${RM} ${NAME}

re: fclean all
	
.PHONY: all clean fclean re minilibx
.DEFAULT_GOAL := all
