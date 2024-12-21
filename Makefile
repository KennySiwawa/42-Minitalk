# SERVER = server
# CLIENT = client

# CFLAGS = -Wall -Werror -Wextra
# CC = gcc
# FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

# PRINTF = ft_printf

# all:
# 	@make -s -C $(PRINTF)
# 	@gcc $(FLAGS) server.c -o $(SERVER)
# 	@gcc $(FLAGS) client.c -o $(CLIENT)
# 	@echo "Server And Client Are Ready!"

# clean:
# 	@make clean -s -C $(PRINTF)

# fclean: clean
# 	@make fclean -s -C $(PRINTF)
# 	@rm -f $(SERVER) $(CLIENT)
# 	@echo "Server and Client Have Been Cleaned Successfully"

# re: fclean all


# Target binaries
SERVER = server
CLIENT = client

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(PRINTF)/headers
LDFLAGS = -L$(PRINTF) -lftprintf

# Directory containing ft_printf
PRINTF = ft_printf

# Source files
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

# Object files
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Rules
all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -s -C $(PRINTF)
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all