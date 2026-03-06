# 📘 Cours Complet — Structures de Données & Algorithmie
### *Appliqué au projet Push-Swap (42)*

---

# PARTIE A : STRUCTURES DE DONNÉES

---

## Chapitre 1 — Le Tableau (Array)

### 1.1 Définition

Un **tableau** est une zone de mémoire **contiguë** (les éléments sont côte à côte) qui stocke un nombre **fixe** d'éléments du même type.

```
Mémoire :
┌─────┬─────┬─────┬─────┬─────┐
│  42 │  17 │  89 │   3 │  56 │   ← 5 cases consécutives en mémoire
└─────┴─────┴─────┴─────┴─────┘
  [0]   [1]   [2]   [3]   [4]     ← index (accès direct)
```

En C, on le déclare ainsi :

```c
int tab[5] = {42, 17, 89, 3, 56};
```

### 1.2 Caractéristiques clés

| Propriété | Détail |
|---|---|
| **Taille** | Fixée à la déclaration (statique) ou via `malloc` (dynamique) |
| **Accès** | **Direct** par index : `tab[3]` donne `3` → c'est du **O(1)** |
| **Mémoire** | Contiguë : chaque élément est à côté du précédent |
| **Insertion/Suppression** | **Coûteux** : il faut décaler tous les éléments → **O(n)** |

### 1.3 Forces et faiblesses

**✅ Forces :**
- Accès instantané à n'importe quel élément par son index
- Très rapide pour la lecture séquentielle (le cache mémoire adore les données contiguës)
- Simple à utiliser

**❌ Faiblesses :**
- Taille fixe : impossible d'ajouter un élément si le tableau est plein (sauf `realloc`)
- Insérer ou supprimer au milieu = décaler tous les éléments suivants
- Gaspillage de mémoire si on alloue trop grand "au cas où"

### 1.4 Dans ton projet Push-Swap

Tu utilises des tableaux dans ta fonction `stack_to_array` pour créer une **copie triée** de ta pile. C'est un bon usage : le tableau est parfait ici car tu connais la taille à l'avance (`lena`) et tu as besoin d'un accès par index pour le tri et la recherche.

```c
// Dans helpers.c — tu copies ta pile dans un tableau
int *array = ft_calloc(1, sizeof(int) * lena);
```

---

## Chapitre 2 — La Liste Chaînée (Linked List)

### 2.1 Définition

Une **liste chaînée** est une collection de **nœuds** (nodes) dispersés en mémoire, reliés entre eux par des **pointeurs**.

```
Mémoire (les nœuds sont dispersés, pas côte à côte) :

  ┌──────────────┐     ┌──────────────┐     ┌──────────────┐
  │ content: 42  │     │ content: 17  │     │ content: 89  │
  │ next: ───────┼────►│ next: ───────┼────►│ next: NULL   │
  └──────────────┘     └──────────────┘     └──────────────┘
     Nœud 0               Nœud 1               Nœud 2
```

### 2.2 Le Nœud (Node) — Brique de base

Chaque **nœud** (aussi appelé **maillon**) est une structure qui contient :
1. Une **donnée** (`content`) — la valeur stockée
2. Un **pointeur** (`next`) — l'adresse du nœud suivant

Dans ta libft, c'est défini comme :

```c
typedef struct s_list
{
    void            *content;   // la donnée (générique)
    struct s_list   *next;      // pointeur vers le nœud suivant
} t_list;
```

> 💡 **Nœud** et **maillon** sont synonymes. On parle de "nœud" en informatique et de "maillon" par analogie avec une chaîne physique — d'où le nom "liste *chaînée*".

### 2.3 Caractéristiques clés

| Propriété | Détail |
|---|---|
| **Taille** | **Dynamique** : on ajoute/retire des nœuds à volonté |
| **Accès** | **Séquentiel** : pour atteindre le 5e élément, il faut traverser les 4 premiers → **O(n)** |
| **Mémoire** | Non contiguë : chaque nœud est quelque part en mémoire |
| **Insertion au début** | **Très rapide** : on change juste un pointeur → **O(1)** |
| **Insertion à la fin** | Il faut parcourir toute la liste → **O(n)** |

### 2.4 Les différents types de listes chaînées

#### a) Liste simplement chaînée ← **C'est ce que tu utilises**

Chaque nœud pointe vers le **suivant**. On ne peut aller que dans un sens.

```
[42] → [17] → [89] → [3] → NULL
```

#### b) Liste doublement chaînée

Chaque nœud a **deux** pointeurs : vers le suivant ET vers le précédent. On peut naviguer dans les deux sens.

```
NULL ← [42] ⇄ [17] ⇄ [89] ⇄ [3] → NULL
```

```c
typedef struct s_dlist
{
    void            *content;
    struct s_dlist  *next;  // vers le suivant
    struct s_dlist  *prev;  // vers le précédent
} t_dlist;
```

**Avantage** : remonter en arrière est en O(1) au lieu de O(n). Utile pour des opérations comme `rra` (reverse rotate).

**Inconvénient** : consomme plus de mémoire (un pointeur en plus par nœud) et plus complexe à gérer.

#### c) Liste circulaire

Le dernier nœud pointe vers le **premier** au lieu de `NULL`. La boucle est fermée.

```
[42] → [17] → [89] → [3] ─┐
  ▲                         │
  └─────────────────────────┘
```

**Avantage** : on peut boucler indéfiniment, et si on garde un pointeur sur le dernier élément, on accède au premier ET au dernier en O(1).

### 2.5 Tableau vs Liste Chaînée — Résumé comparatif

| Critère | Tableau | Liste chaînée |
|---|---|---|
| Accès au i-ème élément | **O(1)** — instantané | **O(n)** — parcours nécessaire |
| Insertion au début | **O(n)** — tout décaler | **O(1)** — changer un pointeur |
| Insertion à la fin | **O(1)** si place disponible | **O(n)** — parcourir jusqu'au bout |
| Taille | Fixe ou coûteux à redimensionner | Dynamique, grandit à volonté |
| Mémoire | Contiguë, efficace en cache | Dispersée, overhead des pointeurs |
| Suppression du premier | **O(n)** — tout décaler | **O(1)** — changer un pointeur |

> 🎯 **Règle simple** : Si tu as besoin d'**accès par index** → tableau. Si tu as besoin d'**insertions/suppressions fréquentes** au début → liste chaînée.

---

## Chapitre 3 — Structures de Données Abstraites

### 3.1 Qu'est-ce qu'une structure abstraite ?

Une **structure de données abstraite** (SDA), c'est un **concept** qui définit un **comportement** — une façon d'interagir avec les données — sans imposer comment on l'implémente concrètement.

C'est la distinction fondamentale qu'on a vue ensemble :

```
Structure CONCRÈTE              Structure ABSTRAITE
(comment c'est fait)            (comment on l'utilise)
─────────────────               ─────────────────────
• Tableau                  ──►  • Pile (Stack)
• Liste simplement chaînée ──►  • File (Queue)
• Liste doublement chaînée ──►  • Deque (Double-ended queue)
• Liste circulaire         ──►  • ...
```

On peut implémenter une **pile** avec un tableau OU une liste chaînée. Le comportement est le même, seule la "mécanique interne" change.

### 3.2 La Pile (Stack) — LIFO

**LIFO** = **Last In, First Out** (dernier entré, premier sorti).

Pense à une **pile d'assiettes** : tu poses les assiettes par le dessus et tu prends toujours celle du dessus. Tu ne peux pas accéder directement à une assiette au milieu sans retirer celles du dessus.

```
Opérations d'une pile :

    PUSH (empiler)          POP (dépiler)           TOP (sommet)
    ┌───┐                   ┌───┐
    │ 5 │ ← ajouté          │ 5 │ ← retiré          On lit le 5
    ├───┤                   ├───┤                    sans le retirer
    │ 3 │                   │ 3 │
    ├───┤                   ├───┤
    │ 7 │                   │ 7 │
    └───┘                   └───┘
```

**Les deux opérations fondamentales :**

| Opération | Description | Complexité |
|---|---|---|
| **push** | Ajouter un élément au sommet | O(1) |
| **pop** | Retirer l'élément du sommet | O(1) |

#### 🔍 Dans ton Push-Swap

Tes `stack_a` et `stack_b` sont des **piles**. Tu les implémentes avec des **listes simplement chaînées** :

- `pb` = **push** sur la pile B (prendre le sommet de A, le poser sur B)
- `pa` = **push** sur la pile A (prendre le sommet de B, le poser sur A)

```c
// Dans ton op2.c — pb fait un "pop" de A puis un "push" dans B
pusha = *stacka;                 // prendre le sommet de A
*stacka = (*stacka)->next;       // A perd son sommet (pop)
pusha->next = *stackb;           // le sommet de A pointe vers B
*stackb = pusha;                 // B gagne un nouveau sommet (push)
```

> ⚠️ **Attention** : tes piles Push-Swap ne sont pas des piles "pures" car tu as aussi `ra`/`rra` (rotation), ce qui viole le principe strict LIFO. En réalité, tes piles Push-Swap ressemblent plus à des **deques** (double-ended queues) — mais on les appelle "piles" par convention du sujet.

### 3.3 La File (Queue) — FIFO

**FIFO** = **First In, First Out** (premier entré, premier sorti).

Pense à une **file d'attente** au supermarché : le premier arrivé est le premier servi.

```
Opérations d'une file :

  ENQUEUE (enfiler)                          DEQUEUE (défiler)
  Entrée ──►  [1] [2] [3] [4] [5]  ──►  Sortie
              ← arrière    avant →
```

| Opération | Description | Complexité |
|---|---|---|
| **enqueue** | Ajouter un élément à l'arrière | O(1) |
| **dequeue** | Retirer l'élément à l'avant | O(1) |

#### Comparaison Pile vs File

| | Pile (LIFO) | File (FIFO) |
|---|---|---|
| **Analogie** | Pile d'assiettes | File d'attente |
| **Ajout** | Par le dessus | Par l'arrière |
| **Retrait** | Par le dessus | Par l'avant |
| **Usage** | Push-Swap, appels de fonctions, undo/redo | Files d'impression, BFS, buffers |

> 💡 Tu n'utilises pas de file dans Push-Swap, mais c'est un concept fondamental à connaître. Quand tu entends "FIFO", pense "file d'attente". Quand tu entends "LIFO", pense "pile d'assiettes".

### 3.4 Résumé visuel complet

```
            ┌─────────────────────────────────────────────┐
            │     STRUCTURES DE DONNÉES                   │
            └─────────────────┬───────────────────────────┘
                              │
              ┌───────────────┼───────────────┐
              ▼               ▼               ▼
        ┌──────────┐   ┌──────────┐   ┌──────────────┐
        │ CONCRÈTES│   │ABSTRAITES│   │  COMPOSITES  │
        └────┬─────┘   └────┬─────┘   └──────┬───────┘
             │              │                 │
         ┌───┼───┐     ┌───┼───┐         ┌───┼───┐
         ▼   ▼   ▼     ▼   ▼   ▼         ▼   ▼   ▼
       Tab  Liste Arbre Pile File Deque  Table Graph
            chaînée            (LIFO)(FIFO)     Hash
```

---

---

# PARTIE B : ALGORITHMIE

---

## Chapitre 4 — La Complexité (Notation Big O)

### 4.1 Qu'est-ce que la complexité ?

La **complexité temporelle** mesure **combien d'opérations** un algorithme effectue en fonction de la taille de l'entrée (notée **n**).

Ce n'est **pas** le temps en secondes (ça dépend de l'ordinateur). C'est une mesure **abstraite** de l'efficacité de l'algorithme : *"Comment le nombre d'opérations évolue-t-il quand la taille de l'entrée grandit ?"*

### 4.2 La notation Big O

On utilise la notation **O(...)** (prononcée "Grand O de...") pour exprimer cette complexité. On ne s'intéresse qu'à la **tendance générale** quand n devient très grand.

**Règles de simplification :**
- On ignore les constantes : `O(3n)` → `O(n)`
- On garde le terme dominant : `O(n² + n)` → `O(n²)`
- On s'intéresse au **pire cas** (sauf mention contraire)

### 4.3 Les complexités courantes

Classées de la plus rapide à la plus lente :

#### O(1) — Temps constant ⚡

Le nombre d'opérations est **toujours le même**, quelle que soit la taille de l'entrée.

```
Exemples :
• Accéder à tab[5] dans un tableau
• Ajouter un nœud au début d'une liste chaînée
• Ton opération pb (push vers la pile B)
```

Ça ne veut pas dire "une seule opération", ça veut dire "un nombre fixe d'opérations", que n soit 10 ou 10 000.

#### O(log n) — Logarithmique 🚀

Le nombre d'opérations augmente très lentement. À chaque étape, on **divise** le problème par 2.

```
Exemples :
• Recherche dichotomique (binary search) dans un tableau trié
• Parcourir les bits d'un nombre (c'est log₂(n) bits)

n = 1 000      → ~10 opérations
n = 1 000 000  → ~20 opérations
```

> 🔍 Dans ton Push-Swap, `get_max_bits` calcule le nombre de bits nécessaires pour représenter la plus grande valeur. Ce nombre de bits, c'est exactement **log₂(n)**.

#### O(n) — Linéaire 📈

Le nombre d'opérations est **proportionnel** à la taille de l'entrée.

```
Exemples :
• Parcourir toute une liste chaînée
• Ta fonction get_min_index (parcourir pour trouver le minimum)
• Ta fonction is_sorted_stack

n = 100    → ~100 opérations
n = 1 000  → ~1 000 opérations
```

#### O(n log n) — Linéarithmique 📊

C'est la complexité **optimale** pour un tri par comparaison. C'est la "limite théorique" — on ne peut pas faire mieux avec des comparaisons.

```
Exemples :
• Merge Sort, Quick Sort (cas moyen), Heap Sort
• Ton Radix Sort (il fait log₂(n) passes de n éléments chacune)

n = 100    → ~664 opérations
n = 1 000  → ~9 966 opérations
```

#### O(n√n) — Racine carrée ×n 📈📈

Entre O(n log n) et O(n²). C'est la complexité de ton algorithme **medium** (chunk-based).

```
n = 100    → ~1 000 opérations
n = 500    → ~11 180 opérations
```

#### O(n²) — Quadratique 🐢

Le nombre d'opérations explose. Pour chaque élément, on fait potentiellement n opérations.

```
Exemples :
• Bubble Sort, Selection Sort, Insertion Sort
• Ton algorithme Simple (ft_simple)
• Deux boucles imbriquées qui parcourent les mêmes données

n = 100    → ~10 000 opérations
n = 1 000  → ~1 000 000 opérations
```

### 4.4 Tableau comparatif — Visualiser la croissance

| n | O(1) | O(log n) | O(n) | O(n log n) | O(n√n) | O(n²) |
|---|---|---|---|---|---|---|
| **10** | 1 | 3 | 10 | 33 | 31 | 100 |
| **100** | 1 | 7 | 100 | 664 | 1 000 | 10 000 |
| **500** | 1 | 9 | 500 | 4 482 | 11 180 | 250 000 |
| **1 000** | 1 | 10 | 1 000 | 9 966 | 31 622 | 1 000 000 |

> 🎯 **Ce qu'il faut retenir** : la complexité décrit la **vitesse de croissance**. Un algo O(n²) ne va pas juste "un peu plus lentement" qu'un O(n log n) — il s'effondre à grande échelle.

### 4.5 Complexité spatiale (mémoire)

La même logique s'applique à la **mémoire** utilisée :

- `O(1)` en espace = pas de mémoire supplémentaire (tri "en place")
- `O(n)` en espace = on utilise une copie des données (comme ton `stack_to_array`)

---

## Chapitre 5 — Algorithmes de Tri

### 5.1 Pourquoi le tri est important

Le tri est un problème **fondamental** en informatique. Presque tout en dépend : recherche efficace, affichage ordonné, détection de doublons, compression de données, etc.

Le **théorème** important : aucun algorithme de tri basé sur des comparaisons ne peut faire mieux que **O(n log n)** dans le pire cas. C'est une borne inférieure mathématiquement prouvée.

### 5.2 Les tris classiques

#### a) Tri par sélection (Selection Sort) — O(n²)

**Principe** : à chaque étape, on trouve le **minimum** de la partie non triée et on le place au bon endroit.

```
[64, 25, 12, 22, 11]
 ↓ minimum = 11
[11, 25, 12, 22, 64]    swap 64 ↔ 11
 ↓ minimum dans le reste = 12
[11, 12, 25, 22, 64]    swap 25 ↔ 12
 ↓ minimum dans le reste = 22
[11, 12, 22, 25, 64]    swap 25 ↔ 22
 → terminé !
```

> 🔍 **Ton `ft_simple`** est essentiellement un **tri par sélection** adapté aux piles Push-Swap ! Tu cherches le minimum avec `get_min_index`, tu le fais remonter au sommet (via `ra`/`rra`), puis tu le pousses dans B (`pb`). Pourquoi c'est O(n²) ? Parce que tu fais **n passes** (une par élément), et à chaque passe tu parcours jusqu'à **n éléments** pour trouver le minimum et le déplacer. Donc n × n = n².

#### b) Tri à bulles (Bubble Sort) — O(n²)

**Principe** : on compare chaque paire d'éléments adjacents et on les échange si nécessaire. On recommence jusqu'à ce que tout soit trié.

```
[5, 3, 8, 1, 2]
 ↓ comparer 5,3 → swap
[3, 5, 8, 1, 2]
 ↓ comparer 5,8 → ok
[3, 5, 8, 1, 2]
 ↓ comparer 8,1 → swap
[3, 5, 1, 8, 2]
 ↓ comparer 8,2 → swap
[3, 5, 1, 2, 8]   ← le 8 a "bullé" vers la fin
...on recommence...
```

> 🔍 C'est exactement l'algo de ta fonction `sort_array` dans `helpers.c` ! Tu l'utilises pour trier ton tableau de référence.

#### c) Tri par base (Radix Sort) — O(n × k)

**Principe** : au lieu de comparer les éléments entre eux, on les trie **bit par bit** (ou chiffre par chiffre). Pas de comparaison directe entre éléments !

C'est un tri **non-comparatif**, ce qui permet de contourner la limite O(n log n).

```
Trier [5, 3, 7, 1, 6] en binaire :

5 = 101    3 = 011    7 = 111    1 = 001    6 = 110

Passe 1 (bit 0, le plus à droite) :
  bit = 1 : [5, 3, 7, 1] → restent dans A
  bit = 0 : [6]           → poussés dans B
  Résultat après remise : [5, 3, 7, 1, 6]

Passe 2 (bit 1) :
  bit = 1 : [3, 7, 6] → restent dans A
  bit = 0 : [5, 1]    → poussés dans B
  Résultat après remise : [3, 7, 6, 5, 1]

Passe 3 (bit 2) :
  bit = 1 : [7, 5] → restent dans A
  bit = 0 : [3, 6, 1] → poussés dans B
  Résultat après remise : [1, 3, 5, 6, 7] ✓ Trié !
```

> 🔍 **Ton `radix_sort`** dans `complex.c` implémente exactement ce principe ! La variable `i_bits` parcourt les bits de 0 à `max_bits`, et `check_bits` décide pour chaque élément s'il reste dans A ou part dans B en testant le bit courant : `(index >> i_bits) & 1`.

> **Complexité** : O(n × log₂(max_val)), car tu fais `log₂(max_val)` passes de `n` éléments. Comme `max_val` est souvent proche de `n`, on simplifie en **O(n log n)**.

#### d) Tri par chunks (ton algorithme Medium) — O(n√n)

**Principe** : on divise les éléments en **groupes** (chunks) de taille √n, on pousse chaque chunk dans B, puis on rapatrie dans l'ordre.

```
Pour n = 100 éléments, chunk_size ≈ 15-17 éléments :

Étape 1 : Pousser les chunks dans B
  • Chunk 0 (indices 0-16)  → pousse dans B
  • Chunk 1 (indices 17-33) → pousse dans B
  • ...etc

Étape 2 : Rapatrier depuis B
  • Trouver le max dans B → le remonter au sommet → pa
  • Répéter jusqu'à ce que B soit vide
```

> 🔍 **Ton `ft_medium`** : `push_chunk` pousse les éléments chunk par chunk dans B. Ensuite, la boucle `while (tab->stack_b)` rapatrie en cherchant le max avec `get_max_index`.

> **Pourquoi O(n√n) ?** : Tu as √n chunks. Pour chaque chunk, tu parcours au maximum n éléments pour les trouver et les pousser. Puis le rapatriement est en O(n²/2) dans le pire cas. Le résultat global tend vers O(n√n).

---

## Chapitre 6 — L'Invariant de Boucle

### 6.1 Définition

Un **invariant de boucle** est une **propriété** qui est **vraie** :
1. **Avant** la première itération de la boucle (initialisation)
2. **À chaque itération** (maintenance)
3. **Après** la dernière itération (terminaison)

C'est un outil de **preuve de correction** : si on prouve qu'un invariant est maintenu, on prouve que l'algorithme fait ce qu'il est censé faire.

### 6.2 Exemple concret dans ton code

Prenons ta fonction `is_sorted_stack` :

```c
int is_sorted_stack(t_list *stack)
{
    while (stack && stack->next)
    {
        if ((long)stack->content > (long)stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}
```

**L'invariant de boucle** ici est :

> *"Tous les éléments déjà parcourus (du début jusqu'au nœud actuel) sont en ordre croissant."*

- **Initialisation** : avant la boucle, on n'a parcouru aucun élément → l'invariant est trivialement vrai.
- **Maintenance** : à chaque tour, si `content > next->content`, on retourne 0 (pas trié). Sinon, on avance, et l'invariant reste vrai.
- **Terminaison** : si on sort de la boucle sans retourner 0, l'invariant vaut pour toute la liste → elle est triée → on retourne 1.

### 6.3 Exemple dans ft_simple

```c
void ft_simple(t_sta *tab)
{
    // ...
    while (stacka)          // tant qu'il reste des éléments dans A
    {
        j = get_min_index(stacka);  // trouver le minimum
        if (j == 0)
            pb(tab, &stacka, &stackb);   // pousser dans B
        else if (j < i / 2)
            ra(tab, &stacka);             // le rapprocher du sommet
        else
            rra(tab, &stacka);
    }
    while (stackb)
        pa(tab, &stackb, &stacka);   // tout remettre dans A
}
```

**L'invariant** de la première boucle :

> *"Les éléments dans B sont triés en ordre croissant (du sommet = le plus petit, vers le fond = le plus grand), car on pousse toujours le minimum de A."*

Cet invariant garantit qu'à la fin, quand on remet tout dans A, les éléments arrivent dans le bon ordre.

### 6.4 Pourquoi c'est utile ?

L'invariant de boucle te sert à :
1. **Vérifier** que ton algo est correct (surtout pour la défense de projet !)
2. **Débugger** : si le résultat est faux, un de tes invariants a été violé — ça localise le problème
3. **Communiquer** : expliquer ton algo à quelqu'un en disant *"à chaque étape, cette propriété est vraie"*

---

## Chapitre 7 — Résumé général & Vocabulaire

### 7.1 Glossaire des termes essentiels

| Terme | Définition |
|---|---|
| **Nœud (Node)** | Un élément d'une liste chaînée, contenant une donnée et un pointeur |
| **Maillon** | Synonyme de nœud |
| **Tête (Head)** | Le premier nœud d'une liste chaînée |
| **Queue (Tail)** | Le dernier nœud d'une liste chaînée |
| **Pile (Stack)** | Structure abstraite LIFO — dernier entré, premier sorti |
| **File (Queue)** | Structure abstraite FIFO — premier entré, premier sorti |
| **Complexité** | Mesure de l'efficacité d'un algorithme en fonction de la taille de l'entrée |
| **Big O** | Notation pour exprimer la complexité dans le pire cas |
| **Invariant** | Propriété toujours vraie avant, pendant et après une boucle |
| **Tri en place** | Tri qui n'utilise pas de mémoire supplémentaire proportionnelle à n |
| **Tri stable** | Tri qui préserve l'ordre relatif des éléments égaux |
| **Tri non-comparatif** | Tri qui ne compare pas les éléments entre eux (ex: Radix Sort) |

### 7.2 Tes algorithmes Push-Swap — Récapitulatif

| Algo | Complexité | Méthode | Quand l'utiliser |
|---|---|---|---|
| **ft_simple** | O(n²) | Selection sort adapté | Données peu désordonnées (< 20%) |
| **ft_medium** | O(n√n) | Tri par chunks | Désordre moyen (20-50%) |
| **radix_sort** | O(n log n) | Tri par bits (radix) | Données très désordonnées (> 50%) |
| **adaptive** | Variable | Choix automatique selon le désordre | Mode par défaut |

---

### 📝 Questions d'auto-évaluation

Pour vérifier que tu as bien assimilé ces concepts, essaie de répondre à ces questions sans relire le cours :

1. Quelle est la différence entre une structure **concrète** et une structure **abstraite** ?
2. Pour ton opération `rra`, quelle est la complexité avec une liste simplement chaînée ? Pourquoi ?
3. Si ton `ft_simple` fait ~10 000 opérations pour 100 éléments, combien en ferait-il (approximativement) pour 200 éléments ?
4. Dans ton `radix_sort`, pourquoi tester `(index >> i_bits) & 1` permet-il de trier ?
5. Quel est l'invariant de boucle de ta fonction `push_chunk` dans `medium.c` ?

---

*Document rédigé dans le cadre du mentorat Push-Swap — 42*
