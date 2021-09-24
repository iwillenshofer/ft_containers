/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:46 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/20 16:19:14 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <typeinfo>
#include "tests.hpp"

void    compareFilesOutput( void )
{
    std::string lineFt;
    std::ifstream testFt ("ft");
    std::string lineStd;
    std::ifstream testStd ("std");

    std::getline(testFt, lineFt, '\0');
    std::getline(testStd, lineStd, '\0');
    if (lineFt == lineStd)
        std::cout << FGRN("OK") << std::endl;
    else
        std::cout << FRED("KO") << std::endl;
    std::cout << std::endl;
    testFt.close();
    testStd.close();
}

bool    testStack()
{
    return (false);
}

bool    testMap()
{
    return (false);
}

bool    testVector()
{
    std::string input;
    bool exit = false;

    std::cout << FMAG("--- Vector menu ---") << std::endl;
    std::cout << FCYN("1") << FWHT(" - Constructors") << std::endl;
    std::cout << FCYN("2") << FWHT(" - Iterators") << std::endl;
    std::cout << FCYN("3") << FWHT(" - Capacity") << std::endl;
    std::cout << FCYN("4") << FWHT(" - Element access") << std::endl;
    std::cout << FCYN("5") << FWHT(" - Modifiers") << std::endl;
    std::cout << FCYN("6") << FWHT(" - Allocator") << std::endl;
    std::cout << FGRN("A") << FWHT(" - All") << std::endl;
    std::cout << FYEL("B") << FWHT(" - Back") << std::endl;
    std::cout << FRED("E") << FWHT(" - Exit") << std::endl;
    std::cout << FBLU("Select a test section : ");

    while (std::getline(std::cin, input))
    {
        system("clear");
        if (!input.compare("1"))
            exit = testVectorConstructors();
        else if (!input.compare("2"))
            exit = testVectorIterators();
        //else if (!input.compare("3"))
        //    exit = testVectorCapacity();
        //else if (!input.compare("4"))
        //    exit = testVectorElementAccess();
        //else if (!input.compare("5"))
        //    exit = testVectorModifiers();
        //else if (!input.compare("6"))
        //    exit = testVectorAllocator(); 
        else if (!input.compare("B") || !input.compare("b"))
            return (false);
        else if (!input.compare("E") || !input.compare("e"))
            return (true);
        else
            std::cout << FRED("Command not found!") << std::endl << std::endl;
        if (exit == true)
            return (true);
        std::cout << FMAG("--- Vector menu ---") << std::endl;
        std::cout << FCYN("1") << FWHT(" - Constructors") << std::endl;
        std::cout << FCYN("2") << FWHT(" - Iterators") << std::endl;
        std::cout << FCYN("3") << FWHT(" - Capacity") << std::endl;
        std::cout << FCYN("4") << FWHT(" - Element access") << std::endl;
        std::cout << FCYN("5") << FWHT(" - Modifiers") << std::endl;
        std::cout << FCYN("6") << FWHT(" - Allocator") << std::endl;
        std::cout << FGRN("A") << FWHT(" - All") << std::endl;
        std::cout << FYEL("B") << FWHT(" - Back") << std::endl;
        std::cout << FRED("E") << FWHT(" - Exit") << std::endl;
        std::cout << FBLU("Select a test section : ");
    }
    return (true);
}

bool    sectionOthers( void )
{
    return false;
}

bool    sectionIterators( void )
{
    return false;
}

bool    sectionContainers( void )
{
    std::string input;
    bool exit = false;
    
    std::cout << FMAG("--- Containers menu ---") << std::endl;
    std::cout << FCYN("1") << FWHT(" - Vector") << std::endl;
    std::cout << FCYN("2") << FWHT(" - Map") << std::endl;
    std::cout << FCYN("3") << FWHT(" - Stack") << std::endl;
    std::cout << FGRN("A") << FWHT(" - All") << std::endl;
    std::cout << FYEL("B") << FWHT(" - Back") << std::endl;
    std::cout << FRED("E") << FWHT(" - Exit") << std::endl;
    std::cout << FBLU("Select a container : ");

    while (std::getline(std::cin, input))
    {
        system("clear");
        if (!input.compare("1"))
            exit = testVector();
        else if (!input.compare("2"))
            exit = testMap();
        else if (!input.compare("3"))
            exit = testStack();
        else if (!input.compare("B") || !input.compare("b"))
            return (false);
        else if (!input.compare("E") || !input.compare("e"))
            return (true);
        else
            std::cout << FRED("Command not found!") << std::endl << std::endl;
        if (exit == true)
            return (true);
    std::cout << FMAG("--- Containers menu ---") << std::endl;
    std::cout << FCYN("1") << FWHT(" - Vector") << std::endl;
    std::cout << FCYN("2") << FWHT(" - Map") << std::endl;
    std::cout << FCYN("3") << FWHT(" - Stack") << std::endl;
    std::cout << FGRN("A") << FWHT(" - All") << std::endl;
    std::cout << FYEL("B") << FWHT(" - Back") << std::endl;
    std::cout << FRED("E") << FWHT(" - Exit") << std::endl;
    std::cout << FBLU("Select a container : ");
    }
    return (true);
}

int main( void )
{
    system("clear");
    std::string input;
    bool exit = false;

    std::cout << UNDL(FWHT("Ft_Containers tester by rbitett.")) << std::endl << std::endl;
    
        std::cout << FMAG("--- Main menu ---") << std::endl;
        std::cout << FCYN("1") << FWHT(" - Containers") << std::endl;
        std::cout << FCYN("2") << FWHT(" - Iterators") << std::endl;
        std::cout << FCYN("3") << FWHT(" - Others") << std::endl;
        std::cout << FGRN("A") << FWHT(" - All") << std::endl;
        std::cout << FRED("E") << FWHT(" - Exit") << std::endl;
        std::cout << FBLU("Select a section : ");

    while (std::getline(std::cin, input))
    {
        system("clear");
        if (!input.compare("1"))
            exit = sectionContainers();
        else if (!input.compare("2"))
            exit = sectionIterators();
        else if (!input.compare("3"))
            exit = sectionOthers();
        else if (!input.compare("E") || !input.compare("e"))
            return (0);
        else
            std::cout << FRED("Command not found!") << std::endl << std::endl;
        if (exit == true)
            return (0);
        std::cout << FMAG("--- Main menu ---") << std::endl;
        std::cout << FCYN("1") << FWHT(" - Containers") << std::endl;
        std::cout << FCYN("2") << FWHT(" - Iterators") << std::endl;
        std::cout << FCYN("3") << FWHT(" - Others") << std::endl;
        std::cout << FGRN("A") << FWHT(" - All") << std::endl;
        std::cout << FRED("E") << FWHT(" - Exit") << std::endl;
        std::cout << FBLU("Select a section : ");
    }
    return (0);
}