/******************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the
concepts learned. I have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and debugged by my own efforts. I further
certify that I have not copied in part or whole or otherwise plagiarized the work of other students and/or
persons.


Patrick James T. Marcellana, DLSU ID# 12134457
******************************************************************/


/*
Description: This program allows the user to play Stalk Market Millionaire — a game wherein the player can buy and
             sell turnips. The main goal of the game is to reach one million bells within 20 weeks.
             This program follows the Linux Kernel coding standard.
Programmed by: Patrick James T. Marcellana S20A
Last modified: January 17, 2021
Version: 2
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/* This function displays the introductory message of the game.
*/
void
displayStartMessage ()
{
        printf ("\nWelcome to Stalk Market Millionaire!\n");
        printf ("\n[A] Play\n[B] Quit\n");
        printf ("\nPress [A] or [B] then Enter: ");
}


/* This function handles the invalid input when the player chooses between options  A or B 
Precondition: pChoice is a single character or more precisely, a single letter
@param *pChoice is the address where the user's choice between two options will be stored
*/
void
isChoiceValid (char *pChoice)
{
        while (*pChoice != 'A' &&
                *pChoice != 'a' && 
                *pChoice != 'B' && 
                *pChoice != 'b') {
                printf ("That's not a valid input, mate! Press [A] or [B], then Enter: ");
                scanf (" %c", pChoice);
        }
}


/* This function asks the user if he or she wants to play or quit, then checks for invalid inputs
Precondition: pStartChoice is a single character or more precisely, a single letter
@param *pStartChoice is the address where the user's choice at the start of the game will be stored
*/
void 
getStartChoice (char *pStartChoice)
{
        scanf (" %c", pStartChoice);
        isChoiceValid (pStartChoice);
}


/* This function displays Tommy's introduction and the game's brief instructions
*/
void
displayGameIntro ()
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\nTOMMY:  Hello Mate! I'm Tommy, and I'll be your guide in the Stalk Market. You want to become a\n");
        printf ("\tmillionaire, aye? Well, the simplest way to do that here is to buy turnips from Daisy Mae\n");
        printf ("\tand sell them at Nook's Cranny at a higher price to get profit. You can only buy and sell\n");
        printf ("\tthem in stacks of 10, and you only have 20 weeks to do that. To help you start, here are\n");
        printf ("\t5000 bells. Good luck, mate!\n");
}


/* This function shows a prompt on the user's screen to continue the game. It also 
handles invalid inputs by continuously asking the user until a valid input is entered.
*/
void
displayPrompt ()
{
        int nPromptContinue;

        printf ("\nPress [1] then Enter to Continue: ");
        scanf ("%d", &nPromptContinue);

        while (nPromptContinue != 1) {
                printf ("Invalid input. Press [1] then Enter to Continue: ");
                scanf ("%d", &nPromptContinue);
        }
}


/* This function gets the randomized value of the turnip's price with a specific range given
Precondition: nMinPrice and nMaxPrice are non-negative integers
@param nMinPrice is the minimum price of the turnip
@param nMaxPrice is the maximum price of the turnip
@return the randomized price of a single turnip
*/
int 
getRandomPrice (int nMinPrice,
                int nMaxPrice)
{
        int nRange, nPrice;

        nRange = nMaxPrice - nMinPrice + 1; // added one to the difference because of inclusivity 
        nPrice = rand () % nRange + nMinPrice; /* added nMinPrice to set the minimum price of the randomized
                                                value from 0 to the intended price */

        return nPrice;
}


/* This function displays the day and week number based on the player's game progress
Precondition: nDay and nWeek are both integers greater than 0 (non-zero and non-negative integers)
@param nDay is the number with a corresponding day where the player's progress is currently at
@param nWeek is the number of week where the player's progress is currently at
*/
void
displayDayAndWeek (int nDay, 
                   int nWeek)
{
        printf ("\n**Week: %d**", nWeek);
        printf ("\n**Day: ");
    
        switch (nDay) {
        case 1:
                printf ("Sunday");
                break;
        case 2:
                printf ("Monday");
                break;
        case 3:
                printf ("Tuesday");
                break;
        case 4:
                printf ("Wednesday");
                break;
        case 5:
                printf ("Thursday");
                break;
        case 6:
                printf ("Friday");
                break;
        case 7:
                printf ("Saturday");
                break;
        }

        printf ("**");
}


/* This function displays the current number of bells the player has
Precondition: nPlayerBells is a non-negative integer
@param nPlayerBells is the current number of bells the player has
*/
void
displayNoOfBells (int nPlayerBells)
{
        printf ("\n**Current Number of Bells: %d**", nPlayerBells);
}


/* This function displays the current number of stacks of turnips the player has
Precondition: nCurrentStacks is a non-negative integer
@param nCurrentStacks is the current number of turnip stacks the player has
*/
void
displayNoOfStacks (int nCurrentStacks)
{
        printf ("\n**Current Number of Stacks of Turnips: %d**\n\n", nCurrentStacks);
}


/* This function displays the current stats of the player in the game
Precondition: nDay and nWeek are both integers greater than 0 (non-zero and non-negative integers)
              nPlayerBells and nCurrentStacks are both non-negative integers
@param nDay is the number with a corresponding day where the player's progress is currently at
@param nWeek is the number of week where the player's progress is currently at
@param nPlayerBells is the current number of bells the player has
@nCurrentStacks is the current number of stacks of turnips that the player has
*/
void displayStats (int nDay,
                   int nWeek,
                   int nPlayerBells,
                   int nCurrentStacks)
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");

        displayDayAndWeek (nDay, 
                           nWeek);

        displayNoOfBells (nPlayerBells);
        displayNoOfStacks (nCurrentStacks);
}


/* This function displays Daisy Mae's message every time she arrives at Sunday to sell turnips
Precondition: nDay and nWeek are both integers greater than 0 (non-zero and non-negative integers)
              nBuyPrice, nPlayerBells, nBuyStackPrice, and nCurrentStacks are all non-negative integers
@param nDay is the number with a corresponding day where the player's progress is currently at
@param nWeek is the number of week where the player's progress is currently at
@param nBuyPrice is the randomized value of Daisy Mae's buying price, ranging from 90 to 110, inclusive
@param nPlayerBells is the current number of bells the player has
@param nBuyStackPrice is the buying cost of one stack of turnips
@nCurrentStacks is the current number of stacks of turnips that the player has
*/
void
displayDaisyMessage (int nDay, 
                     int nWeek,
                     int nBuyPrice, 
                     int nPlayerBells, 
                     int nBuyStackPrice,
                     int nCurrentStacks)
{
        displayStats (nDay,
                      nWeek,
                      nPlayerBells,
                      nCurrentStacks);

        printf ("\nDAISY MAE: I've got plenty of turnips, fresh from Sow Joan's Stalk Market.\n");
        printf ("\t   I currently sell them for %d bells per turnip; however, I can\n", nBuyPrice);
        printf ("\t   only sell turnips in stacks of 10, so that would be %d bells per stack.\n", nBuyStackPrice);
}


/* This function asks the user if he or she wants to buy turnips or not, then checks for invalid inputs
Precondition: pBuyChoice is a single character or more precisely, a single letter
@param pBuyChoice is the address where the user's choice to buy or not is stored
*/
void
getBuyChoice (char *pBuyChoice)
{
        printf ("\nDAISY MAE: Would you like to buy?\n");
        printf ("\n[A] Yes\n[B] No\n");
        printf ("\nPress [A] or [B] then Enter: ");

        scanf (" %c", pBuyChoice);
        isChoiceValid (pBuyChoice);
}


/* This function computes for the amount of bells spent on buying stacks of turnips
Precondition: nCurrentStacks and nBuyStackPrice are both non-negative integers
@param nCurrentStacks is the current number of turnip stacks that the player has
@param nBuyStackPrice is the buying cost of one stack of turnips
@return the amount spent after buying stacka of turnips
*/
int 
computeBuyCost (int nCurrentStacks, 
                int nBuyStackPrice)
{
        int nBuyCost;
        nBuyCost = nCurrentStacks * nBuyStackPrice;

        return nBuyCost;
}


/* This function handles the invalid inputs of the stacks that the player wants to buy
Precondition: pCurrentStacks, nPlayerBells, and nBuyStackPrice are all non-negative integers
@param pCurrentStacks is the address where the number of bought stacks will be stored
@param nPlayerBells is the current number of bells the player has
@param nBuyStackPrice is the buying cost of one stack of turnips
*/
void
isStacksBoughtValid (int *pCurrentStacks, 
                     int nPlayerBells, 
                     int nBuyStackPrice)
{
        while (computeBuyCost (*pCurrentStacks,
                                nBuyStackPrice) > nPlayerBells ||
                                *pCurrentStacks < 0) {
                if (computeBuyCost (*pCurrentStacks, 
                                    nBuyStackPrice) > nPlayerBells) {
                        printf ("\nYou can't afford that many! You only have %d bells.", nPlayerBells);
                        printf ("\nInput the number of stacks that you want to buy: ");

                        scanf ("%d", pCurrentStacks);
                } else if (*pCurrentStacks < 0) {
                        printf ("\nInvalid input. You can't buy negative stacks of turnips!");
                        printf ("\nInput the number of stacks that you want to buy: ");

                        scanf ("%d", pCurrentStacks);
                }
        }
}


/* This function asks the user the number of stacks he or she would like to buy
Precondition: nCurrentStacks, nPlayerBells, and nBuyStackPrice are all non-negative integers
@param pCurrentStacks is the address where the number of stacks that the player bought will be stored
@param nPlayerBells is the current number of bells the player has
@param nBuyStackPrice is the buying cost of one stack of turnips
*/
void
getBoughtStacks (int *pCurrentStacks,
                 int nPlayerBells,
                 int nBuyStackPrice)
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\nDAISY MAE: How many stacks would you like to buy? ");
    
        scanf ("%d", pCurrentStacks);
        isStacksBoughtValid (pCurrentStacks, 
                             nPlayerBells, 
                             nBuyStackPrice);
}


/* This function displays the receipt after buying or not buying turnips from Daisy Mae
Precondition: nCurrentStacks, nBuyStackPrice, and nPlayerBells are all non-negative integers
@param nCurrentStacks is the number of bought stacks of turnips  
@param nBuyStackPrice is the buyingcost of one stack of turnips
@param nPlayerBells is the current number of bells the player has
*/
void
displayBuyReceipt (int nCurrentStacks, 
                   int nBuyStackPrice, 
                   int nPlayerBells)
{
        printf ("\n-----------------------------------------------------------------------------------------------");
        printf ("\n\n**You bought %d stack(s) of turnips for %d bell(s)**\n", 
                nCurrentStacks, computeBuyCost (nCurrentStacks,
                                                nBuyStackPrice));
        printf ("\nRemaining Bells: %d bells", nPlayerBells);
        printf ("\nCurrent number of stacks of turnips: %d\n", nCurrentStacks);


        if (nCurrentStacks > 0) // message after buying stack(s) of turnips
                printf ("\nDAISY MAE: Thank you for buying, mate. Enjoy the turnips!\n");
        else // message after not buying any stack of turnips
                printf ("\nDAISY MAE: Well, you're a little thrifty this week, mate. Thanks anyways!\n");
}


/* This function gets the minimum and the maximum selling price based on the randomized weekly trend
Precondition: nBuyPrice, pMinSellPrice, and pMaxSellPrice are all non-negative integers
@param nBuyPrice is the randomized value of Daisy Mae's buying price, ranging from 90 to 110, inclusive
@param pMinSellPrice is the address where the minimum selling price will be stored
@param pMaxSellPrice is the address where the maximum selling price will be stored
*/
void
getWeeklyTrend (int nBuyPrice, 
                int *pMinSellPrice, 
                int *pMaxSellPrice)
{
        int nWeeklyTrend;
        nWeeklyTrend = rand () % 3;

        if (nWeeklyTrend == 0) {
                // Bad Trend
                *pMinSellPrice = 20;
                *pMaxSellPrice = nBuyPrice;
        } else if (nWeeklyTrend == 1) {
                // Average Trend
                *pMinSellPrice = 80;
                *pMaxSellPrice = 1.05 * nBuyPrice;
        } else {
                // Awesome Trend
                *pMinSellPrice = nBuyPrice;
                *pMaxSellPrice = nBuyPrice * 3;
        }
}


/* This function displays the selling price of the turnips on that specific day
Precondition: nDailySellPrice and nSellStackPrice are both non-negative integers
@param nDailySellPrice is the randomized value of the daily selling price based on a randomized weekly trend  
@param nSellStackPrice is the selling cost of one stack of turnips
*/
void
displaySellingPrice (int nDailySellPrice, 
                     int nSellStackPrice)
{
        printf ("\nTOMMY:  It's time to sell those turnips at Nook's Cranny, mate.\n");
        printf ("\tThe selling price today is %d bells per turnip or %d bells per stack of turnip.\n", 
                nDailySellPrice, nSellStackPrice);
}


/* This function asks the user if he or she wants to sell turnips or not, then checks for invalid inputs
Precondition: pSellChoice is a single character or more precisely, a single letter
@param pSellChoice is the address where the user's choice to sell turnips or not will be stored
*/
void
getSellChoice (char *pSellChoice)
{
        printf ("\nTOMMY:  Would you like to sell turnips today?\n");
        printf ("\n[A] Yes\n[B] No\n");
        printf ("\nPress [A] or [B] then Enter: ");

        scanf (" %c", pSellChoice);
        isChoiceValid (pSellChoice); 
}


/* This function checks if the number of stacks that the player inputs is valid
Precondition: pStacksSold and nCurrentStacks are both non-negative integers
@param pStacksSold is the address where the number of stacks the player wants to sell is stored
@param nCurrentStacks is the current number of stacks of turnips that the player has
*/
void
isStackSoldValid (int *pStacksSold,
                  int nCurrentStacks)
{
        while (*pStacksSold > nCurrentStacks ||
                *pStacksSold < 0) {
                if (*pStacksSold > nCurrentStacks) {
                        printf ("\nYou don't have that many stacks!");
                        printf ("\nInput the number of stacks you want to sell: ");

                        scanf ("%d", pStacksSold);
                } else if (*pStacksSold < 0) {
                        printf ("\nYou can't sell negative number of stacks!");
                        printf ("\nInput the number of stacks you want to sell: ");
                        scanf ("%d", pStacksSold);
                }
        }
}


/* This function asks the user the number of stacks he or she would like to sell
Precondition: pStacksSold and nCurrentStacks are both non-negative integers
@param pStacksSold is the address where the number of stacks the player sold will be stored
@param nCurrentStacks is the current number of stacks of turnips that the player has
*/
void
getSoldStacks (int *pStacksSold, 
               int nCurrentStacks)
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\nTOMMY:  How many stacks would you like to sell? ");

        scanf ("%d", pStacksSold);
        isStackSoldValid (pStacksSold, 
                          nCurrentStacks);
}


/* This function displays the receipt of the transaction after selling stacks of turnips
Precondition: nStacksSold, nCurrentStacks, nRevenue, and nPlayerBells are all non-negative integers
@param nStacksSold is the number of stacks that the player sold that day
@param nCurrentStacks is the current number of stacks of turnips that the player has
@param nRevenue is the total amount of bells earned by the player after selling turnips during that day
@param nPlayerBells is the current number of bells the player has
*/
void
displaySellReceipt (int nStacksSold, 
                    int nCurrentStacks,
                    int nRevenue,
                    int nPlayerBells)
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\n**You sold %d stack(s) of turnips for %d bell(s).**\n", nStacksSold, nRevenue);
        printf ("\nNumber of bells earned today: %d", nRevenue);
        printf ("\nNumber of Stacks Left: %d stack(s)", nCurrentStacks);
        printf ("\nTotal Current Number of Bells: %d bell(s)\n", nPlayerBells);

}


/* This function displays the Tommy's message to the player if there are no more stacks left to sell
Precondition: nWeek is a non-negative integer
@param nWeek is the number of week where the player's progress is currently at
*/
void
displayNoMoreStock (int nWeek)
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\nTOMMY:  Looks like you don't have any stacks left to sell for this week.");

        if (nWeek >= 1 && nWeek <= 19)
                printf("\n\n**WOOSH!**\n**Time fast forwards to Sunday next week**\n");
        else
                printf ("\n");
}


/* This function displays the Tommy's message to the player if there are turnips that become spoiled
Precondition: nCurrentStacks is a non-negative integer
@param nCurrentStacks is the current number of stacks of turnips that the player has
*/
void
displaySpoiledMessage (int nCurrentStacks)
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\nTOMMY:  It looks like you still have %d stack(s) of turnips left. It's been a", nCurrentStacks);
        printf ("\nweek since you've bought them, and now they became spoiled. You can no");
        printf ("\nlonger sell them!\n");
}


/* This function displays the Game Over message if the player no longer has enough bells to buy at least one
stack of turnips.
*/
void
displayOutOfBells ()
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\nGAME OVER!\n");
        printf ("\nYou do not have enough bells to buy at least one stack of turnips.");
        printf ("\nTry again, and better luck next time, aspiring millionaire!");
}


/* This function displays the Congratulations message if the player has accumulated more than 1 million
bells after 20 weeks.
Precondition: nPlayerBells is a non-negative integer
@param nPlayerBells is the current number of bells the player has
*/
void
displayCongrats (int nPlayerBells)
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\nCONGRATULATIONS, MATE!\n");
        printf ("\nAfter the given 20 weeks, you were able to become a millionaire with exactly %d bells.", 
                nPlayerBells);
}


/* This function displays the Game Over message if the player has failed to accumulate more than 1 million
bells after 20 weeks.
Precondition: nPlayerBells is a non-negative integer
@param nPlayerBells is the current number of bells the player has
*/
void
displayShortOfBells (int nPlayerBells)
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\nGAME OVER!\n");
        printf ("\n20 weeks have already passed, and you only had %d bells.", nPlayerBells);
        printf ("\nYou failed to become a millionaire. Try again, and better luck next time, aspiring millionaire!");
}


/* This function displays Tommy's message if the player chooses to quit the game.
*/
void
displayQuitMessage ()
{
        printf ("\n-----------------------------------------------------------------------------------------------\n");
        printf ("\nTOMMY:  It's sad to see you go. Hope to see you next time, mate!");
}


int main ()
{
        char cStartChoice, cBuyChoice, cSellChoice;
        int nPlayerBells, nCurrentStacks, nDay, nWeek;
        int nMinBuyPrice, nMaxBuyPrice, nBuyPrice, nBuyStackPrice;
        int nMinSellPrice, nMaxSellPrice, nDailySellPrice, nSellStackPrice, nStacksSold, nRevenue;


        srand (time (NULL)); // to handle the random value generator for the buying and selling prices


        displayStartMessage ();
        getStartChoice (&cStartChoice); // asks the player if he or she wants to play or not
    

        if (cStartChoice == 'A' ||
            cStartChoice == 'a') {
                /* the pathway of the game if the player chooses to play */


                displayGameIntro ();


                // initialization of the player's starting stats in the game
                nPlayerBells = 5000;
                nCurrentStacks = 0;


                displayPrompt (); 

        
                for (nWeek = 1;
                     nWeek <= 20;
                     nWeek++) {
                        /* start of buying phase */


                        // initialization to set the day to 1 (Sunday) every time the week starts
                        nDay = 1; 


                        // initialization of the variables needed for the randomized buying price
                        nMinBuyPrice = 90;
                        nMaxBuyPrice = 110;
                        nBuyPrice = getRandomPrice (nMinBuyPrice, 
                                                    nMaxBuyPrice); // cost of one turnip
                        nBuyStackPrice = nBuyPrice * 10; // cost of one stack of turnips (1 stack = 10 turnips)


                        displayDaisyMessage (nDay, 
                                             nWeek, 
                                             nBuyPrice, 
                                             nPlayerBells, 
                                             nBuyStackPrice,
                                             nCurrentStacks); 


                        if (nPlayerBells >= nBuyStackPrice) {
                                getBuyChoice (&cBuyChoice); /* asks if the player wants to buy turnips or not;
                                                               [A] if yes and [B] if no */


                                if (cBuyChoice == 'A' ||
                                    cBuyChoice == 'a') {          
                                        /* the pathway of the game if the player chooses to buy stacks */      


                                        getBoughtStacks (&nCurrentStacks, 
                                                         nPlayerBells, 
                                                         nBuyStackPrice);


                                        // decrementation of the player's bells in the game after buying turnips
                                        nPlayerBells -= computeBuyCost (nCurrentStacks, 
                                                                        nBuyStackPrice);
                                } else // pathway of the game if the player chooses not to buy at least one stack
                                        nCurrentStacks = 0;
                

                                displayBuyReceipt (nCurrentStacks, 
                                                   nBuyStackPrice, 
                                                   nPlayerBells);
                

                                getWeeklyTrend (nBuyPrice, 
                                                &nMinSellPrice, 
                                                &nMaxSellPrice);


                                displayPrompt ();


                                for (nDay = 2; 
                                     nDay <= 7;
                                     nDay++) {
                                        /* start of selling phase */


                                        // initialization of the selling price per day
                                        nDailySellPrice = getRandomPrice (nMinSellPrice, 
                                                                        nMaxSellPrice);
                                        nSellStackPrice = nDailySellPrice * 10; // cost of one stack of turnips


                                        if (nCurrentStacks >= 1) {
                                                /*game pathway if the player still has at least one stack of turnips */


                                                displayStats (nDay,
                                                              nWeek,
                                                              nPlayerBells,
                                                              nCurrentStacks);
                    

                                                displaySellingPrice (nDailySellPrice, 
                                                                     nSellStackPrice);
                                                getSellChoice (&cSellChoice);
    

                                                if (cSellChoice == 'A' ||
                                                    cSellChoice == 'a') {
                                                        /* game pathway if the player wants to sell turnips on
                                                           that day */


                                                        getSoldStacks (&nStacksSold, 
                                                                       nCurrentStacks);


                                                        nRevenue = nStacksSold * nSellStackPrice; /* amount of bells 
                                                                                                earned during that
                                                                                                day */
                                                } else {
                                                        /* game pathway if the player chooses to skip selling
                                                        of turnips on that day */

                                                        nStacksSold = 0;
                                                        nRevenue = 0;
                                                }
                        

                                                /* incrementation and decrementation of the player's current
                                                stats in the game after selling */
                                                nPlayerBells += nRevenue;
                                                nCurrentStacks -= nStacksSold;


                                                displaySellReceipt (nStacksSold, 
                                                                    nCurrentStacks, 
                                                                    nRevenue, 
                                                                    nPlayerBells);


                                                displayPrompt ();
                                        } else {
                                                /* game pathway if the player no longer has at least one stack 
                                                  of turnips */ 


                                                displayNoMoreStock (nWeek);
                                                nDay = 8; /* initialization to end the selling phase, moving the game
                                                        to the next Sunday */
                        

                                                displayPrompt ();
                                        }
                                }

                                if (nCurrentStacks > 0) {
                                        /* to check if there are unsold stacks after the last day of buying phase */


                                        displaySpoiledMessage (nCurrentStacks);
                                        nCurrentStacks = 0; // initialization to remove all spoiled stacks of turnips


                                        displayNoOfBells (nPlayerBells);
                                        displayNoOfStacks (nCurrentStacks);


                                        displayPrompt ();


                                        if (nWeek == 20 &&
                                            nPlayerBells < nBuyStackPrice)
                                                displayShortOfBells (nPlayerBells); /* since the conditions for the
                                                                                       else if statement below can't
                                                                                       include players that failed to
                                                                                       have 1 million bells after 20
                                                                                       weeks and that doesn't have 
                                                                                       enough bells to buy at least one
                                                                                       stack of turnips, the function 
                                                                                       has to be called here with a
                                                                                       specific if statement */
                                }
                        } else {
                                /* pathway of the game if the player can no longer afford at least
                                one stack of turnips */


                                displayPrompt ();


                                displayOutOfBells ();
                                nWeek = 21; // initialization to end the game
                        }
                }


                /* To check if the player has accumulated more than 1 million bells after 20 weeks.
                   The second statement is to make sure that this message won't show to players who
                   do not have enough bells to afford at least one stack of turnips */
                if (nPlayerBells >= 1000000) 
                        displayCongrats (nPlayerBells);
                else if (nPlayerBells < 1000000 &&
                        nPlayerBells >= nBuyStackPrice) {
                        displayShortOfBells (nPlayerBells);
                }
        } else // the pathway of the game if the player chooses to quit
                displayQuitMessage ();


        return 0;
}
