out:
	@mkdir -p out

libft:
	@git submodule update --init --recursive
	@make -C 42-libft > /dev/null


%: learn/%.cpp res/%.cpp | out libft
	@g++ -Wall -Wextra -Werror -std=c++17 $^ -L42-libft -lft -lgtest -lpthread -o out/$@ -I42-libft -Ires
