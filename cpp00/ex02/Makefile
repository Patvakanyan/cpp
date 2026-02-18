TARGET := test_account
SRCS := Account.cpp \
		tests.cpp
OBJS := $(SRCS:.cpp=.o)
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
RM := rm -f

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

# Phony targets
.PHONY: all clean fclean re
