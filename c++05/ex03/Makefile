NAME	=	Form
RM		=	rm -rf
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++17 -g
INCLUDE	=	-I/

SRCS	=	Bureaucrat.cpp \
			AForm.cpp \
			Intern.cpp \
			main.cpp \
			Pointer.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \

OBJS	=	$(SRCS:%.cpp=$(OBJDIR)/%.o)
OBJDIR	=	objects

all:	$(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o : %.cpp
	$(CC) -c $^ $(CFLAGS) $(INCLUDE) -o $@

clean:
	$(RM) $(OBJDIR) *_shrubbery

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re test
