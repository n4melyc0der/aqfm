#include <iostream>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

float rateMe = 3;
double cashBank = 0;
short int hoursForTheDay = 0;
short int daysLeft = 0;
char name[21];
int memePoints = 0;
float currentMulti = 0;
unsigned short int deathMode = 666;
double blingBlingDolla = 0;
short int itemsToBuy = 0;
unsigned short int temFlakes = 0;
unsigned short int temWater = 0;
bool extraBool = true;
unsigned short int valReturn = 0;
short int fullness = 0;
short int hydration = 0;
int totalStatChecks = 0;
FILE *gems;
short int totalEXP = 0;
short int codingLevel = 0;
short int books[8] = {0, 0, 0, 0, 0, 0, 0, 0};
short int bookReadTime[8] = {0, 3, 5, 10, 15, 20, 24, 48};
short int games[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
long fsize;
char *loadVar;
short int currentHotGame = 1; // 1 for Call of Pepe V, 2 for Unmemed 5: Memes Uncultured, 3 for Meme Funeral, 4 for Holla' 3, 5 for The Memes Unleashed 2, 6 for Battlememe 9001, 7 for Harambe Simulator, 8 for Memeza 3: Pepeizon, 9 for Hotline Memeami, 10 for Counterdank: Global Meme
bool loaded = false;
double tranCash = 1.23;

struct mailMsg {
	void (*payloadPointer)();
	char subject[20];
	char contents[100];
	int msgID;
	bool newMsg;
};

int readMailMsg (struct mailMsg message) {
	cout << "Subject: " << message.subject << endl << endl;
	cout << "Body:" << endl << message.contents << endl;
	if (message.newMsg) message.payloadPointer();
	message.newMsg = false;
}

int random(unsigned int minimal, unsigned int maximal){
	srand(time(0));
	maximal++;
    maximal -= minimal;
    return maximal ? (rand() % maximal + minimal) : minimal;
}

int skillTreeCheck(int jobLevel) {
	if (jobLevel == codingLevel) totalEXP++;
	if (totalEXP % 25 == 0 && totalEXP != 0 && codingLevel < 7) {
		codingLevel++; // 0 for Flash, 1 for HTML, 2 for CSS, 3 for JS, 4 for PHP, 5 for Java, 6 for C++, 7 for Assembler
		switch (codingLevel) {
			case 1:
				cout << endl << "You remembered that you saw an advert when browsing the net about ShitPages hiring." << endl;
				cout << "Seeing the page that the advert linked to, you read that they're highly understaffed." << endl;
				cout << "They're apparently even willing to hire someone that knows just HTML for 10$/hr." << endl;
				cout << "\"Man, HTML mustn't be that hard, right?\"" << endl;
				cout << "\"Y'know what they say, it's the basic building block of every website.\"" << endl;
				cout << "\"Might check if there's a book on HTML in the Tem Shop and give this a try." << endl;
			break;
			case 2:
				cout << endl << "You got a email saying that you could get promoted if you knew CSS and gave a single shit about your job."<<endl;
				cout << "\"Time to get a new book.\""<<endl;
			break;
			case 3:
				cout << endl << "You got new mail!" <<endl;
				cout << "\"alert(\"We need a little more of that scripting ya know?\");"<<endl;
				cout << "\"alert(\"Go talk to me once you'll understand this, dummy.\");"<<endl;
				cout << "You don't know what this means, but you get a slight vibe of this being the boss telling you to learn JS."<<endl;
			break;
			case 4:
				cout << endl << "\"Another spam mail, another phishing mail, oh, what's this?\""<<endl;
				cout << "\"We real need some extra spicy security up on these sites.\""<<endl;
				cout << "\"Pick up the pace, or I'll fire you for that JS someone hacked and overwrote the whole page with \"LOLZ H4X0RD BY THE_MEN\".\""<<endl;
			break;
			case 5:
				cout << endl << "\"Could I get you for one second?\""<<endl;
				cout << "\"Sure thing, boss.\""<<endl;
				cout << "\"Listen up, you sound like a good guy. I know a relative at MacroHard.\""<<endl;
				cout << "\"Boss, isn't that nepotism or something?\""<<endl;
				cout << "\"Shut up! Nepotism would be if he'd hire me! He'll make some shit up on you and YOU'll be hired.\""<<endl;
				cout << "\"You just have to prove yourself one more time.\""<<endl;
				cout << "\"Make some crappy-ass Java apps to show those competitor fuckheads how great we really are!\""<<endl;
			break;
			case 6:
				cout << endl << "You find another email in your inbox."<<endl;
				cout << "\"Cool thing dude! I got you a new job!\""<<endl;
				cout << "\"Sorry for those things back then, I hoped that'd even us out...\""<<endl;
				cout << "\"I'll find some other fool if I'll need one.\""<<endl;
				cout << "\"Sorry to see ya go, dude.\""<<endl;
				cout << "\"Thanks for all the sites you made, Boss.\""<<endl;
				cout << "\"PS: There should be an invitation from MacroHard a'comin'!\""<<endl;
				cout << "You take a long breath."<<endl;
				cout << "\"Maybe he isn't that bad after all...\""<<endl;
				cout << "(Press any key to continue...)"<<endl;
				getch();
				cout << endl << "New mail!"<<endl;
				cout << "\"Welcome to MacroHard!\""<<endl;
				cout << "\"We've heard of your vast C++ knowledge, and we'd like you to join us!\""<<endl;
				cout << "\"Reply to this email anytime you're ready and login to our site with the attached credidentials to get started!\""<<endl;
				cout << "\"Vast C++ knowledge?\", you mumble to yourself."<<endl;
				cout << "\"What the hell?\""<<endl;
			break;
			case 7:
				cout << endl << "A mail from MacroHard?"<<endl;
				cout << "\"We've found your skills extremely valuable to our team!\""<<endl;
				cout << "\"Somehow, we managed to cut VoIP expenses!\""<<endl;
				cout << "\"They probably know...\", you say to yourself."<<endl;
				cout << "\"We decided to move you over to the low-level software section.\""<<endl;
				cout << "\"You seem to know a bit of Assembler already, learn a bit more on that and reply to this mail to let us finalize the move.\""<<endl;
				cout << "\"Assembler, \" - you say - \"nothing can be more difficult than this.\""<<endl;
			break;
		}
	}
}

int load() {
	while ((gems = fopen("save", "rb")) == NULL) {
		cout << "The file is probably used by some other applications." << endl;
		cout << "Please, close them and press any key to try again..." << endl <<endl;
		getch();
	}
	char buffer[256];
	int lel = 0;
	int checker = 0;
  	while (fgets(buffer, 256, gems)) { 
  		buffer[strcspn(buffer, "\n")] = 0;
    	lel++;
    	switch(lel) {
    		case 1:
    			checker+=sscanf(buffer, "%i", &hoursForTheDay);
    		break;
    		case 2: 
    			checker+=sscanf(buffer, "%i", &daysLeft);
    		break;
    		case 3:
    			checker+=sscanf(buffer, "%f", &currentMulti);
    		break;
    		case 4:
    			checker+=sscanf(buffer, "%i", &memePoints);
    		break;
    		case 5: 
    			checker+=sscanf(buffer, "%lf", &blingBlingDolla);
    		break;
			case 6:
    			checker+=sscanf(buffer, "%i", &temFlakes);
    		break;
    		case 7: 
    			checker+=sscanf(buffer, "%i", &temWater);
    		break;
    		case 8:
    			checker+=sscanf(buffer, "%i", &fullness);
    		break;
    		case 9: 
    			checker+=sscanf(buffer, "%i", &hydration);
    		break;
    		case 10:
    			checker+=sscanf(buffer, "%i", &totalStatChecks);
    		break;
    		case 11:
    			checker+=sscanf(buffer, "%i", &codingLevel);
    		break;
    		case 12: 
    			checker+=sscanf(buffer, "%i", &totalEXP);
    		break;
			case 13:
    			checker+=sscanf(buffer, "%i", &bookReadTime[1]);
    		break;
    		case 14: 
    			checker+=sscanf(buffer, "%i", &bookReadTime[2]);
    		break;
    		case 15:
    			checker+=sscanf(buffer, "%i", &bookReadTime[3]);
    		break;
    		case 16: 
    			checker+=sscanf(buffer, "%i", &bookReadTime[4]);
    		break;
    		case 17:
    			checker+=sscanf(buffer, "%i", &bookReadTime[5]);
    		break;
    		case 18: 
    			checker+=sscanf(buffer, "%i", &bookReadTime[6]);
    		break;
    		case 19: 
    			checker+=sscanf(buffer, "%i", &bookReadTime[7]);
    		break;
    		case 20:
    			checker+=sscanf(buffer, "%i", &books[1]);
    		break;
    		case 21: 
    			checker+=sscanf(buffer, "%i", &books[2]);
    		break;
    		case 22:
    			checker+=sscanf(buffer, "%i", &books[3]);
    		break;
    		case 23: 
    			checker+=sscanf(buffer, "%i", &books[4]);
    		break;
    		case 24:
    			checker+=sscanf(buffer, "%i", &books[5]);
    		break;
    		case 25: 
    			checker+=sscanf(buffer, "%i", &books[6]);
    		break;
    		case 26: 
    			checker+=sscanf(buffer, "%i", &books[7]);
    		break;
    		case 27:
    			checker+=sscanf(buffer, "%i", &games[1]);
    		break;
    		case 28: 
    			checker+=sscanf(buffer, "%i", &games[2]);
    		break;
    		case 29: 
    			checker+=sscanf(buffer, "%i", &games[3]);
    		break;
    		case 30:
    			checker+=sscanf(buffer, "%i", &games[4]);
    		break;
    		case 31: 
    			checker+=sscanf(buffer, "%i", &games[5]);
    		break;
    		case 32:
    			checker+=sscanf(buffer, "%i", &games[6]);
    		break;
    		case 33: 
    			checker+=sscanf(buffer, "%i", &games[7]);
    		break;
    		case 34:
    			checker+=sscanf(buffer, "%i", &games[8]);
    		break;
    		case 35: 
    			checker+=sscanf(buffer, "%i", &games[9]);
    		break;
    		case 36: 
    			checker+=sscanf(buffer, "%i", &games[10]);
    		break;
    		case 37: 
    			checker+=sscanf(buffer, "%i", &currentHotGame);
    		break;
    		case 38: 
    			checker+=sscanf(buffer, "%lf", &cashBank);
    		break;
    		case 39: 
    			checker+=sscanf(buffer, "%f", &rateMe);
    		break;
    		case 40: 
    			strcpy(name, buffer);
    		break;
    	}	
  	}
  	fclose(gems);
	if (checker!=39) {
		cout << "Something went wrong while trying to read the file." << endl;
		cout << "File is probably corrupted, starting new game instead..." << endl <<endl;
		return 1;
	} else {
		return 0;
	}
}

int chuckNorris() {
	cout << endl << "As you were sitting on your computer, baking some fresh memes, Chuck Norris decided to take you home."<<endl;
	cout << "\"His home?\", you may ask. Meme-heaven."<<endl;
	cout << "\"Well, you've done good, my boy.\""<<endl;
	cout << "\"At the time I took you here, you had " << memePoints << "memepoints.\""<<endl;
	cout << "\"I have to go. Enjoy the memes for now.\""<<endl;
	cout << "GAME OVER. You died like a man."<<endl;
	cout << "Press any key to quit..."<<endl;
	getch();
	exit(0);
	return 0;
}

int fadedAway() {
	cout << endl << "You've made your mistakes."<<endl;
	cout << "Got nowhere to run."<<endl;
	cout << "The night went on."<<endl;
	cout << "As you faded away..."<<endl;
	PlaySound(TEXT("fadedaway.wav"), NULL, SND_FILENAME);
	cout << endl << "GAME OVER. You died like a pussy."<<endl;
	cout << "(You had " << memePoints << " memepoints before you decided to jump.)"<<endl;
	cout << "Press any key to quit..."<<endl;
	getch();
	exit(0);
	return 0;
}

int checkForFullnessAndHydration() {
	if (fullness <= 0) {
		deathMode = 2; // you died from hunger
		cout << endl << "Every 10 seconds a person dies from hunger."<<endl;
		cout << "Looks like this was your 10 seconds."<<endl;
		cout << "GAME OVER. You died from hunger."<<endl;
		cout << "(You had " << memePoints << " memepoints before you died from hunger.)"<<endl;
		cout << "Press any key to quit..."<<endl;
		getch();
		exit(0);
		return 0;
	}
	if (hydration <= 0) {
		deathMode = 3; // you died from dehydration
		cout << endl << "Human body has around 50-65% of water."<<endl;
		cout << "To dehydrate, you have to drop that level to at least 30%."<<endl;
		cout << "Looks like you had below 30%."<<endl;
		cout << "GAME OVER. You died from dehydration."<<endl;
		cout << "(You had " << memePoints << " memepoints before you died from dehydration.)"<<endl;
		cout << "Press any key to quit..."<<endl;
		getch();
		exit(0);
		return 0;
	}
	if (fullness <= 30) {
		cout << "Your fullness is dangerously low. (Now " << fullness << ".)"<<endl;
		cout << "Go get something to eat or you might not get to live another hour."<<endl;	
	}
	if (hydration <= 30) {
		cout << "Your thirst is dangerously low. (Now " << hydration << ".)"<<endl;
		cout << "Go get something to drink or you might not get to live another hour."<<endl;
	}
	return 0;
}

int statBoard() {
	cout << endl << "You type \"statboard.com\" into the URL bar and hit enter, the famous StatBoard(TM) website pops up."<<endl;
	while (hoursForTheDay != 0) {
		cout << "The website contains three buttons, \"View Stats\", \"Save\" and \"Leave\"."<<endl;
		cout << endl << "Which one do you pick?" <<endl;
		cout << "1. \"View Stats\"." <<endl;
		cout << "2. \"Save\"." <<endl;
		cout << "3. \"Leave\"." <<endl;
theHell:switch (getch()) {
			case '1':
				cout << endl << "\"Your name is " << name << ".\"" << endl;
				cout << "\"This is the day " << 100-daysLeft << " of your life.\""<<endl;
				cout << "\"You think about going to bed in " << hoursForTheDay << " hours.\"" <<endl;
				cout << "\"You have " << memePoints << " meme points.\""<<endl;
				cout << "\"You have a " << currentMulti << "x multiplier.\""<<endl;
				cout << "\"You have currently " << blingBlingDolla << "$ on hand.\""<<endl;
				cout << "\"You also have " << temFlakes << " boxes of temmie flakes and " << temWater << " bottles of tem water.\""<<endl;
				cout << "\"You have checked this page " << totalStatChecks << " times.\""<<endl;
				cout << "\"You have a coding level of " << codingLevel << " and the EXP of " << totalEXP<< "." << endl;
				totalStatChecks++;
				cout << endl << "The page dumped everything it knew about you, the tree buttons are still there."<<endl;
			break;
			case '2':
				cout << endl << "A box flashes before your eyes;" << endl;
				cout << "\"THIS WILL OVERWRITE A FILE FROM THE ORIGINATING DIRECTORY NAMED \"save\".\"" <<endl;
				cout << "\"IF IT EXISTS, MOVE THE FILE OUT OF THIS DIRECTORY AND PRESS ANY KEY TO CONTINUE...\""<<endl;
				getch();
				if (access("save", F_OK) == 0) {
					while (access("save", W_OK) == -1) {
						cout << "This file doesn't have write access enabled." << endl;
						cout << "Please enable write permissions to \"save\" and press any key to try again." << endl;
						getch();
					}
					while ((gems = fopen("save", "w")) == NULL) { // they'll always save the day
						cout << "Unknown error." << endl; // and if you think they can't
						cout << "Press any key to try again." << endl; // they'll always find a way
						getch();
					}
				} else {
					while ((gems = fopen("save", "w")) == NULL) { // they'll always save the day
						cout << "The game has read-only permissions or there was an unknown error." << endl; // and if you think they can't
						cout << "Make sure the game doesn't have read-only permissions and press any key to try again." << endl; // they'll always find a way
						getch();
					}
				}
				fprintf(gems, "%d\n%d\n%.2f\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%.2f\n%.1f\n%s", hoursForTheDay, daysLeft, currentMulti, memePoints, blingBlingDolla, temFlakes, temWater, fullness, hydration, totalStatChecks, codingLevel, totalEXP, bookReadTime[1], bookReadTime[2], bookReadTime[3], bookReadTime[4], bookReadTime[5], bookReadTime[6], bookReadTime[7], books[1], books[2], books[3], books[4], books[5], books[6], books[7], games[1], games[2], games[3], games[4], games[5], games[6], games[7], games[8], games[9], games[10], currentHotGame, cashBank, rateMe, name);
				fclose(gems);
				cout << endl << "\"What was this werid box?\", you wonder." <<endl;
				cout << "Another one pops up: \"GAME SAVED!\"." <<endl;
				cout << "\"Man, I need to go to sleep earlier next time.\""<<endl;
				cout << "The three buttons are still there."<<endl;
			break;
			case '3':
				cout << endl << "\"The next thing I know, this website is going to give me my adress.\", you mumble to yourself."<<endl;
				cout << "You click the leave button, somehow it closing the browser."<<endl;
				return 0;
			break;
			default:
				goto theHell;
			break;
		}
	}
}

int goToWork() {
	if ((codingLevel == 0) || (codingLevel == 1 && bookReadTime[1] > 0)) {
		cout << endl << "You coded a piss-poor Flash object for a Elsa game."<<endl;
		cout << "You looked down at the object and said \"It is piss-poor.\""<<endl;
		blingBlingDolla += 5;
		cout << "You got a few quick bucks from some company (+5$, now " << blingBlingDolla << "$)."<<endl;
		skillTreeCheck(0);
		cout << 0 << " " << codingLevel << " " << totalEXP << endl;
	} else if ((codingLevel == 1 && bookReadTime[1] == 0) || (codingLevel == 2 && bookReadTime[2] > 0)) {
		cout << endl << "You helped someone design a site."<<endl;
		cout << "It is piss-poor, too."<<endl;
		blingBlingDolla += 10;
		cout << "Another quick buck from ShitPages (+10$, now " << blingBlingDolla << "$)."<<endl;
		skillTreeCheck(1);
	} else if ((codingLevel == 2 && bookReadTime[2] == 0) || (codingLevel == 3 && bookReadTime[3] > 0)) {
		cout << endl << "You designed a site."<<endl;
		cout << "Guess the quality? Piss-poor."<<endl;
		blingBlingDolla += 15;
		cout << "ShitPages ain't shit (+15$, now " << blingBlingDolla << "$)."<<endl;
		skillTreeCheck(2);
	} else if ((codingLevel == 3 && bookReadTime[3] == 0) || (codingLevel == 4 && bookReadTime[4] > 0)) {
		cout << endl << "You scripted a site with some jazzy interactive stuff."<<endl;
		cout << "\"It doesn't sound that piss-poor now...\""<<endl;
		blingBlingDolla += 20;
		cout << "Forever and ever and ever ShitPages (+20$, now " << blingBlingDolla << "$)..."<<endl;
		skillTreeCheck(3);
	} else if ((codingLevel == 4 && bookReadTime[4] == 0) || (codingLevel == 5 && bookReadTime[5] > 0)) {
		cout << endl << "You helped someone design a backend for a site login."<<endl;
		cout << "Piss-poor..."<<endl;
		blingBlingDolla += 25;
		cout << "PHP is a nightmare (+25$, now " << blingBlingDolla << "$)."<<endl;
		skillTreeCheck(4);
	} else if ((codingLevel == 5 && bookReadTime[5] == 0) || (codingLevel == 6 && bookReadTime[6] > 0)) {
		cout << endl << "You are coding some Java apps to appease your boss..."<<endl;
		cout << "Sadly, they are the first code of yours that isn't piss-poor. :("<<endl;
		blingBlingDolla += 30;
		cout << "He even gave you cash for them (+30$, now " << blingBlingDolla << "$)."<<endl;
		skillTreeCheck(5);
	} else if ((codingLevel == 6 && bookReadTime[6] == 0) || (codingLevel == 7 && bookReadTime[7] > 0)) {
		cout << endl << "Some guy argues with you on a co-op programming project video-conference about the type of main()."<<endl;
		cout << "You tell a long story about how C didn't have a void type back in the ages..."<<endl;
		cout << "Everyone, even the guy that argued with you, fell asleep on their keyboards."<<endl;
		blingBlingDolla += 40;
		cout << "Cash from MacroHard (+40$, now " << blingBlingDolla << "$)!"<<endl;
		skillTreeCheck(6);
	} else if (codingLevel == 7 && bookReadTime[7] == 0) {
		cout << endl << "You carefully code a new basic I/O function."<<endl;
		cout << "HaltAndCatchFire();"<<endl;
		blingBlingDolla += 50;
		cout << "More cash from MacroHard (+50$, now " << blingBlingDolla << "$)!"<<endl;
	}
}

int gameMeme() {
	if (games[currentHotGame]) {
		memePoints += floor(1*currentMulti);
		currentMulti += 0.2;
		hoursForTheDay -= 1;
		fullness -= 10;
		hydration -= 10;
		checkForFullnessAndHydration();
		cout << endl << "\"yo dudes, I pwn'd some n00bs\"" << endl;
		cout << "\"awsum, m8!\"" << endl;
		cout << "Everyone bows down to your skillz, oh m1gh7y l0rd." << endl;
		cout << "You have now " << memePoints << " memepoints."<<endl;
		cout << "Your multiplier is now " << currentMulti << "."<<endl;
		cout << "You'll go to bed in " << hoursForTheDay << " hours."<<endl;
	} else {
		cout << endl << "\"lolz m8, you still pwning n00bs at that crap game?\"" << endl;
		cout << "\"dude, you might wanna check out ";
		switch (currentHotGame) {
			case 1:
				cout << "Call of Pepe V";
			break;
			case 2:
				cout << "Unmemed 5: Memes Uncultured";
			break;
			case 3:
				cout << "Meme Funeral";
			break;
			case 4:
				cout << "Holla' 3";
			break;
			case 5:
				cout << "The Memes Unleashed 2";
			break;
			case 6:
				cout << "Battlememe 9001";
			break;
			case 7:
				cout << "Harambe Simulator";
			break;
			case 8:
				cout << "Memeza 3: Pepeizon";
			break;
			case 9:
				cout << "Hotline Memeami";
			break;
			case 10:
				cout << "Counterdank: Global Meme";
			break;
		}
		cout << ", that's what all the cool kidz play\"" << endl;
		cout << "(You can buy games in the Tem Shop.)" << endl;
	}
	return 0;
}

int bankSucks(unsigned int theHeat, bool isDeposit) {
	switch (theHeat) {
		case 1:
		case 2:
		case 3:
			cout << endl << "You feel like an idiot for inputting letters or trying to ";
			if (isDeposit) {
				cout << "steal ";
			} else {
				cout << "deposit ";
			}
			cout << "money." << endl;
			cout << "What were you thinking?" <<endl;
		break;
		
		case 4:
			cout << endl << "You are an idiot, hahahaha!" <<endl;
			cout << "I feel like I'm going insane." <<endl;
		break;
		
		case 5:
			cout << endl << "Do you need any pointers?" << endl;
			printf("%p, %p, %p.\n", (void *) &blingBlingDolla, (void *) &memePoints, (void *) &daysLeft);
		break;
		
		case 6:
			cout << endl << "Man, I've given you the pointers, what else do you want?" << endl;
			cout << "You could whip out Cheat Engine, search and just change your money or something..."<< endl;
			cout << "Guess you aren't the sharpest tool in the shed." << endl;
		break;
		
		case 7:
			cout << endl << "Man, from the start of coding this game, I've been wondering:" <<endl;
			cout << "\"What would it be like to print an... unterminated string?\"" << endl;
			cout << "Wouldn't be a great idea, wouldn't it?" << endl;
			cout << "Don't try this again, or else..." << endl;
		break;
		
		case 8:
			memset(&name[0], ' ', sizeof(name));
			cout << endl << "Your name, I mean, worst nightmare is... ";
			puts(name);
			puts("\n");
		break;
	}
	return 0;
}

int banKING() {
	unsigned int angerLevel = 0;
	cout << endl << "\"fboa.com\""<<endl;
	cout << "You see the First Bank of America banner and proceed to log in." <<endl;
	cout << "After typing your password for what feels like the millionth time, you got in."<<endl;
	while (hoursForTheDay != 0) {
		cout << endl << "What do you want to do?" <<endl;
		cout << "1. Check checking account." << endl;
		printf("2. Deposit money (at day rate of %.10g%%).\n", rateMe);
		cout << "3. Withdraw money." <<endl;
		cout << "4. H4x0r t3h b4nk." <<endl;
		cout << "5. Log out."<<endl;
daBank: switch (getch()) {
			case '1':
				cout << endl << "\"Current funds in the bank: " << cashBank << ".\"" << endl;
			break;
			case '2':
				do {
			chance3:cout << endl << "How much money do you want to deposit (to 2 decimal places, will round down if more)?"<<endl;
					valReturn = scanf("%lf", &tranCash);
					tranCash = floorf(tranCash * 100) / 100;
					extraBool = !valReturn;
					fflush(stdin);
					if (valReturn != 1 || tranCash < 0) {
						angerLevel++;
						bankSucks(angerLevel, true);
						goto chance3;
					} 
				} while (extraBool);
				if (blingBlingDolla < tranCash) {
					cout << "You don't have enough cash dude."<<endl;
					cout << "You'll need " << tranCash-blingBlingDolla << "$ more... so close."<<endl;
				} else {
					blingBlingDolla -= tranCash;
					cashBank += tranCash;
					cout << "\"Funds transferred.\""<<endl;
					cout << "You feel like the computer has sucked the money out of your wallet." <<endl;
					cout << "You now have " << cashBank << "$ and " << blingBlingDolla << "$ on hand." <<endl;
				}
			break;
			case '3':
				do {
			chance4:cout << endl << "How much money do you want to withdraw (to 2 decimal places, will round down if more)?"<<endl;
					valReturn = scanf("%lf", &tranCash);
					tranCash = floorf(tranCash * 100) / 100;
					extraBool = !valReturn;
					fflush(stdin);
					if (valReturn != 1 || tranCash < 0) {
						angerLevel++;
						bankSucks(angerLevel, false);
						goto chance4;
					} 
				} while (extraBool);
				if (blingBlingDolla < tranCash) {
					cout << "You don't have enough cash in the bank dude."<<endl;
					cout << "You'll need " << tranCash-cashBank << "$ more... so close."<<endl;
				} else {
					blingBlingDolla += tranCash;
					cashBank -= tranCash;
					cout << "\"Funds transferred.\""<<endl;
					cout << "You feel like the computer has sucked the money into your wallet." <<endl;
					cout << "You now have " << cashBank << "$ and " << blingBlingDolla << "$ on hand." <<endl;
				}
			break;
			case '4':
				cout << endl << "You sure wanna do this?" << endl;
				cout << "Say I didn't warn ya, but bank hacks have a 1/10000 chance of going the right way." <<endl;
				cout << "Yes or no (Y/N)?" << endl;
				lp1:switch (getch()) {
					case 'Y':
					case 'y':
						if (random(1, 10000) == 1337) {
							cout << "y00... g0t in" << endl;
							PlaySound(TEXT("y00.wav"), NULL, SND_FILENAME);
							cout << "Surprisingly, you did it." << endl;
							cout << "...check your checking account." << endl;
							cashBank += 1000000;
						} else {
							cout << endl << "\"Doin' the crime, doin' the time... hacker scum.\"" << endl << endl;
							PlaySound(TEXT("crime.wav"), NULL, SND_FILENAME);
							cout << "You got arrested for hacking for a lifetime because FBOA got a good prosecutor going." << endl;
							cout << "It's over now, isn't it?" << endl;
							cout << "GAME OVER. You rotted like dirty hacker scum you are." << endl;
							cout << "(You had... you know what? I'm not going to even tell you your memepoints. This is laughable.)" << endl;
							cout << "(Any key to quit.)" << endl;
							getch();
							exit(0);
						}
					break;
					
					case 'N':
					case 'n':
						cout << "Good choice, really." << endl;
					break;
					
					default:
						goto lp1;
					break;
				}
			break;
			case '5':
				cout << endl << "You logged out of the FBOA." << endl;
				return 0;
			break;
			default:
				goto daBank;
			break;
		}
	}
}

int useComputer() {
	while (hoursForTheDay != 0) {
		cout << endl << "What would you like to do?" <<endl;
		cout << "1. Meme about current events."<<endl;
		cout << "2. Pwn some n00bs in some cool game."<<endl;
		cout << "3. Code something for money."<<endl;
		cout << "4. Check out the bank." <<endl;
		cout << "5. Check the StatBoard(TM)."<<endl;
		cout << "6. Turn off the computer."<<endl;
backOn: switch (getch()) {
			case '1':
				memePoints += floor(1*currentMulti);
				currentMulti += 0.1;
				hoursForTheDay -= 1;
				fullness -= 10;
				hydration -= 10;
				checkForFullnessAndHydration();
				cout << endl << "You meme'd them hard, boyo! Here comes dat boi!"<<endl;
				cout << "You have now " << memePoints << " memepoints."<<endl;
				cout << "Your multiplier is now " << currentMulti << "."<<endl;
				cout << "You'll go to bed in " << hoursForTheDay << " hours."<<endl;
			break;
			case '2':
				gameMeme();
			case '3':
				fullness -= 10;
				hydration -= 10;
				checkForFullnessAndHydration();
				goToWork();
				hoursForTheDay -= 1;
				cout << "You'll go to bed in " << hoursForTheDay << " hours."<<endl;
			break;
			case '4':
				banKING();
			break;
			case '5':
				statBoard();
			break;
			case '6':
				cout << endl << "You decided to take a break and turn off the computer." <<endl<<endl;
				return 0;
			break;
			default:
				goto backOn;
			break;
		}
	}
}

int buyHelper (float price, int index, bool whatIWant) {
lp1:switch (getch()) {
		case 'Y':
		case 'y':
			if (blingBlingDolla < price) {
				cout << "(You look deep into your pockets but unfortunately don't find the money to purchase this ";
				if (whatIWant) {cout << "book";}
				else {cout << "game";}
				cout << ".)"<<endl;
				cout << "You'll need " << price-blingBlingDolla << "$ more to buy this ";
				if (whatIWant) {cout << "book";}
				else {cout << "game";}
				cout << ", seeing as you currently have " << blingBlingDolla << "$."<<endl;
			} else {
				blingBlingDolla -= price;
				if (whatIWant) {
					books[index] = 1;
				} else {
					games[index] = 1;
				}
				cout << "(You give all the money needed to Tem, wondering what he's gathering funds for next.)"<<endl;
				cout << "Thanks for purchasing!"<<endl;
			}
		break;
		
		case 'N':
		case 'n':
			cout << "Well, tell me if you'll need it." << endl;
		break;
		
		default:
			goto lp1;
		break;
	}
}

int checkBooks() {
	if (codingLevel < 1) {
		cout << endl << "You don't find any of the books interesting." << endl;
		cout << "They're mostly books about tem history." << endl;
	} else if (codingLevel == 1 && books[1] == 0) {
		cout << endl << "You see a book that'd help you learn HTML." << endl;
		cout << "Luck is on your side, because the book isn't in tem language." << endl;
		cout << "\"How much would this cost, Tem?\"" << endl;
		cout << "\"Honestly, this one was packed in a \"2 for the price of 1\" deal.\"" << endl;
		cout << "\"The cheap bastard didn't tell me this one's in human language, which tem won't buy.\"" << endl;
		cout << "\"Since the 2 costed 15$, guess you can get this one for 10$.\"" << endl;
		cout << "Do you want the book (Y/N)?" << endl;
		buyHelper(10, 1, true);
	} else if (codingLevel == 2 && books[2] == 0) {
		cout << endl << "CSS book." << endl;
		cout << "Just in the nick of time." << endl;
		cout << "\"This CSS book, Tem.\"" << endl;
		cout << "\"This one's also from that deal.\"" << endl;
		cout << "\"You know, I also have this JS book if you want.\"" << endl;
		cout << "\"I'll buy just this one for now.\""<<endl;
		cout << "\"Yet again, since the 2 costed 15$, guess you can get this one for 10$.\"" << endl;
		cout << "Do you want the book (Y/N)?" << endl;
		buyHelper(10, 2, true);
	} else if (codingLevel == 3 && books[3] == 0) {
		cout << endl << "You find that JS book Tem was talking about." << endl;
		cout << "You give the book to the Tem at the counter." << endl;
		cout << "\"How about this one?\"" << endl;
		cout << "\"Well, this one was a little more expensive deal.\"" << endl;
		cout << "\"2 for 30$, guess you can get this one for 20$.\"" << endl;
		cout << "Do you want the book (Y/N)?" << endl;
		buyHelper(20, 3, true);
	} else if (codingLevel == 4 && books[4] == 0) {
		cout << endl << "You find the PHP book a bit old for some reason." << endl;
		cout << "\"Why is this book old, Tem?\"" << endl;
		cout << "\"Well, the guy who sold me it told me that it was potentially cursed.\"" << endl;
		cout << "\"Would you believe this book passed hands like 10 times?\""<<endl;
		cout << "\"Apparently everyone who had it wanted a refund the day after.\"" << endl;
		cout << "You say: \"Meh dude, it's just PHP.\""<<endl;
		cout << "\"Bought this one for 20$, guess I can sell you for 30$.\"" << endl;
		cout << "Do you want the book (Y/N)?" << endl;
		buyHelper(30, 4, true);
	} else if (codingLevel == 5 && books[5] == 0) {
		cout << endl << "Surprisingly tem title for a Java book: "<<endl;
		cout << "\"Tem Expert Rites 'bout: Cup O' Coffee Language! (Lern In Tem Hours! yAYA!)\"." << endl<<endl;
		cout << "\"Don't you have other books for that?\"" << endl;
		cout << "\"Well, he's the expert dude.\"" << endl;
		cout << "\"But it's 10 hours and twice as long that because it's tem language!\""<<endl;
		cout << "\"He's an expert, dude...\"" << endl;
		cout << "\"Selling for 40$.\"" << endl;
		cout << "Do you want the book (Y/N)?" << endl;
		buyHelper(40, 5, true);
	} else if (codingLevel == 6 && books[6] == 0) {
		cout << endl << "\"Tem Expert Rites 'bout: See++! (Lern In 12 Hours! yAYA!)\"." << endl<<endl;
		cout << "\"Empathy sucks...\"" << endl;
		cout << "\"Just give me the book.\"" << endl;
		cout << "\"50$, please.\"" << endl;
		cout << "Do you want the book (Y/N)?" << endl;
		buyHelper(50, 6, true);
	} else if (codingLevel == 7 && books[7] == 0) {
		cout << endl << "\"Tem Expert Rites 'bout: The 8086 Architemture and Assembler! (Lern In A Day! yAYA!)\"." << endl<<endl;
		cout << "\"I'm right there with you.\"" << endl;
		cout << "He quietly takes out the book." << endl;
		cout << "\"75$.\"" << endl;
		cout << "\"Kinda expensive, but guess I gotta take it.\""<<endl;
		cout << "Do you want the book (Y/N)?" << endl;
		buyHelper(75, 7, true);
	}
	return 0;
}

int checkGames() {
	cout << endl <<  "Which one do you want?" << endl;
	cout << "1. Call of Pepe V" << endl;
	cout << "2. Unmemed 5: Memes Uncultured" << endl;
	cout << "3. Meme Furneral" << endl;
	cout << "4. Holla' 3" << endl;
	cout << "5. The Memes Unleashed 2" << endl;
	cout << "6. Battlememe 9001" << endl;
	cout << "7. Harambe Simulator" << endl;
	cout << "8. Memeza 3: Pepeizon" << endl;
	cout << "9. Hotline Memeami" << endl;
	cout << "0. Counterdank: Global Meme" << endl;
	cout << "N. Nevermind..." << endl;
	switch (getch()) {
		case '1':
			cout << "That'd be 10$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(10, 1, false);
		break;
		case '2':
			cout << "That'd be 19$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(19, 2, false);
		break;
		case '3':
			cout << "That'd be 13$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(13, 3, false);
		break;
		case '4':
			cout << "That'd be 14$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(14, 4, false);
		break;
		case '5':
			cout << "That'd be 11$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(11, 5, false);
		break;
		case '6':
			cout << "That'd be 16$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(16, 6, false);
		break;
		case '7':
			cout << "That'd be 25$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(25, 7, false);
		break;
		case '8':
			cout << "That'd be 20$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(20, 8, false);
		break;
		case '9':
			cout << "That'd be 17$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(17, 9, false);
		break;
		case '0':
			cout << "That'd be 12$." << endl;
			cout << "Do you want the game (Y/N)?" << endl;
			buyHelper(12, 10, false);
		break;
		case 'N':
		case 'n':
			cout << "\"What was I thinking about again?\"" << endl;
		break;
		return 0;
	}
}

int temShop() {
	cout << endl << "hOI!" << endl << "welcom to..." << endl << "da TEM SHOP!!!" <<endl;
	PlaySound(TEXT("temshop.wav"), NULL, SND_FILENAME);
	while (hoursForTheDay != 0) {
		cout << endl << "What would you like?"<<endl;
		cout << "1. Get some tem flakes."<<endl;
		cout << "2. Get some tem water."<<endl;
		cout << "3. Browse books."<<endl;
		cout << "4. Check out some cool games, yo!"<<endl;
		cout << "5. \"Wow, how did you just speak like that?\""<<endl;
		cout << "6. \"That's all, thanks.\""<<endl;
   back:switch (getch()) {
			case '1':
				do {
			chance1:cout << endl << "How many boxes of tem flakes would you like? (1000 max.)"<<endl;
					valReturn = scanf("%4hu", &itemsToBuy);
					extraBool = !valReturn;
					fflush(stdin);
					if (valReturn != 1 || itemsToBuy < 0) {
						cout << "Man, I can't calculate with letters." <<endl;
						cout << "And don't attempt to sell boxes to me!" <<endl;
						goto chance1;
					} 
				} while (extraBool);
				cout << endl << "That'd be " << 5*itemsToBuy << "$." <<endl;
				if (blingBlingDolla < 5*itemsToBuy) {
					cout << "(You look deep into your pockets but unfortunately don't find the money to purchase this many boxes of tem flakes.)"<<endl;
					cout << "You'll need " << 5*itemsToBuy-blingBlingDolla << "$ more to buy these, seeing as you currently have " << blingBlingDolla << "$."<<endl;
				} else {
					blingBlingDolla -= 5*itemsToBuy;
					temFlakes += itemsToBuy;
					cout << "(You give all the money needed to Tem, wondering what he's gathering funds for next.)"<<endl;
					cout << "\"Here you go!\" (You now have " << blingBlingDolla << "$ and " << temFlakes << " boxes.)"<<endl;
				}
			break;
			case '2':
				do {
			chance2:cout << endl << "How many bottles of tem water would you like? (1000 max.)"<<endl;
					valReturn = scanf("%4hu", &itemsToBuy);
					extraBool = !valReturn;
					fflush(stdin);
					if (valReturn != 1 || itemsToBuy < 0) {
						cout << endl << "Man, I can't calculate with letters." <<endl;
						cout << "And don't attempt to sell bottles to me!" <<endl;
						goto chance2;
					} 
				} while (extraBool);
				cout << endl <<"That'd be " << 3*itemsToBuy << "$." <<endl;
				if (blingBlingDolla < 3*itemsToBuy) {
					cout << "(You look deep into your pockets but unfortunately don't find the money to purchase this many tem water bottles.)"<<endl;
					cout << "You'll need " << 3*itemsToBuy-blingBlingDolla << "$ more to buy these, seeing as you currently have " << blingBlingDolla << "$."<<endl;
				} else {
					blingBlingDolla -= 3*itemsToBuy;
					temWater += itemsToBuy;
					cout << "(You give all the money needed to Tem, wondering what he's gathering funds for next.)"<<endl;
					cout << "\"Here you go!\" (You now have " << blingBlingDolla << "$ and " << temWater << " bottles.)" <<endl;
				}
			break;
			case '3':
				checkBooks();
			break;
			case '4':
				checkGames();
			break;
			case '5':
				cout << endl << "Is this a joke?" << endl << "Are you having a chuckle?" << endl << "Ha ha, very funny." << endl << "I'm the one with a degree."<<endl;
				PlaySound(TEXT("degree.wav"), NULL, SND_FILENAME);
			break;
			case '6':
				cout << endl << "Thanks for visiting the Tem Shop!"<<endl<<endl;
				return(0);
			break;
			default:
				goto back;
			break;
		}
	}
}

int goToTheFridge() {
	while (hoursForTheDay != 0) {
		cout << endl << "You walk into the kitchen, checking in on something you'd like to eat."<<endl;
		cout << "Anyways, what would you like to eat?" <<endl;
		cout << "1. Eat some tem flakes. (You have " << temFlakes << " boxes.)"<<endl;
		cout << "2. Drink some tem water. (You have " << temWater << " bottles.)"<<endl;
		cout << "3. Nevermind."<<endl;
noTLeft:switch (getch()) {
			case '1':
				if (temFlakes > 0) {
					temFlakes--;
					fullness = 100;
					cout << endl << "You ate the box of tem flakes. Without opening it."<<endl;
					cout << "You feel full, your hunger has been fully replenished."<< endl <<endl;
				} else {
					cout << endl << "Sadly, you don't have any tem flakes." << endl << ":(" << endl <<endl;
				}
				return 0;
			break;
			case '2':
				if (temWater > 0) {
					temWater--;
					hydration += 20;
					if (hydration > 100) hydration = 100;
					cout << endl << "You drank the water from the bottle and threw the bottle out the window."<<endl;
					cout << "You partially quenched yourself. (Current hydration: " << hydration << ".)" << endl <<endl;
				} else {
					cout << endl << "Sadly, you don't have any tem water." << endl << ":(" << endl <<endl;
				}
				return 0;
			break;
			case '3':
				cout << endl;
				return 0;
			break;
			default:
				goto noTLeft;
			break;
		}
	}
}

int bookcase() {
	if (codingLevel < 1) {
		cout << endl << "You don't find any of the books interesting." << endl;
		cout << "They're mostly books about tem history." << endl << endl;
	} else if (codingLevel > 6) {
		cout << "You know all the shit from these dumb books!" << endl;
		cout << "Go meme instead!" << endl;
	} else if (books[codingLevel] == 1) {
		if (bookReadTime[codingLevel] != 0) {
			cout << endl<< "Read the book about ";
			switch (codingLevel) {
				case 1:
					cout << "HTML";
				break;
				case 2:
					cout << "CSS";
				break;
				case 3:
					cout << "JS";
				break;
				case 4:
					cout << "PHP";
				break;
				case 5:
					cout << "Java";
				break;
				case 6:
					cout << "C++";
				break;
				case 7:
					cout << "Assembler";
				break;
			}
			cout << " for one hour (Y/N)?" << endl;
sneakyLike: switch (getch()) {
				case 'Y':
				case 'y':
					bookReadTime[codingLevel]--;
					if (bookReadTime[codingLevel] != 0) {
						cout << "You need to put " << bookReadTime[codingLevel] << " more hour";
						if (bookReadTime[codingLevel] != 1) {
							cout << "s";
						}
						cout << " into this book."<<endl << endl;
					}
					fullness -= 10;
					hydration -= 10;
					checkForFullnessAndHydration();
					hoursForTheDay--;
				break;
				
				case 'N':
				case 'n':
					cout << "Well, tell me if you'll need it." << endl;
				break;
				
				default:
					goto sneakyLike;
				break;
			}
		} else {
			cout << "You don't need to read any books, that last book bores you anyway."<<endl;
		}
	} else {
		cout << codingLevel << " " << books[codingLevel] << endl;
		cout << "You don't seem to own the current book for your language."<<endl;
		cout << "Pick one up from the Tem Shop!"<<endl;
	}
	return 0;
}

int justInCase() {
	cout << endl << "You might want to save before quitting." << endl;
	cout << "Do you want to do just that (Y/N)?" << endl;
jic:switch (getch()) {
		case 'Y':
		case 'y':
			if (access("save", F_OK) == 0) {
				while (access("save", W_OK) == -1) {
					cout << "This file doesn't have write access enabled." << endl;
					cout << "Please enable write permissions to \"save\" and press any key to try again." << endl;
					getch();
				}
				while ((gems = fopen("save", "w")) == NULL) { // they'll always save the day
					cout << "Unknown error." << endl; // and if you think they can't
					cout << "Press any key to try again." << endl; // they'll always find a way
					getch();
				}
			} else {
				while ((gems = fopen("save", "w")) == NULL) { // they'll always save the day
					cout << "The game has read-only permissions or there was an unknown error." << endl; // and if you think they can't
					cout << "Make sure the game doesn't have read-only permissions and press any key to try again." << endl; // they'll always find a way
					getch();
				}
			}
			fprintf(gems, "%d\n%d\n%.2f\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%.2f\n%.1f\n%s", hoursForTheDay, daysLeft, currentMulti, memePoints, blingBlingDolla, temFlakes, temWater, fullness, hydration, totalStatChecks, codingLevel, totalEXP, bookReadTime[1], bookReadTime[2], bookReadTime[3], bookReadTime[4], bookReadTime[5], bookReadTime[6], bookReadTime[7], books[1], books[2], books[3], books[4], books[5], books[6], books[7], games[1], games[2], games[3], games[4], games[5], games[6], games[7], games[8], games[9], games[10], currentHotGame, cashBank, rateMe, name);
			fclose(gems);
			cout << "Saved for you, bye!" << endl;
			sleep(1);
			exit(0);
		break;
			
		case 'N':
		case 'n':
			cout << "Okay, bye!" << endl;
			sleep(1);
			exit(0);
		break;
		
		default:
			goto jic;
		break;
	}
}

int theDailyGrind() {
	while (hoursForTheDay != 0) {
		cout << "What would you like to do?" <<endl;
		cout << "1. Turn on the computer."<<endl;
		cout << "2. Read a book from the bookcase."<<endl;
		cout << "3. Pick something up from the kitchen."<<endl;
		cout << "4. #ShoppingSpree"<<endl;
		cout << "5. \"kys n00b\"."<<endl;
		cout << "6. Exit."<<endl;
mainLoo:switch (getch()) {
			case '1':
				useComputer();
			break;
			case '2':
				bookcase();
			break;
			case '3':
				goToTheFridge();
			break;
			case '4':
				temShop();
			break;
			case '5':
				deathMode = 1; // you died like a pussy
				fadedAway();
			break; // just in case you're Chuck Norris
			case '6':
				justInCase();
			default:
				goto mainLoo;
			break;
		}
	}
	cout << endl << "You went to bed to get a good ol' night's sleep..." << endl;
	cout << "(Days left: " << daysLeft << ")." << endl <<endl;
}

int gameCheck() {
	if (!loaded) {
		cashBank = cashBank * rateMe / 100;
		cashBank = floorf(cashBank * 100) / 100;
		if (random(0,1) == 0) {
			rateMe -= random(1,10) / 10;
			if (rateMe < 1) rateMe = 1;
		} else {
			rateMe += random(1,10) / 10;
			if (rateMe > 5) rateMe = 5;
		}
	}
	if ((daysLeft == 99 ||  (daysLeft+1)%7 == 0) && !loaded) {
		currentHotGame = random(1,10);
	}
	loaded = false;
}

int runEasterEgg() {
	cout << endl << "Name the fallen human:";
	
	fgets(name, sizeof(name), stdin);
	fflush(stdin);
	name[strcspn(name, "\n")] = 0;
	
	unsigned long long youMightTryToSaveMe = 0;
	bool beingAGoodPacifist = true;
	
	cout << "You encounter a monster!\nType S to try sparing it or K to kill it!" << endl;
	while (beingAGoodPacifist){
		switch(getch()){
			case 'S':
			case 's':
				youMightTryToSaveMe++;
				cout << "You were killed " << youMightTryToSaveMe << " times!\nStay determined " << name << "!\nType S to try sparing it again or K to kill it out of frustration!" << endl;
			break;
			case 'K':
			case 'k':
				beingAGoodPacifist = false;
				cout << endl << "What do you think you've done?" << endl;
			break;
			default:
				cout << "Please retype your message!" << endl;
			break;
		}
	}
	
	cout << endl << "The end." << endl;
	cout << "Sit in the corner and think about what you've done." << endl;
	cout << endl << "Achievement Unlocked: What A Assbag!" << endl;
	cout << "Guess you're getting away with this this time." << endl;
	cout << "TODO: Make a pernament achievement system." << endl;
	cout << "For now... press any key to quit." << endl;
	getch();
	exit(0);
}

int main() {
	if (access("save", F_OK) != -1) {
		cout << "Do you want to continue playing from the point you've saved (Y/N)? " << endl;
mane:   switch (getch()) {
			case 'Y':
			case 'y':
				if (load() == 0) {
					goto itscheating;
				} else {
					goto fck;
				}
			break;
				
			case 'N':
			case 'n':
			break;
			
			default:
				goto mane;
			break;
		}
	}
fck:cout << "Pick yourself a name, fella. " << endl;
	fgets(name, sizeof(name), stdin);
	fflush(stdin);
	name[strcspn(name, "\n")] = 0;
	
	if (strcmp("Determined", name) == 0) runEasterEgg();
	
	hoursForTheDay = 12;
	daysLeft = 99;
	currentMulti = 1;
	memePoints = 0;
	totalStatChecks = 0;
	fullness = 100;
	hydration = 100;
	
	itscheating: cout << endl << "Your name is: " << name <<  "."<<endl;
	while (daysLeft != 0) {
	gameCheck();
	theDailyGrind();
	daysLeft--;
	hoursForTheDay = 12;
	}
	deathMode = 0; // you died like a man
	chuckNorris();
}
