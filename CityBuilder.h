#ifndef CITYBUILDER_H
#define CITYBUILDER_H

/**
 * @brief Builder class for constructing the city in stages.
 *
 * Builder participant in the Builder design pattern. It defines the steps to build different parts of the city such as residential areas, commercial areas, and infrastructure.
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
    ~CityBuilder();

    /**
     * @brief Builds the residential area of the city.
     */
    void buildResidentialArea();

    /**
     * @brief Builds the commercial area of the city.
     */
    void buildCommercialArea();

    /**
     * @brief Builds the city's infrastructure, such as roads, utilities, and public services.
     */
    void buildInfrastructure();
};

#endif // CITYBUILDER_H
