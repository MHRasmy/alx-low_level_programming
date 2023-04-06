#ifndef DOG_H
#define DOG_H

/**
 * struct dog - structure for dog's information
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner name
 *
 * Description: structure called dog containing name, age and owner's name
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);
#endif /* DOG_H */
