##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc-9

SRC	=	my_showmem.c			\
		my_str_isprintable.c		\
		my_showstr.c			\
		my_str_isupper.c		\
		my_compute_square_root.c	\
		my_show_word_array.c		\
		my_strlen.c			\
		my_find_prime_sup.c		\
		my_sort_int_array.c		\
		my_strlowcase.c			\
		my_getnbr.c			\
		my_strcapitalize.c		\
		my_strncat.c			\
		my_isneg.c			\
		my_strcat.c			\
		my_strncmp.c			\
		my_is_prime.c			\
		my_strcmp.c			\
		my_strncpy.c			\
		my_putchar.c			\
		my_strcpy.c			\
		my_strstr.c			\
		my_put_nbr.c			\
		my_str_isalpha.c		\
		my_str_to_word_array.c		\
		my_putstr.c			\
		my_str_islower.c		\
		my_strupcase.c			\
		my_revstr.c			\
		my_str_isnum.c			\
		my_swap.c			\
		my_pow.c			\
		my_strdup.c			\
		my_strdupcat.c			\
		convert_base.c			\
		my_getnbr_base.c		\
		my_printf.c			\
		putb.c				\
		put_ptr.c			\
		putu.c				\
		put_float.c			\
		my_sort_list.c			\
		my_rev_list.c			\
		my_params_to_list.c		\
		my_merge.c			\
		my_list_size.c			\
		my_find_node.c			\
		my_delete_nodes.c		\
		my_concat_list.c		\
		my_apply_on_nodes.c		\
		my_apply_on_matching_nodes.c	\
		my_add_in_sorted_list.c		\
		my_int_tobase.c			\
		my_itoa.c			\
		put_color.c			\
		get_next_line.c

OBJ	=	$(SRC:%.c=$(BUILD_DIR)/%.o)

CFLAGS	+=	-W -Wall -Werror -Wextra -I../../include

NAME	=	libmy.a

BUILD_DIR = build

all	:	options $(NAME)

options:
	@echo "  LIB  CC       $(CC)"
	@echo "  LIB  CFLAGS   $(CFLAGS)"
	@echo "  LIB  LDFLAGS  $(LDFLAGS)"

$(BUILD_DIR)/%.o: %.c $(INC)
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "  RM       $(BUILD_DIR)    LIB"
	@rm -rf $(BUILD_DIR)

fclean:	clean
	@echo "  RM       $(NAME)    LIB"
	@$(RM) $(NAME) *~

$(NAME): $(OBJ)
	@echo "  AR       $@"
	@$(AR) rc $(NAME) $(OBJ)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY	:	 all options clean fclean re
