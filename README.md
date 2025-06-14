# Linear Linked List Manager in C

This is a C program that manages a singly linked list with support for:
- Inserting elements at different positions
- Deleting elements under various conditions
- Searching elements
- Classifying nodes into even and odd sublists
- Displaying list contents

## Files

- `liste.h`: Defines the node and list structures, as well as function prototypes.
- `liste.c`: Contains all the list operations and logic.
- `main.c`: Demonstrates the use of list operations with sample input.

## Features

- Initialize an empty list
- Insert elements at:
  - The beginning
  - The end
  - Before a reference node
- Delete:
  - The first node
  - Alternate nodes (`supp_skip`)
  - The node with the smallest key
- Check if a value exists
- Classify values into even and odd lists without duplicates
- Print the entire list

---

## How to Compile

```bash
gcc main.c liste.c -o list-manager
```

## How to Run

```bash
./list-manager
```

## Example Input/Output

```
Donner un entier 1 de la liste: 10
Voulez vous inserer un autre entier ds la liste (1:oui, 0:non): 1
Donner un entier 2 de la liste: 15
Voulez vous inserer un autre entier ds la liste (1:oui, 0:non): 1
Donner un entier 3 de la liste: 22
Voulez vous inserer un autre entier ds la liste (1:oui, 0:non): 1
Donner un entier 4 de la liste: 15
Voulez vous inserer un autre entier ds la liste (1:oui, 0:non): 0

ur liste : 
10    15    22    15    

donnez un nbr a inser : 99

Liste après insertion avant chaque 2ᵉ élément:
99    10    15    22    15    

Liste après suppression d’un élément sur deux:
99    15    15    

Liste des éléments pairs (sans doublons) :
Liste vide

Liste des éléments impairs (sans doublons) :
99    15    
```

