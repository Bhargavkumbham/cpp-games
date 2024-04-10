#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// Function to get random number between min and max
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

// Function to simulate a hunting attempt
bool hunt()
{
    int probability = getRandomNumber(1, 100);
    if (probability <= 60)
    {
        cout << "You successfully hunted a rabbit!" << endl;
        return true;
    }
    else
    {
        cout << "You failed to hunt anything." << endl;
        return false;
    }
}

// Function to simulate foraging for berries
bool forage()
{
    int probability = getRandomNumber(1, 100);
    if (probability <= 80)
    {
        cout << "You found a patch of edible berries!" << endl;
        return true;
    }
    else
    {
        cout << "You couldn't find any edible berries." << endl;
        return false;
    }
}

// Function to simulate exploring the wilderness
bool explore()
{
    int probability = getRandomNumber(1, 100);
    if (probability <= 70)
    {
        cout << "You discovered a new area with valuable resources!" << endl;
        return true;
    }
    else
    {
        cout << "You didn't find anything useful during your exploration." << endl;
        return false;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); 

    int food = 20; 
    int water = 15; 
    int daysSurvived = 0;
    vector<string> discoveredResources;

    cout << "Welcome to the Wilderness Survival Challenge!" << endl;

    while (food > 0 && water > 0)
    {
        // Display status
        cout << "Days survived: " << daysSurvived << endl;
        cout << "Food remaining: " << food << endl;
        cout << "Water remaining: " << water << endl;
        cout << "Discovered resources: ";
        for (const auto& resource : discoveredResources)
        {
            cout << resource << " ";
        }
        cout << endl;

        // Ask for user input
        cout << "What would you like to do?" << endl;
        cout << "1. Hunt for food" << endl;
        cout << "2. Forage for berries" << endl;
        cout << "3. Explore the wilderness" << endl;
        cout << "4. Do nothing" << endl;

        int choice;
        cin >> choice;

        // Process user input
        switch (choice)
        {
        case 1:
            if (hunt())
            {
                food += 3; // Hunted rabbit provides 3 units of food
            }
            else
            {
                food--; // Failed hunt consumes 1 unit of food
            }
            break;
        case 2:
            if (forage())
            {
                food += 2; // Found berries provide 2 units of food
            }
            else
            {
                food--; // Failed foraging consumes 1 unit of food
            }
            break;
        case 3:
            if (explore())
            {
                string newResource = "Valuable resource";
                discoveredResources.push_back(newResource);
                cout << "You have discovered a new resource: " << newResource << endl;
            }
            else
            {
                water--; // Exploration consumes 1 unit of water
            }
            break;
        case 4:
            // Do nothing, but consume 1 unit of food and 1 unit of water
            food--;
            water--;
            break;
        default:
            cout << "Invalid choice. Please choose 1, 2, 3, or 4." << endl;
            break;
        }

        daysSurvived++;

        // Check if the player has survived for 10 days
        if (daysSurvived == 10)
        {
            cout << "Congratulations! You have survived for 10 days!" << endl;
            break;
        }
    }

    if (food == 0)
    {
        cout << "You have run out of food and have starved to death." << endl;
    }
    else if (water == 0)
    {
        cout << "You have run out of water and have died of dehydration." << endl;
    }

    cout << "Game over." << endl;
    return 0;
}
