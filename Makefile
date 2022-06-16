NAME = cub3D
CC = cc

CFLAGS = -g -Wall -Wextra -Werror
MLXFL =  -L mlx -l mlx -framework OpenGL -framework AppKit

OBJDIR = ./objs
VPATH = ./srcs ./srcs/parser_map ./srcs/utils
LIBFT_DIR = libft/
HEADDIR = ./includes

HEADER = cub3D.h
LIBFT = libft/libft.a
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
SRC = $(wildcard $(addsuffix /*.c,$(VPATH)))


all:    $(LIBFT) $(NAME)

$(OBJDIR)/%.o :	%.c $^ $(HEADDIR)/$(HEADER)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) $(MLXFL) -o $(NAME) $(LIBFT_DIR)libft.a -I$(HEADER) $(OBJ) 
	@echo "$(NAME) compile"

$(OBJDIR):
	@if [ ! -d $(OBJDIR) ] ; then mkdir $(OBJDIR); fi

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@if [ -d $(OBJDIR) ] ; then rm -r $(OBJDIR); fi
	@make fclean -C $(LIBFT_DIR)
	@echo "clean $(NAME) done"


fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
