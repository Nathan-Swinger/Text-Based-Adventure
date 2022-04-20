      #include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int currentCity, monster, monsterHpInt, monsterArmorInt, monsterDamageInt, monsterGoldInt, fightOption, inventoryChoice, shopChoice, quantity;
string monsterNameString, cityDisplayName;
bool inArena = false;
int playerDamage = 3;
int playerHealth = 50;


//Prototype functions for game choices
int travelToCity(int);
void visitLocalShop(string);
void talkToLocals();
int travelFunction();
int monsterSpawn();
void combatFunction(int);
void displayInventory();
void enterArena();

struct monsters
{
    string monsterName;
    int hp, armor, damage, gold;
};

struct inventory
{
    string weapon, helmet, chestplate, boots;
    int healthPotions, bombs, gold, armor;
};

inventory playerInventory = {"Fists", "None", "None", "None", 0, 0, 0, 0};

monsters monst_array[10] = {{"Bug", 10, 0, 1, 2}, // bug
                            {"Fire Spitting Lizard", 5, 0, 3, 4}, // fireSpittingLizard
                            {"Wolf", 15, 0, 2, 5}, // Wolf
                            {"Cursed Pigeon", 4, 0, 2, 1}, // CursedPigeon
                            {"Mountain Lion", 10, 0, 5, 7}, // mountainLion
                            {"Demonic Turtle", 10, 2, 1, 5}, // demonicTurtle
                            {"Angry Cow", 12, 1, 2, 3}, // angryCow
                            {"Exiled Monk", 10, 3, 3, 5}, // exiledMonk
                            {"Spirit", 4, 0, 1, 2}, // spirit
                            {"Vampire", 5, 0, 3, 4}}; // vampire

//main function and driver of the code
int main()
{
    //Code for the start of the game and initializing variables
    srand((unsigned int)time(NULL));
    string firstchoice;
    int choice, currentCity;
    cout << "Welcome to the world of Azeroth!" << endl << endl;
    cout << "You awaken in a cold sweat. After looking around for a while, you realize you're in a a dark and ran down tavern in Atorioth." << endl << endl;
    while(firstchoice != "2")
    {
        cout << "1. Talk to the tavern keeper." << endl;
        cout << "2. Leave the tavern." << endl;
        cout << "\nWhat will you do? ";
        cin >> firstchoice;
        if(firstchoice == "1")
        {
            cout << "\nThe tavern keeper gives you a smug look and says 'Either pay your rent for another night, or get out!" << endl << endl;
        }
        else
        {
            cout << "\nYou leave the tavern and step out into the wondrous world of Azeroth!" << endl;
        }
    }
    cout << "You get the feeling you should travel to a city first!" << endl;
    travelToCity(currentCity);
    //Code for the main game
    while(playerHealth > 0)
    {
        cout << "\nYou begin to ponder what you should do next..." << endl << endl;
        cout << "1. Travel to a city." << endl;
        cout << "2. Visit the local shop." << endl;
        cout << "3. Talk to the locals." << endl;
        cout << "4. Inventory." << endl;
        cout << "5. Enter the grand arena of " << cityDisplayName << endl;
        cout << "What will you do? ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                travelToCity(currentCity);
                break;
            case 2:
                visitLocalShop(cityDisplayName);
                break;
            case 3:
                talkToLocals();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                enterArena();
                break;

        }
    }
}

int travelToCity(int)
{
    int destination;
    cout << "\n1. Darnassus" << endl;
    cout << "2. Corinthia" << endl;
    cout << "3. Torbold" << endl;
    cout << "4. Mortsworth" << endl;
    cout << "\nWhich city do you want to travel to? ";
    cin >> destination;
    if(destination != currentCity)
    {
        currentCity = destination;
        cout << "\nTraveling to city..." << endl;
        travelFunction();
        switch(currentCity)
        {
        case 1:
            cityDisplayName = "Darnassus";
            break;
        case 2:
            cityDisplayName = "Corinthia";
            break;
        case 3:
            cityDisplayName = "Torbold";
            break;
        case 4:
            cityDisplayName = "Mortsworth";
            break;
        }
    if(playerHealth > 0 && destination != currentCity)
    cout << "\nYou arrived in " << cityDisplayName << "!";
    }
    else if(playerHealth > 0 && destination == currentCity)
    {
        cout << "\nYou're already in that city!" << endl;
    }

}

int travelFunction()
{
    cout << "\nWhile traveling you come across an enemy!" << endl;
    monsterSpawn();
    combatFunction(monster);
}

int monsterSpawn()
{
    int v1 = rand() % 10;
    switch(v1)
    {
    case 0:
        monster = 1; // 1 = bug
        return monster;
        break;
    case 1:
        monster = 2; // 2 = Fire Spitting Lizard
        return monster;
        break;
    case 2:
        monster = 3; // 3 = Wolf
        return monster;
        break;
    case 3:
        monster = 4; // 4 = Cursed Pigeon
        return monster;
        break;
    case 4:
        monster = 5; // 5 = Mountain Lion
        return monster;
        break;
    case 5:
        monster = 6; // 6 = Demonic Turtle
        return monster;
        break;
    case 6:
        monster = 7; // 7 = Angry Cow
        return monster;
        break;
    case 7:
        monster = 8; // 8 = Exiled Monk
        return monster;
        break;
    case 8:
        monster = 9; // 9 = Spirit
        return monster;
        break;
    case 9:
        monster = 10; // 10 = Vampire
        return monster;
        break;
    }

}

void combatFunction(int)
{
    for(int i = 0; i != monster; i++)
    {
        monsterHpInt = monst_array[i].hp;
        monsterNameString = monst_array[i].monsterName;
        monsterArmorInt = monst_array[i].armor;
        monsterDamageInt = monst_array[i].damage;
        monsterGoldInt = monst_array[i].gold;
    }
    cout << "\nYou encountered a(n) " << monsterNameString << endl;
    cout << monsterNameString << " HP: " << monsterHpInt << " Armor: " << monsterArmorInt << " Damage: " << monsterDamageInt << " Gold: " << monsterGoldInt << endl;
    while(monsterHpInt > 0 && playerHealth > 0)
    {
        cout << "\n1. Attack" << endl;
        cout << "2. Strong Attack" << endl;
        cout << "3. Items" << endl;
        cout << "4. Flee" << endl;
        cout << "Choose an option: ";
        cin >> fightOption;
        switch(fightOption)
        {
        case 1:
            cout << "You did " << playerDamage - monsterArmorInt << " damage!" << endl;
            monsterHpInt -= (playerDamage - monsterArmorInt);
            cout << "Remaining monster HP: " << monsterHpInt << endl;
            cout << "You took " << monsterDamageInt - playerInventory.armor << " damage!" << endl;
            playerHealth -= (monsterDamageInt - playerInventory.armor);
            cout << "Remaining HP: " << playerHealth << endl;
            break;
        case 2:
            if((rand() % 2) + 1 == 2)
            {
                cout << "Critical Hit!" << endl;
                cout << "You did " << (playerDamage * 2) - monsterArmorInt << " damage!" << endl;
                monsterHpInt -= ((playerDamage * 2) - monsterArmorInt);
                cout << "Remaining monster HP: " << monsterHpInt << endl;
                cout << "You took " << monsterDamageInt - playerInventory.armor << " damage!" << endl;
                playerHealth -= (monsterDamageInt - playerInventory.armor);
                cout << "Remaining HP: " << playerHealth << endl;
            }
            else
            {
                cout << "You missed!" << endl;
                cout << "Remaining monster HP: " << monsterHpInt << endl;
                cout << "You took " << monsterDamageInt << " damage!" << endl;
                playerHealth -= monsterDamageInt;
                cout << "Remaining HP: " << playerHealth << endl;

            }
            break;
        case 3:
            cout << "\n__________" << endl;
            cout << "Inventory" << endl;
            cout << "__________" << endl;
            cout << "Gold: " << playerInventory.gold << endl;
            cout << "Weapon: " << playerInventory.weapon << endl;
            cout << "Armor: " << playerInventory.armor << endl;
            cout << "Helmet: " << playerInventory.helmet << endl;
            cout << "Chestplate: " << playerInventory.chestplate << endl;
            cout << "Boots: " << playerInventory.boots << endl;
            cout << "1. Health Potions [" << playerInventory.healthPotions << "]" << endl;
            cout << "2. Bombs [" << playerInventory.bombs << "]" << endl;
            cout << "Enter your choice:";
            cin >> inventoryChoice;
            if(inventoryChoice == 1)
            {
                if(playerInventory.healthPotions > 0)
                {
                    cout << "Potion healed you for 10 HP!" << endl;
                    playerHealth += 10;
                    if(playerHealth > 50)
                    {
                        playerHealth = 50;
                    }
                }
                else
                {
                    cout << "You don't have any potions!" << endl;
                }
            }
            else if(inventoryChoice == 2)
            {
                if(playerInventory.bombs > 0)
                {
                    cout << "You did 20 damage!" << endl;
                    monsterHpInt -= 20;
                }
                else
                {
                    cout << "\n You don't have any bombs!" << endl;
                }
            }
            break;
        case 4:
            if(inArena == false)
            {
                cout << "You ran away! (pussy!)" << endl;
            }
            else if (inArena == true)
            {
                cout << "You can't run away in the arena!" << endl;
            }
            break;
        }

    }
    if(fightOption != 4)
    {
        cout << "\n You killed " << monsterNameString << "!" << endl;
        cout << "You gained " << monsterGoldInt << " gold!" << endl;
        playerInventory.gold += monsterGoldInt;
    }
}
void visitLocalShop(string)
{
    cout << "Visiting the " << cityDisplayName << " shop!" << endl;
    while(shopChoice != 7)
    {
        cout << "1. Health Potions [20 gold]" << endl;
        cout << "2. Bomb [20 gold]" << endl;
        cout << "3. Sword [30 gold]" << endl;
        cout << "4. Chestplate [30 gold]" << endl;
        cout << "5. Boots [15 gold]" << endl;
        cout << "6. Helmet [20 gold]" << endl;
        cout << "7. Leave shop" << endl;
        cout << "Enter your choice: ";
        cin >> shopChoice;
        switch(shopChoice)
        {
        case 1:
            if(playerInventory.gold < 20)
            {
                cout << "\nYou cannot afford that!" << endl;
            }
            else
            {
                cout << "\nYou bought a Health Potion!" << endl;
                playerInventory.gold -= 20;
                playerInventory.healthPotions += 1;
            }
        case 2:
            if(playerInventory.gold < 20)
            {
                cout << "\nYou cannot afford that!" << endl;
            }
            else
            {
                cout << "\nYou bought a bomb!" << endl;
                playerInventory.gold -= 20;
                playerInventory.bombs += 1;
            }
        case 3:
            if(playerInventory.gold < 30)
            {
                cout << "\nYou cannot afford that!" << endl;
            }
            else
            {
                if(playerInventory.weapon == "Sword")
                {
                    cout << "\n You already have a sword!" << endl;
                }
                else
                {
                    cout << "\nYou bought a sword!" << endl;
                    playerDamage += 3;
                    playerInventory.gold -= 20;
                    playerInventory.weapon = "Sword";
                }
            }
        case 4:
            if(playerInventory.gold < 30)
            {
                cout << "\nYou cannot afford that!" << endl;
            }
            else
            {
                if(playerInventory.chestplate == "Chestplate")
                {
                    cout << "\nYou already have a chestplate!" << endl;
                }
                else
                {
                    cout << "\nYou bought a chestplate!" << endl;
                    playerInventory.armor += 2;
                    playerInventory.gold -= 30;
                    playerInventory.chestplate = "Chestplate";
                }
            }
        case 5:
            if(playerInventory.gold < 15)
            {
                cout << "\nYou cannot afford that!" << endl;
            }
            else
            {
                if(playerInventory.boots == "Boots")
                {
                    cout << "\nYou already have a pair of boots!" << endl;
                }
                else
                {
                    cout << "\nYou bought a pair of boots!" << endl;
                    playerInventory.armor += 2;
                    playerInventory.gold -= 15;
                    playerInventory.boots = "Boots";
                }
            }
        }
    }
}

void talkToLocals()
{
    cout << "Talking to locals" << endl;
}

void enterArena()
{
    cout << "Entering the arena!" << endl;
}

void displayInventory()
{
    cout << "Displaying inventory!" << endl;
}

