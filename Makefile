NAME  = cub3D

SRCS	= ./srcs/mandatory/parser/ft_check_all.c \
			./srcs/mandatory/parser/ft_check_color.c \
			./srcs/mandatory/parser/utils_parser.c \
			./srcs/mandatory/parser/parser_id.c \
			./srcs/mandatory/parser/parser_map.c \
			./srcs/mandatory/raycasting/utils_raycasting.c \
			./srcs/mandatory/raycasting/raycast.c \
			./srcs/mandatory/utils/init_struc.c \
			./srcs/mandatory/utils/utils.c \
			./srcs/mandatory/utils/malloc_lst.c \
			./srcs/mandatory/main.c \
			./srcs/mandatory/raycasting/render_functions.c \
			./srcs/mandatory/raycasting/handle_key.c \
			./srcs/mandatory/raycasting/rays.c \
			./srcs/mandatory/raycasting/cast_rays.c \
			./srcs/mandatory/raycasting/rays_content.c \
			./srcs/mandatory/raycasting/mlx_utils.c \
			./srcs/mandatory/raycasting/textures.c \
			./lib_cub/ft_strchr.c \
			./lib_cub/ft_strdup.c \
			./lib_cub/ft_substr.c \
			./lib_cub/ft_strjoin.c \
			./lib_cub/ft_strrchr.c \
			./lib_cub/get_next_line.c \
			./lib_cub/ft_strlen.c \
			./lib_cub/ft_lstclear.c \
			./lib_cub/ft_lstnew.c \
			./lib_cub/ft_lstadd_back.c \
			./lib_cub/ft_memset.c
			
SRCS_BONUS = ./srcs/mandatory/parser/ft_check_all.c \
			./srcs/mandatory/parser/ft_check_color.c \
			./srcs/mandatory/parser/utils_parser.c \
			./srcs/mandatory/utils/init_struc.c \
			./srcs/mandatory/utils/utils.c \
			./srcs/mandatory/utils/malloc_lst.c \
			./srcs/mandatory/raycasting/render_functions.c \
			./srcs/mandatory/raycasting/rays.c \
			./srcs/mandatory/raycasting/rays_content.c \
			./srcs/mandatory/raycasting/cast_rays.c \
			./srcs/mandatory/raycasting/utils_raycasting.c \
			./srcs/mandatory/parser/parser_id.c \
			./srcs/mandatory/raycasting/mlx_utils.c \
			./srcs/mandatory/parser/parser_map.c \
			./srcs/bonus/raycasting/raycast.c \
			./srcs/bonus/raycasting/render_bonus.c \
			./srcs/bonus/raycasting/handle_key.c \
			./srcs/bonus/raycasting/calcules.c \
			./srcs/bonus/raycasting/utils_bonus.c \
			./lib_cub/ft_strchr.c \
			./lib_cub/ft_strdup.c \
			./lib_cub/ft_substr.c \
			./lib_cub/ft_strjoin.c \
			./lib_cub/ft_strrchr.c \
			./lib_cub/get_next_line.c \
			./lib_cub/ft_strlen.c \
			./lib_cub/ft_memset.c \
			./lib_cub/ft_lstclear.c \
			./lib_cub/ft_lstnew.c \
			./lib_cub/ft_lstadd_back.c \
			./srcs/bonus/main.c \

OBJS= $(SRCS:.c=.o)

OBJS_BONUS= $(SRCS_BONUS:.c=.o)

INC	=	-I inc -I ${MLX_D}

CC	=	clang

CFLAGS	=	-Wall -Werror -Wextra

MLX_D	=	mlx

.c.o	:
			${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all : ${NAME}

$(NAME) :	${OBJS}
			make -C ${MLX_D}
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX_D) -lX11 -lXext -lmlx -lm


bonus :	${OBJS_BONUS}
			make -C ${MLX_D}
			${CC} $(CFLAGS) -o $(NAME) $(OBJS_BONUS) -L $(MLX_D) -lX11 -lXext -lmlx -lm

clean	:	
			make clean -C ${MLX_D}
			rm -rf ${OBJS}
			rm -rf ${OBJS_BONUS}

fclean	:	clean
			rm -rf ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re