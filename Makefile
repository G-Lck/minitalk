CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFTPRINTF		= libftprintf/libftprintf.a

CLIENT = client
SERVER = server

SRCS = server.c \
		client.c \
		utils.c

INCLUDES	= -I libftprintf -I .

OBJS_SERVER	= server.o utils.o
OBJS_CLIENT	= client.o utils.o

all: libft $(SERVER) $(CLIENT)

libft: $(LIBFTPRINTF)

$(LIBFTPRINTF):
	$(MAKE) -C libftprintf

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SERVER): $(OBJS_SERVER) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(LIBFTPRINTF)

$(CLIENT): $(OBJS_CLIENT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(LIBFTPRINTF)

clean:
	$(MAKE) -C libftprintf clean
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(MAKE) -C libftprintf fclean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re libft
