INC_DIR 	:= ./include
SRC_DIR 	:= ./src

CC 			:= cc
CFLAGS 		+= -Wall -Wextra -Werror
CFLAGS		+= -I$(INC_DIR)
CFLAGS		+= $(DBG)	# make DBG="-g"

LIBFT_DIR 	:= ./libft
LIBFT 		:= $(LIBFT_DIR)/libft.a

NAME 		:= server client
SRC			:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(NAME)))
OBJ			:= $(SRC:.c=.o)

all: $(NAME)

$(NAME): %: $(SRC_DIR)/%.o $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re