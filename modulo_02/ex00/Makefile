# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/10 13:35:00 by dkolarov          #+#    #+#              #
#    Updated: 2026/03/10 14:33:26 by dkolarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re