# C Compiler (Clang-12)
CC := clang
# Libft Variables
NAME := libft.a
SRCS_DIR := srcs/
INC_DIR := .
OBJS_DIR := objects/
LIBFT_DIR := .
# Printf Variables
PRINTF_DIR := printf/
PRINTF_SRCS_DIR := printf/srcs/
PRINTF_OBJS_DIR := printf/objects/

SRCS = $(addprefix $(SRCS_DIR), ft_isalpha.c\
		ft_isdigit.c\
		ft_isxdigit.c\
		ft_isspace.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_atoi_base.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_strndup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strdjoin.c\
		ft_strd2join.c\
		ft_btoa.c\
		ft_uitoa.c\
		ft_ptoa.c\
		ft_specstrjoin.c\
		ft_specstrdjoin.c\
		ft_specstrd2join.c\
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\
		get_next_line_bonus.c\
		get_next_line_utils_bonus.c\
		ft_getenv.c\
		free_str_array.c\
		)

PRINTF_SRCS = $(addprefix $(PRINTF_SRCS_DIR), ft_printf.c\
		ft_vprintf.c\
		format_string.c\
		args_validation.c\
		handle_default_precision_unknown_args.c\
		init_formatted_args.c\
		update_width_and_precision.c\
		append_formatted_args.c\
		append_flags.c\
		join_char_to_fmt_str.c\
		)

OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
OBJS += $(patsubst $(PRINTF_SRCS_DIR)%.c, $(PRINTF_OBJS_DIR)%.o, $(PRINTF_SRCS))

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $?
	@echo "--------------------------"
	@echo "Libft created and indexed."
	@echo "--------------------------"

$(PRINTF_OBJS_DIR)%.o: $(PRINTF_SRCS_DIR)%.c
	@if [ ! -d "$(PRINTF_OBJS_DIR)" ]; then \
		mkdir -p $(PRINTF_OBJS_DIR); \
	fi
	@$(CC) $(CFLAGS) -c $? -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@if [ ! -d "$(OBJS_DIR)" ]; then \
		mkdir -p $(OBJS_DIR); \
	fi
	@$(CC) $(CFLAGS) -c $? -o $@ -D BUFFER_SIZE=4096


.PHONY: all clean fclean re bonus log

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(PRINTF_OBJS_DIR)
	@echo "--------------------------"
	@echo "Libft Objects removed."
	@echo "--------------------------"

fclean: clean
	@rm -f $(NAME)
	@echo "Libft removed."
	@echo "--------------------------"

re: fclean all

log:
	@echo "Libft Source Files:" $(SRCS)
	@printf "\n"
	@echo "Libft Objects Files:" $(OBJS)
	@printf "\n"
