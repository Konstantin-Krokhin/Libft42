# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:53:09 by jkaczmar          #+#    #+#              #
#    Updated: 2021/12/06 11:51:12 by jkaczmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_strrchr.c ft_putstr_fd.c ft_strtrim.c ft_bzero.c ft_calloc.c ft_split.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_substr.c ft_tolower.c ft_toupper.c ft_memcpy.c
OBJS			= $(SRCS:.c=.o)
BONUSSRC		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS			= ${BONUSSRC:.c=.o}
CC				= gcc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -I.

FNAME			= libft.a

all:			$(FNAME)

$(FNAME):		$(OBJS)
				ar rcs	$(FNAME) $(OBJS)
clean: 
				$(RM)	$(OBJS)

fclean:			clean
				$(RM)	$(FNAME)				
re: fclean all

bonus:			$(OBJS) ${BONUS}
				ar rcs	$(FNAME) $(OBJS) ${BONUS}