##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	cc

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)main.c					\
		$(D_SRC)game.c					\
		$(D_SRC)check.c					\
		$(D_SRC)dead.c					\
		$(D_SRC)win.c					\
		$(D_SRC)init.c					\
		$(D_SRC)init_game.c				\
		$(D_SRC)init_pnj.c				\
		$(D_SRC)perso.c					\
		$(D_SRC)get_name.c				\
		$(D_SRC)update.c				\
		$(D_SRC)action_game.c				\
		$(D_SRC)window.c				\
		$(D_SRC)charge_room.c				\
		$(D_SRC)set_obj_in_room.c			\
		$(D_SRC)window_init.c				\
		$(D_SRC)copy_room.c				\
		$(D_SRC)display_room.c				\
		$(D_SRC)movement.c				\
		$(D_SRC)init_enemy.c				\
		$(D_SRC)beat.c					\
		$(D_SRC)pause.c					\
		$(D_SRC)turn.c					\
		$(D_SRC)items.c					\
		$(D_SRC)talk.c					\
		$(D_SRC)init_play.c				\
		$(D_SRC)dialogue.c				\
		$(D_SRC)condition.c				\
		$(D_SRC)move_rect.c				\
		$(D_SRC)reward.c				\
		$(D_SRC)inventory.c				\
		$(D_SRC)gameplay.c				\
		$(D_SRC)particle.c				\
		$(D_SRC)particle_water.c			\
		$(D_SRC)circle.c				\
		$(D_SRC)credit/credit.c				\
		$(D_SRC)menu/clic_opt.c				\
		$(D_SRC)menu/delete.c				\
		$(D_SRC)menu/option.c				\
		$(D_SRC)menu/init_opt.c				\
		$(D_SRC)menu/print_opt.c			\
		$(D_SRC)menu/button_font.c			\
		$(D_SRC)menu/menu.c				\
		$(D_SRC)menu/menu_ft.c				\
		$(D_SRC)moteur_3d/draw.c			\
		$(D_SRC)moteur_3d/line.c			\
		$(D_SRC)moteur_3d/iso.c				\
		$(D_SRC)moteur_3d/triangle.c			\
		$(D_SRC)moteur_3d/z_buff.c			\
		$(D_SRC)moteur_3d/display.c			\
		$(D_SRC)moteur_3d/transform.c			\
		$(D_SRC)moteur_3d/file_obj.c			\
		$(D_SRC)moteur_3d/init_obj.c			\
		$(D_SRC)moteur_3d/set_obj.c			\
		$(D_SRC)moteur_3d/my_getfloat.c			\
		$(D_SRC)moteur_3d/init_img.c			\
		$(D_SRC)moteur_3d/draw_poly.c			\
		$(D_SRC)moteur_3d/draw_poly_interpolation.c	\
		$(D_SRC)moteur_3d/draw_poly_init.c		\
		$(D_SRC)moteur_3d/set_triangle.c		\
		$(D_SRC)moteur_3d/charge_obj.c			\
		$(D_SRC)moteur_3d/movement_camera.c		\
		$(D_SRC)moteur_3d/rotation_camera.c		\
		$(D_SRC)moteur_3d/rotation_camera_process.c	\
		$(D_SRC)moteur_3d/transform_camera.c		\
		$(D_SRC)moteur_3d/shader.c			\
		$(D_SRC)moteur_3d/raster_cliping.c		\

OBJ	=	$(SRC:%.c=$(BUILD_DIR)/%.o)

NAME	=	my_rpg

CFLAGS	=	-W -Wall -Wextra -I$(D_INC) -g

LDFLAGS	=	-L$(D_LIB) -lmy -l csfml-graphics -l csfml-system  -l csfml-window -l csfml-audio -lm
LDFLAGS_WAGNER += -L $(D_LIB) -lmy -lm -lc_graph_prog
BUILD_DIR = build

all:	$(NAME)

options:
	@echo "  CC       $(CC)"
	@echo "  CFLAGS   $(CFLAGS)"
	@echo "  LDFLAGS  $(LDFLAGS)"

$(BUILD_DIR)/%.o: %.c $(INC)
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "  RM       $(BUILD_DIR)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@$(MAKE) -C $(D_LIB) fclean --no-print-directory
	@echo "  RM       $(NAME)"
	@rm -f $(NAME) *~

libmy:
	@make -C $(D_LIB) --no-print-directory

$(NAME): libmy options $(OBJ)
	@echo "  BUILD    $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

wagner: libmy options $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS_WAGNER)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all options clean fclean re
