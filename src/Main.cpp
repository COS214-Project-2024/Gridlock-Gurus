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

std::shared_ptr<TaxAuthority> tax = std::make_shared<TaxAuthority>();
std::vector<Citizen *> cits;

class GridGui : public olc::PixelGameEngine {
public:
    GridGui() {
        sAppName = "GridLock";
    }

    bool OnUserCreate() override {
        png = new olc::Sprite("imageSet.png");

        buildingListBox->m_vList.emplace_back("BUILDINGS:");
        buildingNameLabel->nAlign = olc::QuickGUI::Label::Alignment::Left;
        buildingNameLabel->bHasBorder = true;
        toggleBuildingGroup();

        citSatisfactionLabel->nAlign = olc::QuickGUI::Label::Alignment::Left;
        citTypeLabel->nAlign = olc::QuickGUI::Label::Alignment::Left;
        newCitizenButton->bVisible = false;
        citizenListBox->bVisible = false;
        citizenGroupToggle(false);

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {

        Clear(olc::BLACK);

        guiManager.Update(this);
        guiManager.DrawDecal(this);

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
            renderCitizenGroup();
        }

        if (buildingListBox->nSelectedItem) {
            DrawPartialSprite(400, 20, png, 22, 16, 68, 130);
        }

        if (newCitizenButton->bReleased) {
            citizenGroupToggle(true);
        }

        if (addCitButton->bReleased) {
            CitizenType type = (citTypeCheckBoxC) ? CitizenType::Citizen : (citTypeCheckBoxR) ? CitizenType::Retired : CitizenType::Worker;
            cits.push_back(new Citizen(cits.size() + 1, type, std::stoi(citSatisfactionTextBox->sText), 500, tax));
            renderCitizenGroup();
            citizenGroupToggle(false);
            addCitButton->bReleased = false;
        }

        if (cancelCitButton->bReleased) {
            citizenGroupToggle(false);
            cancelCitButton->bReleased = false;
        }

        if (citizenListBox->bSelectionChanged) {
            if (citizenListBox->nSelectedItem == 0) {
            } else {
                console->sText = cits.at(citizenListBox->nSelectedItem - 1)->getName();
            }
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

    void citizenGroupToggle(const bool t) {
        citTypeLabel->bVisible = t;
        citTypeCheckBoxW->bVisible = t;
        citTypeCheckBoxW->bChecked = false;
        citTypeCheckBoxC->bVisible = t;
        citTypeCheckBoxC->bChecked = false;
        citTypeCheckBoxR->bVisible = t;
        citTypeCheckBoxR->bChecked = false;
        citSatisfactionLabel->bVisible = t;
        citSatisfactionTextBox->bVisible = t;
        citSatisfactionTextBox->sText = "";
        addCitButton->bVisible = t;
        cancelCitButton->bVisible = t;
    }

    void getCitizens(std::vector<std::string> &v) {
        for (Citizen *c: cits) {
            v.push_back(c->getName());
        }
    }

    void renderCitizenGroup() {
        size_t n = buildingListBox->nSelectedItem;
        if (n == 0) {
            newCitizenButton->bVisible = false;
            citizenListBox->bVisible = false;
            citizenGroupToggle(false);
        } else {
            citizenList.clear();
            citizenList.emplace_back(buildingListBox->m_vList.at(n));
            getCitizens(citizenList);

            newCitizenButton->bVisible = true;
            citizenListBox->bVisible = true;
        }
    }

    olc::Sprite *png = nullptr;

    olc::QuickGUI::Manager guiManager;

    olc::QuickGUI::Button *newBuildingButton = new olc::QuickGUI::Button(guiManager, "Build New Building", {5, 5}, {120, 15});
    std::vector<std::string> buildingList;
    olc::QuickGUI::ListBox *buildingListBox = new olc::QuickGUI::ListBox(guiManager, buildingList, {5, 20}, {120, 60});
    olc::QuickGUI::Label *buildingNameLabel = new olc::QuickGUI::Label(guiManager, "Building Name:", {5, 80}, {100, 15});
    olc::QuickGUI::TextBox *buildingNameTextBox = new olc::QuickGUI::TextBox(guiManager, "", {5, 95}, {100, 15});
    olc::QuickGUI::Button *addBuildingButton = new olc::QuickGUI::Button(guiManager, "Confirm", {5, 110}, {60, 15});
    olc::QuickGUI::Button *cancelBuildingButton = new olc::QuickGUI::Button(guiManager, "Cancel", {65, 110}, {60, 15});

    olc::QuickGUI::Button *newCitizenButton = new olc::QuickGUI::Button(guiManager, "New Citizen", {130, 5}, {120, 15});
    std::vector<std::string> citizenList;
    olc::QuickGUI::ListBox *citizenListBox = new olc::QuickGUI::ListBox(guiManager, citizenList, {130, 20}, {200, 60});
    olc::QuickGUI::Label *citTypeLabel = new olc::QuickGUI::Label(guiManager, "Citizen Type:", {130, 80}, {100, 15});
    olc::QuickGUI::CheckBox *citTypeCheckBoxW = new olc::QuickGUI::CheckBox(guiManager, "Worker", false, {130, 95}, {50, 15});
    olc::QuickGUI::CheckBox *citTypeCheckBoxC = new olc::QuickGUI::CheckBox(guiManager, "Citizen", false, {180, 95}, {50, 15});
    olc::QuickGUI::CheckBox *citTypeCheckBoxR = new olc::QuickGUI::CheckBox(guiManager, "Retired", false, {230, 95}, {50, 15});
    olc::QuickGUI::Label *citSatisfactionLabel = new olc::QuickGUI::Label(guiManager, "Citizen Satisfaction:", {130, 110}, {100, 15});
    olc::QuickGUI::TextBox *citSatisfactionTextBox = new olc::QuickGUI::TextBox(guiManager, "", {130, 125}, {100, 15});
    olc::QuickGUI::Button *addCitButton = new olc::QuickGUI::Button(guiManager, "Confirm", {130, 250}, {60, 15});
    olc::QuickGUI::Button *cancelCitButton = new olc::QuickGUI::Button(guiManager, "Cancel", {190, 250}, {60, 15});

    olc::QuickGUI::TextBox *console = new olc::QuickGUI::TextBox(guiManager, "", {5, 300}, {720, 65});
};

int main() {
    cits.push_back(new Citizen(1, CitizenType::Worker, 80, 5000, tax));
    cits.push_back(new Citizen(2, CitizenType::Citizen, 75, 1000, tax));

    GridGui gui;
    if (gui.Construct(730, 370, 2, 2)) {
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
