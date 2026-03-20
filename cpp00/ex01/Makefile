NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       PhoneBook.cpp \
       Contact.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c  $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
