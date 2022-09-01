NAME = libftprintf.a

SRCS = ft_isdigit.c ft_print_char.c ft_print_high_sixteen.c ft_print_pointer.c ft_print_sixteen.c ft_print_string.c ft_printf.c ft_strchr.c ft_strlen.c ft_print_int.c ft_print_unsigned_int.c ft_left_print_uint.c ft_strdup.c ft_itoa.c ft_print_perc.c ft_get_type.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
DEPSFLAGS = -MMD -MF $(@:.o=.d)

deps := $(patsubst %.o,%.d,$(OBJS))

%.o: %.c 
	$(CC) $(CFLAG) -c -o $@ $< $(DEPSFLAGS)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
-include $(deps)

bonus : re

clean :
	@$(RM) $(OBJS) $(deps)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
