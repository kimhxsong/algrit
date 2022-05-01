GTEST_PREFIX := $(shell brew --prefix googletest)

NAME = test

CC = c++
CXXFLAGS = -g3 -Wall -Wextra -Werror -std=c++11 -mmacosx-version-min=12.0

INCLUDES = -I $(GTEST_PREFIX)/include
LDFLAGS = -L $(GTEST_PREFIX)/lib -lgtest

SRCS = $(wildcard *.cpp)

OBJDIR = ./obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@$(CC) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS): | $(OBJDIR)
$(OBJDIR):
	@mkdir $(OBJDIR)

.PHONY: clean
clean:
	@$(RM) -r $(OBJDIR)

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)

.PHONY: re
re: fclean all
