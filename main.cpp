#include "Traveller.h"
#include "Trip.h"
#include "ShortestRoute.h"
#include "ScenicRoute.h"
#include "CheapestRoute.h"
#include "Map.h"
#include "LocationDecorator.h"
#include "WorldBuilder.h"
#include "DesertFactory.h"
#include "CityFactory.h"
#include "OceanFactory.h"
#include "ForestFactory.h"
#include <iostream>
#include <vector>

void buildBiome(WorldBuilder* factory) {
    NPC* npc = factory->createNPC();
    Terrain* terrain = factory->createTerrain();
    Obstacle* obstacle = factory->createObstacle();

    npc->print();
    terrain->print();
    obstacle->print();

    delete npc;
    delete terrain;
    delete obstacle;
}

int main() {
    std::cout << "=== State: Traveller movement ===" << std::endl;
    Traveller traveller;
    traveller.move();               // starts on foot
    traveller.enterBikeRack();
    traveller.move();                // transitions to bicycle
    traveller.enterDock();
    traveller.move();                // parks bicycle, transitions to boat
    traveller.enterDock();
    traveller.move();                // recovers bicycle at dock
    std::cout << "Traveller position: " << traveller.getPosition() << std::endl;

    std::cout << "\n=== Strategy: route planning ===" << std::endl;
    Trip trip;
    trip.setRouteStrategy(new ShortestRoute());
    std::cout << trip.plan() << std::endl;
    trip.setRouteStrategy(new ScenicRoute());
    std::cout << trip.plan() << std::endl;
    trip.setRouteStrategy(new CheapestRoute());
    std::cout << trip.plan() << std::endl;

    std::cout << "\n=== Composite: world map ===" << std::endl;
    Region* world = new Region("World");
    Location* oasis = new Location("Oasis", "Desert");
    Location* harbor = new Location("Harbor", "Ocean");
    Region* desertRegion = new Region("Desert Region");
    desertRegion->add(new Location("Dune Camp", "Desert"));
    world->add(oasis);
    world->add(harbor);
    world->add(desertRegion);
    world->print();

    std::cout << "\n=== Decorator: stackable place features ===" << std::endl;
    Map* decorated = new Location("Old Well", "Desert");
    decorated = new WeatherLocation(decorated, "Sandstorm");
    decorated = new TollLocation(decorated, "5 gold");
    decorated = new QuestLocation(decorated, "Find the lost caravan");
    decorated->print();

    std::cout << "\n=== Abstract Factory: biome content ===" << std::endl;
    std::vector<WorldBuilder*> factories;
    factories.push_back(new DesertFactory());
    factories.push_back(new CityFactory());
    factories.push_back(new OceanFactory());
    factories.push_back(new ForestFactory());

    for (WorldBuilder* factory : factories) {
        std::cout << "--- Biome ---" << std::endl;
        buildBiome(factory);
    }

    delete world;
    delete decorated;
    for (WorldBuilder* factory : factories) {
        delete factory;
    }

    return 0;
}
