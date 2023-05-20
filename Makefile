# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 10:04:40 by madmax42          #+#    #+#              #
#    Updated: 2023/05/20 10:18:46 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     						= gnl.a
CC       						= gcc
CFLAGS   						= -Wall -Wextra -Werror -g3
RM       						= rm -f

SRCS     						= get_next_line.c \
           							get_next_line_utils.c \
									main.c

VPATH    						= ./srcs/

OBJSDIR  						= objs
OBJS     						= $(patsubst %.c, $(OBJSDIR)/%.o, $(SRCS))

$(OBJSDIR)/%.o: 				%.c
									@mkdir -p $(OBJSDIR)
									$(CC) $(CFLAGS) -c $< -o $@ -I./include

all: 							$(NAME)

$(NAME): 						$(OBJS)
									$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS):						| $(OBJSDIR)

$(OBJSDIR):
								@mkdir -p $(OBJSDIR)

clean:
									$(RM) $(OBJS)
									$(RM) -r $(OBJSDIR)

fclean: 						clean
								$(RM) $(NAME)

re: 							fclean all

.PHONY: 						all clean fclean re