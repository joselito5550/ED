/*!
   \file defines.hpp
   \brief Definition of some things in the program
   \author Omar Sotillo
 */

#ifndef __DEFINES_HPP_
#define __DEFINES_HPP_

// COLORS

/**Color red.*/
#define FAIL "\033[91m"

/**Color green.*/
#define OKGREEN "\033[92m"

/**Color yellow.*/
#define WARNING "\033[93m"

/**Color blue.*/
#define OKBLUE "\033[94m"

/**Color purple.*/
#define HEADER "\033[95m"

/**END color.*/
#define ENDC "\033[0m"

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

#endif // ifndef __DEFINES_HPP_
