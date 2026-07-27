#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl;
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("valid form creation by intern");
	Intern	robert;
	AForm *form = robert.makeForm("robotomy request", "lalla");
	Bureaucrat bob("Bob", 1);
	bob.signForm(*form);
	bob.executeForm(*form);
	title("invalid form creation by intern");
	Intern	roberto;
	AForm *form1 = roberto.makeForm("robotomy requestt", "lalla");
	if (form1 == NULL)
		std::cout << "makeForm returned NULL" << std::endl;
	delete form;
	delete form1;
}