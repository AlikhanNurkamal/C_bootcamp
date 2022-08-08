TARGET = my_ngram
OBJ = my_ngram.c

$(TARGET) : $(OBJ)
	gcc -Wall -Wextra -Werror -o $(TARGET) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
