# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 18:04:23 by vsilva-r          #+#    #+#              #
#    Updated: 2024/05/07 18:04:24 by vsilva-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a

SRCS = ft_printf.c ft_iputnbr.c ft_iputnbr_base.c ft_iputstr.c ft_iputchar.c \
		ft_uputnbr_base.c ft_iputbinary.c
		
BONUS = ft_printf_bonus.c
				
OBJS := $(SRCS:%.c=objs/%.o)
BONUS_OBJS = $(BONUS:%.c=bonus_objs/%.o)

.PHONY = all clean fclean re bonus

all : ${NAME}

$(NAME): ${LIBFT} ${OBJS}
	@echo -n "Linking archive... "
	@cp ${LIBFT} ${NAME} 
	@ar rs ${NAME} ${OBJS}
	@echo "Done."
	
${LIBFT}: 
	@echo "Making libft library... "
	@make -C libft
	@echo "Done."

$(OBJS): $(SRCS)
	@echo -n "Creating objects... "
	@mkdir -p objs
	@cc ${CFLAGS} ${SRCS} -c
	@mv *.o objs
	@echo "Done."
	
${BONUS_OBJS}: ${BONUS}
	@echo -n "Creating bonus objects... "
	@mkdir -p bonus_objs
	@cc ${CFLAGS} ${BONUS} -c
	@mv *.o bonus_objs
	@echo "Done."

bonus: ${BONUS_OBJS} ${LIBFT}
	@echo -n "Linking bonus... "
	@cp ${LIBFT} ${NAME} 
	@ar rs ${NAME} ${BONUS_OBJS}
	@echo "Done."

clean:
	@echo -n "Cleaning objects... "
	@rm -rf *.o *.gch objs
	@echo "Done."
	
fclean: clean
	@echo -n "Cleaning archives... "
	@rm -rf ${NAME} .bonus
	@make fclean -C libft
	@echo "Done."

re: fclean all
