# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 18:18:55 by yoel-idr          #+#    #+#              #
#    Updated: 2023/03/27 23:52:15 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := run

GNL_LIST  = ../GNL_using_linked_list/get_next_line.c ../GNL_using_linked_list/get_tools.c main.c\

GNL := ../GNL_using_arrays/get_next_line_bonus.c ../GNL_using_arrays/get_next_line_utils_bonus.c main.c\

RED := \033[1;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
BLUE := \033[1;34m
RESET := \033[0m

FLAGS := -g

#logo : 
#	echo $(LOGO)
	
sp : $(GNL)
	@echo "commpiling $(GREEN)" $^
	@cc $(FLAGS) $(GNL) -o $(NAME)

bonus : $(GNL)
	@echo "commpiling$(YELLOW)" $^
	@cc $(FLAGS) $(GNL) -o $(NAME)

list : $(GNL_LIST)
	@echo "compiling$(RED)" $^ 
	@cc $(FLAGS) $(GNL_LIST) -o $(NAME)
	
clean :
	@echo "$(YELLOW)\nCleaning done successfully$(RESET)"
	@rm -f $(NAME)

.PHONY: bonus clean sp
