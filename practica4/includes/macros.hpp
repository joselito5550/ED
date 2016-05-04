/*!
	\file  macros.hpp
	\brief Macros para el diseño de pantallas
*/
#ifndef MACROS_HPP
#define MACROS_HPP
/**Macro for place.*/
#define LUGAR(x, y) printf("\033[%d;%dH", x, y)

/**Macro for delete.*/
#define BORRAR       printf("\33[2J")

/**Macro of interaction.*/
#define PARPADEO     printf("%c[5m", 27)

/**Macro of interaction.*/
#define APAGA        printf("%c[0m", 27)

/**Macro of interaction.*/
#define INVERSO      printf("%c[7m", 27)

/**Macro of interaction.*/
#define SUBRAYADO    printf("%c[4m", 27)

/**Macro of interaction.*/
#define INTENSIDAD   printf("%c[1m", 27)

#endif
