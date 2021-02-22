#!bin/zsh

CHEM=..

if [ $# = 0 ]
then
	cat README.txt
	exit
fi

if [ $1 = "erase" ]
then
	echo "=> suppression du(des) programme(s) de correction." 
	rm -f $CHEM/ft_atoi $CHEM/ft_calloc $CHEM/ft_isascii $CHEM/ft_itoa $CHEM/ft_memcmp 
	rm -f $CHEM/ft_memset $CHEM/ft_putnbr_fd $CHEM/ft_strchr $CHEM/ft_strlcat
	rm -f $CHEM/ft_strmapi $CHEM/ft_strrchr $CHEM/ft_tolower $CHEM/putendl_fd.txt
	rm -f $CHEM/ft_bonus $CHEM/ft_isalnum $CHEM/ft_isdigit $CHEM/ft_memccpy
	rm -f $CHEM/ft_memcpy $CHEM/ft_putchar_fd $CHEM/ft_putstr_fd $CHEM/ft_strdup
	rm -f $CHEM/ft_strlcpy $CHEM/ft_strncmp $CHEM/ft_strtrim $CHEM/ft_toupper
	rm -f $CHEM/putnbr_fd.txt $CHEM/ft_bzero $CHEM/ft_isalpha $CHEM/ft_isprint
	rm -f $CHEM/ft_memchr $CHEM/ft_memmove $CHEM/ft_putendl_fd $CHEM/ft_split
	rm -f $CHEM/ft_strjoin $CHEM/ft_strlen $CHEM/ft_strnstr $CHEM/ft_substr
	rm -f $CHEM/putchar_fd.txt $CHEM/putstr_fd.txt
	exit
fi

if [ -e $CHEM/libft.h ]
then
	echo "=> 'libft.h' : fichier détecté."
else
	echo "ERREUR => 'libft.h' : fichier non détecté. Utilisation du 'libft.h' de remplacement."
fi

if [ $1 = "memmove" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_memmove.c ]
	then
		chmod a+r $CHEM/ft_memmove.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" memmove_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' memmove_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_memmove.c\"/g" memmove_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_memmove.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_memmove.c
		else
			echo "ERREUR => 'ft_memmove.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_memmove.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_memmove memmove_main.c
		chmod a+x $CHEM/ft_memmove

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_memmove.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" memmove_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" memmove_main.h
		sed -i -e "s/# include \"$CHEM\/ft_memmove.c\"/# include \".c\"/g" memmove_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_memmove.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "memset" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_memset.c ]
	then
		chmod a+r $CHEM/ft_memset.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" memset_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' memset_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_memset.c\"/g" memset_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_memset.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_memset.c
		else
			echo "ERREUR => 'ft_memset.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_memset.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_memset memset_main.c
		chmod a+x $CHEM/ft_memset

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_memset.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" memset_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" memset_main.h
		sed -i -e "s/# include \"$CHEM\/ft_memset.c\"/# include \".c\"/g" memset_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_memset.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "bzero" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_bzero.c ]
	then
		chmod a+r $CHEM/ft_bzero.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" bzero_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' bzero_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_bzero.c\"/g" bzero_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_bzero.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_bzero.c
		else
			echo "ERREUR => 'ft_bzero.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_bzero.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_bzero bzero_main.c
		chmod a+x $CHEM/ft_bzero

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_bzero.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" bzero_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" bzero_main.h
		sed -i -e "s/# include \"$CHEM\/ft_bzero.c\"/# include \".c\"/g" bzero_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_bzero.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "memcpy" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_memcpy.c ]
	then
		chmod a+r $CHEM/ft_memcpy.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" memcpy_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' memcpy_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_memcpy.c\"/g" memcpy_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_memcpy.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_memcpy.c
		else
			echo "ERREUR => 'ft_memcpy.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_memcpy.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_memcpy memcpy_main.c
		chmod a+x $CHEM/ft_memcpy

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_memcpy.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" memcpy_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" memcpy_main.h
		sed -i -e "s/# include \"$CHEM\/ft_memcpy.c\"/# include \".c\"/g" memcpy_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_memcpy.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "memccpy" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_memccpy.c ]
	then
		chmod a+r $CHEM/ft_memccpy.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" memccpy_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' memccpy_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_memccpy.c\"/g" memccpy_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_memccpy.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_memccpy.c
		else
			echo "ERREUR => 'ft_memccpy.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_memccpy.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_memccpy memccpy_main.c
		chmod a+x $CHEM/ft_memccpy

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_memccpy.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" memccpy_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" memccpy_main.h
		sed -i -e "s/# include \"$CHEM\/ft_memccpy.c\"/# include \".c\"/g" memccpy_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_memccpy.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "memchr" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_memchr.c ]
	then
		chmod a+r $CHEM/ft_memchr.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" memchr_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' memchr_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_memchr.c\"/g" memchr_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_memchr.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_memchr.c
		else
			echo "ERREUR => 'ft_memchr.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_memchr.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_memchr memchr_main.c
		chmod a+x $CHEM/ft_memchr

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_memchr.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" memchr_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" memchr_main.h
		sed -i -e "s/# include \"$CHEM\/ft_memchr.c\"/# include \".c\"/g" memchr_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_memchr.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "memcmp" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_memcmp.c ]
	then
		chmod a+r $CHEM/ft_memcmp.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" memcmp_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' memcmp_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_memcmp.c\"/g" memcmp_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_memcmp.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_memcmp.c
		else
			echo "ERREUR => 'ft_memcmp.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_memcmp.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_memcmp memcmp_main.c
		chmod a+x $CHEM/ft_memcmp

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_memcmp.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" memcmp_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" memcmp_main.h
		sed -i -e "s/# include \"$CHEM\/ft_memcmp.c\"/# include \".c\"/g" memcmp_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_memcmp.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strlen" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strlen.c ]
	then
		chmod a+r $CHEM/ft_strlen.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strlen_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strlen_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strlen.c\"/g" strlen_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strlen.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strlen.c
		else
			echo "ERREUR => 'ft_strlen.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strlen.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_strlen strlen_main.c
		chmod a+x $CHEM/ft_strlen

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strlen.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strlen_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strlen_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strlen.c\"/# include \".c\"/g" strlen_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strlen.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "isalpha" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_isalpha.c ]
	then
		chmod a+r $CHEM/ft_isalpha.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" isalpha_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' isalpha_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_isalpha.c\"/g" isalpha_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_isalpha.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_isalpha.c
		else
			echo "ERREUR => 'ft_isalpha.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_isalpha.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_isalpha isalpha_main.c
		chmod a+x $CHEM/ft_isalpha

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_isalpha.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" isalpha_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" isalpha_main.h
		sed -i -e "s/# include \"$CHEM\/ft_isalpha.c\"/# include \".c\"/g" isalpha_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_isalpha.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "isdigit" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_isdigit.c ]
	then
		chmod a+r $CHEM/ft_isdigit.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" isdigit_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' isdigit_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_isdigit.c\"/g" isdigit_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_isdigit.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_isdigit.c
		else
			echo "ERREUR => 'ft_isdigit.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_isdigit.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_isdigit isdigit_main.c
		chmod a+x $CHEM/ft_isdigit

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_isdigit.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" isdigit_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" isdigit_main.h
		sed -i -e "s/# include \"$CHEM\/ft_isdigit.c\"/# include \".c\"/g" isdigit_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_isdigit.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "isalnum" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_isalnum.c ]
	then
		chmod a+r $CHEM/ft_isalnum.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" isalnum_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' isalnum_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_isalnum.c\"/g" isalnum_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_isalnum.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_isalnum.c
		else
			echo "ERREUR => 'ft_isalnum.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_isalnum.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_isalnum isalnum_main.c
		chmod a+x $CHEM/ft_isalnum

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_isalnum.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" isalnum_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" isalnum_main.h
		sed -i -e "s/# include \"$CHEM\/ft_isalnum.c\"/# include \".c\"/g" isalnum_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_isalnum.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "isascii" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_isascii.c ]
	then
		chmod a+r $CHEM/ft_isascii.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" isascii_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' isascii_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_isascii.c\"/g" isascii_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_isascii.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_isascii.c
		fi

		echo "=> 'ft_isascii.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_isascii isascii_main.c
		chmod a+x $CHEM/ft_isascii

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_isascii.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" isascii_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" isascii_main.h
		sed -i -e "s/# include \"$CHEM\/ft_isascii.c\"/# include \".c\"/g" isascii_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_isascii.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "isprint" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_isprint.c ]
	then
		chmod a+r $CHEM/ft_isprint.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" isprint_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' isprint_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_isprint.c\"/g" isprint_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_isprint.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_isprint.c
		fi

		echo "=> 'ft_isprint.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_isprint isprint_main.c
		chmod a+x $CHEM/ft_isprint

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_isprint.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" isprint_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" isprint_main.h
		sed -i -e "s/# include \"$CHEM\/ft_isprint.c\"/# include \".c\"/g" isprint_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_isprint.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "toupper" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_toupper.c ]
	then
		chmod a+r $CHEM/ft_toupper.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" toupper_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' toupper_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_toupper.c\"/g" toupper_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_toupper.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_toupper.c
		else
			echo "ERREUR => 'ft_toupper.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_toupper.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_toupper toupper_main.c
		chmod a+x $CHEM/ft_toupper

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_toupper.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" toupper_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" toupper_main.h
		sed -i -e "s/# include \"$CHEM\/ft_toupper.c\"/# include \".c\"/g" toupper_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_toupper.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "tolower" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_tolower.c ]
	then
		chmod a+r $CHEM/ft_tolower.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" tolower_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' tolower_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_tolower.c\"/g" tolower_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_tolower.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_tolower.c
		else
			echo "ERREUR => 'ft_tolower.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_tolower.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_tolower tolower_main.c
		chmod a+x $CHEM/ft_tolower

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_tolower.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" tolower_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" tolower_main.h
		sed -i -e "s/# include \"$CHEM\/ft_tolower.c\"/# include \".c\"/g" tolower_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_tolower.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strchr" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strchr.c ]
	then
		chmod a+r $CHEM/ft_strchr.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strchr_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strchr_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strchr.c\"/g" strchr_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strchr.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strchr.c
		else
			echo "ERREUR => 'ft_strchr.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strchr.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_strchr strchr_main.c
		chmod a+x $CHEM/ft_strchr

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strchr.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strchr_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strchr_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strchr.c\"/# include \".c\"/g" strchr_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strchr.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strrchr" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strrchr.c ]
	then
		chmod a+r $CHEM/ft_strrchr.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strrchr_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strrchr_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strrchr.c\"/g" strrchr_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strrchr.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strrchr.c
		else
			echo "ERREUR => 'ft_strrchr.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strrchr.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_strrchr strrchr_main.c
		chmod a+x $CHEM/ft_strrchr

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strrchr.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strrchr_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strrchr_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strrchr.c\"/# include \".c\"/g" strrchr_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strrchr.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strncmp" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strncmp.c ]
	then
		chmod a+r $CHEM/ft_strncmp.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strncmp_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strncmp_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strncmp.c\"/g" strncmp_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strncmp.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strncmp.c
		else
			echo "ERREUR => 'ft_strncmp.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strncmp.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_strncmp strncmp_main.c
		chmod a+x $CHEM/ft_strncmp

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strncmp.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strncmp_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strncmp_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strncmp.c\"/# include \".c\"/g" strncmp_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strncmp.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strlcpy" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strlcpy.c ]
	then
		chmod a+r $CHEM/ft_strlcpy.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strlcpy_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strlcpy_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strlcpy.c\"/g" strlcpy_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strlcpy.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strlcpy.c
		else
			echo "ERREUR => 'ft_strlcpy.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strlcpy.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -lbsd -o $CHEM/ft_strlcpy strlcpy_main.c
		chmod a+x $CHEM/ft_strlcpy

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strlcpy.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strlcpy_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strlcpy_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strlcpy.c\"/# include \".c\"/g" strlcpy_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strlcpy.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strlcat" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strlcat.c ]
	then
		chmod a+r $CHEM/ft_strlcat.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strlcat_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strlcat_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strlcat.c\"/g" strlcat_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strlcat.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strlcat.c
		else
			echo "ERREUR => 'ft_strlcat.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strlcat.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -lbsd -o $CHEM/ft_strlcat strlcat_main.c
		chmod a+x $CHEM/ft_strlcat

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strlcat.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strlcat_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strlcat_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strlcat.c\"/# include \".c\"/g" strlcat_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strlcat.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strnstr" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strnstr.c ]
	then
		chmod a+r $CHEM/ft_strnstr.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strnstr_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strnstr_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strnstr.c\"/g" strnstr_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strnstr.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strnstr.c
		else
			echo "ERREUR => 'ft_strnstr.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strnstr.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -lbsd -o $CHEM/ft_strnstr strnstr_main.c
		chmod a+x $CHEM/ft_strnstr

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strnstr.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strnstr_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strnstr_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strnstr.c\"/# include \".c\"/g" strnstr_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strnstr.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "atoi" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_atoi.c ]
	then
		chmod a+r $CHEM/ft_atoi.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" atoi_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' atoi_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_atoi.c\"/g" atoi_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_atoi.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_atoi.c
		else
			echo "ERREUR => 'ft_atoi.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_atoi.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_atoi atoi_main.c
		chmod a+x $CHEM/ft_atoi

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_atoi.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" atoi_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" atoi_main.h
		sed -i -e "s/# include \"$CHEM\/ft_atoi.c\"/# include \".c\"/g" atoi_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_atoi.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "calloc" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_calloc.c ]
	then
		chmod a+r $CHEM/ft_calloc.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" calloc_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' calloc_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_calloc.c\"/g" calloc_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_calloc.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_calloc.c
		else
			echo "ERREUR => 'ft_calloc.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_calloc.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_calloc calloc_main.c
		chmod a+x $CHEM/ft_calloc

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_calloc.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" calloc_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" calloc_main.h
		sed -i -e "s/# include \"$CHEM\/ft_calloc.c\"/# include \".c\"/g" calloc_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_calloc.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strdup" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strdup.c ]
	then
		chmod a+r $CHEM/ft_strdup.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strdup_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strdup_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strdup.c\"/g" strdup_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strdup.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strdup.c
		else
			echo "ERREUR => 'ft_strdup.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strdup.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_strdup strdup_main.c
		chmod a+x $CHEM/ft_strdup

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strdup.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strdup_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strdup_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strdup.c\"/# include \".c\"/g" strdup_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strdup.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "substr" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_substr.c ]
	then
		chmod a+r $CHEM/ft_substr.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" substr_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' substr_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_substr.c\"/g" substr_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_substr.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_substr.c
		else
			echo "ERREUR => 'ft_substr.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_substr.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_substr substr_main.c
		chmod a+x $CHEM/ft_substr

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_substr.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" substr_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" substr_main.h
		sed -i -e "s/# include \"$CHEM\/ft_substr.c\"/# include \".c\"/g" substr_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_substr.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strjoin" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strjoin.c ]
	then
		chmod a+r $CHEM/ft_strjoin.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strjoin_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strjoin_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strjoin.c\"/g" strjoin_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strjoin.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strjoin.c
		else
			echo "ERREUR => 'ft_strjoin.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strjoin.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_strjoin strjoin_main.c
		chmod a+x $CHEM/ft_strjoin

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strjoin.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strjoin_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strjoin_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strjoin.c\"/# include \".c\"/g" strjoin_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strjoin.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strtrim" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strtrim.c ]
	then
		chmod a+r $CHEM/ft_strtrim.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strtrim_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strtrim_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strtrim.c\"/g" strtrim_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strtrim.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strtrim.c
		else
			echo "ERREUR => 'ft_strtrim.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strtrim.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_strtrim strtrim_main.c
		chmod a+x $CHEM/ft_strtrim

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strtrim.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strtrim_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strtrim_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strtrim.c\"/# include \".c\"/g" strtrim_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strtrim.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "split" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_split.c ]
	then
		chmod a+r $CHEM/ft_split.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" split_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' split_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_split.c\"/g" split_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_split.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_split.c
		else
			echo "ERREUR => 'ft_split.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_split.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_split split_main.c
		chmod a+x $CHEM/ft_split

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_split.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" split_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" split_main.h
		sed -i -e "s/# include \"$CHEM\/ft_split.c\"/# include \".c\"/g" split_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_split.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "itoa" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_itoa.c ]
	then
		chmod a+r $CHEM/ft_itoa.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" itoa_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' itoa_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_itoa.c\"/g" itoa_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_itoa.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_itoa.c
		else
			echo "ERREUR => 'ft_itoa.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_itoa.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_itoa itoa_main.c
		chmod a+x $CHEM/ft_itoa

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_itoa.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" itoa_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" itoa_main.h
		sed -i -e "s/# include \"$CHEM\/ft_itoa.c\"/# include \".c\"/g" itoa_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_itoa.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "strmapi" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_strmapi.c ]
	then
		chmod a+r $CHEM/ft_strmapi.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" strmapi_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' strmapi_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_strmapi.c\"/g" strmapi_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_strmapi.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_strmapi.c
		else
			echo "ERREUR => 'ft_strmapi.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_strmapi.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_strmapi strmapi_main.c
		chmod a+x $CHEM/ft_strmapi

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_strmapi.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" strmapi_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" strmapi_main.h
		sed -i -e "s/# include \"$CHEM\/ft_strmapi.c\"/# include \".c\"/g" strmapi_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_strmapi.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "putchar_fd" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_putchar_fd.c ]
	then
		chmod a+r $CHEM/ft_putchar_fd.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" putchar_fd_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' putchar_fd_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_putchar_fd.c\"/g" putchar_fd_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_putchar_fd.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_putchar_fd.c
		else
			echo "ERREUR => 'ft_putchar_fd.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_putchar_fd.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_putchar_fd putchar_fd_main.c
		touch $CHEM/putchar_fd.txt
		chmod a+rw $CHEM/putchar_fd.txt
		chmod a+x $CHEM/ft_putchar_fd

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_putchar_fd.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" putchar_fd_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" putchar_fd_main.h
		sed -i -e "s/# include \"$CHEM\/ft_putchar_fd.c\"/# include \".c\"/g" putchar_fd_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_putchar_fd.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "putstr_fd" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_putstr_fd.c ]
	then
		chmod a+r $CHEM/ft_putstr_fd.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" putstr_fd_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' putstr_fd_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_putstr_fd.c\"/g" putstr_fd_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_putstr_fd.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_putstr_fd.c
		else
			echo "ERREUR => 'ft_putstr_fd.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_putstr_fd.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_putstr_fd putstr_fd_main.c
		touch $CHEM/putstr_fd.txt
		chmod a+rw $CHEM/putstr_fd.txt
		chmod a+x $CHEM/ft_putstr_fd

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_putstr_fd.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" putstr_fd_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" putstr_fd_main.h
		sed -i -e "s/# include \"$CHEM\/ft_putstr_fd.c\"/# include \".c\"/g" putstr_fd_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_putstr_fd.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "putendl_fd" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_putendl_fd.c ]
	then
		chmod a+r $CHEM/ft_putendl_fd.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" putendl_fd_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' putendl_fd_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_putendl_fd.c\"/g" putendl_fd_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_putendl_fd.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_putendl_fd.c
		else
			echo "ERREUR => 'ft_putendl_fd.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_putendl_fd.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_putendl_fd putendl_fd_main.c
		touch $CHEM/putendl_fd.txt
		chmod a+rw $CHEM/putendl_fd.txt
		chmod a+x $CHEM/ft_putendl_fd

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_putendl_fd.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" putendl_fd_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" putendl_fd_main.h
		sed -i -e "s/# include \"$CHEM\/ft_putendl_fd.c\"/# include \".c\"/g" putendl_fd_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_putendl_fd.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "putnbr_fd" ] || [ $1 = "all" ]
then
	if [ -e $CHEM/ft_putnbr_fd.c ]
	then
		chmod a+r $CHEM/ft_putnbr_fd.c

		if [ -e $CHEM/libft.h ]
		then
			sed -i -e "s/# include \".h\"/# include \"$CHEM\/libft.h\"/g" putnbr_fd_main.h
		else
			sed -i -e 's/# include ".h"/# include "libft_main.h"/g' putnbr_fd_main.h
		fi

		sed -i -e "s/# include \".c\"/# include \"$CHEM\/ft_putnbr_fd.c\"/g" putnbr_fd_main.h

		INC=$(grep '#include "libft.h"' $CHEM/ft_putnbr_fd.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_putnbr_fd.c
		else
			echo "ERREUR => 'ft_putnbr_fd.c' : absence de '#include \"libft.h\"'."
		fi

		echo "=> 'ft_putnbr_fd.c' : compilation du programme de correction."
		clang -Wall -Wextra -Werror -o $CHEM/ft_putnbr_fd putnbr_fd_main.c
		touch $CHEM/putnbr_fd.txt
		chmod a+rw $CHEM/putnbr_fd.txt
		chmod a+x $CHEM/ft_putnbr_fd

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_putnbr_fd.c
		sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \".h\"/g" putnbr_fd_main.h
		sed -i -e "s/# include \"libft_main.h\"/# include \".h\"/g" putnbr_fd_main.h
		sed -i -e "s/# include \"$CHEM\/ft_putnbr_fd.c\"/# include \".c\"/g" putnbr_fd_main.h
	else
		echo "ERREUR => le fichier '$CHEM/ft_putnbr_fd.c' n'existe pas. Abandon de la compilation."
	fi
fi

if [ $1 = "bonus" ] || [ $1 = "all" ]
then
	COUNT=0
	if [ -e $CHEM/libft.h ]
	then
		sed -i -e "s/# include \"\"/# include \"$CHEM\/libft.h\"/g" bonus_main.h
	else
		sed -i -e 's/# include ""/# include "libft_main.h"/g' bonus_main.h
	fi

	if [ -e $CHEM/ft_lstnew.c ]
	then
		COUNT=$(($COUNT + 1))
		INC=$(grep '#include "libft.h"' $CHEM/ft_lstnew.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_lstnew.c
		else
			echo "ERREUR => 'ft_lstnew.c' : absence de '#include \"libft.h\"'."
		fi
		echo "=> partie bonus : ajout du fichier 'ft_lstnew.c' au programme de correction." 
		sed -i -e 's/# define NEW 0/# define NEW 1/g' bonus_main.h
		NEW=0
		chmod a+r $CHEM/ft_lstnew.c
	else
		NEW=1
		cp ft_lstnew.c $CHEM
		echo "ERREUR => le fichier '$CHEM/ft_lstnew.c' n'existe pas."
	fi

	if [ -e $CHEM/ft_lstadd_front.c ]
	then
		COUNT=$(($COUNT + 1))
		INC=$(grep '#include "libft.h"' $CHEM/ft_lstadd_front.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_lstadd_front.c
		else
			echo "ERREUR => 'ft_lstadd_front.c' : absence de '#include \"libft.h\"'."
		fi
		echo "=> partie bonus : ajout du fichier 'ft_lstadd_front.c' au programme de correction." 
		sed -i -e 's/# define ADDFRONT 0/# define ADDFRONT 1/g' bonus_main.h
		ADDFRONT=0
		chmod a+r $CHEM/ft_lstadd_front.c
	else
		ADDFRONT=1
		cp ft_lstadd_front.c $CHEM
		echo "ERREUR => le fichier '$CHEM/ft_lstadd_front.c' n'existe pas."
	fi

	if [ -e $CHEM/ft_lstsize.c ]
	then
		COUNT=$(($COUNT + 1))
		INC=$(grep '#include "libft.h"' $CHEM/ft_lstsize.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_lstsize.c
		else
			echo "ERREUR => 'ft_lstsize.c' : absence de '#include \"libft.h\"'."
		fi
		echo "=> partie bonus : ajout du fichier 'ft_lstsize.c' au programme de correction." 
		sed -i -e 's/# define SIZE 0/# define SIZE 1/g' bonus_main.h
		SIZE=0
		chmod a+r $CHEM/ft_lstsize.c
	else
		SIZE=1
		cp ft_lstsize.c $CHEM
		echo "ERREUR => le fichier '$CHEM/ft_lstsize.c' n'existe pas."
	fi

	if [ -e $CHEM/ft_lstlast.c ]
	then
		COUNT=$(($COUNT + 1))
		INC=$(grep '#include "libft.h"' $CHEM/ft_lstlast.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_lstlast.c
		else
			echo "ERREUR => 'ft_lstlast.c' : absence de '#include \"libft.h\"'."
		fi
		echo "=> partie bonus : ajout du fichier 'ft_lstlast.c' au programme de correction." 
		sed -i -e 's/# define LAST 0/# define LAST 1/g' bonus_main.h
		LAST=0
		chmod a+r $CHEM/ft_lstlast.c
	else
		LAST=1
		cp ft_lstlast.c $CHEM
		echo "ERREUR => le fichier '$CHEM/ft_lstlast.c' n'existe pas."
	fi

	if [ -e $CHEM/ft_lstadd_back.c ]
	then
		COUNT=$(($COUNT + 1))
		INC=$(grep '#include "libft.h"' $CHEM/ft_lstadd_back.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_lstadd_back.c
		else
			echo "ERREUR => 'ft_lstadd_back.c' : absence de '#include \"libft.h\"'."
		fi
		echo "=> partie bonus : ajout du fichier 'ft_lstadd_back.c' au programme de correction." 
		sed -i -e 's/# define ADDBACK 0/# define ADDBACK 1/g' bonus_main.h
		ADDBACK=0
		chmod a+r $CHEM/ft_lstadd_back.c
	else
		ADDBACK=1
		cp ft_lstadd_back.c $CHEM
		echo "ERREUR => le fichier '$CHEM/ft_lstadd_back.c' n'existe pas."
	fi
	
	if [ -e $CHEM/ft_lstdelone.c ]
	then
		COUNT=$(($COUNT + 1))
		INC=$(grep '#include "libft.h"' $CHEM/ft_lstdelone.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_lstdelone.c
		else
			echo "ERREUR => 'ft_lstdelone.c' : absence de '#include \"libft.h\"'."
		fi
		echo "=> partie bonus : ajout du fichier 'ft_lstdelone.c' au programme de correction." 
		sed -i -e 's/# define DELONE 0/# define DELONE 1/g' bonus_main.h
		DELONE=0
		chmod a+r $CHEM/ft_lstdelone.c
	else
		DELONE=1
		cp ft_lstdelone.c $CHEM
		echo "ERREUR => le fichier '$CHEM/ft_lstdelone.c' n'existe pas."
	fi
		
	if [ -e $CHEM/ft_lstclear.c ]
	then
		COUNT=$(($COUNT + 1))
		INC=$(grep '#include "libft.h"' $CHEM/ft_lstclear.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_lstclear.c
		else
			echo "ERREUR => 'ft_lstclear.c' : absence de '#include \"libft.h\"'."
		fi
		echo "=> partie bonus : ajout du fichier 'ft_lstclear.c' au programme de correction." 
		sed -i -e 's/# define CLEAR 0/# define CLEAR 1/g' bonus_main.h
		CLEAR=0
		chmod a+r $CHEM/ft_lstclear.c
	else
		CLEAR=1
		cp ft_lstclear.c $CHEM
		echo "ERREUR => le fichier '$CHEM/ft_lstclear.c' n'existe pas."
	fi
	
	if [ -e $CHEM/ft_lstiter.c ]
	then
		COUNT=$(($COUNT + 1))
		INC=$(grep '#include "libft.h"' $CHEM/ft_lstiter.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_lstiter.c
		else
			echo "ERREUR => 'ft_lstiter.c' : absence de '#include \"libft.h\"'."
		fi
		echo "=> partie bonus : ajout du fichier 'ft_lstiter.c' au programme de correction." 
		sed -i -e 's/# define ITER 0/# define ITER 1/g' bonus_main.h
		ITER=0
		chmod a+r $CHEM/ft_lstiter.c
	else
		ITER=1
		cp ft_lstiter.c $CHEM
		echo "ERREUR => le fichier '$CHEM/ft_lstiter.c' n'existe pas."
	fi
	
	if [ -e $CHEM/ft_lstmap.c ]
	then
		COUNT=$(($COUNT + 1))
		INC=$(grep '#include "libft.h"' $CHEM/ft_lstmap.c)
		if [ -n "$INC" ]
		then
			sed -i -e 's/#include "libft.h"/\/\/#include "libft.h"/g' $CHEM/ft_lstmap.c
		else
			echo "ERREUR => 'ft_lstmap.c' : absence de '#include \"libft.h\"'."
		fi
		echo "=> partie bonus : ajout du fichier 'ft_lstmap.c' au programme de correction." 
		sed -i -e 's/# define MAP 0/# define MAP 1/g' bonus_main.h
		MAP=0
		chmod a+r $CHEM/ft_lstmap.c
	else
		MAP=1
		cp ft_lstmap.c $CHEM
		echo "ERREUR => le fichier '$CHEM/ft_lstmap.c' n'existe pas."
	fi

	if [ $COUNT = 0 ]
	then
		echo "=> partie bonus : aucune fonction ajoutée au programme de correction. Abandon de la compilation."
	else
		if [ $COUNT = 1 ]
		then
			echo "=> partie bonus : 1 fonction ajoutée. Compilation du programme de correction." 
		fi
		if [ $COUNT > 1 ]
		then
			echo "=> partie bonus : $COUNT fonctions ajoutées. Compilation du programme de correction." 
		fi
		clang -Wall -Wextra -Werror -o $CHEM/ft_bonus bonus_main.c
		chmod a+x $CHEM/ft_bonus
	
		if [ $NEW = 1 ]
		then
			rm -f $CHEM/ft_lstnew.c
			sed -i -e 's/# define NEW 1/# define NEW 0/g' bonus_main.h
		fi

		if [ $ADDFRONT = 1 ]
		then
			rm -f $CHEM/ft_lstadd_front.c
			sed -i -e 's/# define ADDFRONT 1/# define ADDFRONT 0/g' bonus_main.h
		fi

		if [ $SIZE = 1 ]
		then
			rm -f $CHEM/ft_lstsize.c
			sed -i -e 's/# define SIZE 1/# define SIZE 0/g' bonus_main.h
		fi

		if [ $LAST = 1 ]
		then
			rm -f $CHEM/ft_lstlast.c
			sed -i -e 's/# define LAST 1/# define LAST 0/g' bonus_main.h
		fi

		if [ $ADDBACK = 1 ]
		then
			rm -f $CHEM/ft_lstadd_back.c
			sed -i -e 's/# define ADDBACK 1/# define ADDBACK 0/g' bonus_main.h
		fi

		if [ $DELONE = 1 ]
		then
			rm -f $CHEM/ft_lstdelone.c
			sed -i -e 's/# define DELONE 1/# define DELONE 0/g' bonus_main.h
		fi

		if [ $CLEAR = 1 ]
		then
			rm -f $CHEM/ft_lstclear.c
			sed -i -e 's/# define CLEAR 1/# define CLEAR 0/g' bonus_main.h
		fi

		if [ $ITER = 1 ]
		then
			rm -f $CHEM/ft_lstiter.c
			sed -i -e 's/# define ITER 1/# define ITER 0/g' bonus_main.h
		fi

		if [ $MAP = 1 ]
		then
			rm -f $CHEM/ft_lstmap.c
			sed -i -e 's/# define MAP 1/# define MAP 0/g' bonus_main.h
		fi

		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_lstnew.c
		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_lstadd_front.c
		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_lstsize.c
		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_lstlast.c
		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_lstadd_back.c
		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_lstdelone.c
		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_lstclear.c
		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_lstiter.c
		sed -i -e 's/\/\/#include "libft.h"/#include "libft.h"/g' $CHEM/ft_lstmap.c
	fi
	
	sed -i -e "s/# include \"$CHEM\/libft.h\"/# include \"\"/g" bonus_main.h
	sed -i -e "s/# include \"libft_main.h\"/# include \"\"/g" bonus_main.h
fi
