#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;
    int name_len, owner_len;

    /* allocate memory for new dog */
    new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return (NULL);

    /* find the length of name and owner */
    for (name_len = 0; name[name_len] != '\0'; name_len++)
        ;
    for (owner_len = 0; owner[owner_len] != '\0'; owner_len++)
        ;

    /* allocate memory for name and owner */
    new_dog->name = malloc(sizeof(char) * (name_len + 1));
    if (new_dog->name == NULL)
    {
        free(new_dog);
        return (NULL);
    }
    new_dog->owner = malloc(sizeof(char) * (owner_len + 1));
    if (new_dog->owner == NULL)
    {
        free(new_dog->name);
        free(new_dog);
        return (NULL);
    }

    /* copy name and owner to new dog */
    for (name_len = 0; name[name_len] != '\0'; name_len++)
        new_dog->name[name_len] = name[name_len];
    new_dog->name[name_len] = '\0';

    for (owner_len = 0; owner[owner_len] != '\0'; owner_len++)
        new_dog->owner[owner_len] = owner[owner_len];
    new_dog->owner[owner_len] = '\0';

    new_dog->age = age;

    return (new_dog);
}
