#include "Traveller.h"
#include "Trip.h"
#include "ShortestRoute.h"
#include "FastestRoute.h"
#include "ScenicRoute.h"
#include "CheapestRoute.h"
#include "Map.h"
#include "LocationDecorator.h"
#include "WorldBuilder.h"
#include "Desert.h"
#include "City.h"
#include "Ocean.h"
#include "Forest.h"
#include <iostream>
#include <string>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

int readChoice(int min, int max) {
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < min || choice > max) {
            clearInput();
            std::cout << "Enter a number between " << min << " and " << max << ": ";
        } else {
            clearInput();
            return choice;
        }
    }
}

void printMainMenu() {
    std::cout << "\n===== Wayfarer =====" << std::endl;
    std::cout << "1. Choose travel mode" << std::endl;
    std::cout << "2. Choose route strategy" << std::endl;
    std::cout << "3. Walk the map" << std::endl;
    std::cout << "4. Step into a biome" << std::endl;
    std::cout << "5. Stack a feature onto your current place" << std::endl;
    std::cout << "6. Show traveller status" << std::endl;
    std::cout << "0. Quit" << std::endl;
    std::cout << "Choose: ";
}

void chooseTravelMode(Traveller& traveller) {
    std::cout << "\nYou are currently moving. Reach a location to change mode:" << std::endl;
    std::cout << "1. Bike rack   (foot -> bicycle)" << std::endl;
    std::cout << "2. Garage      (foot <-> car)" << std::endl;
    std::cout << "3. Dock        (bicycle/car -> boat, parks vehicle; boat -> recovers it)" << std::endl;
    std::cout << "4. Just move" << std::endl;
    std::cout << "Choose: ";
    int choice = readChoice(1, 4);

    switch (choice) {
        case 1: traveller.enterBikeRack(); break;
        case 2: traveller.enterGarage(); break;
        case 3: traveller.enterDock(); break;
        default: break;
    }

    traveller.move();
    std::cout << "Position is now " << traveller.getPosition() << "." << std::endl;
}

void chooseRouteStrategy(Trip& trip) {
    std::cout << "\nPick a route priority:" << std::endl;
    std::cout << "1. Shortest" << std::endl;
    std::cout << "2. Fastest" << std::endl;
    std::cout << "3. Scenic" << std::endl;
    std::cout << "4. Cheapest" << std::endl;
    std::cout << "Choose: ";
    int choice = readChoice(1, 4);

    switch (choice) {
        case 1: trip.setRouteStrategy(new ShortestRoute()); break;
        case 2: trip.setRouteStrategy(new FastestRoute()); break;
        case 3: trip.setRouteStrategy(new ScenicRoute()); break;
        case 4: trip.setRouteStrategy(new CheapestRoute()); break;
    }

    std::cout << trip.plan() << std::endl;
}

void walkTheMap(Region* world) {
    std::cout << "\nHere's the world map:" << std::endl;
    world->print();
}

void stepIntoBiome() {
    std::cout << "\nWhich biome do you enter?" << std::endl;
    std::cout << "1. Desert" << std::endl;
    std::cout << "2. City" << std::endl;
    std::cout << "3. Ocean" << std::endl;
    std::cout << "4. Forest" << std::endl;
    std::cout << "Choose: ";
    int choice = readChoice(1, 4);

    WorldBuilder* factory = nullptr;
    switch (choice) {
        case 1: factory = new DesertFactory(); break;
        case 2: factory = new CityFactory(); break;
        case 3: factory = new OceanFactory(); break;
        case 4: factory = new ForestFactory(); break;
    }

    NPC* npc = factory->createNPC();
    Terrain* terrain = factory->createTerrain();
    Obstacle* obstacle = factory->createObstacle();

    std::cout << "\nYou step into the biome..." << std::endl;
    terrain->print();
    npc->print();
    obstacle->print();

    delete npc;
    delete terrain;
    delete obstacle;
    delete factory;
}

void stackFeature(Map*& currentPlace) {
    std::cout << "\nStack a feature onto your current place:" << std::endl;
    std::cout << "1. Weather" << std::endl;
    std::cout << "2. Toll" << std::endl;
    std::cout << "3. Quest" << std::endl;
    std::cout << "4. Stop stacking" << std::endl;

    while (true) {
        std::cout << "Choose: ";
        int choice = readChoice(1, 4);
        if (choice == 4) {
            break;
        }

        std::string detail;
        switch (choice) {
            case 1:
                std::cout << "Describe the weather: ";
                std::getline(std::cin, detail);
                currentPlace = new WeatherLocation(currentPlace, detail);
                break;
            case 2:
                std::cout << "Describe the toll: ";
                std::getline(std::cin, detail);
                currentPlace = new TollLocation(currentPlace, detail);
                break;
            case 3:
                std::cout << "Describe the quest: ";
                std::getline(std::cin, detail);
                currentPlace = new QuestLocation(currentPlace, detail);
                break;
        }

        std::cout << "\nYour place now reads:" << std::endl;
        currentPlace->print();
        std::cout << "\nStack another?" << std::endl;
        std::cout << "1. Weather  2. Toll  3. Quest  4. Stop stacking" << std::endl;
    }
}

int main() {
    std::cout << "Welcome to Wayfarer." << std::endl;

    Traveller traveller;
    Trip trip;

    Region* world = new Region("World");
    Location* oasis = new Location("Oasis", "Desert");
    Location* harbor = new Location("Harbor", "Ocean");
    Region* desertRegion = new Region("Desert Region");
    desertRegion->add(new Location("Dune Camp", "Desert"));
    world->add(oasis);
    world->add(harbor);
    world->add(desertRegion);

    Map* currentPlace = new Location("Trailhead", "Home");

    bool running = true;
    while (running) {
        printMainMenu();
        int choice = readChoice(0, 6);

        switch (choice) {
            case 1: chooseTravelMode(traveller); break;
            case 2: chooseRouteStrategy(trip); break;
            case 3: walkTheMap(world); break;
            case 4: stepIntoBiome(); break;
            case 5: stackFeature(currentPlace); break;
            case 6:
                std::cout << "\nPosition: " << traveller.getPosition() << std::endl;
                std::cout << "Current place: " << std::endl;
                currentPlace->print();
                break;
            case 0:
                running = false;
                break;
        }
    }

    std::cout << "\nThanks for playing Wayfarer." << std::endl;

    delete world;
    delete currentPlace;

    return 0;
}