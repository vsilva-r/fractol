all:
	make -C ./minilibx-linux
	cc main.c -Lminilibx-linux -lmlx -lX11 -lXext -lm
	./a.out