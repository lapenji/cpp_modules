NAME := megaphone
SRCS := main.cpp
OBJS := main.o

all : $(NAME)

$(NAME) : $(OBJS)
	clang++ $(OBJS) -o $(NAME)

$(OBJS) :
	clang++ -Wall -Werror -Wextra -c $(SRCS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re $(NAME) $(OBJS)
