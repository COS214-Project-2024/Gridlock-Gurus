#ifndef CITYBUILDER_H
#define CITYBUILDER_H

/**
 * @brief A class responsible for building various parts of a city.
 */
class CityBuilder {
public:
    /**
     * @brief Constructs a new CityBuilder object.
     */
    CityBuilder();

    /**
     * @brief Destroys the CityBuilder object.
     */
    virtual ~CityBuilder();

    /**
     * @brief Builds a residential area in the city.
     */
    void buildResidentialArea();

    /**
     * @brief Builds a commercial area in the city.
     */
    void buildCommercialArea();

    /**
     * @brief Builds city infrastructure.
     */
    void buildInfrastructure();
};

#endif // CITYBUILDER_H
