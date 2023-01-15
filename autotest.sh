echo  "\n\033[0;31m*****test one : BUFFER_SIZE = 1******"
echo  "\n\033[0m			----- file 1 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=1 get_next_line.c tst.c 
./a.out | cat -e
echo  "\n			----- file 2 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=1 get_next_line.c tst2.c 
./a.out | cat -e
echo  "\n\033[0;34m=====end of test one====="
echo  "\n\033[0;31m*****test two : BUFFER_SIZE = 10******"
echo  "\n\033[0m			----- file 1 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=10 get_next_line.c tst.c 
./a.out | cat -e
echo  "\n			----- file 2 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=10 get_next_line.c tst2.c 
./a.out | cat -e
echo  "\n\033[0;34m=====end of test two====="
echo  "\n\033[0;31m*****test three : BUFFER_SIZE = 17******"
echo  "\n\033[0m			----- file 1 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=17 get_next_line.c tst.c 
./a.out | cat -e
echo  "\n			----- file 2 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=17 get_next_line.c tst2.c 
./a.out | cat -e
echo  "\n\033[0;34m=====end of test three====="
echo  "\n\033[0;31m*****test four : BUFFER_SIZE = 42******"
echo  "\n\033[0m			----- file 1 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=42 get_next_line.c tst.c 
./a.out | cat -e
echo  "\n			----- file 2 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=42 get_next_line.c tst2.c 
./a.out | cat -e
echo  "\n\033[0;34m=====end of test four====="
echo  "\n\033[0;31m*****test five : BUFFER_SIZE = 77******"
echo  "\n\033[0m			----- file 1 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=77 get_next_line.c tst.c 
./a.out | cat -e
echo  "\n			----- file 2 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=77 get_next_line.c tst2.c 
./a.out | cat -e
echo  "\n\033[0;34m=====end of test five====="
echo  "\n\033[0;31m*****test six : BUFFER_SIZE = 144******"
echo  "\n\033[0m			----- file 1 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=144 get_next_line.c tst.c 
./a.out | cat -e
echo  "\n			----- file 2 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=144 get_next_line.c tst2.c 
./a.out | cat -e
echo  "\n\033[0;34m=====end of test six====="
echo  "\n\033[0;31m*****test seven : BUFFER_SIZE = 1'000******"
echo  "\n\033[0m			----- file 1 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=1000 get_next_line.c tst.c 
./a.out | cat -e
echo  "\n			----- file 2 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=1000 get_next_line.c tst2.c 
./a.out | cat -e
echo  "\n\033[0;34m=====end of test seven====="
echo  "\n\033[0;31m*****test eight : BUFFER_SIZE = 100'000******"
echo  "\n\033[0m			----- file 1 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=100000 get_next_line.c tst.c 
./a.out | cat -e
echo  "\n			----- file 2 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=100000 get_next_line.c tst2.c 
./a.out | cat -e
echo  "\n\033[0;34m=====end of test eight====="
echo  "\n\033[0;31m*****test nine : BUFFER_SIZE = 1'000'000******"
echo  "\n\033[0m			----- file 1 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=1000000 get_next_line.c tst.c 
./a.out | cat -e
echo  "\n			----- file 2 -----"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=1000000 get_next_line.c tst2.c 
./a.out | cat -e
echo "\n\033[0;34m=====end of test nine====="
echo "END OF TESTS"
