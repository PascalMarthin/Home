#include "ConsoleGlobalInst.h"

TextScreen MainScreen(10, 10, "¤±");
Monster* AllMonsters = new Monster[10];
Player MainPlayer(&MainScreen, "¡Ú");

extern bool EndGame = false;

//ConsoleGlobalInst::ConsoleGlobalInst() 
//{
//}
//
//ConsoleGlobalInst::~ConsoleGlobalInst() 
//{
//}
//
