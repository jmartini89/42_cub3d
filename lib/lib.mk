all : libft.a #libmlx.dylib

libft.a :
	@make -s -C ./libft
	@cp ./libft/libft.a .
	@make fclean -C ./libft
	@echo "\033[32m"$@" compilation successfull\033[0m"

libmlx.dylib :
	@make -s -C ./mlx
	@cp ./mlx/$@ .
	@make clean -C ./mlx
	@echo "\033[32m"$@" compilation successfull\033[0m"

clean :
	@rm -f libft.a libmlx.dylib
	@echo "\033[33mlibraries clean completed\033[0m"