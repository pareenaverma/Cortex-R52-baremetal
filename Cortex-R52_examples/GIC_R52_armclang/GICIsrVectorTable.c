// ****************************************************************************
// ****************************************************************************
//
// Project Name:		Cortex-R52 example
//
// Date:				$$
// Version: 			$Revision: $
// Author(s):			$Author: $
// URL:					$HeadURL: $
//
// Company:				ARM
// Processor:			Cortex-R52
// Compiler:			armclang
//
// ****************************************************************************
// ****************************************************************************

#include "./typedefs.h"

typedef void (*ptr_func)();
/*========================================================================*/
/*		PROTOTYPES						  */
/*========================================================================*/
void unhandled (void);
extern void SGI1IRQhandler (void);
extern void virtualTimerIRQhandler (void);
extern void DualTimer0IRQhandler (void);

/*========================================================================*/
/*	GLOBAL VARIABLES						  */
/*========================================================================*/
 
ptr_func const GICIsrVectorTable[1024] = {

unhandled, SGI1IRQhandler, unhandled, unhandled, unhandled, /* ISRs 00 - 04 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 05 - 09 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 10 - 14 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 15 - 19 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 20 - 24 */
unhandled, unhandled, virtualTimerIRQhandler, unhandled, unhandled, /* ISRs 25 - 29 */
unhandled, unhandled, unhandled, unhandled, DualTimer0IRQhandler, /* ISRs 30 - 34 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 35 - 39 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 40 - 44 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 45 - 49 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 50 - 54 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 55 - 59 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 60 - 64 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 65 - 69 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 70 - 74 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 75 - 79 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 80 - 84 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 85 - 89 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 90 - 94 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 95 - 99 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 100 - 104 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 105 - 109 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 110 - 114 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 115 - 119 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 120 - 124 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 125 - 129 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 130 - 134 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 135 - 139 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 140 - 144 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 145 - 149 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 150 - 154 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 155 - 159 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 160 - 164 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 165 - 169 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 170 - 174 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 175 - 179 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 180 - 184 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 185 - 189 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 190 - 194 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 195 - 199 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 200 - 204 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 205 - 209 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 210 - 214 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 215 - 219 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 220 - 224 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 225 - 229 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 230 - 234 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 235 - 239 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 240 - 244 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 245 - 249 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 250 - 254 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 255 - 259 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 260 - 264 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 265 - 269 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 270 - 274 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 275 - 279 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 280 - 284 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 285 - 289 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 290 - 294 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 295 - 299 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 300 - 304 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 305 - 309 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 310 - 314 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 315 - 319 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 320 - 324 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 325 - 329 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 330 - 334 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 335 - 339 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 340 - 344 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 345 - 349 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 350 - 354 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 355 - 359 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 360 - 364 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 365 - 369 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 370 - 374 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 375 - 379 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 380 - 384 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 385 - 389 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 390 - 394 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 395 - 399 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 400 - 404 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 405 - 409 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 410 - 414 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 415 - 419 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 420 - 424 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 425 - 429 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 430 - 434 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 435 - 439 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 440 - 444 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 445 - 449 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 450 - 454 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 455 - 459 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 460 - 464 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 465 - 469 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 470 - 474 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 475 - 479 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 480 - 484 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 485 - 489 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 490 - 494 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 495 - 499 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 500 - 504 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 505 - 509 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 510 - 514 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 515 - 519 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 520 - 524 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 525 - 529 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 530 - 534 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 535 - 539 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 540 - 544 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 545 - 549 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 550 - 554 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 555 - 559 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 560 - 564 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 565 - 569 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 570 - 574 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 575 - 579 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 580 - 584 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 585 - 589 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 590 - 594 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 595 - 599 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 600 - 604 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 605 - 609 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 610 - 614 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 615 - 619 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 620 - 624 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 625 - 629 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 630 - 634 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 635 - 639 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 640 - 644 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 645 - 649 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 650 - 654 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 655 - 659 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 660 - 664 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 665 - 669 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 670 - 674 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 675 - 679 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 680 - 684 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 685 - 689 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 690 - 694 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 695 - 699 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 700 - 704 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 705 - 709 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 710 - 714 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 715 - 719 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 720 - 724 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 725 - 729 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 730 - 734 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 735 - 739 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 740 - 744 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 745 - 749 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 750 - 754 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 755 - 759 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 760 - 764 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 765 - 769 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 770 - 774 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 775 - 779 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 780 - 784 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 785 - 789 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 790 - 794 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 795 - 799 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 800 - 804 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 805 - 809 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 810 - 814 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 815 - 819 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 820 - 824 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 825 - 829 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 830 - 834 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 835 - 839 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 840 - 844 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 845 - 849 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 850 - 854 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 855 - 859 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 860 - 864 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 865 - 869 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 870 - 874 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 875 - 879 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 880 - 884 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 885 - 889 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 890 - 894 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 895 - 899 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 900 - 904 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 905 - 909 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 910 - 914 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 915 - 919 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 920 - 924 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 925 - 929 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 930 - 934 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 935 - 939 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 940 - 944 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 945 - 949 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 950 - 954 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 955 - 959 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 960 - 964 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 965 - 969 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 970 - 974 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 975 - 979 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 980 - 984 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 985 - 989 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 990 - 994 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 995 - 999 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 1000 - 1004 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 1005 - 1009 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 1010 - 1014 */
unhandled, unhandled, unhandled, unhandled, unhandled, /* ISRs 1015 - 1019 */
unhandled, unhandled, unhandled, unhandled	/* ISRs 1020 - 1023 */
};      

/*========================================================================*/
/*			FUNCTIONS													  */
/*========================================================================*/
  
/**************************************************************************/
/* FUNCTION    : unhandled												  */
/* PURPSE      : Dummy function which is entered if any non-used vector   */
/*							is called.									  */
/**************************************************************************/
void unhandled (void) {
     
    while (1){};                 
	    
}  
