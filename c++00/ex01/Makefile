NAME	=	Phonebook
RM		=	rm -rf
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++11 -g #-fsanitize=address
HEADERS	=	-I/Contact.hpp -I/Phonebook.hpp
SRCS	=	Contact.cpp \
			Main.cpp \
			Phonebook.cpp \

OBJS	=	$(SRCS:%.cpp=$(OBJDIR)/%.o)
OBJDIR	=	objbook

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
