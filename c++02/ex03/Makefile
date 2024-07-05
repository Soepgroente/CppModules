NAME	=	triangle
RM		=	rm -rf
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++11 -g
SRCS	=	calculate.cpp \
			Fixed.cpp \
			main.cpp \
			Point.cpp \

OBJS	=	$(SRCS:%.cpp=$(OBJDIR)/%.o)
OBJDIR	=	objects

all:	$(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(HEADERS) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o : %.cpp
	$(CC) -c $^ $(CFLAGS) -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
