/*!
   \file defines.hpp
   \brief Definition of some things in the program
   \author Omar Sotillo
 */

#ifndef __DEFINES_HPP_
#define __DEFINES_HPP_

// COLORS

#define FAIL "\033[91m"
#define OKGREEN "\033[92m"
#define WARNING "\033[93m"
#define OKBLUE "\033[94m"
#define HEADER "\033[95m"
#define ENDC "\033[0m"

#define LUGAR(x,y)   printf("\033[%d;%dH",x,y)
#define BORRAR       printf("\33[2J")
#define PARPADEO     printf("%c[5m",27)
#define APAGA        printf("%c[0m",27)
#define INVERSO      printf("%c[7m",27)
#define SUBRAYADO    printf("%c[4m",27)
#define INTENSIDAD   printf("%c[1m",27)

#endif // ifndef __DEFINES_HPP_
