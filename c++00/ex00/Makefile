NAME	= megaphone
RM		= rm -rf
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++11 #-g3 -fsanitize=address
SRCS	= megaphone.cpp
OBJS	= $(SRCS:%.cpp=$(OBJDIR)/%.o)
OBJDIR	= megaphobj

all:	$(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o : %.cpp
	$(CC) -c $(CFLAGS) -o $@ $^

clean:	
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
