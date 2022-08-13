#include "./libmem.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

// NOTE: Dans ce fichier, et tout code utilisé par ce fichier,  vous ne pouvez
// pas utiliser `malloc`, `free`, etc.

static struct {
    void* ptr;
    size_t len;
    mem_strategy_t strategy;
    // TODO: Ajouter au moins 1 champ pour le *next-fit*.
} state;

// NOTE: Avant de commencer à implémenter le code de ce
// laboratoire, discuter en équipe afin d'être sûr de tous avoir compris la
// structure de données ce-dessous.

typedef struct block {
    struct block* previous;
    size_t size;
    bool free;
    // NOTE: Vous pouvez ajouter des champs à cette structure de données, mais
    // vous aller perdre des points pour la qualitée.
} block_t;

/**
 * @brief Retourne le premier bloc dans la liste de blocs.
 *
 * @return Le premier bloc
 */
static inline block_t* block_first()
{
    // NOTE: Voici un indice !
    return state.ptr;
}

/**
 * @brief Retourne le prochain bloc dans la liste de blocks.
 * @note Retourne @e NULL s'il n'y a pas de prochain bloc.
 *
 * @param block Un bloc
 * @return Le prochain bloc
 */
static block_t* block_next(block_t* block)
{
    // TODO: À implémenter.

    ((void)block);

    return NULL;
}

/**
 * @brief Acquiert un nombre d'octet du bloc dans le cadre d'une allocation de
 * mémoire.
 *
 * @param block Le noeud libre à utiliser
 * @param size La taille de l'allocation
 */
static void block_acquire(block_t* block, size_t size)
{
    assert(block != NULL);
    assert(block->size >= size);
    assert(block->free);

    // TODO: À implémenter.
    //
    // NOTE:
    // Que faire si `block->size > size` ?  Utiliser les 1000 octets d'un bloc
    // libre pour une allocation de 10 octets ne fait pas de sens.
}

/**
 * @brief Relâche la mémoire utilisé par une allocation, et fusionne le bloc
 * avec son précédant et suivant lorsque nécessaire.
 *
 * @param block Un bloc à relâcher
 */
static void block_release(block_t* block)
{
    assert(block != NULL);
    assert(!block->free);

    // TODO: À implémenter.

    // NOTE:
    // Que faire si le bloc suivant est libre ?
    // Que faire si le bloc précédent est libre ?
}

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
void mem_init(size_t size, mem_strategy_t strategy)
{
    assert(size > 0);
    assert(strategy >= 0);
    assert(strategy < NUM_MEM_STRATEGIES);

    // TODO: Initialiser l'allocateur de mémoire.
}

void mem_deinit(void)
{
    // TODO: Libérez la mémoire utilisée par votre allocateur de mémoire.
}

void* mem_alloc(size_t size)
{
    assert(size > 0);

    // TODO: Alloue un bloc de `size` octets.
    //
    // Ce bloc et ses métadonnées doivent être réservées dans la mémoire pointée
    // entr `state.ptr` et `state.ptr + state.len`.

    // NOTE: Utiliser la structure `block_t` ci-dessus et ses fonctions
    // associées pour implémenter votre allocateur de mémoire.
    //
    // Venez me poser des questions si cela n'est pas clair !

    return NULL;
}

void mem_free(void* ptr)
{
    assert(ptr != NULL);

    // TODO: Libère le bloc de mémoire pointé par `ptr`.
    //
    // Assumez que `ptr` est TOUJOURS un pointeur retourné par `mem_alloc`.
}

size_t mem_get_free_block_count()
{
    // TODO: Indiquez combien de blocs de mémoire sont libre.

    return 0;
}

size_t mem_get_allocated_block_count()
{
    // TODO: Indiquez combien de blocs de mémoire sont alloués.

    return 0;
}

size_t mem_get_free_bytes()
{
    // TODO: Indiquez combien d'octets sont disponibles pour des allocations
    // de mémoire.

    return 0;
}

size_t mem_get_biggest_free_block_size()
{
    // TODO: Indiquez la taille en octets du plus gros plus de mémoire libre.

    return 0;
}

size_t mem_count_small_free_blocks(size_t max_bytes)
{
    assert(max_bytes > 0);

    // TODO: Indiquez combien de blocs de mémoire plus petit que `max_bytes`
    // sont disponibles.

    return 0;
}

bool mem_is_allocated(void* ptr)
{
    assert(ptr != NULL);

    // TODO: Indiquez si l'octet pointé par `ptr` est alloué.

    // NOTE: Ce pointeur peut pointer vers n'importe quelle adresse mémoire.

    return false;
}

void mem_print_state(void)
{
    // TODO: Imprimez l'état de votre structure de données.
    //
    //   - Affichez les blocs en ordre.
    //   - Un bloc alloué commence par un 'A', tandis qu'un bloc libre commence
    //     par 'F'.
    //   - Après la lettre, imprimez la taille du bloc.
    //   - Séparez les blocs par un espace.
    //   - Cela ne dérange pas s'il y a un espace supplémentaire à la fin de la
    //     ligne.
    //
    // Ex.:
    //
    // ```
    // A100 F24 A20 A58 F20 A27 F600
    // ```
}
