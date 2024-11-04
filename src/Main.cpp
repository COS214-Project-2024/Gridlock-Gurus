#define OLC_PGE_APPLICATION
#define OLC_PGEX_QUICKGUI
#include "olcPixelGameEngine.h"
#include "olcPGEX_QuickGUI.h"
#include "TransportDepartment.h"
#include "CitizenFactory.h"
// #include "Train.h"
// #include "Taxi.h"
// #include "Truck.h"
// #include "Functional.h"
// #include "Damaged.h"
// #include "Broken.h"
#include "City.h"

#include <iostream>

std::shared_ptr<City> city = std::make_shared<City>();
std::vector<int> ids;

const std::unordered_map<BuildingType, std::string> buildingTypeName = {
    {BuildingType::Residential, "Residential"},
    {BuildingType::Shop, "Shop"},
    {BuildingType::BrickFactory, "Brick Factory"},
    {BuildingType::SteelFactory, "Steel Factory"},
    {BuildingType::WoodFactory, "Wood Factory"},
    {BuildingType::Bank, "Bank"},
    {BuildingType::Flat, "Flat"},
    {BuildingType::Estate, "Estate"},
    {BuildingType::House, "House"},
    {BuildingType::Statue, "Statue"},
    {BuildingType::Park, "Park"},
    {BuildingType::PoliceStation, "Police Station"},
    {BuildingType::Hospital, "Hospital"},
    {BuildingType::School, "School"}
};

class GridGui : public olc::PixelGameEngine {
public:
    GridGui() {
        sAppName = "GridLock";
    }

    bool OnUserCreate() override {
        png = new olc::Sprite("./images/imageSet.png");

        buildingListBox->m_vList.emplace_back("BUILDINGS:");
        buildingNameLabel->nAlign = olc::QuickGUI::Label::Alignment::Left;
        buildingNameLabel->bHasBorder = true;
        buildingGroupToggle(false);

        citSatisfactionLabel->nAlign = olc::QuickGUI::Label::Alignment::Left;
        citTypeLabel->nAlign = olc::QuickGUI::Label::Alignment::Left;
        newCitizenButton->bVisible = false;
        citizenListBox->bVisible = false;
        newCitizenGroupToggle(false);

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        Clear(olc::BLACK);

        guiManager.Update(this);
        guiManager.DrawDecal(this);

        if (newBuildingButton->bReleased) {
            buildingNameTextBox->sText = "";
            buildingGroupToggle(true);
        }

        if (buildingListBox->bSelectionChanged) {
            if (buildingListBox->nSelectedItem != 0) {
                console->sText = buildingTypeName.at(city->getBuildings().at(buildingListBox->nSelectedItem - 1)->getType());
            }
            renderCitizenGroup();
        }

        if (addBuildingButton->bReleased) {
            BuildingType type; {
                type = (bTypeScho->bChecked)
                           ? BuildingType::School
                           : (bTypeEsta->bChecked)
                                 ? BuildingType::Estate
                                 : (bTypeFlat->bChecked)
                                       ? BuildingType::Flat
                                       : (bTypeHous->bChecked)
                                             ? BuildingType::House
                                             : (bTypePark->bChecked)
                                                   ? BuildingType::Park
                                                   : (bTypeStat->bChecked)
                                                         ? BuildingType::Statue
                                                         : (bTypeResi->bChecked)
                                                               ? BuildingType::Residential
                                                               : (bTypeShop->bChecked)
                                                                     ? BuildingType::Shop
                                                                     : (bTypeBFac->bChecked)
                                                                           ? BuildingType::BrickFactory
                                                                           : (bTypeSFac->bChecked)
                                                                                 ? BuildingType::SteelFactory
                                                                                 : (bTypeWFac->bChecked)
                                                                                       ? BuildingType::WoodFactory
                                                                                       : (bTypeBank->bChecked)
                                                                                             ? BuildingType::Bank
                                                                                             : (bTypePoli->bChecked)
                                                                                                   ? BuildingType::PoliceStation
                                                                                                   : (bTypeHosp->bChecked)
                                                                                                           ? BuildingType::Hospital
                                                                                                           : BuildingType::Residential;
            }
            std::cout << "type: " << buildingTypeName.at(type) << std::endl;
            std::string name = buildingNameTextBox->sText;
            city->addBuilding(name, type);

            std::vector<std::string> names = city->getBuildingNames();
            buildingList.erase(++buildingList.begin(), buildingList.end());
            buildingList.insert(++buildingList.begin(), names.begin(), names.end());

            std::cout << city->getBuildings().at(0)->getDetails();

            buildingGroupToggle(false);
            addBuildingButton->bReleased = false;
        }

        if (cancelBuildingButton->bReleased) {
            buildingGroupToggle(false);
            cancelBuildingButton->bReleased = false;
        }

        if (buildingListBox->nSelectedItem) {
            std::string building = buildingTypeName.at(city->getBuildings().at(buildingListBox->nSelectedItem - 1)->getType());
            png = new olc::Sprite("./images/" + building + ".png");
            DrawSprite(330, 5, png);
        }

        if (newCitizenButton->bReleased) {
            newCitizenGroupToggle(true);
        }

        if (addCitButton->bReleased) {
            CitizenType type = (citTypeCheckBoxC) ? CitizenType::Citizen : (citTypeCheckBoxR) ? CitizenType::Retired : CitizenType::Worker;
            console->sText = city->createCitizen(type, stoi(citSatisfactionTextBox->sText), stoi(citFundsTextBox->sText));
            renderCitizenGroup();
            newCitizenGroupToggle(false);
            addCitButton->bReleased = false;
        }

        if (cancelCitButton->bReleased) {
            newCitizenGroupToggle(false);
            cancelCitButton->bReleased = false;
        }

        if (citizenListBox->bSelectionChanged) {
            if (citizenListBox->nSelectedItem == 0) {
                newCitizenGroupToggle(false);
            } else {
                std::cout << "got here\n";
                console->sText = city->getCitizenDetails(ids.at(citizenListBox->nSelectedItem) - 1);
            }
        }

        if (cityReportButton->bReleased) {
            std::string r;
            city->generateReport(r);
            console->sText = r;
        }

        if (newTaxiButton->bReleased) {
            city->increaseTransport(Taxi);
        }

        if (newTrainButton->bReleased) {
            city->increaseTransport(Train);
        }

        if (taxButton->bReleased) {

        }

        return true;
    }

protected:
    void buildingGroupToggle(const bool t) {
        buildingNameLabel->bVisible = t;
        buildingNameTextBox->bVisible = t;
        buildingTypeLabel->bVisible = t;
        bTypeScho->bVisible = t;
        bTypeEsta->bVisible = t;
        bTypeShop->bVisible = t;
        bTypeStat->bVisible = t;
        bTypeBank->bVisible = t;
        bTypePark->bVisible = t;
        bTypeHous->bVisible = t;
        bTypeHosp->bVisible = t;
        bTypeFlat->bVisible = t;
        bTypeResi->bVisible = t;
        bTypePoli->bVisible = t;
        bTypeBFac->bVisible = t;
        bTypeSFac->bVisible = t;
        bTypeWFac->bVisible = t;
        addBuildingButton->bVisible = t;
        cancelBuildingButton->bVisible = t;
    }

    void newCitizenGroupToggle(const bool t) {
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
        citFundsLabel->bVisible = t;
        citFundsTextBox->bVisible = t;
        citFundsTextBox->sText = "";
        addCitButton->bVisible = t;
        cancelCitButton->bVisible = t;
    }

    void renderCitizenGroup() {
        size_t n = buildingListBox->nSelectedItem;
        if (n == 0) {
            newCitizenButton->bVisible = false;
            citizenListBox->bVisible = false;
            newCitizenGroupToggle(false);
        } else {
            citizenList.clear();
            citizenList.emplace_back(buildingListBox->m_vList.at(n));

            Building *b = city->getBuildings().at(buildingListBox->nSelectedItem - 1);
            ids.clear(); {
                if (b->getType() == BuildingType::BrickFactory || b->getType() == BuildingType::SteelFactory || b->getType() ==
                    BuildingType::WoodFactory) {
                    //Factory
                    auto *f = dynamic_cast<Factory *>(b);
                    ids = f->getEmployees();
                } else if (b->getType() == BuildingType::Shop || b->getType() == BuildingType::Bank) {
                    auto *f = dynamic_cast<Commercial *>(b);
                    ids = f->getEmployees();
                } else if (b->getType() == BuildingType::Flat || b->getType() == BuildingType::House || b->getType() == BuildingType::Estate) {
                    auto *f = dynamic_cast<Residential *>(b);
                    ids = f->getTenants();
                } else if (b->getType() == BuildingType::Statue || b->getType() == BuildingType::Park) {
                    //Landmark
                    //no citizens
                } else {
                    auto *f = dynamic_cast<Service *>(b);
                    ids = f->getEmployees();
                }
            }
            std::vector<std::string> names;
            for (const auto id: ids) {
                names.push_back(city->getCitizen(id).getName());
            }
            citizenList.insert(++citizenList.begin(), names.begin(), names.end());

            newCitizenButton->bVisible = true;
            citizenListBox->bVisible = true;
        }
    }

    olc::v_2d<int> getSpritePartials(int i, bool b) {
        switch (i) {
            case 1:
                return (b) ? olc::v_2d{30, 30} : olc::v_2d{51, 99};
            case 2:
                return (b) ? olc::v_2d{110, 30} : olc::v_2d{51, 99};
            case 3:
                return (b) ? olc::v_2d{190, 30} : olc::v_2d{51, 99};
            default:
                return (b) ? olc::v_2d{493, 128} : olc::v_2d{21, 20};
        }
    }

    olc::Sprite *png = nullptr;

    olc::QuickGUI::Manager guiManager;

    olc::QuickGUI::Button *newBuildingButton = new olc::QuickGUI::Button(guiManager, "Build New Building", {5, 5}, {120, 15});
    std::vector<std::string> buildingList;
    olc::QuickGUI::ListBox *buildingListBox = new olc::QuickGUI::ListBox(guiManager, buildingList, {5, 20}, {120, 60});
    olc::QuickGUI::Label *buildingNameLabel = new olc::QuickGUI::Label(guiManager, "Building Name:", {5, 80}, {120, 15});
    olc::QuickGUI::TextBox *buildingNameTextBox = new olc::QuickGUI::TextBox(guiManager, "", {5, 95}, {100, 15});
    olc::QuickGUI::Label *buildingTypeLabel = new olc::QuickGUI::Label(guiManager, "Building Type:", {5, 110}, {100, 15});
    olc::QuickGUI::CheckBox *bTypeScho = new olc::QuickGUI::CheckBox(guiManager, "School", false, {5, 125}, {60, 15});
    olc::QuickGUI::CheckBox *bTypeShop = new olc::QuickGUI::CheckBox(guiManager, "Shop", false, {5, 140}, {60, 15});
    olc::QuickGUI::CheckBox *bTypeBank = new olc::QuickGUI::CheckBox(guiManager, "Bank", false, {5, 155}, {60, 15});
    olc::QuickGUI::CheckBox *bTypeHous = new olc::QuickGUI::CheckBox(guiManager, "House", false, {5, 170}, {60, 15});
    olc::QuickGUI::CheckBox *bTypeFlat = new olc::QuickGUI::CheckBox(guiManager, "Flat", false, {5, 185}, {50, 15});
    olc::QuickGUI::CheckBox *bTypeEsta = new olc::QuickGUI::CheckBox(guiManager, "Estate", false, {65, 125}, {60, 15});
    olc::QuickGUI::CheckBox *bTypeStat = new olc::QuickGUI::CheckBox(guiManager, "Statue", false, {65, 140}, {60, 15});
    olc::QuickGUI::CheckBox *bTypePark = new olc::QuickGUI::CheckBox(guiManager, "Park", false, {65, 155}, {60, 15});
    olc::QuickGUI::CheckBox *bTypeHosp = new olc::QuickGUI::CheckBox(guiManager, "Hospital", false, {65, 170}, {60, 15});
    olc::QuickGUI::CheckBox *bTypeResi = new olc::QuickGUI::CheckBox(guiManager, "Residential", false, {55, 185}, {70, 15});
    olc::QuickGUI::CheckBox *bTypePoli = new olc::QuickGUI::CheckBox(guiManager, "Police Station", false, {5, 200}, {100, 15});
    olc::QuickGUI::CheckBox *bTypeBFac = new olc::QuickGUI::CheckBox(guiManager, "Brick Factory", false, {5, 215}, {100, 15});
    olc::QuickGUI::CheckBox *bTypeSFac = new olc::QuickGUI::CheckBox(guiManager, "Steel Factory", false, {5, 230}, {100, 15});
    olc::QuickGUI::CheckBox *bTypeWFac = new olc::QuickGUI::CheckBox(guiManager, "Wood Factory", false, {5, 245}, {100, 15});
    olc::QuickGUI::Button *addBuildingButton = new olc::QuickGUI::Button(guiManager, "Confirm", {5, 265}, {60, 15});
    olc::QuickGUI::Button *cancelBuildingButton = new olc::QuickGUI::Button(guiManager, "Cancel", {65, 265}, {60, 15});

    olc::QuickGUI::Button *newCitizenButton = new olc::QuickGUI::Button(guiManager, "New Citizen", {130, 5}, {120, 15});
    std::vector<std::string> citizenList;
    olc::QuickGUI::ListBox *citizenListBox = new olc::QuickGUI::ListBox(guiManager, citizenList, {130, 20}, {200, 60});
    olc::QuickGUI::Label *citTypeLabel = new olc::QuickGUI::Label(guiManager, "Citizen Type:", {130, 80}, {100, 15});
    olc::QuickGUI::CheckBox *citTypeCheckBoxW = new olc::QuickGUI::CheckBox(guiManager, "Worker", false, {130, 95}, {50, 15});
    olc::QuickGUI::CheckBox *citTypeCheckBoxC = new olc::QuickGUI::CheckBox(guiManager, "Citizen", false, {180, 95}, {50, 15});
    olc::QuickGUI::CheckBox *citTypeCheckBoxR = new olc::QuickGUI::CheckBox(guiManager, "Retired", false, {230, 95}, {50, 15});
    olc::QuickGUI::Label *citSatisfactionLabel = new olc::QuickGUI::Label(guiManager, "Citizen Satisfaction:", {130, 110}, {100, 15});
    olc::QuickGUI::TextBox *citSatisfactionTextBox = new olc::QuickGUI::TextBox(guiManager, "", {130, 125}, {100, 15});
    olc::QuickGUI::Label *citFundsLabel = new olc::QuickGUI::Label(guiManager, "Citizen Funds:", {130, 140}, {100, 15});
    olc::QuickGUI::TextBox *citFundsTextBox = new olc::QuickGUI::TextBox(guiManager, "", {130, 155}, {100, 15});
    olc::QuickGUI::Button *addCitButton = new olc::QuickGUI::Button(guiManager, "Confirm", {130, 250}, {60, 15});
    olc::QuickGUI::Button *cancelCitButton = new olc::QuickGUI::Button(guiManager, "Cancel", {190, 250}, {60, 15});

    olc::QuickGUI::Button *cityReportButton = new olc::QuickGUI::Button(guiManager, "City Report", {550, 5}, {120, 15});
    olc::QuickGUI::Button *newTaxiButton = new olc::QuickGUI::Button(guiManager, "New Taxi", {550, 20}, {60, 15});
    olc::QuickGUI::Button *newTrainButton = new olc::QuickGUI::Button(guiManager, "New Train", {610, 20}, {60, 15});
    olc::QuickGUI::Button *taxButton = new olc::QuickGUI::Button(guiManager, "Tax Report", {550, 35}, {120, 15});

    olc::QuickGUI::TextBox *console = new olc::QuickGUI::TextBox(guiManager, "", {5, 300}, {720, 65});
};

int main() {
    TransportDepartment department;

    // Train *train = new Train(100);
    // Taxi *taxi = new Taxi(4);
    // Truck *truck = new Truck(10);

    GridGui gui;
    if (gui.Construct(730, 370, 2, 2)) {
        gui.Start();
    } else {
        std::cout << "ERROR:\tGui failed to construct\n";
    }


    // Functional functional;
    // Damaged damaged;
    // Broken broken;
    //
    // train->setState(&functional);
    // taxi->setState(&damaged);
    // truck->setState(&broken);
    //
    // department.addVehicle(train);
    // department.addVehicle(taxi);
    // department.addVehicle(truck);
    //
    // cits.at(0)->callTransport(department, "Train");
    // cits.at(1)->callTransport(department, "Taxi");
    //
    // train->run();
    // train->delay();
    // truck->run();
    // truck->breakDown();
    //
    // std::cout << "\n--- State Transitions ---" << std::endl;
    // taxi->repair();
    // taxi->setState(&functional);
    // taxi->run();
    //
    // std::cout << "\n--- Offloading Passengers ---" << std::endl;
    // cits.at(0)->offloadVehicle();
    // cits.at(1)->offloadVehicle();
    //
    // std::cout << "\n--- Cloning Vehicles ---" << std::endl;
    // Vehicle *clonedTrain = train->clone();
    // std::cout << "Cloned a new: " << clonedTrain->getType() << std::endl;
    //
    // delete train;
    // delete taxi;
    // delete truck;
    // delete clonedTrain;

    std::cout << "\n--- All Tests Completed ---" << std::endl;

    return 0;
}
