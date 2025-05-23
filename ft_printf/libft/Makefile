NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_*.c
				
OBJS := $(SRCS:%.c=%.o)

.PHONY = all clean fclean re bonus

all : ${NAME}

$(NAME): libft.h ${OBJS}
	@echo -n "Linking archive... "
	@ar rcs $@ ${OBJS} 
	@echo "Done."

$(OBJS): $(SRCS) libft.h
	@echo -n "Creating objects... "
	@cc ${CFLAGS} ${SRCS} -c
	@echo "Done."

clean:
	@echo -n "Cleaning objects... "
	@rm -rf *.o *.gch
	@echo "Done."
	
fclean: clean
	@echo -n "Cleaning archive... "
	@rm -rf ${NAME} .bonus
	@echo "Done."

re: fclean all

#			HOW TO CREATE A LIBRARY			
# Step	1:	Create mylib.h header file 				
# Step	2:	Create mylib.c implementation files
# Step	3a:	gcc -c mylib.c
#	3b:	gcc -shared -o mylib.so *.o -lm
#	3c:	ar
# Step	4:	
