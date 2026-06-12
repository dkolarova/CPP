NAME = PmergeMe
PREVIEW_NAME = PmergeMe_preview

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC = \
	src/PmergeMe.cpp \
	src/printing.cpp \
	src/validation.cpp \
	src/main.cpp

OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

PREVIEW_OBJDIR = obj_preview
PREVIEW_OBJ = $(addprefix $(PREVIEW_OBJDIR)/,$(SRC:.cpp=.o))

all: $(NAME)

debug: CXXFLAGS += -DNUMBER_COMPARISIONS=1
debug: re

preview: CXXFLAGS += -DPRINT_PREVIEW=1 -DNUMBER_COMPARISIONS=1
preview: $(PREVIEW_NAME)

$(PREVIEW_NAME): $(PREVIEW_OBJ)
	$(CXX) $(CXXFLAGS) -o $(PREVIEW_NAME) $(PREVIEW_OBJ)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PREVIEW_OBJDIR)/%.o: %.cpp | $(PREVIEW_OBJDIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(PREVIEW_OBJDIR):
	mkdir -p $(PREVIEW_OBJDIR)

clean:
	rm -rf $(OBJDIR) $(PREVIEW_OBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(PREVIEW_NAME)

re: fclean all

.PHONY: all clean fclean re debug