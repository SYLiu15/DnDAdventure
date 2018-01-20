/****************************************************************************************************
 ** Program: DnDAdventure.cpp
 ** Version: 1.0
 ** Author: Suyang Liu
 ** Date: Jan 20, 2018
 ** Description: This program simulates a DnD adventure, giving you choices to influence the outcome
 ** Input: Numbers from 1-5
 ** Output: Text that describes the adventure
 ****************************************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	int prompt, spellprompt, stage = 1, armor = 0, spells = 10, php = 80, mhp = 80, garbage, mattack = 0;
	int aroll, aroll1, aroll2, droll, droll1, droll2, hitrand, mushprompt, mushval = 0, mroll, spellcheck, escape = 0;
	srand(time(NULL));
	
	// Start of adventure
	for (; stage == 1; ) {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
		cout << "You are a wizard living in a city embeddded into a grandiose cliff" << endl;
		cout << "face overlooking the sea. You are asked to deliver a letter to a" << endl;
		cout << "nearby city.\n" << endl;
		cout << "You have " << php << " hitpoints and " << spells << " spell slots.\n" << endl;
		cout << "How do you want to begin your adventure?\n" << endl;
		cout << "Choose a number\n" << endl;
		cout << "    1) Enter the tunnels that travel deep within the cliffside" << endl;
		cout << "    2) Jump off the cliff and fly there\n" << endl;
		cin >> prompt;
		
		if (prompt == 1) {
			stage = 2;
			break;
		}
		if (prompt == 2) {
			stage = 0;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "Humans can't fly, you fall into the water below.\n" << endl;
			cout << "You are dead.\n" << endl;
			break;
		}
	}
	
	// You find a mushroom
	for (; stage == 2; ) {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
		cout << "You find a strange mushroom. What do you do?\n" << endl;
		cout << "Choose one\n" << endl;
		cout << "    1) Take the mushroom" << endl;
		cout << "    2) Eat the mushroom" << endl;
		cout << "    3) Leave it\n" << endl;
		cin >> mushprompt;
		
		if (mushprompt == 1) {
			mushval = 1;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "You now have a strange mushroom. You continue on.\n" << endl;
			cout << "Enter any value to continue\n" << endl;
			cin >> garbage;
			stage = 3;
		}
		if (mushprompt == 2) {
			mroll = rand() %31 - 15;
			if (mroll > 0){
				php = php + mroll;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "You gain " << mroll << " hitpoints!\n" << endl;
				cout << "You now have " << php << " hitpoints!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			else if (mroll == 0) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "Nothing happens. You continue on.\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			else {
				php = php + mroll;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "You lose " << mroll << " hitpoints!\n" << endl;
				cout << "You have " << php << " hitpoints remaining!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			stage = 3;
		}
		if (mushprompt == 3) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "You continue on with your quest.\n" << endl;
			cout << "Enter any value to continue\n" << endl;
			cin >> garbage;
			stage = 3;
		}
		if (php < 1) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "You are dead\n" << endl;
			stage = 0;
			break;
		}
	}
	
	// Combat with troll
	for (; stage == 3; ) {
		// Alternate menu if player takes mushroom
		if (mushval == 1) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "You encounter a troll. What do you do?\n" << endl;
			cout << "Choose one\n" << endl;
			cout << "    1) Swing at him with your dagger" << endl;
			cout << "    2) Cast a spell" << endl;
			cout << "    3) Talk to him" << endl;
			cout << "    4) Run away" << endl;
			cout << "    5) Eat the mushroom\n" << endl;
			cin >> prompt;
		}
		else {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "You encounter a troll. What do you do?\n" << endl;
			cout << "Choose one\n" << endl;
			cout << "    1) Swing at him with your dagger" << endl;
			cout << "    2) Cast a spell" << endl;
			cout << "    3) Talk to him" << endl;
			cout << "    4) Run away\n" << endl;
			cin >> prompt;
		}
		
		// Dagger attack
		if (prompt == 1) {
			aroll = rand() %20 + 1;
			if (aroll + 7 >= 15) {
				droll = rand() %4 + 1;
				mhp = mhp - (droll + 2);
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "You hit for " << droll + 2 << " damage!\n" << endl;
				cout << "The troll has " << mhp << " hitpoints left!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
				mattack = 1;
			}
			else {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "You missed!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
				mattack = 1;
			}
		}
		
		// Spell menu
		if (prompt == 2) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "What spell do you use?\n" << endl;
			cout << "Choose one\n" << endl;
			cout << "    1) Use ray of frost (0 cost)" << endl;
			cout << "    2) Use mage armor (1 cost)" << endl;
			cout << "    3) Use scorching ray (2 cost)" << endl;
			cout << "    4) Use fireball (3 cost)\n" << endl;
			cin >> spellprompt;
			spellcheck = spells;
			
			// Ray of frost
			if (spellprompt == 1) {
				aroll = rand() %20 + 1;
				if (aroll + 7 >= 15) {
					droll = rand() %8 + 1;
					droll1 = rand() %8 + 1;
					mhp = mhp - (droll + droll1);
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "You hit for " << droll + droll1 << " damage!\n" << endl;
					cout << "The troll has " << mhp << " hitpoints left!\n" << endl;
					cout << "Enter any value to continue\n" << endl;
					cin >> garbage;
					mattack = 1;
				}
				else {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "You missed!\n" << endl;
					cout << "Enter any value to continue\n" << endl;
					cin >> garbage;
					mattack = 1;
				}
			}
			
			// Mage armor
			if (spellprompt == 2 && spells > 0) {
				armor = 1;
				spells = spells - 1;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "You boost your armor stat and become harder to damage!\n" << endl;
				cout << "You used up 1 spell slot, you have " << spells << " remaining!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
				mattack = 1;
			}
			if (spellprompt == 2 && spellcheck < 1) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "Not enough spell slots!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			
			// Scorching ray
			if (spellprompt == 3 && spells > 1) {
				droll = 0;
				droll1 = 0;
				droll2 = 0;
				
				aroll = rand() %20 + 1;
				aroll1 = rand() %20 + 1;
				aroll2 = rand() %20 + 1;
				if (aroll + 7 >= 15) {
					droll = rand()%6+1 + rand()%6+1;
				}
				else {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "You miss your first scorching ray!\n" << endl;
					cout << "Enter any value to continue\n" << endl;
					cin >> garbage;
				}
				
				if (aroll1 + 7 >= 15) {
					droll1 = rand()%6+1 + rand()%6+1;
				}
				else {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "You miss your second scorching ray!\n" << endl;
					cout << "Enter any value to continue\n" << endl;
					cin >> garbage;
				}
				
				if (aroll2 + 7 >= 15) {
					droll2 = rand()%6+1 + rand()%6+1;
				}
				else {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "You miss your Third scorching ray!\n" << endl;
					cout << "Enter any value to continue\n" << endl;
					cin >> garbage;
				}
				
				mhp = mhp - (droll + droll1 + droll2);
				spells = spells - 2;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "The troll takes " << droll + droll1 + droll2 << " damage!\n" << endl;
				cout << "The troll has " << mhp << " hitpoints remaining!\n" << endl;
				cout << "You used up 2 spell slots, you have " << spells << " remaining!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
				mattack = 1;
			}
			if (spellprompt == 3 && spellcheck < 2) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "Not enough spell slots!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			
			// Fireball
			if (spellprompt == 4 && spells > 2) {
				hitrand = rand()%20 + 1;
				
				if (hitrand >= 15) {
					droll = rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1;
					mhp = mhp - droll;
					php = php - droll;
					spells = spells - 3;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "Because you're in a tunnel, the fireball's explosion also hits you." << endl;
					cout << "You hit the troll and yourself for " << droll << " damage!\n" << endl;
					cout << "The troll has " << mhp << " hitpoints remaining!\n" << endl;
					cout << "You have " << php << " hitpoints remaining!\n" << endl;
					cout << "You used up 3 spell slots, you have " << spells << " remaining!\n" << endl;
					cout << "Enter any value to continue\n" << endl;
					cin >> garbage;
					if (php > 0){
						mattack = 1;
					}
				}
				else {
					droll = rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1 + rand()%6+1;
					mhp = mhp - droll;
					spells = spells - 3;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "You hit the troll for " << droll << " damage!\n" << endl;
					cout << "The troll has " << mhp << " hitpoints remaining!\n" << endl;
					cout << "You used up 3 spell slots, you have " << spells << " remaining!\n" << endl;
					cout << "Enter any value to continue\n" << endl;
					cin >> garbage;
					mattack = 1;
				}
			}
			if (spellprompt == 4 && spellcheck < 3) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "Not enough spell slots!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			
			
		}
		
		// Talk to troll
		if (prompt == 3) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "The troll doesn't understand you. It looks confused.\n" << endl;
			cout << "Enter any value to continue\n" << endl;
			cin >> garbage;
			aroll = rand()%2;
			if (aroll == 1) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "The troll decides to attack you!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
				mattack = 1;
			}			
		}
		
		// Run away
		if (prompt == 4 && php < 40) {
			//reset damage values
			droll = 0;
			
			aroll = rand() %20 + 1;
			if (aroll + 7 >= 17 && armor == 1) {
				droll = (rand()%6 + 1 + rand()%6 + 1 + 4) * 4;
				php = php - droll;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "The troll attacks you as you run!\n" << endl;
				cout << "You take " << droll << " damage!\n" << endl;
				cout << "You have " << php << " hitpoints remaining!\n" << endl;
			}
			else if (aroll + 7 < 17 && armor == 1) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "The troll attacks you as you run, however it misses its attack!\n" << endl;
			}
			else {
				droll = (rand()%6 + 1 + rand()%6 + 1 + 4) * 2;
				php = php - droll;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "The troll attacks you as you run!\n" << endl;
				cout << "You take " << droll << " damage!\n" << endl;
				cout << "You have " << php << " hitpoints remaining!\n" << endl;
			}
			cout << "Enter any value to continue\n" << endl;
			cin >> garbage;
			escape = 1;
		}
		
		if (prompt == 4 && php >= 40) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "You still have a good chance at winning the battle. Why would you run away?\n" << endl;
			cout << "Enter any value to continue\n" << endl;
			cin >> garbage;
		}
		
		// Eat mushroom
		if (prompt == 5) {
			mroll = rand() %31 - 15;
			if (mroll > 0){
				php = php + mroll;
				mushval = 0;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "You gain " << mroll << " hitpoints!\n" << endl;
				cout << "You now have " << php << " hitpoints!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			else if (mroll == 0) {
				mushval = 0;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "Nothing happens. You continue on.\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			else {
				php = php + mroll;
				mushval = 0;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "You lose " << mroll << " hitpoints!\n" << endl;
				cout << "You have " << php << " hitpoints remaining!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			if (php > 0) {
				mattack = 1;
			}
		}
		
		// Run away check if player above 0 hp
		if (php > 0 && escape == 1) {
			stage = 4;
			break;
		}
		
		// Winning combat check
		if (mhp < 1 && php > 0) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "Congratulations, the troll is dead! You continue on.\n" << endl;
			cout << "Enter any value to continue\n" << endl;
			cin >> garbage;
			stage = 4;
			break;
		}
		
		// Troll attack check
		if (mattack == 1) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "The troll attacks 3 times!\n" << endl;
			cout << "It uses a bite attack and 2 claw attacks!\n" << endl;
			cout << "Enter any value to continue\n" << endl;
			cin >> garbage;
			//reset damage values
			droll = 0;
			droll1 = 0;
			droll2 = 0;
			
			aroll = rand() %20 + 1;
			aroll1 = rand() %20 + 1;
			aroll2 = rand() %20 + 1;
			if (aroll + 7 >= 17 && armor == 1) {
				droll = rand() %6 + 1 + 4;
			}
			else if (aroll + 7 < 17 && armor == 1) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "The troll misses its bite attack!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			else {
				droll = rand()%6 + 1 + 4;
			}
			
			if (aroll1 + 7 >= 17 && armor == 1) {
				droll1 = rand()%6 + 1 + rand()%6 + 1 + 4;
			}
			else if (aroll1 + 7 < 17 && armor == 1) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "The troll misses a claw attack!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			else {
				droll1 = rand()%6 + 1 + rand()%6 + 4;
			}
			
			if (aroll2 + 7 >= 17 && armor == 1) {
				droll2 = rand()%6 + 1 + rand()%6 + 1 + 4;
			}
			else if (aroll2 + 7 < 17 && armor == 1) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				cout << "The troll misses its second claw attack!\n" << endl;
				cout << "Enter any value to continue\n" << endl;
				cin >> garbage;
			}
			else {
				droll2 = rand()%6 + 1 + rand()%6 + 1 + 4;
			}
			
			php = php - (droll + droll1 + droll2);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "You take " << droll + droll1 + droll2 << " damage!\n" << endl;
			cout << "You have " << php << " hitpoints remaining!\n" << endl;
			cout << "Enter any value to continue\n" << endl;
			cin >> garbage;
			mattack = 0;
		}
		
		// Death check
		if (php < 1) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "You are dead.\n" << endl;
			break;
		}
	}
	
	// End quest
	for (; stage == 4; ) {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
		cout << "You make it to the nearby city. You are rewarded a sizable paycheck" << endl;
		cout << "for completing your quest. Congratulations!\n" << endl;
		break;
	}
	
	return 0;
}