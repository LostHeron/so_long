NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR = src/libft/
LIBFT = $(LIBFT_DIR)libft.a

C_FILES := so_long.c

OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR),$(C_FILES:.c=.o))

INCLUDES := -I $(LIBFT_DIR)includes -I includes/

D_FILES := $(OBJ_FILES:.o=.d);

all: makelibft $(NAME)

makelibft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ 


$(OBJ_DIR)%.o:%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@ 

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
	
