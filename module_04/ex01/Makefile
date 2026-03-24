# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diana <diana@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 15:39:02 by dkolarov          #+#    #+#              #
#    Updated: 2026/03/24 07:23:22 by diana            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC = main.cpp \
	src/Animal.cpp \
	src/Dog.cpp \
	src/Cat.cpp \
	src/WrongAnimal.cpp \
	src/WrongCat.cpp

OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re