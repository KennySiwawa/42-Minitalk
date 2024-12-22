# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Libraries
LIBFT_DIR = ft_printf/libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = ft_printf/libftprintf.a
INCLUDES = -I $(LIBFT_DIR) -I ft_printf

# Source files
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

# Object files
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Targets
all: client server

client: $(OBJS_CLIENT) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o client $(OBJS_CLIENT) $(LIBFT) $(FT_PRINTF)

server: $(OBJS_SERVER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o server $(OBJS_SERVER) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C ft_printf

client.o: client.c
	$(CC) $(CFLAGS) $(INCLUDES) -c client.c -o client.o

server.o: server.c
	$(CC) $(CFLAGS) $(INCLUDES) -c server.c -o server.o

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f client server
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re