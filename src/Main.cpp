#define OLC_PGE_APPLICATION
#define OLC_PGEX_QUICKGUI
#include "olcPixelGameEngine.h"
#include "olcPGEX_QuickGUI.h"
#include "TransportDepartment.h"
#include "CitizenFactory.h"
#include "Train.h"
#include "Taxi.h"
#include "Truck.h"
#include "Functional.h"
#include "Damaged.h"
#include "Broken.h"
#include "TaxAuthority.h"

#include <iostream>

std::vector<Citizen *> cits;

class GridGui : public olc::PixelGameEngine {
public:
    GridGui() {
        sAppName = "GridLock";
    }

    bool OnUserCreate() override {
        png = new olc::Sprite("imageSet.png");

        buildingList.emplace_back("BUILDINGS");

        citizenList.emplace_back("CITIZENS IN BUILDING");
        citizenListBox->bVisible = false;

        buildingNameLabel->nAlign = olc::QuickGUI::Label::Alignment::Left;
        buildingNameLabel->bHasBorder = true;
        toggleBuildingGroup();

        newCitizenButton->bVisible = false;

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        guiManager.Update(this);
        guiManager.DrawDecal(this);

        Clear(olc::BLACK);

        if (newBuildingButton->bReleased) {
            buildingNameTextBox->sText = "";
            toggleBuildingGroup();
        }

        if (cancelBuildingButton->bReleased) {
            toggleBuildingGroup();
            cancelBuildingButton->bReleased = false;
        }

        if (addBuildingButton->bReleased) {
            buildingList.emplace_back(buildingNameTextBox->sText);
            toggleBuildingGroup();
            addBuildingButton->bReleased = false;
        }

        if (buildingListBox->bSelectionChanged) {
            size_t n = buildingListBox->nSelectedItem;
            if (n == 0) {
                newCitizenButton->bVisible = false;
                citizenListBox->bVisible = false;
            } else {
                citizenList.clear();
                citizenList.emplace_back(buildingListBox->m_vList.at(n));
                getCitizens(citizenList);

                newCitizenButton->bVisible = true;
                citizenListBox->bVisible = true;
            }
        }

        if (buildingListBox->nSelectedItem) {
            DrawPartialSprite(400, 20, png, 22, 16, 68, 130);
        }

        if (newCitizenButton->bPressed) {
        }

        return true;
    }

protected:
    void toggleBuildingGroup() {
        buildingNameLabel->bVisible = !buildingNameLabel->bVisible;
        buildingNameTextBox->bVisible = !buildingNameTextBox->bVisible;
        addBuildingButton->bVisible = !addBuildingButton->bVisible;
        cancelBuildingButton->bVisible = !cancelBuildingButton->bVisible;
    }

    void getCitizens(std::vector<std::string> &v) {
        for (Citizen *c: cits) {
            v.push_back(c->getName());
        }
    }

    olc::Sprite *png = nullptr;

    olc::QuickGUI::Manager guiManager;

    olc::QuickGUI::Button *newBuildingButton = new olc::QuickGUI::Button(guiManager, "Build New Building", {5, 5}, {120, 15});
    olc::QuickGUI::Button *newCitizenButton = new olc::QuickGUI::Button(guiManager, "New Citizen", {130, 5}, {120, 15});

    std::vector<std::string> buildingList;
    olc::QuickGUI::ListBox *buildingListBox = new olc::QuickGUI::ListBox(guiManager, buildingList, {5, 20}, {120, 60});

    std::vector<std::string> citizenList;
    olc::QuickGUI::ListBox *citizenListBox = new olc::QuickGUI::ListBox(guiManager, citizenList, {130, 20}, {200, 60});

    olc::QuickGUI::Label *buildingNameLabel = new olc::QuickGUI::Label(guiManager, "Building Name:", {5, 80}, {100, 15});
    olc::QuickGUI::TextBox *buildingNameTextBox = new olc::QuickGUI::TextBox(guiManager, "", {5, 95}, {100, 15});
    olc::QuickGUI::Button *addBuildingButton = new olc::QuickGUI::Button(guiManager, "Confirm", {5, 110}, {60, 15});
    olc::QuickGUI::Button *cancelBuildingButton = new olc::QuickGUI::Button(guiManager, "Cancel", {65, 110}, {60, 15});
};

int main() {
    std::shared_ptr<TaxAuthority> tax = std::make_shared<TaxAuthority>();

    cits.push_back(new Citizen(1, CitizenType::Worker, 80, 5000, tax));
    cits.push_back(new Citizen(2, CitizenType::Citizen, 75, 1000, tax));

    GridGui gui;
    if (gui.Construct(640, 250, 2, 2)) {
        gui.Start();
    } else {
        std::cout << "ERROR:\tGui failed to construct\n";
    }

    TransportDepartment department;

    Train *train = new Train(100);
    Taxi *taxi = new Taxi(4);
    Truck *truck = new Truck(10);

    Functional functional;
    Damaged damaged;
    Broken broken;

    train->setState(&functional);
    taxi->setState(&damaged);
    truck->setState(&broken);

    department.addVehicle(train);
    department.addVehicle(taxi);
    department.addVehicle(truck);

    cits.at(0)->callTransport(department, "Train");
    cits.at(1)->callTransport(department, "Taxi");

    train->run();
    train->delay();
    truck->run();
    truck->breakDown();

    std::cout << "\n--- State Transitions ---" << std::endl;
    taxi->repair();
    taxi->setState(&functional);
    taxi->run();

    std::cout << "\n--- Offloading Passengers ---" << std::endl;
    cits.at(0)->offloadVehicle();
    cits.at(1)->offloadVehicle();

    std::cout << "\n--- Cloning Vehicles ---" << std::endl;
    Vehicle *clonedTrain = train->clone();
    std::cout << "Cloned a new: " << clonedTrain->getType() << std::endl;

    delete train;
    delete taxi;
    delete truck;
    delete clonedTrain;

    std::cout << "\n--- All Tests Completed ---" << std::endl;

    return 0;
}
