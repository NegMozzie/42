# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2014/11/15 22:46:57 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell3

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/
BDIR = srcs/builtins/
FDIR = srcs/free_functions/
PDIR = srcs/lexer_parser/
IDIR = srcs/init/
EDIR = srcs/execution/
RDIR = srcs/readline/

SRC = $(SDIR)main.c \
	  $(BDIR)env_to_list.c $(BDIR)aff_env.c $(BDIR)setenv.c $(BDIR)unsetenv.c\
	  $(BDIR)env_to_tab.c $(BDIR)get_env.c $(BDIR)builtins_center.c $(BDIR)cd.c\
	  $(BDIR)pwd.c $(BDIR)exit.c $(BDIR)cd_utils.c\
	  $(FDIR)free_env.c $(FDIR)free_struct.c $(FDIR)free_tree.c $(FDIR)free_shell.c\
	  $(PDIR)grammar.c $(PDIR)grammar1.c $(PDIR)grammar2.c $(PDIR)grammar3.c \
	  $(PDIR)grammar4.c \
	  $(PDIR)redir_syntax.c $(PDIR)syntax_error.c $(PDIR)lexer.c $(PDIR)parser.c \
	  $(IDIR)ft_init.c \
	  $(EDIR)execution.c $(EDIR)prep_cmd.c $(EDIR)xcommand.c $(EDIR)xpipe.c \
	  $(EDIR)xleft_redir.c $(EDIR)xpipe2.c $(EDIR)xright_redir.c $(EDIR)fd.c \
	  $(RDIR)get_line.c $(RDIR)utils.c $(RDIR)ft_term.c $(RDIR)delete_mode.c \
	  $(RDIR)insert_mode.c $(RDIR)autoimpl.c $(RDIR)select.c 


OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)includes
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31;1m"
	@echo -n '---> Creating the Libft... <---'
	@echo "\033[0m"
	$(MAKE) re -C $(LDIR)
	@echo "\033[31;1m"
	@echo -n '---> Compilation in progress... <---'
	@echo "\033[0m"
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB) -ltermcap
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "\033[31;1m"
	@echo -n '---> Clean : <---'
	@echo "\033[0m"
	$(RM) -rf $(OBJ)
	$(MAKE) clean -C $(LDIR)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

fclean: clean
	@echo "\033[31;1m"
	@echo -n '---> FClean : <---'
	@echo "\033[0m"
	$(RM) -rf $(NAME)
	$(MAKE) fclean -C $(LDIR)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

re: fclean all

.PHONY: all name clean fclean re