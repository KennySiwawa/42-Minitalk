# Variables : Compilation tools
CC = gcc
FLAGS = -Wall -Wextra -Werror

#Variables : libraries
LIB = minitalk.h

#variables : Sources files 
SERVER = server.c 
CLIENT = client.c
LIBFTPRINTF = ft_printf/libftprintf.a

#Variables : Objects files 
OSERVER = $(SERVER:.c=.o)
OCLIENT = $(CLIENT:.c=.o)

#Variables : Cleaning rule
OBJS = $(OSERVER) $(OCLIENT)
EXEC = server client

#Mandatory part
NAME = minitalk
all : $(NAME)

$(NAME)  : $(OSERVER) $(OCLIENT) $(LIB)
	@make -C ft_printf
	@$(CC) $(FLAGS) $(SERVER) $(LIBFTPRINTF) -o server
	@$(CC) $(FLAGS) $(CLIENT) $(LIBFTPRINTF) -o client

#Clean objects (Mandatory)
clean :
	@make fclean -C ft_printf
	@rm -rf $(OBJS)

#Clean objects and executable files (Mandatory)
fclean : clean
	@rm -rf $(EXEC)

#Recompile the mandatory part
re : fclean all