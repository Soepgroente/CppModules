NAME	=	mutantstack
RM		=	rm -rf
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++20 #-g
SRCS	=	main.cpp \

OBJS	=	$(SRCS:%.cpp=$(OBJDIR)/%.o)
OBJDIR	=	objects

all:	$(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o : %.cpp
	$(CC) -c $^ $(CFLAGS) -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
