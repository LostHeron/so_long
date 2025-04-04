NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror

MINILIBX_DIR := src/minilibx-linux/
MINILIBX_FILES := $(MINILIBX_DIR)libmlx_Linux.a $(MINILIBX_DIR)libmlx.a

LIB_INCLUDES := -lmlx -lX11 -lXext -L $(MINILIBX_DIR)

LIBFT_DIR = src/libft/
LIBFT = $(LIBFT_DIR)libft.a

PARSING_DIR := src/parsing/
PARSING_FILES := parsing.c \
				 read_map.c \
				 check_map.c \

PRINTING_DIR := src/printing/
PRINTING_FILES := print_error.c

FREEING_DIR := src/freeing/
FREEING_FILES := free_data.c \

C_FILES := so_long.c \
		   $(addprefix $(PARSING_DIR),$(PARSING_FILES)) \
		   $(addprefix $(PRINTING_DIR), $(PRINTING_FILES)) \
		   $(addprefix $(FREEING_DIR), $(FREEING_FILES)) \

OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR),$(C_FILES:.c=.o))

INCLUDES := -I $(LIBFT_DIR)includes -I includes/ -I $(MINILIBX_DIR) 

D_FILES := $(OBJ_FILES:.o=.d);

all: makelibft makeminilibx $(NAME)

makeminilibx:
	$(MAKE) -C $(MINILIBX_DIR)

makelibft:
	$(MAKE) -C $(LIBFT_DIR)

git:
	git submodule update --init --remote --recursive

$(NAME): $(OBJ_FILES) $(LIBFT) $(MINILIBX_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_INCLUDES) $^ -o $@ 


$(OBJ_DIR)%.o:%.c | $(OBJ_DIR)$(PARSING_DIR) $(OBJ_DIR)$(PRINTING_DIR) $(OBJ_DIR)$(FREEING_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@ 

$(OBJ_DIR)$(PARSING_DIR):
	mkdir -p $@

$(OBJ_DIR)$(PRINTING_DIR):
	mkdir -p $@

$(OBJ_DIR)$(FREEING_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
	
