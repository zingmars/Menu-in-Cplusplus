#pragma once

#define UP false
#define DOWN true
#define DEFAULT 0
#define UPPERBAR 1

// Klase, kas satur izvēlnes punktu
class MenuItem {
public:
	std::string Name = "";
	std::function<void()> function;
	int strlength = 0;
	int value = 0;
	
	MenuItem() {
		Name = "";
		strlength = 0;
		function = []() {};
	}
	MenuItem(std::string newName, std::function<void()> newFunction) {
		Name = newName;
		strlength = Name.length();
		function = newFunction;
	}
	MenuItem(std::string newName) {
		Name = newName;
		strlength = Name.length();
		function = []() {};
	}

	void execute() {
		function();
	};
};

class Menu {
protected:
	unsigned int currentlySelected = 1;
	std::vector<MenuItem> items;
	int mode = DEFAULT;
public:
	Menu() {		
	}
	Menu(int menuMode) {		
		mode = menuMode;
	}

	void AddItem(MenuItem newItem){		
		items.push_back(newItem);
	}
	void AddItem(MenuItem* newItem){
		items.push_back(*newItem);
	}

	void Erase() {
		items.clear();
		currentlySelected = 1;
		mode = DEFAULT;
	}

	void DeleteItem(int num) {
		items.erase(items.begin() + num-1);
	}

	void processMovement(bool direction) {		
		if ( direction == false && currentlySelected > 1 ) currentlySelected--;
		else if ( direction == true && currentlySelected < items.size() ) currentlySelected++;
	}

	void Execute() {
		if (items.size() > 0)
			items[currentlySelected-1].execute();
	}

	int getX(int member) {
		int result = 0;
		if (mode == UPPERBAR) {
			int count = 0;
			for each(MenuItem item in items) {
				result += item.Name.length() + 2;
				count++;
				if (count == member-1) break;
			}
		}
		return result;
	}

	void Draw() {
		unsigned int index = 1;		

		if (mode == UPPERBAR) {
			int x = 0;			
			gotoxy(0, 0);
			for (int iii = 0; iii < 80; iii++) {
				printColouredText(" ", LIGHTGRAY);
			}

			for each(MenuItem item in items) {
				gotoxy(x, 0);				
				int colour = LIGHTGRAY;
				int shortcutColour = REDONGRAY;

				if (currentlySelected == index) {
					colour = DARKGREEN;
					shortcutColour = REDONGREEN;
				}
				
				printColouredText(" " + item.Name.substr(0, 1), shortcutColour);
				printColouredText(item.Name.substr(1, item.Name.length() - 1) + " ", colour);												

				gotoxy(100, 100);
				x = x + item.Name.length() + 2;
				index++;
			}
		}		
		else if (mode == DEFAULT) {
			for each (MenuItem item in items) {
				gotoxy(0, index-1);
				if (currentlySelected == index) printColouredText(std::to_string(index) + ". " + item.Name, RED);			
				else printColouredText(std::to_string(index) + ". " + item.Name, GRAY);
				index++;
			}
		}		
	}
};
class SubMenu : public Menu {
private:
	int width = 0;
	bool drawn = false;
	int location = 0;

public:
	SubMenu() {
	}
	SubMenu(int Location) {
		location = Location;
	}
	SubMenu(int Location, int Width){
		location = Location;
		width = Width;
	}
	void SetWidth(int newWidth) {
		width = newWidth;
	}
	void CalculateWidth() {
		int lenghtiest = 0;
		for each (MenuItem item in items) {
			if (item.Name.length() > lenghtiest) lenghtiest = item.Name.length();
		}
		width = lenghtiest+2;		
	}
	void SetLocation(int x) {
		location = x;
	}
	bool Drawn() { 
		return drawn; 
	}
	void DoDraw() {
		drawn = !drawn;
	}
	void Redraw() {
		if (!drawn) return;
		if (width == 0) CalculateWidth();

		int y = 1;

		for each(MenuItem item in items) {
			int x = location;
			int colour = LIGHTGRAY;
			if (currentlySelected == y) colour = DARKGREEN;
			int extra = width - item.Name.length();

			gotoxy(x, y);
			
			printColouredText(" " + item.Name, colour);

			if (extra > 0) {
				for (int iii = 0; iii < extra; iii++) {
					printColouredText(" ", colour);
				}
			}

			y++;
		}
	}
	void Clear() {
		int y = 1;
		for each(MenuItem item in items) {
			int x = location;
			gotoxy(x, y);
			for (int iii = 0; iii < width+1; iii++) {
				printColouredText(" ", 25);
			}
			y++;
		}
		currentlySelected = 1;
	}
	void Close() {
		DoDraw();
	}
	void Close(bool clear) {
		DoDraw();
		if (clear) Clear();
	}
};