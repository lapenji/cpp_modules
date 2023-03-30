#include "Bureaucrat.hpp"

int main( void )
{
    try {
        Bureaucrat bureaucrat1("pinco", 151);
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.increment();
        std::cout << bureaucrat1 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureaucrat2("pallo", 10);
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrement();
        std::cout << bureaucrat2 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
