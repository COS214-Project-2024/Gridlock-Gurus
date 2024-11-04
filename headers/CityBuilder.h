#ifndef CITYBUILDER_H
#define CITYBUILDER_H

class CityBuilder {
public:
    CityBuilder();
    virtual ~CityBuilder();
    void buildResidentialArea();
    void buildCommercialArea();
    void buildInfrastructure();
};

#endif // CITYBUILDER_H
