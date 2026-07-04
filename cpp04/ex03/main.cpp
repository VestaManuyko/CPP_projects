#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <cassert>

static void title(const std::string &s)
{
    std::cout << "\n=== " << s << " ===\n" << std::endl;
}

static void test_subject_flow()
{
    title("Subject test");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");

    AMateria* tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

static void test_materia_basic_behavior()
{
    title("AMateria basic behavior");
    Ice ice;
    Cure cure;

    assert(ice.getType() == "ice");
    assert(cure.getType() == "cure");

    AMateria* cloned = ice.clone();
    assert(cloned != NULL);
    assert(cloned->getType() == "ice");
    delete cloned;

    Character target("target");
    ice.use(target);
    cure.use(target);
}

static void test_character_inventory_edge_cases()
{
    title("Character inventory edge cases");
    Character hero("hero");

    hero.equip(new Ice());
    hero.equip(new Cure());
    hero.equip(new Ice());
    hero.equip(new Cure());
    hero.equip(new Ice());

    assert(hero.getMateria(0) != NULL);
    assert(hero.getMateria(1) != NULL);
    assert(hero.getMateria(2) != NULL);
    assert(hero.getMateria(3) != NULL);
    assert(hero.getMateria(4) == NULL);

    hero.use(0, hero);
    hero.use(1, hero);
    hero.use(2, hero);
    hero.use(3, hero);
    hero.use(4, hero);
    hero.use(-1, hero);

	AMateria *saved = hero.getMateria(0);
    hero.unequip(0);
	delete saved;
    hero.unequip(4);
    hero.unequip(-1);
    hero.use(0, hero);
}

static void test_materia_source_behavior()
{
    title("MateriaSource behavior");
    MateriaSource source;

    source.learnMateria(new Ice());
    source.learnMateria(new Cure());
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());
    source.learnMateria(new Ice());

    AMateria* createdIce = source.createMateria("ice");
    AMateria* createdCure = source.createMateria("cure");
    AMateria* createdUnknown = source.createMateria("unknown");

    assert(createdIce != NULL);
    assert(createdIce->getType() == "ice");
    assert(createdCure != NULL);
    assert(createdCure->getType() == "cure");
    assert(createdUnknown == NULL);

    delete createdIce;
    delete createdCure;
	std::cout << "Everything works!\n";
}

static void test_copy_semantics()
{
    title("Copy semantics");
    Character original("original");
    original.equip(new Ice());
	original.equip(new Cure);
	original.equip(new Cure);
	original.equip(new Cure);

    Character copy("copy");
    copy = original;
    assert(copy.getName() == "original");
    assert(copy.getMateria(0) != NULL);
    assert(copy.getMateria(0)->getType() == "ice");
	copy.equip(new Ice());

    MateriaSource source;
    source.learnMateria(new Ice());

    MateriaSource copied;
    copied = source;
	AMateria *saved = copied.createMateria("ice");
    assert(saved != NULL);
	delete saved;

	std::cout << "Everything works!\n";
}

int main()
{
    test_subject_flow();
    test_materia_basic_behavior();
    test_character_inventory_edge_cases();
    test_materia_source_behavior();
    test_copy_semantics();
    return 0;
}
