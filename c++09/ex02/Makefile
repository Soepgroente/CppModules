NAME	=	PmergeMe
RM		=	rm -rf
CC		=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++20 #-g -fsanitize=address
SRCS	=	main.cpp \
			PmergeMe.cpp \
			withDeque.cpp \
			withVector.cpp \

OBJS	=	$(SRCS:%.cpp=$(OBJDIR)/%.o)
OBJDIR	=	objects

all:	$(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o : %.cpp
	$(CC) -c $^ $(CPPFLAGS) -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
