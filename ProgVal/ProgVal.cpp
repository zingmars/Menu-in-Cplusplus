#include <stdio.h>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <functional>

#include "colours.h"
#include "HelperFunctions.h"
#include "MenuClasses.h"

//Karstie taustiņi
bool active = true;

int main() {	
	system("color 1F"); 
	MenuItem testItem = MenuItem("Item1", [](){ gotoxy(0, 10);  printColouredText("Test", 0x1F); });

	Menu* test = new Menu(UPPERBAR);	
	SubMenu* submenu = new SubMenu();

	test->AddItem(testItem);	
	test->AddItem(MenuItem("Item2", [&submenu](){ submenu->DoDraw(); }));
	test->AddItem(MenuItem("Item3", [](){}));
	test->AddItem(new MenuItem("Exit", [](){ exit(0); }));

	submenu->SetLocation(test->getX(2));
	submenu->AddItem(testItem);
	submenu->AddItem(MenuItem("Item2", [](){}));
	submenu->AddItem(MenuItem("Close", [&submenu](){ submenu->Close(true); }));

	//Handlo keyboard shortcutus.
	int input;	
	while( active ) {
		test->Draw(); 
		submenu->Redraw();
		input = _getch();
		if (submenu->Drawn()) {
			switch (input) {
			case 13: submenu->Execute(); break;
			case 72: case 75: submenu->processMovement(UP); break;
			case 80: case 77: submenu->processMovement(DOWN); break;
			}
		}
		else {
			switch( input ) {
				case 13: test->Execute(); break;
				case 72: case 75: test->processMovement(UP); break;				
				case 80: case 77: test->processMovement(DOWN); break;
			}
		}
	}	
	return 0;
}