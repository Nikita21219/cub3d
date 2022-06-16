NAME = libft.a
HEADER = libft.h
CC = cc
SRC_DIR = srcs
OBJDIR = objs
HEADDIR = includes
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))

FLAGS = -Wall -Wextra -Werror -O3

all: $(NAME)

$(OBJDIR)/%.o :	$(SRC_DIR)/%.c $(HEADDIR)/$(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libft compile"

$(OBJDIR):
	@if [ ! -d $(OBJDIR) ] ; then mkdir $(OBJDIR); fi;

clean:
	@if [ -d $(OBJDIR) ] ; then rm -r $(OBJDIR); fi
	@echo "clean libft done"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re